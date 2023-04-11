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
	cout << "Выход - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 13) || (key == 49)) return key;
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
		if ((key==27)|| (key == 49) || (key == 50) || (key == 51) || (key == 37) || (key == 38) || (key == 39) || (key == 40)) return key;
	}
}

void menu_insert_citizen(CitizenList& citizens) {
	setlocale(LC_ALL, "");
	system("cls");
	cout << endl;
	cout << "Введите имя:" << endl;
	string name; 
	cin >> name;
	Type type;
	string org;
	int num;
	bool lf = false;
	float ar;
	int snils;
	int exp;
	int index;
	Citizen* c = nullptr;
	cout << "Введите статус объекта: (k|s|o)" << endl;
	switch (get_key()) {
	case 107:
		type = Kid;
		cout << "Введите название образовательной организации:" << endl;
		cin >> org;
		cout << "Введите персональный номер ученика:" << endl;
		cin >> num;
		cout << "Введите статус многодетности семьи: (y|n)" << endl;
		if (get_key() == 89) {
			lf = true;
			}
		c = Citizen::create_kid(name, org, num, lf);
		break;
	case 115:
		type = Student;
		cout << "Введите название образовательной организации:" << endl;
		cin >> org;
		cout << "Введите персональный номер студента:" << endl;
		cin >> num;
		cout << "Введите рейтинг студента:" << endl;
		cin >> ar;
		c = Citizen::create_student(name, org, num, ar);
		break;
	case 111:
		type = Oldman;
		cout << "Введите СНИЛС:" << endl;
		cin >> snils;
		cout << "Введите стаж работы" << endl;
		cin >> exp;
		c = Citizen::create_oldman(name, snils, exp);
		break;
	}
	system("cls");
	citizens.show();
	cout << "Введите индекс, по которому вставить новый объект" << endl;
	cin >> index;
	citizens.insert(c, index);
}

void menu_add_citizen(CitizenList& citizens) {
	setlocale(LC_ALL, "");
	system("cls");
	cout << endl;
	cout << "Введите имя:" << endl;
	string name;
	cin >> name;
	Type type;
	string org;
	int num;
	bool lf = false;
	float ar;
	int snils;
	int exp;
	Citizen* c = nullptr;
	cout << "Введите статус объекта: (k|s|o)" << endl;
	switch (get_key()) {
	case 107:
		type = Kid;
		cout << "Введите название образовательной организации:" << endl;
		cin >> org;
		cout << "Введите персональный номер ученика:" << endl;
		cin >> num;
		cout << "Введите статус многодетности семьи: (y|n)" << endl;
		if (get_key() == 89) {
			lf = true;
		}
		c = Citizen::create_kid(name, org, num, lf);
		break;
	case 115:
		type = Student;
		cout << "Введите название образовательной организации:" << endl;
		cin >> org;
		cout << "Введите персональный номер студента:" << endl;
		cin >> num;
		cout << "Введите рейтинг студента:" << endl;
		cin >> ar;
		c = Citizen::create_student(name, org, num, ar);
		break;
	case 111:
		type = Oldman;
		cout << "Введите СНИЛС:" << endl;
		cin >> snils;
		cout << "Введите стаж работы" << endl;
		cin >> exp;
		c = Citizen::create_oldman(name, snils, exp);
		break;
	}
	citizens.add(c);
}

void menu_delete(CitizenList& citizens) {
	setlocale(LC_ALL, "");
	system("cls");
	int index;
	cout << endl;
	citizens.show();
	cout << "Введите индекс объекта, который нужно удалить:" << endl;
	cin >> index;
	citizens.delete_citizen(index);
}

//Citizen menu_max()
//sort
//

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
	citizens.add(Citizen::create_student("Дмитрий", "МАОУ ФМЛ №38", 3421, 4.5f));
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
			while (true) {
				system("cls");
				citizens.show();
				int m3 = menu3();
				if (m3 == 27) break;
				if (m3 == 49) {
					menu_insert_citizen(citizens);
				}
				if (m3 == 50) {
					menu_add_citizen(citizens);
				}
				if (m3 == 51) {
					menu_delete(citizens);
				}
			}
		}
	}
	return 0;
}