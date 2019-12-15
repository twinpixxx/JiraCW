#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template<typename T>
class List
{
protected:
	template<typename T> friend class Iterator;
	Node<T>* head;
	Node<T>* tail;
	long amount;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		amount = 0;
	}
	~List()
	{
		while (head)
		{
			this->pop_head();
		}
	}

	//Длина списка
	long size()
	{
		return this->amount;
	}

	//Добавление с головы
	void push_head(T input_object)
	{
		if (head == nullptr)
		{
			head = new Node<T>;
			head->data = input_object;
			head->next = nullptr;
			head->prev = nullptr;
			tail = head;
			amount++;
			return;
		}
		Node<T>* node = new Node<T>;
		node->data = input_object;
		node->next = head;
		node->prev = nullptr;
		head->prev = node;
		head = node;
		amount++;
		return;
	}
	//Доавление в хвост
	void push_tail(T input_object)
	{
		if (head == nullptr)
		{
			head = new Node<T>;
			head->data = input_object;
			head->next = nullptr;
			head->prev = nullptr;
			tail = head;
			amount++;
			return;
		}
		Node<T>* node = new Node<T>;
		node->data = input_object;
		node->next = nullptr;
		node->prev = tail;
		tail->next = node;
		tail = node;
		amount++;
		return;
	}

	//Удаление от головы
	T pop_head()
	{
		if (!(head)) return T();
		T data = head->data;
		Node<T>* node = head;
		head = head->next;
		if (head)
			head->prev = nullptr;
		delete node;
		amount--;
		return data;
	}
	//Удаление из хвоста
	T pop_tail()
	{
		if (!(head)) return T();
		T data = tail->data;
		Node<T>* node = tail;
		tail = tail->prev;
		if (tail)
			tail->next = nullptr;
		delete node;
		amount--;
		return data;
	}

	// произвольный доступ к объектам
	T& operator[](long num)
	{
		Node<T>* curr = head;
		if (num < 0 || num >= amount) return curr->data;
		for (long i = 0; i < num; i++)
			curr = curr->next;
		return curr->data;
	}

	// удаление элемента из списка
	void delete_element(long num)
	{
		Node<T>* curr = head;
		long i = 0;
		if (num < 0 || num >= amount) {
			head = head->next;
			delete curr;
			curr = nullptr;
			this->amount--;
			return;
		}
		for (i = 0; i < num; i++) {
			curr = curr->next;
		}
		if (i == num) {
			if (curr->next != nullptr) curr->next->prev = curr->prev;
			if (curr->prev != nullptr) curr->prev->next = curr->next;
			delete curr;
			curr = nullptr;
			this->amount--;
			return;
		}
	}


	// функции для работы с итератором
	Node<T>* begin()
	{
		return head;
	}
	Node<T>* end()
	{
		if (tail != nullptr) return tail->next;
		return tail;
	}

	// вывод на экран содержимого списка
	void output()
	{
		int i = 0;
		if (!head) cout << "Список пуст!";
		else
			for (Node<T>* node = head; node != nullptr; node = node->next)
			{
				cout << setw(3) << i + 1 << node->data;
				cout << endl;
				i++;
			}
	}


	void outputByName(std::string _title)
	{
		int i = 0;
		bool flag = false;
		if (!head) cout << "Список пуст!";
		else
			for (Node<T>* node = head; node != nullptr; node = node->next)
			{
				if (node->data.getTitle() == _title)
				{
					cout << setw(3) << i + 1 << node->data;
					cout << endl;
					i++;
					flag = true;
				}
			}
		if (!flag) cout << "Проект не найден." << endl;

	}
	void outputByPriority(int _priority)
	{
		int i = 0;
		bool flag = false;
		if (!head) cout << "Список пуст!";
		else
			for (Node<T>* node = head; node != nullptr; node = node->next)
			{
				if (node->data.getPriority() == _priority)
				{
					cout << setw(3) << i + 1 << node->data;
					cout << endl;
					i++;
					flag = true;
				}
			}
		if (!flag) cout << "Проект не найден." << endl;
	}
	void outputByExec(std::string _exec)
	{
		int i = 0;
		bool flag = false;
		if (!head) cout << "Список пуст!";
		else
			for (Node<T>* node = head; node != nullptr; node = node->next)
			{
				if (node->data.getProjectExecutor() == _exec)
				{
					cout << setw(3) << i + 1 << node->data;
					cout << endl;
					i++;
					flag = true;
				}
			}
		if (!flag) cout << "Проект не найден." << endl;
	}
};

template <typename T>
class Iterator
{
	Node<T>* current;
public:
	Iterator()
	{
		current = nullptr;
	}
	Iterator(List<T>& container)
	{
		current = container.head;
	}
	Iterator(Iterator<T>& iter)
	{
		current = iter.current;
	}
	Iterator(Node<T>* node)
	{
		current = node;
	}
	~Iterator() {}

	Node<T>* get_node()
	{
		return current;
	}

	bool operator++(int i)
	{
		if (current == nullptr) return false;
		current = current->next;
		return true;
	}
	bool operator--(int i)
	{
		if (current->prev == nullptr) return false;
		current = current->prev;
		return true;
	}
	T& operator*()
	{
		return current->data;
	}

	bool operator==(Iterator& iter)
	{
		if (current == nullptr && iter.current == nullptr)
			return true;
		if (current == nullptr || iter.current == nullptr)
			return false;
		if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
			return true;
		return false;
	}
	bool operator!=(Iterator& iter)
	{
		if (current == nullptr && iter.current == nullptr)
			return false;
		if ((current == nullptr && iter.current != nullptr) || (current != nullptr && iter.current == nullptr))
			return true;
		if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
			return false;
		return true;
	}
};