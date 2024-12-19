#include "../polinom/polinom.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

void display_menu() {
	cout << "�������� ��������:\n";
	cout << "1. ������ � ��������� �������\n";
	cout << "2. ������� ������� � ��������� ��������\n";
	cout << "3. �����\n";
	cout << "��� �����: ";
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
			cout << "������� �������. E��� ������� ���������� 1 - ��� ����������� ������ ���� �������. ���� ����������� ����� 1 ��� -1, ��� ����� �� �������)\n��������, 3x2 + 2y1 - z1: ";
			string input;
			cin.ignore();
			getline(cin, input);
			try 
			{
				Polinom newPolinom(input);
				polynomials.push_back(newPolinom);
				cout << "������� ������� ��������.\n";
			}
			catch (const char* error) 
			{
				cout << "������: " << error << endl;
			}
			break;
		}
		case 2: 
		{
			if (polynomials.empty()) 
			{
				cout << "��� ����������� ���������. ������� �������� ��������.\n";
				break;
			}
			cout << "����������� ��������:\n";
			for (size_t i = 0; i < polynomials.size(); ++i) 
			{
				cout << i + 1 << ": " << polynomials[i].to_String() << endl;
			}
			cout << "�������� ������� (�����): ";
			int index;
			cin >> index;
			if (index < 1 || index > polynomials.size()) 
			{
				cout << "�������� ����� ��������.\n";
				break;
			}
			Polinom selectedPolinom = polynomials[index - 1];
			cout << "�������� ��������:\n";
			cout << "1. ��������\n";
			cout << "2. ���������\n";
			cout << "3. ��������� �� ���������\n";
			cout << "��� �����: ";
			int operation;
			cin >> operation;
			switch (operation)
			{
			case 1: 
			{
				cout << "������� ������� ��� ��������: ";
				string input;
				cin.ignore();
				getline(cin, input);
				try 
				{
					Polinom otherPolinom(input);
					Polinom result = selectedPolinom + otherPolinom;
					cout << "���������: " << result.to_String() << endl;
				}
				catch (const char* error) 
				{
					cout << "������: " << error << endl;
				}
				break;
			}
			case 2: 
			{
				cout << "������� ������� ��� ���������: ";
				string input;
				cin.ignore();
				getline(cin, input);
				try 
				{
					Polinom otherPolinom(input);
					Polinom result = selectedPolinom - otherPolinom;
					cout << "���������: " << result.to_String() << endl;
				}
				catch (const char* error) 
				{
					cout << "������: " << error << endl;
				}
				break;
			}
			case 3: 
			{
				cout << "������� ��������� ��� ���������: ";
				double constant;
				cin >> constant;
				Polinom result = selectedPolinom * constant;
				cout << "���������: " << result.to_String() << endl;
				break;
			}
			default:
				cout << "�������� ����� ��������.\n";
				break;
			}
			break;
		}
		case 3:
			cout << "����� �� ���������.\n";
			return 0;
		default:
			cout << "�������� �����. ����������, ���������� �����.\n";
			break;
		}
		Sleep(1500);
		system("cls");
	}
	return 0;
}