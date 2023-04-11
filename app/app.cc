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
	cout << "����������� � ���������� �����" << endl;
	cout << endl;
	cout << "������� ����� ������ - Enter" << endl;
	cout << "����� - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 13)) return key;
	}
}

int menu2() {
	cout << endl;
	cout << "������������� ������ - Enter" << endl;
	cout << "����� ������������ ������� - 1" << endl;
	cout << "����� - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 13) || (key == 49)) return key;
	}

}

int menu3() {
	cout << endl;
	cout << "�������� �� ������� - 1" << endl;
	cout << "�������� � ����� ������� - 2" << endl;
	cout << "������� �� ������� - 3" << endl;
	cout << "����� Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key==27)|| (key == 49) || (key == 50) || (key == 51) || (key == 37) || (key == 38) || (key == 39) || (key == 40)) return key;
	}
}

void menu_insert_citizen(CitizenList& citizens) {
	setlocale(LC_ALL, "");
	system("cls");
	cout << endl;
	cout << "������� ���:" << endl;
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
	cout << "������� ������ �������: (k|s|o)" << endl;
	switch (get_key()) {
	case 107:
		type = Kid;
		cout << "������� �������� ��������������� �����������:" << endl;
		cin >> org;
		cout << "������� ������������ ����� �������:" << endl;
		cin >> num;
		cout << "������� ������ ������������� �����: (y|n)" << endl;
		if (get_key() == 89) {
			lf = true;
			}
		c = Citizen::create_kid(name, org, num, lf);
		break;
	case 115:
		type = Student;
		cout << "������� �������� ��������������� �����������:" << endl;
		cin >> org;
		cout << "������� ������������ ����� ��������:" << endl;
		cin >> num;
		cout << "������� ������� ��������:" << endl;
		cin >> ar;
		c = Citizen::create_student(name, org, num, ar);
		break;
	case 111:
		type = Oldman;
		cout << "������� �����:" << endl;
		cin >> snils;
		cout << "������� ���� ������" << endl;
		cin >> exp;
		c = Citizen::create_oldman(name, snils, exp);
		break;
	}
	system("cls");
	citizens.show();
	cout << "������� ������, �� �������� �������� ����� ������" << endl;
	cin >> index;
	citizens.insert(c, index);
}

void menu_add_citizen(CitizenList& citizens) {
	setlocale(LC_ALL, "");
	system("cls");
	cout << endl;
	cout << "������� ���:" << endl;
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
	cout << "������� ������ �������: (k|s|o)" << endl;
	switch (get_key()) {
	case 107:
		type = Kid;
		cout << "������� �������� ��������������� �����������:" << endl;
		cin >> org;
		cout << "������� ������������ ����� �������:" << endl;
		cin >> num;
		cout << "������� ������ ������������� �����: (y|n)" << endl;
		if (get_key() == 89) {
			lf = true;
		}
		c = Citizen::create_kid(name, org, num, lf);
		break;
	case 115:
		type = Student;
		cout << "������� �������� ��������������� �����������:" << endl;
		cin >> org;
		cout << "������� ������������ ����� ��������:" << endl;
		cin >> num;
		cout << "������� ������� ��������:" << endl;
		cin >> ar;
		c = Citizen::create_student(name, org, num, ar);
		break;
	case 111:
		type = Oldman;
		cout << "������� �����:" << endl;
		cin >> snils;
		cout << "������� ���� ������" << endl;
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
	cout << "������� ������ �������, ������� ����� �������:" << endl;
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
	citizens.add(Citizen::create_student("�������", "���� ��� �38", 3421, 4.5f));
	citizens.insert(Citizen::create_kid("Ivan", "���� ��� �322", 45345, true), 0);
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