#pragma once
//��������� ���
struct Person {
	char surname[20];
	char name[20];
	char patronymic[20];
};
//��������� ����
struct Data {
	int day;
	int month;
	int year;
};
//��������� ������ � ��� �������� ����� ��
struct Grades {
	char code[2];
	int subject1;
	int subject2;
	int subject3;
	int sum;
};

struct Student {
	int npp;//���������� �����
	Person person;
	Data data;
	Grades grades;
};
//����
typedef struct tag_obj {
	Student stud;
	struct tag_obj *prev, *next;

}OBJ;
OBJ *head = nullptr, *tail = nullptr;
//���������� ��������� � ������
int quantity;
//���� ������
int f1 = 5;
int f2 = 5;
int f3 = 5;
