#include "cException.h"
#include <iostream>
#include <string>
using namespace std;



//	input exceptions
int inputExceptions::inputNumber(long int min, long int max) {
	bool flag = true;
	int value;
	do
	{
		try
		{
			cin.sync();
			cin.clear();
			cin >> value;
			flag = true;
			if (!cin || cin.peek() != '\n')
			{
				flag = false;
				throw inputExceptions(1);
			}
			if (value<min || value>max)
			{
				flag = false;
				throw inputExceptions(3);
			}
		}
		catch (inputExceptions err)
		{
			rewind(stdin);
			err.ErrorText();
			if (err.errorCode == 3) {
				cout << "Ошибка ввода. Введите числа из заданного диапазона " << min << "," << max << ")." << endl;
			}
			rewind(stdin);
		}
		catch (...) {
			cout << endl << "Непредвиденная ошибка!" << endl;
			rewind(stdin);
		}
	} while (!flag);
	return value;
}

void inputExceptions::ErrorText()
{
	cout << "Ошибка ввода (код ошибки " << this->errorCode << "): ";
	switch (this->errorCode)
	{
	case 1:
	{
		cout << "Неправильный набор символов." << endl
		<< "Ожидается ввод только цифр." << endl;
		break;
	}
	case 2:
	{
		cout << "Превышена ожидаемая длина строки." << endl
		<< "Вы можете ввести только до 1000 символов" << endl;
		break;
	}
	case 3:
	{
		cout << "Число не входит в заданный диапазон" << endl;
		break;
	}
	case 4:
	{
		cout << "You have entered the wrong character set! Only letter input is available" << endl;
		break;
	}
	case 5: {
		cout << "Вы ввели неправильный набор символов. Пожалуйста, повторите попытку." << endl;
		break;
	}
	case 6:
	{
		cout << "Неправильный ввод даты." << endl
			<< "Дата должна быть в виде ДД.ММ.ГГГГ" << endl;
		break;
	}
	default:
		cout << "Повторите ввод." << endl;
		break;
	}
}

string inputExceptions::inputString() {
	string st;
	int len = 0;
	bool flag = true;
	while (flag) {
		try {
			rewind(stdin);
			getline(cin, st);
			len = st.length();
			if (len == 0) {
				throw inputExceptions(5);
			}
			for (int i = 0; i < len; i++) {
				if ((st[i] < 'a' || st[i]>'z') && (st[i] < 'A' || st[i]>'Z') && (st[i] > '1' || st[i] < '9')) {
					throw inputExceptions(4);
				}
			}
			if (len >= 1000) {
				throw inputExceptions(2);
			}
			flag = false;
		}
		catch (inputExceptions err) {
			rewind(stdin);
			err.ErrorText();
			rewind(stdin);
		}
		catch (...) {
			cout << endl << "Непредвиденная ошибка!" << endl;
			rewind(stdin);
		}
	}
	return st;
}

string inputExceptions::inputDate() {
	string st;
	int i = 0, len = 0;
	bool flag = true;
	while (flag) {
		try {
			rewind(stdin);
			getline(cin, st);
			len = st.length();
			if (len == 0) {
				throw inputExceptions(5);
			}
			if (len != 10) {
				throw inputExceptions(5);
			}
			if (((st[0] > '3' || st[0] < '0') || (st[0] == '3' && st[1] > '1')) || (st[1] > '9'
				|| st[1] < '0') || (st[1] > '9' || st[1] < '0') || (st[0] == '3' && st[1] > '1') || (st[2] != '.')
				|| (st[3] > '1' || st[3] < '0') || (st[3] == '1' && st[4] > '2') || (st[4] > '9' || st[4] < '0')
				|| (st[5] != '.') || (st[6] < '0' || st[6]>'2' || st[7] != '0' || st[8] < '0')
				|| (st[8] > '1' || st[9] < '0' || st[9]>'9')) {
				throw inputExceptions(6);
			}
			flag = false;
		}
		catch (inputExceptions err) {
			rewind(stdin);
			err.ErrorText();
			rewind(stdin);
		}
		catch (...) {
			cout << endl << "Непредвиденная ошибка!" << endl;
			rewind(stdin);
		}
	}
	return st;
}



//	list exceptions

void listExceptions::ErrorText() {
	switch (this->errorCode)
	{
	case 1:
		cout << "Ошибка! Список пуст." << endl;
		break;
	}
}