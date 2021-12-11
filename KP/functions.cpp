#include"main.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include"functions.h"
using namespace std;
OBJ*obj;
void SwapObj(OBJ *obj) {
	swap(obj->stud.person.surname, obj->next->stud.person.surname);
	swap(obj->stud.person.name, obj->next->stud.person.name);
	swap(obj->stud.person.patronymic, obj->next->stud.person.patronymic);
	swap(obj->stud.data.day, obj->next->stud.data.day);
	swap(obj->stud.data.month, obj->next->stud.data.month);
	swap(obj->stud.data.year, obj->next->stud.data.year);
	swap(obj->stud.grades.subject1, obj->next->stud.grades.subject1);
	swap(obj->stud.grades.subject2, obj->next->stud.grades.subject2);
	swap(obj->stud.grades.subject3, obj->next->stud.grades.subject3);
	swap(obj->stud.grades.sum, obj->next->stud.grades.sum);
	swap(obj->stud.grades.code, obj->next->stud.grades.code);
}
//������������� ����
void InitNode() {
	obj = new OBJ;
	if (head == NULL)//���� ������ ������
	{
		obj->prev = NULL;//���������� ������� 0
		obj->next = NULL;//��������� ������� 0
		head = obj;//������ ���������� obj
		tail = obj;//��������� ���������� obj
	}
	//���� ������ �� ������(������� �������� � �����)
	else
	{
		obj->prev = tail;//����� obj ������ ���������
		obj->next = NULL;//��������� �� obj ����
		tail->next = obj;//��������� �� ��������� obj
		tail = obj;//��������� ���������� obj
	}
}
void InitObj() {
	ifstream reading("Input.txt");//��������� ������
	if (reading) {
		reading >> quantity;//��������� ���������� ������
		int count = 0;
		for (int i = 0; i < quantity; i++) {
			count++;//����� ���������
			InitNode();
			reading >> count;
			reading >> obj->stud.person.surname;
			reading >> obj->stud.person.name;
			reading >> obj->stud.person.patronymic;
			reading >> obj->stud.data.day;
			reading >> obj->stud.data.month;
			reading >> obj->stud.data.year;
			reading >> obj->stud.grades.subject1;
			reading >> obj->stud.grades.subject2;
			reading >> obj->stud.grades.subject3;
			reading >> obj->stud.grades.sum;
			reading >> obj->stud.grades.code;
		}
	}
	else
		cout << "������ �������� �����!" << endl;
	reading.close();
}
void AddObj()
{
	cout << "������� ���������� ������, ������� ������ ������: " << endl;
	int n;
	cin >> n;
	quantity = quantity + n;

	for (int i = 0; i < n; i++)
	{
		InitNode();
		system("cls");
		cout << "������� �������, ��� � �������� ���������: " << endl;
		cin >> obj->stud.person.surname
			>> obj->stud.person.name
			>> obj->stud.person.patronymic;
		system("cls");
		cout << "������� ���� ��������: " << endl;
		cin >> obj->stud.data.day
			>> obj->stud.data.month
			>> obj->stud.data.year;
		if ((obj->stud.data.day > 31) ||
			(obj->stud.data.month > 12) ||
			(obj->stud.data.year < 1900) ||
			(obj->stud.data.year > 2021))
		{
			cout << "���� ������� �����������. ���������� ��� ���..." << endl;
			cin >> obj->stud.data.day
				>> obj->stud.data.month
				>> obj->stud.data.year;
		}
		cout << "������� ������ : " << endl
			<< "������ �������: " << endl;
		cin >> obj->stud.grades.subject1;
		while (obj->stud.grades.subject1 > 10) {
			cout << "������ �� ������� �������� ������� �������. ���������� ��� ���... " << endl;
			cin >> obj->stud.grades.subject1;
		}
		cout << "������ �������: " << endl;
		cin >> obj->stud.grades.subject2;
		while (obj->stud.grades.subject2 > 10) {
			cout << "������ �� ������� �������� ������� �������. ���������� ��� ���... " << endl;
			cin >> obj->stud.grades.subject2;
		}
		cout << "������ �������: " << endl;
		cin >> obj->stud.grades.subject3;
		while (obj->stud.grades.subject3 > 10) {
			cout << "������ �� �������� �������� ������� �������. ���������� ��� ���... " << endl;
			cin >> obj->stud.grades.subject3;
		}
		obj->stud.grades.sum = obj->stud.grades.subject1 + obj->stud.grades.subject2 + obj->stud.grades.subject3;
		cout << "�������� ���� �������������: " << endl
			<< "�1- �������  �1 " << endl
			<< "�2- �������  �2 " << endl
			<< "�3- �������  �3 " << endl;
		cin >> obj->stud.grades.code;
		if (strcmp(obj->stud.grades.code, "�1") == 0) SavingCurrent();
		if (strcmp(obj->stud.grades.code, "�2") == 0) SavingCurrent();
		if (strcmp(obj->stud.grades.code, "�3") == 0) SavingCurrent();
		else {
			cout << " ������ ������� �� �����. ���������� ��� ���... ";
			cin >> obj->stud.grades.code;
		}
	}
}
void PTable() {
	//������������ ��������
	cout << "+------------------------------------------------------------------------------+" << endl;
	cout << setw(3) << setfill(' ') << "�";
	cout << left << setw(20) << setfill(' ') << "  ��� �����������";
	cout << left << setw(20) << setfill(' ') << " ���� ��������";
	cout << left << setw(20) << setfill(' ') << "  ������";
	cout << left << setw(3) << setfill(' ') << "  ����";
	cout << left << setw(3) << setfill(' ') << "  ���� " << endl;
	cout << "+------------------------------------------------------------------------------+" << endl;
}
void Print() {
	obj = head;
	int count = 0;
	PTable();
	while (obj != NULL) {
		count++;
		cout << endl;
		//���
		cout << right << setw(3) << setfill(' ') << count << " ";
		//���
		cout << left << setw(20) << setfill(' ') << obj->stud.person.surname << endl
			<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.name << endl
			<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.patronymic;
		//����
		cout << right << setw(2) << setfill('0') << obj->stud.data.day << "."
			<< setw(2) << obj->stud.data.month << "."
			<< setw(4) << obj->stud.data.year << "\t";
		//������
		cout << setw(2) << setfill(' ') << obj->stud.grades.subject1 << "\t"
			<< setw(2) << setfill(' ') << obj->stud.grades.subject2 << "\t"
			<< setw(2) << setfill(' ') << obj->stud.grades.subject3 << "\t";
		cout << setw(2) << setfill(' ') << obj->stud.grades.sum << "\t";
		cout << setw(2) << setfill(' ') << obj->stud.grades.code << endl;
		cout << "+-----------------------------------------------------------------------------+" << endl;
		obj = obj->next;
	}
}
void ReadingObj() {
	cout << "������� �������� �����: ";
	string filename;
	cin >> filename;
	ifstream reading(filename);//������� ����� ��� ������ �� �����
	int temp = 0;//���������� ������ � �����
	if (reading) {
		reading >> temp;//��������� ���������� ������
		int count = 0;
		for (int i = 0; i < temp; i++) {
			InitNode();
			reading >> count;
			reading >> obj->stud.person.surname;
			reading >> obj->stud.person.name;
			reading >> obj->stud.person.patronymic;
			reading >> obj->stud.data.day;
			reading >> obj->stud.data.month;
			reading >> obj->stud.data.year;
			reading >> obj->stud.grades.subject1;
			reading >> obj->stud.grades.subject2;
			reading >> obj->stud.grades.subject3;
			reading >> obj->stud.grades.sum;
			reading >> obj->stud.grades.code;
			SavingCurrent();
		}
		system("cls");
		cout << "������ �������!" << endl;
		quantity = quantity + temp;
	}
	else
		cout << "������ �������� �����!" << endl;
	reading.close();
}
void ChangeObj() {
	int n;
	cout << "������� ����� ��������: " << endl;
	cin >> n;
	system("cls");
	//�������� ������������ �����
	if (n > 0 && n <= quantity) {
		obj = head;
		int count = 1;
		while (obj != NULL) {
			if (count == n) {
				cout << " ���������� �������: " << endl;
				cout << " " << obj->stud.person.surname << " "
					<< obj->stud.person.name << " "
					<< obj->stud.person.patronymic << endl;
				cout << " ���� ��������: " << obj->stud.data.day << "."
					<< obj->stud.data.month << "."
					<< obj->stud.data.year << endl;
				cout << " ������ �� ���������: " << obj->stud.grades.subject1 << " , "
					<< obj->stud.grades.subject2 << " , "
					<< obj->stud.grades.subject3 << endl;
				cout << " ��� �������������: " << obj->stud.grades.code << endl << endl;
				cout << "������� �������, ��� � �������� ���������: " << endl;
				cin >> obj->stud.person.surname
					>> obj->stud.person.name
					>> obj->stud.person.patronymic;
				cout << "������� ���� ��������: " << endl;
				cin >> obj->stud.data.day
					>> obj->stud.data.month
					>> obj->stud.data.year;
				if ((obj->stud.data.day > 31) ||
					(obj->stud.data.month > 12) ||
					(obj->stud.data.year < 1900) ||
					(obj->stud.data.year > 2021))
				{
					cout << "���� ������� �����������. ���������� ��� ���..." << endl;
					cin >> obj->stud.data.day
						>> obj->stud.data.month
						>> obj->stud.data.year;
				}
				cout << "������� ������ : " << endl
					<< "������ �������: " << endl;
				cin >> obj->stud.grades.subject1;
				while (obj->stud.grades.subject1 > 10) {
					cout << "������ �� ������� �������� ������� �������. ���������� ��� ���... " << endl;
					cin >> obj->stud.grades.subject1;
				}
				cout << "������ �������: " << endl;
				cin >> obj->stud.grades.subject2;
				while (obj->stud.grades.subject2 > 10) {
					cout << "������ �� ������� �������� ������� �������. ���������� ��� ���... " << endl;
					cin >> obj->stud.grades.subject2;
				}
				cout << "������ �������: " << endl;
				cin >> obj->stud.grades.subject3;
				while (obj->stud.grades.subject3 > 10) {
					cout << "������ �� �������� �������� ������� �������. ���������� ��� ���... " << endl;
					cin >> obj->stud.grades.subject3;
				}
				obj->stud.grades.sum = obj->stud.grades.subject1 + obj->stud.grades.subject2 + obj->stud.grades.subject3;
				cout << "�������� ���� �������������: " << endl
					<< "�1- �������  �1 " << endl
					<< "�2- �������  �2 " << endl
					<< "�3- �������  �3 " << endl;
				cin >> obj->stud.grades.code;
				if (strcmp(obj->stud.grades.code, "�1") == 0) SavingCurrent();
				if (strcmp(obj->stud.grades.code, "�2") == 0) SavingCurrent();
				if (strcmp(obj->stud.grades.code, "�3") == 0) SavingCurrent();
				else {
					cout << " ������ ������� �� �����. ���������� ��� ���... ";
					cin >> obj->stud.grades.code;
				}
				system("cls");
				cout << "������ ��������!" << endl;
			}
			obj = obj->next;
			count++;
		}
	}
	else {
		cout << "����� ������ �� �����! ���������� ��� ���..." << endl;
		cin >> n;
	}
}
void DelObj()
{
	// ���� �������� ����������� ��� ����� 0, �� ����������� ���:
	int n;
	cout << "������� ����� ��������, ������� ������ �������: " << endl;
	cin >> n;
	system("cls");
	//���������, ��� ��������� ����� ����������
	if (n > 0 && n <= quantity) {
		OBJ *Del = head;
		for (int i = 1; i < n; i++)
		{   // ������� �� ��������, ������� ���������:
			Del = Del->next;
		}
		// ������� �� ��������,
		// ������� ������������ ����������:
		OBJ *PrevDel = Del->prev;
		// ������� �� ��������, ������� ������� �� ���������:
		OBJ *AfterDel = Del->next;
		// ���� ������� �� ������:
		if (PrevDel != 0 && quantity != 1)
			PrevDel->next = AfterDel;
		// ���� ������� �� �����:
		if (AfterDel != 0 && quantity != 1)
			AfterDel->prev = PrevDel;
		// ��������� �������?
		if (n == 1)
			head = AfterDel;
		if (n == quantity)
			tail = PrevDel;
		delete Del;
		quantity--;
		SavingCurrent();
		cout << "������ �������!" << endl;
	}
	else {
		cout << "����� ������ �� �����. ���������� ��� ���..." << endl;
		return DelObj();
	}
}
void SavingObj()
{
	string filename;
	cout << "������� �������� �����:";
	cin >> filename;
	OBJ*c;
	c = head;
	ofstream record(filename, ios::out);
	if (record) {
		record << quantity << endl;
		int n = 1;//�������
		while (c != NULL) {
			record << n << " ";
			record << c->stud.person.surname << " ";
			record << c->stud.person.name << " ";
			record << c->stud.person.patronymic << endl;
			record << "  " << c->stud.data.day << " ";
			record << c->stud.data.month << " ";
			record << c->stud.data.year << endl;
			record << "  " << c->stud.grades.subject1 << " ";
			record << c->stud.grades.subject2 << " ";
			record << c->stud.grades.subject3 << endl;
			record << " " << c->stud.grades.sum << endl;
			record << "  " << c->stud.grades.code << endl;
			c = c->next;
			n++;
		}
		cout << "������ ���������!" << endl;
	}
	else
		cout << "������ �������� �����!" << endl;
	record.close();
	delete[]c;
}
void SavingCurrent()
{
	string filename;
	OBJ*c;
	c = head;
	ofstream record("Input.txt", ios::out);
	if (record) {
		record << quantity << endl;
		int n = 1;//�������
		while (c != NULL) {
			record << n << " ";
			record << c->stud.person.surname << " ";
			record << c->stud.person.name << " ";
			record << c->stud.person.patronymic << endl;
			record << "  " << c->stud.data.day << " ";
			record << c->stud.data.month << " ";
			record << c->stud.data.year << endl;
			record << "  " << c->stud.grades.subject1 << " ";
			record << c->stud.grades.subject2 << " ";
			record << c->stud.grades.subject3 << endl;
			record << " " << c->stud.grades.sum << endl;
			record << "  " << c->stud.grades.code << endl;
			c = c->next;
			n++;
		}
	}
	else
		cout << "������ �������� �����!" << endl;
	record.close();
	delete[]c;
}
void Sorting_sv() {

	for (int i = 0; i < quantity - 1; i++) {
		obj = head;
		for (int j = i; j < quantity - 1; j++) {
			if (obj->stud.grades.sum > obj->next->stud.grades.sum) {
				SwapObj(obj);
			}
			obj = obj->next;
		}
	}
}
void Sorting_su() {
	for (int i = 0; i < quantity - 1; i++) {
		obj = head;
		for (int j = i; j < quantity - 1; j++) {
			if (obj->stud.grades.sum < obj->next->stud.grades.sum) {
				SwapObj(obj);
			}
			obj = obj->next;
		}
	}
}
void Sorting_dv() {
	for (int i = 0; i < quantity - 1; i++) {
		obj = head;
		for (int j = i; j < quantity - 1; j++) {
			while (obj->next != NULL) {
				//���������� �� ����
				if (obj->stud.data.year > obj->next->stud.data.year) {
					SwapObj(obj);
				}
				//���� ��� ����������, �� ���������� �� ������
				if (obj->stud.data.year == obj->next->stud.data.year) {
					if (obj->stud.data.month > obj->next->stud.data.month) {
						SwapObj(obj);
					}
				}
				if (obj->stud.data.year == obj->next->stud.data.year) {
					if (obj->stud.data.month == obj->next->stud.data.month) {
						if (obj->stud.data.day > obj->next->stud.data.day) {
							SwapObj(obj);
						}
					}
				}
				obj = obj->next;
			}
		}
	}
}
void Sorting_du() {
	for (int i = 0; i < quantity - 1; i++) {
		obj = head;
		for (int j = i; j < quantity - 1; j++) {
			while (obj->next != NULL) {
				//���������� �� ����
				if (obj->stud.data.year < obj->next->stud.data.year) {
					SwapObj(obj);
				}
				//���� ��� ����������, �� ���������� �� ������
				if (obj->stud.data.year == obj->next->stud.data.year) {
					if (obj->stud.data.month < obj->next->stud.data.month) {
						SwapObj(obj);
					}
				}
				if (obj->stud.data.year == obj->next->stud.data.year) {
					if (obj->stud.data.month == obj->next->stud.data.month) {
						if (obj->stud.data.day < obj->next->stud.data.day) {
							SwapObj(obj);
						}
					}
				}
				obj = obj->next;
			}
		}
	}
}
void Sorting_abc_U() {
	for (int i = 0; i < quantity - 1; i++) {
		obj = head;
		for (int j = i; j < quantity - 1; j++) {
			if (strcmp(obj->next->stud.person.surname, obj->stud.person.surname) > 0) {
				SwapObj(obj);
			}
			if (obj->stud.person.surname == obj->next->stud.person.surname) {
				if (strcmp(obj->stud.person.name, obj->next->stud.person.name) > 0) {
					SwapObj(obj);
				}
			}
			if (obj->stud.person.name == obj->next->stud.person.name) {
				if (strcmp(obj->stud.person.patronymic, obj->next->stud.person.patronymic) > 0) {
					SwapObj(obj);
				}
			}
			obj = obj->next;
		}
	}
}
void Sorting_abc_V() {
	for (int i = 0; i < quantity - 1; i++) {
		obj = head;
		for (int j = i; j < quantity - 1; j++) {
			if (strcmp(obj->stud.person.surname, obj->next->stud.person.surname) > 0) {
				SwapObj(obj);
			}
			if (obj->stud.person.surname == obj->next->stud.person.surname) {
				if (strcmp(obj->stud.person.name, obj->next->stud.person.name) > 0) {
					SwapObj(obj);
				}
			}
			if (obj->stud.person.name == obj->next->stud.person.name) {
				if (strcmp(obj->stud.person.patronymic, obj->next->stud.person.patronymic) > 0) {
					SwapObj(obj);
				}
			}
			obj = obj->next;
		}
	}
}
void Filter(int n) {
	Sorting_su();
	obj = head;
	int count = 0;
	string cod;
	if (n == 1) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << "  ������������� '�1' " << "\t ���� ������ : " << f1 << " �������" << endl;
		cod = "�1";
	}
	if (n == 2) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << "  ������������� '�2' " << "\t ���� ������ : " << f2 << " �������" << endl;
		cod = "�2";
	}
	if (n == 3) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << "  ������������� '�3' " << "\t ���� ������ : " << f3 << " �������" << endl;
		cod = "�3";
	}
	while (obj != NULL) {

		if (obj->stud.grades.code == cod) {
			count++;
			if (count == 1) {
				//������������ ��������
				cout << "+------------------------------------------------------------------------------+" << endl;
				cout << setw(3) << setfill(' ') << "�";
				cout << left << setw(20) << setfill(' ') << "  ��� �����������";
				cout << left << setw(20) << setfill(' ') << " ���� ��������";
				cout << left << setw(20) << setfill(' ') << "  ������";
				cout << left << setw(3) << setfill(' ')  << "  ����";
				cout << left << setw(3) << setfill(' ') << "  ���� " << endl;
				cout << "+------------------------------------------------------------------------------+" << endl;
			}
			if (count > 0) {
				count++;
				cout << endl;
				//���
				cout << right << setw(3) << setfill(' ') << count << " ";
				//���
				cout << left << setw(20) << setfill(' ') << obj->stud.person.surname << endl
					<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.name << endl
					<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.patronymic;
				//����
				cout << right << setw(2) << setfill('0') << obj->stud.data.day << "."
					<< setw(2) << obj->stud.data.month << "."
					<< setw(4) << obj->stud.data.year << "\t";
				//������
				cout << setw(2) << setfill(' ') << obj->stud.grades.subject1 << "\t"
					<< setw(2) << setfill(' ') << obj->stud.grades.subject2 << "\t"
					<< setw(2) << setfill(' ') << obj->stud.grades.subject3 << "\t";
				cout << setw(2) << setfill(' ') << obj->stud.grades.sum << "\t";
				cout << setw(2) << setfill(' ') << obj->stud.grades.code << endl;
				cout << "+-----------------------------------------------------------------------------+" << endl;
			}
		}
		obj = obj->next;
	}
}
void FilterSt1(int _n, int plan) {//int plan- ���� ������,  int _n- ����� ���� �������������
	Sorting_su();
	obj = head;
	int count = 0;
	if (_n == 1) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << endl << " ���� ������ �� ������������� �1: " << f1 << " �������" << endl
			<< " ������  ����������� ��������� �� 1 ����: " << endl << endl;
		plan = f1;
	}
	if (_n == 2) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << endl << " ���� ������ �� ������������� �2: " << f2 << " �������" << endl
			<< " ������ ����������� ��������� �� 1 ����: " << endl << endl;
		plan = f2;
	}
	if (_n == 3) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << endl << " ���� ������ �� ������������� �3: " << f3 << " �������" << endl
			<< " ������ ����������� ��������� �� 1 ����: " << endl << endl;
		plan = f3;
	}
	if (_n == 4) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << endl << " ������ ����������� ��������� �� 1 ����: " << endl << endl;
	}
	while (obj != NULL) {
		while (count < plan) {
			count++;
			//���
			cout << right << setw(3) << setfill(' ') << count << " ";
			//���
			cout << obj->stud.person.surname << " "
				<< obj->stud.person.name << " "
				<< obj->stud.person.patronymic << endl;
			obj = obj->next;
		}
		cout << endl;
		break;
	}
}
void Searchname()
{
	obj = head;
	char n[20];
	cout << "������� ������� ";
	cin >> n;
	system("cls");
	int count = 0;
	while (obj != NULL) {
		for (int i = 0; i < quantity; i++) {
			if (strcmp(n, obj->stud.person.surname) == 0) {
				count++;
				if (count == 1) {
					cout << "+------------------------------------------------------------------------------+" << endl;
					cout << setw(3) << setfill(' ') << "�";
					cout << left << setw(20) << setfill(' ') << "  ��� �����������";
					cout << left << setw(20) << setfill(' ') << " ���� ��������";
					cout << left << setw(20) << setfill(' ') << "  ������";
					cout << left << setw(3) << setfill(' ') << "  ����";
					cout << left << setw(3) << setfill(' ') << "  ���� " << endl;
					cout << "+------------------------------------------------------------------------------+" << endl;
				}
				cout << endl;
				//���
				cout << right << setw(3) << setfill(' ') << count << " ";
				//���
				cout << left << setw(20) << setfill(' ') << obj->stud.person.surname << endl
					<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.name << endl
					<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.patronymic;

				//����
				cout << right << setw(2) << setfill('0') << obj->stud.data.day << "."
					<< setw(2) << obj->stud.data.month << "."
					<< setw(4) << obj->stud.data.year << "\t";
				//������
				cout << setw(2) << setfill(' ') << obj->stud.grades.subject1 << "\t"
					<< setw(2) << setfill(' ') << obj->stud.grades.subject2 << "\t"
					<< setw(2) << setfill(' ') << obj->stud.grades.subject3 << "\t";

				cout << setw(2) << setfill(' ') << obj->stud.grades.sum << "\t";
				cout << setw(2) << setfill(' ') << obj->stud.grades.code << endl;
				cout << "+-----------------------------------------------------------------------------+" << endl;
			}
			obj = obj->next;
		}
	}
	if (count == 0) cout << " �� ������ ������� ������ �� �������!" << endl;
}
