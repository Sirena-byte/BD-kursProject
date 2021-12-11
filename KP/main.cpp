#include"functions.h"
#include<iostream>
#include<Windows.h>
using namespace std;
int stMenu;
void Menu()
{
	cout << endl;
	cout << "  �������� ��������: " << endl
		<< "  (0)  ����� �� ���������" << endl
		<< "  (1)  ���������� ������" << endl
		<< "  (2)  ������ ������" << endl
		<< "  (3)  ��������� ������" << endl
		<< "  (4)  �������� ������" << endl
		<< "  (5)  ������ ������" << endl
		<< "  (6)  ���������� ������" << endl
		<< "  (7)  ���������� ������ � ����" << endl
		<< "  (8)  �������� ������ �����������" << endl
		<< "  (9)  ����� �� �������" << endl
		<< endl
		<< "  ������� ��� �����: ";
	cin >> stMenu;
}
int main() {
	SetConsoleCP(1251);//����������� ������ �����
	SetConsoleOutputCP(1251);//����������� ������ ������
	extern int quantity;
	extern int f1, f2, f3;
	InitObj();
	Menu();
	while (stMenu != 0)
	{
		switch (stMenu)
		{
			int actions;
		case 1:
			system("cls");
			cout << "  ������ ������ ������ ������� ��� �� �����?" << endl
				<< "  (1) ����� �������" << endl << endl
				<< "  ��� ����� ������ �� ����� ������� ����� �����";
			cin >> actions;
			system("cls");
			if (actions == 1)AddObj();//���� �������
			else ReadingObj(); //���� �� �����
			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			if (quantity == 0)	cout << "������ ����!" << endl;
			else Print();
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			if (quantity == 0) cout << "������ ����!" << endl;
			else ChangeObj();
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			if (quantity == 0) cout << "������ ����!" << endl;
			else DelObj();
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			if (quantity == 0) cout << "������ ����!" << endl;
			else {
				cout << " (1) ������ ����������� �� ������������� �1 " << endl
					<< " (2) ������ ����������� �� ������������� �2 " << endl
					<< " (3) ������ ����������� �� ������������� �3 " << endl << endl
					<< " ������� ���� �����: ";
				int n;
				cin >> n;
				if (n == 1) { system("cls"); Filter(1); }
				if (n == 2) { system("cls"); Filter(2); }
				if (n == 3) { system("cls"); Filter(3); }
				if (n > 3 || n < 0) {
					cout << " ����������� ������ �����. ���������� ��� ���...";
					cin >> n;
				}
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			if (quantity == 0)
				cout << "������ ����!" << endl;
			else {
				int n;
				cout << "(1) ����������� ������ �� �������" << endl
					<< "(2) ����������� ������ �� ���� �������� " << endl
					<< "(3) ����������� ������ �� ����� ������ " << endl << endl;
				cout << "������� ��� �����: ";
				cin >> n;
				//�� �������
				if (n == 1) {
					system("cls");
					cout << "(1) ������������� ������ �� ����������� " << endl
						<< "����� ������������� ������ �� ��������, ������� ����� ������� ";
					int _n;
					cin >> _n;
					if (_n == 1) { Sorting_abc_V(); system("cls"); Print(); }
					else { Sorting_abc_U(); system("cls"); Print(); }
				}
				//�� ���� ��������
				if (n == 2) {
					system("cls");
					cout << " (1) ������������� ������ �� ����������� " << endl
						<< "  ����� ������������� ������ �� ��������, ������� ����� ����� ";
					int _n;
					cin >> _n;
					if (_n == 1) { Sorting_dv(); system("cls"); Print(); }
					else { Sorting_du(); system("cls"); Print(); }
				}
				//�� ������
				if (n == 3) {
					system("cls");
					cout << " (1) ������������� ������ �� ����������� " << endl
						<< "  ����� ������������� ������ �� ��������," <<
						endl << " ������� ����� ������� ";
					int _n;
					cin >> _n;
					if (_n == 1) { Sorting_sv(); system("cls"); Print(); }
					else { Sorting_su(); system("cls"); Print(); }
				}
				if (n < 1 || n>3) {
					system("cls");
					cout << "������� ������ ����� ��������! ���������� ��� ���" << endl;
					cin >> n;
				}
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");
			if (quantity == 0) cout << "������ ����!" << endl;
			else
				SavingObj();
			system("pause");
			system("cls");
			Menu();
			break;
		case 8:
			system("cls");
			if (quantity == 0) cout << " ������ ����!" << endl;
			else
			{
				cout << endl;
				cout << " �������� ����������: " << endl;
				cout << " (1) ������ ����������� ��������� �� ������������� �1" << endl;
				cout << " (2) ������ ����������� ��������� �� ������������� �2" << endl;
				cout << " (3) ������ ����������� ��������� �� ������������� �3" << endl;
				cout << " (4) ����� ������ ����������� ��������� " << endl << endl;
				cout << " ������� ��� �����: ";
				int _n;
				cin >> _n;
				system("cls");
				if (_n == 1) { FilterSt1(1, f1); }
				if (_n == 2) { FilterSt1(2, f2); }
				if (_n == 3) { FilterSt1(3, f3); }
				if (_n == 4) { int pl; pl = f1 + f2 + f3; FilterSt1(4, pl); }
				if (_n < 1 || _n>4)cout << "����������� ������ �����!";
				//Filter4(_n);
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 9:
			system("cls");
			Searchname();
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			system("cls");
			cout << "������� ������ ����� ��������!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
	return 0;
}

