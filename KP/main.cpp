#include"functions.h"
#include<iostream>
#include<Windows.h>
using namespace std;
int stMenu;
void Menu()
{
	cout << endl;
	cout << "  Выберите действие: " << endl
		<< "  (0)  Выход из программы" << endl
		<< "  (1)  Добавление данных" << endl
		<< "  (2)  Печать данных" << endl
		<< "  (3)  Изменение данных" << endl
		<< "  (4)  Удаление данных" << endl
		<< "  (5)  Фильтр данных" << endl
		<< "  (6)  Сортировка данных" << endl
		<< "  (7)  Сохранение данных в файл" << endl
		<< "  (8)  Показать списки поступивших" << endl
		<< "  (9)  Поиск по фамилии" << endl
		<< endl
		<< "  Введите ваш выбор: ";
	cin >> stMenu;
}
int main() {
	SetConsoleCP(1251);//русификация потока ввода
	SetConsoleOutputCP(1251);//русификация потока вывода
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
			cout << "  Хотите ввести данные вручную или из файла?" << endl
				<< "  (1) Вести вручную" << endl << endl
				<< "  Для ввода данных из файла введите любую цифру";
			cin >> actions;
			system("cls");
			if (actions == 1)AddObj();//ввод вручную
			else ReadingObj(); //ввод из файла
			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			if (quantity == 0)	cout << "Список пуст!" << endl;
			else Print();
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			if (quantity == 0) cout << "Список пуст!" << endl;
			else ChangeObj();
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			if (quantity == 0) cout << "Список пуст!" << endl;
			else DelObj();
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			if (quantity == 0) cout << "Список пуст!" << endl;
			else {
				cout << " (1) Список поступающих на специальность ф1 " << endl
					<< " (2) Список поступающих на специальность ф2 " << endl
					<< " (3) Список поступающих на специальность ф3 " << endl << endl
					<< " Введите свой выбор: ";
				int n;
				cin >> n;
				if (n == 1) { system("cls"); Filter(1); }
				if (n == 2) { system("cls"); Filter(2); }
				if (n == 3) { system("cls"); Filter(3); }
				if (n > 3 || n < 0) {
					cout << " Неправильно введен номер. Попробуйте еще раз...";
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
				cout << "Список пуст!" << endl;
			else {
				int n;
				cout << "(1) Сортировать список по фамилии" << endl
					<< "(2) Сортировать список по дате рождения " << endl
					<< "(3) Сортировать список по сумме баллов " << endl << endl;
				cout << "Введите ваш выбор: ";
				cin >> n;
				//по фамилии
				if (n == 1) {
					system("cls");
					cout << "(1) Отсортировать список по возрастанию " << endl
						<< "Чтобы отсортировать список по убыванию, нажмите любую клавишу ";
					int _n;
					cin >> _n;
					if (_n == 1) { Sorting_abc_V(); system("cls"); Print(); }
					else { Sorting_abc_U(); system("cls"); Print(); }
				}
				//по дате рождения
				if (n == 2) {
					system("cls");
					cout << " (1) Отсортировать список по возрастанию " << endl
						<< "  Чтобы отсортировать список по убыванию, нажмите любую цифру ";
					int _n;
					cin >> _n;
					if (_n == 1) { Sorting_dv(); system("cls"); Print(); }
					else { Sorting_du(); system("cls"); Print(); }
				}
				//по баллам
				if (n == 3) {
					system("cls");
					cout << " (1) Отсортировать список по возрастанию " << endl
						<< "  Чтобы отсортировать список по убыванию," <<
						endl << " нажмите любую клавишу ";
					int _n;
					cin >> _n;
					if (_n == 1) { Sorting_sv(); system("cls"); Print(); }
					else { Sorting_su(); system("cls"); Print(); }
				}
				if (n < 1 || n>3) {
					system("cls");
					cout << "Неверно введен номер действия! Попробуйте еще раз" << endl;
					cin >> n;
				}
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");
			if (quantity == 0) cout << "Список пуст!" << endl;
			else
				SavingObj();
			system("pause");
			system("cls");
			Menu();
			break;
		case 8:
			system("cls");
			if (quantity == 0) cout << " Список пуст!" << endl;
			else
			{
				cout << endl;
				cout << " Выберите действтвие: " << endl;
				cout << " (1) Список зачисленных студентов на специальность ф1" << endl;
				cout << " (2) Список зачисленных студентов на специальность ф2" << endl;
				cout << " (3) Список зачисленных студентов на специальность ф3" << endl;
				cout << " (4) Общий список зачисленных студентов " << endl << endl;
				cout << " Введите ваш выбор: ";
				int _n;
				cin >> _n;
				system("cls");
				if (_n == 1) { FilterSt1(1, f1); }
				if (_n == 2) { FilterSt1(2, f2); }
				if (_n == 3) { FilterSt1(3, f3); }
				if (_n == 4) { int pl; pl = f1 + f2 + f3; FilterSt1(4, pl); }
				if (_n < 1 || _n>4)cout << "Неправильно введен номер!";
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
			cout << "Неверно введен номер действия!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
	return 0;
}

