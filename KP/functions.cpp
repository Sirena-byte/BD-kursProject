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
//инициализация узла
void InitNode() {
	obj = new OBJ;
	if (head == NULL)//если список пустой
	{
		obj->prev = NULL;//предыдущий элемент 0
		obj->next = NULL;//следующий элемент 0
		head = obj;//первым становится obj
		tail = obj;//последним становится obj
	}
	//если список не пустой(вставка элемента в конец)
	else
	{
		obj->prev = tail;//перед obj бывший последний
		obj->next = NULL;//следующий за obj нуль
		tail->next = obj;//следующий за последним obj
		tail = obj;//последним становится obj
	}
}
void InitObj() {
	ifstream reading("Input.txt");//считываем данные
	if (reading) {
		reading >> quantity;//считываем количество данных
		int count = 0;
		for (int i = 0; i < quantity; i++) {
			count++;//номер попорядку
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
		cout << "Ошибка открытия файла!" << endl;
	reading.close();
}
void AddObj()
{
	cout << "Введите количество данных, которые хотите ввести: " << endl;
	int n;
	cin >> n;
	quantity = quantity + n;

	for (int i = 0; i < n; i++)
	{
		InitNode();
		system("cls");
		cout << "Введите фамилию, имя и отчество полностью: " << endl;
		cin >> obj->stud.person.surname
			>> obj->stud.person.name
			>> obj->stud.person.patronymic;
		system("cls");
		cout << "Введите дату рождения: " << endl;
		cin >> obj->stud.data.day
			>> obj->stud.data.month
			>> obj->stud.data.year;
		if ((obj->stud.data.day > 31) ||
			(obj->stud.data.month > 12) ||
			(obj->stud.data.year < 1900) ||
			(obj->stud.data.year > 2021))
		{
			cout << "Дата введена некорректно. Попробуйте еще раз..." << endl;
			cin >> obj->stud.data.day
				>> obj->stud.data.month
				>> obj->stud.data.year;
		}
		cout << "Введите оценки : " << endl
			<< "Первый предмет: " << endl;
		cin >> obj->stud.grades.subject1;
		while (obj->stud.grades.subject1 > 10) {
			cout << "Данные по первому предмету введены неверно. Попробуйте еще раз... " << endl;
			cin >> obj->stud.grades.subject1;
		}
		cout << "Второй предмет: " << endl;
		cin >> obj->stud.grades.subject2;
		while (obj->stud.grades.subject2 > 10) {
			cout << "Данные по второму предмету введены неверно. Попробуйте еще раз... " << endl;
			cin >> obj->stud.grades.subject2;
		}
		cout << "Третий предмет: " << endl;
		cin >> obj->stud.grades.subject3;
		while (obj->stud.grades.subject3 > 10) {
			cout << "Данные по третьему предмету введены неверно. Попробуйте еще раз... " << endl;
			cin >> obj->stud.grades.subject3;
		}
		obj->stud.grades.sum = obj->stud.grades.subject1 + obj->stud.grades.subject2 + obj->stud.grades.subject3;
		cout << "Выберите шифр специальности: " << endl
			<< "ф1- введите  ф1 " << endl
			<< "ф2- введите  ф2 " << endl
			<< "ф3- введите  ф3 " << endl;
		cin >> obj->stud.grades.code;
		if (strcmp(obj->stud.grades.code, "ф1") == 0) SavingCurrent();
		if (strcmp(obj->stud.grades.code, "ф2") == 0) SavingCurrent();
		if (strcmp(obj->stud.grades.code, "ф3") == 0) SavingCurrent();
		else {
			cout << " Данные введены не верно. Попробуйте еще раз... ";
			cin >> obj->stud.grades.code;
		}
	}
}
void PTable() {
	//формирование столбцов
	cout << "+------------------------------------------------------------------------------+" << endl;
	cout << setw(3) << setfill(' ') << "№";
	cout << left << setw(20) << setfill(' ') << "  ФИО абитуриента";
	cout << left << setw(20) << setfill(' ') << " дата рождения";
	cout << left << setw(20) << setfill(' ') << "  оценки";
	cout << left << setw(3) << setfill(' ') << "  балл";
	cout << left << setw(3) << setfill(' ') << "  шифр " << endl;
	cout << "+------------------------------------------------------------------------------+" << endl;
}
void Print() {
	obj = head;
	int count = 0;
	PTable();
	while (obj != NULL) {
		count++;
		cout << endl;
		//№пп
		cout << right << setw(3) << setfill(' ') << count << " ";
		//фио
		cout << left << setw(20) << setfill(' ') << obj->stud.person.surname << endl
			<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.name << endl
			<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.patronymic;
		//дата
		cout << right << setw(2) << setfill('0') << obj->stud.data.day << "."
			<< setw(2) << obj->stud.data.month << "."
			<< setw(4) << obj->stud.data.year << "\t";
		//оценки
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
	cout << "Введите название файла: ";
	string filename;
	cin >> filename;
	ifstream reading(filename);//создаем поток для чтения из файла
	int temp = 0;//количество данных в файле
	if (reading) {
		reading >> temp;//считываем количество данных
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
		cout << "Данные считаны!" << endl;
		quantity = quantity + temp;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	reading.close();
}
void ChangeObj() {
	int n;
	cout << "Введите номер элемента: " << endl;
	cin >> n;
	system("cls");
	//проверка корректности ввода
	if (n > 0 && n <= quantity) {
		obj = head;
		int count = 1;
		while (obj != NULL) {
			if (count == n) {
				cout << " Изменяемый элемент: " << endl;
				cout << " " << obj->stud.person.surname << " "
					<< obj->stud.person.name << " "
					<< obj->stud.person.patronymic << endl;
				cout << " дата рождения: " << obj->stud.data.day << "."
					<< obj->stud.data.month << "."
					<< obj->stud.data.year << endl;
				cout << " оценки по предметам: " << obj->stud.grades.subject1 << " , "
					<< obj->stud.grades.subject2 << " , "
					<< obj->stud.grades.subject3 << endl;
				cout << " код специальности: " << obj->stud.grades.code << endl << endl;
				cout << "Введите фамилию, имя и отчество полностью: " << endl;
				cin >> obj->stud.person.surname
					>> obj->stud.person.name
					>> obj->stud.person.patronymic;
				cout << "Введите дату рождения: " << endl;
				cin >> obj->stud.data.day
					>> obj->stud.data.month
					>> obj->stud.data.year;
				if ((obj->stud.data.day > 31) ||
					(obj->stud.data.month > 12) ||
					(obj->stud.data.year < 1900) ||
					(obj->stud.data.year > 2021))
				{
					cout << "Дата введена некорректно. Попробуйте еще раз..." << endl;
					cin >> obj->stud.data.day
						>> obj->stud.data.month
						>> obj->stud.data.year;
				}
				cout << "Введите оценки : " << endl
					<< "Первый предмет: " << endl;
				cin >> obj->stud.grades.subject1;
				while (obj->stud.grades.subject1 > 10) {
					cout << "Данные по первому предмету введены неверно. Попробуйте еще раз... " << endl;
					cin >> obj->stud.grades.subject1;
				}
				cout << "Второй предмет: " << endl;
				cin >> obj->stud.grades.subject2;
				while (obj->stud.grades.subject2 > 10) {
					cout << "Данные по второму предмету введены неверно. Попробуйте еще раз... " << endl;
					cin >> obj->stud.grades.subject2;
				}
				cout << "Третий предмет: " << endl;
				cin >> obj->stud.grades.subject3;
				while (obj->stud.grades.subject3 > 10) {
					cout << "Данные по третьему предмету введены неверно. Попробуйте еще раз... " << endl;
					cin >> obj->stud.grades.subject3;
				}
				obj->stud.grades.sum = obj->stud.grades.subject1 + obj->stud.grades.subject2 + obj->stud.grades.subject3;
				cout << "Выберите шифр специальности: " << endl
					<< "ф1- введите  ф1 " << endl
					<< "ф2- введите  ф2 " << endl
					<< "ф3- введите  ф3 " << endl;
				cin >> obj->stud.grades.code;
				if (strcmp(obj->stud.grades.code, "ф1") == 0) SavingCurrent();
				if (strcmp(obj->stud.grades.code, "ф2") == 0) SavingCurrent();
				if (strcmp(obj->stud.grades.code, "ф3") == 0) SavingCurrent();
				else {
					cout << " Данные введены не верно. Попробуйте еще раз... ";
					cin >> obj->stud.grades.code;
				}
				system("cls");
				cout << "Данные изменены!" << endl;
			}
			obj = obj->next;
			count++;
		}
	}
	else {
		cout << "Номер введен не верно! Попробуйте еще раз..." << endl;
		cin >> n;
	}
}
void DelObj()
{
	// Если параметр отсутствует или равен 0, то запрашиваем его:
	int n;
	cout << "Введите номер элемента, который хотите удалить: " << endl;
	cin >> n;
	system("cls");
	//проверяем, что введенный номер корректный
	if (n > 0 && n <= quantity) {
		OBJ *Del = head;
		for (int i = 1; i < n; i++)
		{   // Доходим до элемента, который удаляется:
			Del = Del->next;
		}
		// Доходим до элемента,
		// который предшествует удаляемому:
		OBJ *PrevDel = Del->prev;
		// Доходим до элемента, который следует за удаляемым:
		OBJ *AfterDel = Del->next;
		// Если удаляем не голову:
		if (PrevDel != 0 && quantity != 1)
			PrevDel->next = AfterDel;
		// Если удаляем не хвост:
		if (AfterDel != 0 && quantity != 1)
			AfterDel->prev = PrevDel;
		// Удаляются крайние?
		if (n == 1)
			head = AfterDel;
		if (n == quantity)
			tail = PrevDel;
		delete Del;
		quantity--;
		SavingCurrent();
		cout << "Данные удалены!" << endl;
	}
	else {
		cout << "Номер введен не верно. Попробуйте еще раз..." << endl;
		return DelObj();
	}
}
void SavingObj()
{
	string filename;
	cout << "Введите название файла:";
	cin >> filename;
	OBJ*c;
	c = head;
	ofstream record(filename, ios::out);
	if (record) {
		record << quantity << endl;
		int n = 1;//счетчик
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
		cout << "Данные сохранены!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
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
		int n = 1;//счетчик
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
		cout << "Ошибка открытия файла!" << endl;
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
				//сравниваем по году
				if (obj->stud.data.year > obj->next->stud.data.year) {
					SwapObj(obj);
				}
				//если год одинаковый, то сравниваем по месяцу
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
				//сравниваем по году
				if (obj->stud.data.year < obj->next->stud.data.year) {
					SwapObj(obj);
				}
				//если год одинаковый, то сравниваем по месяцу
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
		cout << "  Специальность 'ф1' " << "\t План приема : " << f1 << " человек" << endl;
		cod = "ф1";
	}
	if (n == 2) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << "  Специальность 'ф2' " << "\t План приема : " << f2 << " человек" << endl;
		cod = "ф2";
	}
	if (n == 3) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << "  Специальность 'ф3' " << "\t План приема : " << f3 << " человек" << endl;
		cod = "ф3";
	}
	while (obj != NULL) {

		if (obj->stud.grades.code == cod) {
			count++;
			if (count == 1) {
				//формирование столбцов
				cout << "+------------------------------------------------------------------------------+" << endl;
				cout << setw(3) << setfill(' ') << "№";
				cout << left << setw(20) << setfill(' ') << "  ФИО абитуриента";
				cout << left << setw(20) << setfill(' ') << " дата рождения";
				cout << left << setw(20) << setfill(' ') << "  оценки";
				cout << left << setw(3) << setfill(' ')  << "  балл";
				cout << left << setw(3) << setfill(' ') << "  шифр " << endl;
				cout << "+------------------------------------------------------------------------------+" << endl;
			}
			if (count > 0) {
				count++;
				cout << endl;
				//№пп
				cout << right << setw(3) << setfill(' ') << count << " ";
				//фио
				cout << left << setw(20) << setfill(' ') << obj->stud.person.surname << endl
					<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.name << endl
					<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.patronymic;
				//дата
				cout << right << setw(2) << setfill('0') << obj->stud.data.day << "."
					<< setw(2) << obj->stud.data.month << "."
					<< setw(4) << obj->stud.data.year << "\t";
				//оценки
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
void FilterSt1(int _n, int plan) {//int plan- план приема,  int _n- выбор кода специальности
	Sorting_su();
	obj = head;
	int count = 0;
	if (_n == 1) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << endl << " План приема на специальность ф1: " << f1 << " человек" << endl
			<< " Список  зачисленных студентов на 1 курс: " << endl << endl;
		plan = f1;
	}
	if (_n == 2) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << endl << " План приема на специальность ф2: " << f2 << " человек" << endl
			<< " Список зачисленных студентов на 1 курс: " << endl << endl;
		plan = f2;
	}
	if (_n == 3) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << endl << " План приема на специальность ф3: " << f3 << " человек" << endl
			<< " Список зачисленных студентов на 1 курс: " << endl << endl;
		plan = f3;
	}
	if (_n == 4) {
		cout << "+------------------------------------------------------------------------------+" << endl;
		cout << endl << " Список зачисленных студентов на 1 курс: " << endl << endl;
	}
	while (obj != NULL) {
		while (count < plan) {
			count++;
			//№пп
			cout << right << setw(3) << setfill(' ') << count << " ";
			//ФИО
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
	cout << "Введите фамилию ";
	cin >> n;
	system("cls");
	int count = 0;
	while (obj != NULL) {
		for (int i = 0; i < quantity; i++) {
			if (strcmp(n, obj->stud.person.surname) == 0) {
				count++;
				if (count == 1) {
					cout << "+------------------------------------------------------------------------------+" << endl;
					cout << setw(3) << setfill(' ') << "№";
					cout << left << setw(20) << setfill(' ') << "  ФИО абитуриента";
					cout << left << setw(20) << setfill(' ') << " дата рождения";
					cout << left << setw(20) << setfill(' ') << "  оценки";
					cout << left << setw(3) << setfill(' ') << "  балл";
					cout << left << setw(3) << setfill(' ') << "  шифр " << endl;
					cout << "+------------------------------------------------------------------------------+" << endl;
				}
				cout << endl;
				//№пп
				cout << right << setw(3) << setfill(' ') << count << " ";
				//фио
				cout << left << setw(20) << setfill(' ') << obj->stud.person.surname << endl
					<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.name << endl
					<< "    " << left << setw(20) << setfill(' ') << obj->stud.person.patronymic;

				//дата
				cout << right << setw(2) << setfill('0') << obj->stud.data.day << "."
					<< setw(2) << obj->stud.data.month << "."
					<< setw(4) << obj->stud.data.year << "\t";
				//оценки
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
	if (count == 0) cout << " По вашему запросу ничего не найдено!" << endl;
}
