#pragma once
//структура ФИО
struct Person {
	char surname[20];
	char name[20];
	char patronymic[20];
};
//структура дата
struct Data {
	int day;
	int month;
	int year;
};
//структура оценок и код предмета здесь же
struct Grades {
	char code[2];
	int subject1;
	int subject2;
	int subject3;
	int sum;
};

struct Student {
	int npp;//порядковый номер
	Person person;
	Data data;
	Grades grades;
};
//узел
typedef struct tag_obj {
	Student stud;
	struct tag_obj *prev, *next;

}OBJ;
OBJ *head = nullptr, *tail = nullptr;
//количество элементов в списке
int quantity;
//план приема
int f1 = 5;
int f2 = 5;
int f3 = 5;
