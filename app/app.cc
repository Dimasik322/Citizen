#include <gtest/gtest.h>

#include <citizen/citizen.h>
#include <conio.h>

using namespace CitizenNamespace;
using namespace std;

int get_key() {
	int key = getch();
	//if ((key == 0) || (key == 224)) key = getch();
	return key;
}

int menu1() {
	cout << endl;
	cout << "Бухгалтерия в Пенсионном Фонде" << endl;
	cout << endl;
	cout << "Создать новый массив - Enter" << endl;
	cout << "Выход - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 13)) return key;
	}
}

int menu2() {
	cout << endl;
	cout << "Редактировать массив - Enter" << endl;
	cout << "Найти максимальную выплату - 1" << endl;
	cout << "Вывести список - 2" << endl;
	cout << "Выход - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 13) || (key == 49) || (key == 50)) return key;
	}

}

int menu3() {
	cout << endl;
	cout << "Добавить по индексу - 1" << endl;
	cout << "Добавить в конец массива - 2" << endl;
	cout << "Удалить по индексу - 3" << endl;
	cout << "Выход Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key==27)|| (key == 49) || (key == 50) || (key == 51)) return key;
	}
}

int main() {
	setlocale(LC_ALL, "");
	Type type;
	string name;
	string org;
	int number;
	int snils;
	float ar;
	int exp;
	bool lf;
	float payment;

	CitizenList citizens;
	citizens.add(Citizen::create_student("Dmitrii", "МАОУ ФМЛ №38", 3421, 4.5f));
	citizens.insert(Citizen::create_kid("Ivan", "МБОУ СОШ №322", 45345, true), 0);
	citizens.insert(Citizen::create_oldman("Maxim", 45345, 28), 1);

	while (true) {
		system("cls");
		int m1 = menu1();
		if (m1 == 27) break;
		while (true) {
			system("cls");
			citizens.show();
			int m2 = menu2();
			if (m2 == 27) break;
			if (m2 == 13) {
				while (true) {
					int m3 = menu3();
				}
			}

			if (m2 == 49) int m_max;


			if (m2 == 50) int m_show;


		}
	}

	return 0;
}