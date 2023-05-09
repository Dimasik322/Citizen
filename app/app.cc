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

void menu_mrot() {
	cout << endl;
	cout << "Введите новое значение МРОТ:" << endl;
	float mrot;
	cin >> mrot;
	set_mrot(mrot);
}

int menu_warning() {
	cout << endl;
	cout << "Внимание, выход обнулит массив и значение мрот" << endl;
	cout << "Вернуться - Enter" << endl;
	cout << "Выйти - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 13)) return key;
	}
}

int menu1() {
	cout << endl;
	cout << "Бухгалтерия в пенсионном фонде" << endl;
	cout << "Программа запущена" << endl;
	cout << "Создать новый массив - Enter" << endl;
	cout << "Выйти - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 13)) return key;
	}
}

int menu2() {
	cout << endl;
	cout << "Редактировать массив - Enter" << endl;
	cout << "Найти максимальную выплату - 1" << endl;
	cout << "Сменить значение МРОТ - 2" << endl;
	cout << "Выйти - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 13) || (key == 49) || (key == 50)) return key;
	}
}

int menu3() {
	cout << endl;
	cout << "Добавить элемент пр индексу - 1" << endl;
	cout << "Добавить элемент в конец - 2" << endl;
	cout << "Удалить элемент - 3" << endl;
	cout << "Заменить существующий элемент - 4" << endl;
	cout << "Выйти Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 51) || (key == 37) || (key == 38) || (key == 39) || (key == 40) || (key == 52)) return key;
	}
}

void menu_set_citizen(CitizenList& citizens) {
	setlocale(LC_ALL, "");
	system("cls");
	cout << endl;
	cout << "Введите имя:" << endl;
	string name;
	cin >> name;
	string org;
	int num;
	bool lf = false;
	float ar;
	int snils;
	int exp;
	int index;
	cout << "Выберите тип: (k|s|o)" << endl;
	switch (get_key()) {
	case 107:
		cout << "Введите образовательную организацию:" << endl;
		cin >> org;
		cout << "Введите персональный номер учащегося:" << endl;
		cin >> num;
		cout << "Введите статус многодетности семьи : (y|n)" << endl;
		if (get_key() == 89) {
			lf = true;
		}
		system("cls");
		citizens.show();
		cout << "Введите индекс для замены элемента" << endl;
		cin >> index;
		citizens.set(make_shared<CitizenKid>(name, org, num, lf), index);
		break;
	case 115:
		cout << "Введите образовательную организацию:" << endl;
		cin >> org;
		cout << "Введите персональный номер учащегося:" << endl;
		cin >> num;
		cout << "Введите рейтинг учащегося:" << endl;
		cin >> ar;
		system("cls");
		citizens.show();
		cout << "Введите индекс для замены элемента" << endl;
		cin >> index;
		citizens.set(make_shared<CitizenStudent>(name, org, num, ar), index);
		break;
	case 111:
		cout << "Введите номер СНИЛС:" << endl;
		cin >> snils;
		cout << "Введите стаж работы" << endl;
		cin >> exp;
		system("cls");
		citizens.show();
		cout << "Введите индекс для замены элемента" << endl;
		cin >> index;
		citizens.set(make_shared<CitizenOldman>(name, snils, exp), index);
		break;
	}

}

