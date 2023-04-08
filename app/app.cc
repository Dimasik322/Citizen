//#include <gtest/gtest.h>
//
//#include <citizen/citizen.h>
//
//#include <iostream>
//#include <string>
//#include <conio.h>
//#include <string>
//
//using namespace CitizenNamespace;
//using namespace std;
//
//int get_key() {
//	int key = getch();
//	if ((key == 0) || (key == 224)) key = getch();
//	return key;
//}
//
//int menu1() {
//	cout << endl;
//	cout << "Бухгалтерия в Пенсионном Фонде" << endl;
//	cout << endl;
//	cout << "Создать новый массив Enter" << endl;
//	cout << "Выход Esc" << endl;
//	while (true) {
//		int key = get_key();
//		if ((key == 27) || (key == 13)) return key;
//	}
//}
//
//int menu2() {
//	cout << endl;
//	cout << "Редактировать массив Enter" << endl;
//	cout << "Выход Esc" << endl;
//	while (true) {
//		int key = get_key();
//		if ((key == 27) || (key == 13)) return key;
//	}
//}
//
//int menu3() {
//	cout << endl;
//	cout << "Добавить по индексу i" << endl;
//	cout << "Добавить в конец массива a" << endl;
//	cout << "Удалить по индексу d" << endl;
//	cout << "Выход Esc" << endl;
//	while (true) {
//		int key = get_key();
//		if ((key==27)|| (key == 97) || (key == 105) || (key == 100)) return key;
//	}
//}
//
//void menu_add() {
//	cout << endl;
//	cout << "Введите данные объекта" << endl;
//}
//
//Type menu_type_in() {
//	Type type;
//	cout << endl;
//	cout << "Введите тип(k/s/o):" << endl;
//	int key = get_key();
//	switch (key) {
//	case 107:
//		type = Kid;
//		break;
//	case 115:
//		type = Student;
//	case 111:
//		type = Oldman;
//	default:
//		throw runtime_error("Неправильный тип");
//		break;
//	}
//	return type;
//}
//
//void menu_type_out(Type type) {
//	cout << endl;
//	cout << "Тип объекта:" << type << endl;
//}
//
//string menu_name_in() {
//	string name;
//	cout << endl;
//	cout << "Введите имя:" << endl;
//	cin >> name;
//	return name;
//}
//
//void menu_name_out(string name) {
//	cout << endl;
//	cout << "Имя объекта:" << name << endl;
//}
//
//
//
//int main() {
//	setlocale(LC_ALL, "");
//	int size;
//	string name;
//	Type type;
//	while (true) {
//		system("cls");
//		int m1 = menu1();
//		if (m1 == 27) break;
//		//current = 0;
//		while (true) {
//			system("cls");
//			int m2 = menu2();
//			if (m2 == 27) break;
//			cout << "Введите размер массива:";
//			cin >> size;
//			while (true) {
//				system("cls");
//				int m3 = menu3();
//				if (m3 == 27) break;
//				switch (m3) {
//				case 97:
//					system("cls");
//					menu_add();
//					name = menu_name_in();
//					menu_name_out(name);
//					type = menu_type_in();
//					menu_type_out(type);
//					break;
//					while (true) {
//
//					}
//				}
//			}
//		}
//	}
//
//	return 0;
//}