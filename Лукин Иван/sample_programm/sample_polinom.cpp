#include "../polinom/polinom.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

void display_menu() {
	cout << "Выберите действие:\n";
	cout << "1. Ввести и сохранить полином\n";
	cout << "2. Выбрать полином и выполнить операции\n";
	cout << "3. Выход\n";
	cout << "Ваш выбор: ";
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	vector<Polinom> polynomials;
	int choice;
	while (true) 
	{
		display_menu();
		cin >> choice;
		switch (choice) 
		{
		case 1: 
		{
			cout << "Введите полином. Eсли степень переменной 1 - она обязательно должна быть введена. Если коэффициент равен 1 или -1, его можно не вводить)\nНапример, 3x2 + 2y1 - z1: ";
			string input;
			cin.ignore();
			getline(cin, input);
			try 
			{
				Polinom newPolinom(input);
				polynomials.push_back(newPolinom);
				cout << "Полином успешно сохранен.\n";
			}
			catch (const char* error) 
			{
				cout << "Ошибка: " << error << endl;
			}
			break;
		}
		case 2: 
		{
			if (polynomials.empty()) 
			{
				cout << "Нет сохраненных полиномов. Сначала добавьте полиномы.\n";
				break;
			}
			cout << "Сохраненные полиномы:\n";
			for (size_t i = 0; i < polynomials.size(); ++i) 
			{
				cout << i + 1 << ": " << polynomials[i].to_String() << endl;
			}
			cout << "Выберите полином (номер): ";
			int index;
			cin >> index;
			if (index < 1 || index > polynomials.size()) 
			{
				cout << "Неверный номер полинома.\n";
				break;
			}
			Polinom selectedPolinom = polynomials[index - 1];
			cout << "Выберите операцию:\n";
			cout << "1. Сложение\n";
			cout << "2. Вычитание\n";
			cout << "3. Умножение на константу\n";
			cout << "Ваш выбор: ";
			int operation;
			cin >> operation;
			switch (operation)
			{
			case 1: 
			{
				cout << "Введите полином для сложения: ";
				string input;
				cin.ignore();
				getline(cin, input);
				try 
				{
					Polinom otherPolinom(input);
					Polinom result = selectedPolinom + otherPolinom;
					cout << "Результат: " << result.to_String() << endl;
				}
				catch (const char* error) 
				{
					cout << "Ошибка: " << error << endl;
				}
				break;
			}
			case 2: 
			{
				cout << "Введите полином для вычитания: ";
				string input;
				cin.ignore();
				getline(cin, input);
				try 
				{
					Polinom otherPolinom(input);
					Polinom result = selectedPolinom - otherPolinom;
					cout << "Результат: " << result.to_String() << endl;
				}
				catch (const char* error) 
				{
					cout << "Ошибка: " << error << endl;
				}
				break;
			}
			case 3: 
			{
				cout << "Введите константу для умножения: ";
				double constant;
				cin >> constant;
				Polinom result = selectedPolinom * constant;
				cout << "Результат: " << result.to_String() << endl;
				break;
			}
			default:
				cout << "Неверный выбор операции.\n";
				break;
			}
			break;
		}
		case 3:
			cout << "Выход из программы.\n";
			return 0;
		default:
			cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
			break;
		}
		Sleep(1500);
		system("cls");
	}
	return 0;
}