void menu_insert_citizen(CitizenList& citizens) {
	setlocale(LC_ALL, "");
	system("cls");
	cout << endl;
	cout << "Введите имя:" << endl;
	string name;
	cin >> name;
	string org;
	int num;
	bool lf = false;
	float ar;
	int snils;
	int exp;
	int index;
	cout << "Выберите тип: (k|s|o)" << endl;
	switch (get_key()) {
	case 107:
		cout << "Введите образовательную организацию:" << endl;
		cin >> org;
		cout << "Введите персональный номер учащегося:" << endl;
		cin >> num;
		cout << "Введите статус многодетности семьи : (y|n)" << endl;
		if (get_key() == 89) {
			lf = true;
		}
		system("cls");
		citizens.show();
		cout << "Введите индекс для нового элемента" << endl;
		cin >> index;
		citizens.insert(make_shared<CitizenKid>(name, org, num, lf), index);
		break;
	case 115:
		cout << "Введите образовательную организацию:" << endl;
		cin >> org;
		cout << "Введите персональный номер учащегося:" << endl;
		cin >> num;
		cout << "Введите рейтинг учащегося:" << endl;
		cin >> ar;
		system("cls");
		citizens.show();
		cout << "Введите индекс для нового элемента" << endl;
		cin >> index;
		citizens.insert(make_shared<CitizenStudent>(name, org, num, ar), index);
		break;
	case 111:
		cout << "Введите номер СНИЛС:" << endl;
		cin >> snils;
		cout << "Введите стаж работы" << endl;
		cin >> exp;
		system("cls");
		citizens.show();
		cout << "Введите индекс для нового элемента" << endl;
		cin >> index;
		citizens.insert(make_shared<CitizenOldman>(name, snils, exp), index);
		break;
	}

}

void menu_add_citizen(CitizenList& citizens) {
	setlocale(LC_ALL, "");
	system("cls");
	cout << endl;
	cout << "Введите имя:" << endl;
	string name;
	cin >> name;
	string org;
	int num;
	bool lf = false;
	float ar;
	int snils;
	int exp;
	cout << "Выберите тип: (k|s|o)" << endl;
	switch (get_key()) {
	case 107:
		cout << "Введите образовательную организацию:" << endl;
		cin >> org;
		cout << "Введите персональный номер учащегося:" << endl;
		cin >> num;
		cout << "Введите статус многодетности семьи : (y|n)" << endl;
		if (get_key() == 89) {
			lf = true;
		}
		citizens.add(make_shared<CitizenKid>(name, org, num, lf));
		break;
	case 115:
		cout << "Введите образовательную организацию:" << endl;
		cin >> org;
		cout << "Введите персональный номер учащегося:" << endl;
		cin >> num;
		cout << "Введите рейтинг учащегося:" << endl;
		cin >> ar;
		citizens.add(make_shared<CitizenStudent>(name, org, num, ar));
		break;
	case 111:
		cout << "Введите номер СНИЛС:" << endl;
		cin >> snils;
		cout << "Введите стаж работы" << endl;
		cin >> exp;
		citizens.add(make_shared<CitizenOldman>(name, snils, exp));
		break;
	}
}

void menu_delete(CitizenList& citizens) {
	setlocale(LC_ALL, "");
	system("cls");
	int index;
	cout << endl;
	citizens.show();
	cout << "Введите индекс, по которому нужно удалить элемент:" << endl;
	cin >> index;
	citizens.remove(index);
}






int main() {
	setlocale(LC_ALL, "");
	while (true) {
		CitizenList citizens;
		citizens.add(make_shared<CitizenKid>("Дмитрий", "МБОУСОШ", 12434, true));
		citizens.add(make_shared<CitizenStudent>("Иван", "МБОУСОШ", 25534, 4.5f));
		citizens.add(make_shared<CitizenOldman>("Максим", 345346, 40));
		system("cls");
		int m1 = menu1();
		if (m1 == 27) break;
		cout << "Введите значение МРОТ:" << endl;
		float mrot;
		cin >> mrot;
		set_mrot(mrot);
		while (true) {
			system("cls");
			citizens.show();
			int m2 = menu2();
			if (m2 == 49) {
				float max = index_of_max_value(citizens);
				if (get_key() == 27) break;
			}
			if (m2 == 50) {
				menu_mrot();
			}
			if (m2 == 27) {
				system("cls");
				int mesc = menu_warning();
				if (mesc == 27) break;
			}
			if (m2 == 13) {
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
					if (m3 == 52) {
						menu_set_citizen(citizens);
					}
				}
			}
		}
	}
	return 0;
}