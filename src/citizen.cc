#include <citizen/citizen.h>

#include <iostream>
#include <iomanip>

using namespace std;
using namespace CitizenNamespace;

void CitizenNamespace::set_mrot(float mrot) {
	MROT = mrot;
};


CitizenKid::CitizenKid(const string name, const string org, const int num, const bool lf) :Name(name), Organization(org), Number(num), LargeFamily(lf) {};
CitizenStudent::CitizenStudent(const string name, const string org, const int num, const float ar) :Name(name), Organization(org), Number(num), AveRating(ar) {};
CitizenOldman::CitizenOldman(const string name, const int snils, const int exp) :Name(name), Snils(snils), Exp(exp) {};


string CitizenKid::get_name() const { return Name; }
string CitizenStudent::get_name() const { return Name; }
string CitizenOldman::get_name() const { return Name; }
string CitizenKid::get_org() const { return Organization; }
int CitizenKid::get_num() const { return Number; }
bool CitizenKid::get_lf() const { return LargeFamily; }
string CitizenStudent::get_org() const { return Organization; }
int CitizenStudent::get_num() const { return Number; }
float CitizenStudent::get_rating() const { return AveRating; }
int CitizenOldman::get_snils() const { return Snils; }
int CitizenOldman::get_exp() const { return Exp; }

float CitizenKid::calculate_payment() const {
	float value = 0;
	if ((LargeFamily) == true) {
		value = (0.5 * MROT);
	}
	else {
		value = 0;
	}
	return value;
}
float CitizenStudent::calculate_payment() const {
	float value = 0;
	if ((AveRating) < 3.5) {
		value = 0;
	}
	else {
		value = ((0.5 + 0.2 * ((AveRating)-3.5)) * MROT);
	}
	return value;
}
float CitizenOldman::calculate_payment() const {
	float value = 0;
	if (Exp < 5) {
		value = 0;
	}
	else if (Exp > 30) {
		value = 5 * MROT;
	}
	else {
		value = (1 + 0.12 * (Exp - 5)) * MROT;
	}
	return value;
}

void CitizenKid::print_citizen() const {
	cout << setiosflags(ios::left) << setw(15) << get_name() << setw(15) << "Школьник" << setw(15) << calculate_payment() << get_org() << " " << get_num() << " " << " Из многодетной семьи:";
	if (get_lf() == true) {
		cout << "да" << endl;
	}
	else {
		cout << "нет" << endl;
	}
	
}
void CitizenStudent::print_citizen() const {
	cout << setiosflags(ios::left) << setw(15) << get_name() << setw(15) << "Студент" << setw(15) << calculate_payment() << get_org() << " " << get_num() << " " << " Средний балл:" << get_rating() << endl;
}
void CitizenOldman::print_citizen() const {
	cout << setiosflags(ios::left) << setw(15) << get_name() << setw(15) << "Пенсионер" << setw(15) << calculate_payment() << get_snils() << " " << " Стаж работы:" << get_exp() << endl;
}

CitizenPtr CitizenKid::clone() const {
	return make_shared<CitizenKid>(Name, Organization, Number, LargeFamily);
}
CitizenPtr CitizenStudent::clone() const {
	return make_shared<CitizenStudent>(Name, Organization, Number, AveRating);
}
CitizenPtr CitizenOldman::clone() const {
	return make_shared<CitizenOldman>(Name, Snils, Exp);
}

bool CitizenKid::equals(CitizenPtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<CitizenKid>(other);
	if (downcasted_other == nullptr) {
		return false;
	}
	return (Name == downcasted_other->Name) && (Organization == downcasted_other->Organization) && (LargeFamily == downcasted_other->LargeFamily) && (Number == downcasted_other->Number);
}
bool CitizenStudent::equals(CitizenPtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<CitizenStudent>(other);
	if (downcasted_other == nullptr) {
		return false;
	}
	return (Name == downcasted_other->Name) && (Organization == downcasted_other->Organization) && (AveRating == downcasted_other->AveRating) && (Number == downcasted_other->Number);
}
bool CitizenOldman::equals(CitizenPtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<CitizenOldman>(other);
	if (downcasted_other == nullptr) {
		return false;
	}
	return (Name == downcasted_other->Name) && (Snils == downcasted_other->Snils) && (Exp == downcasted_other->Exp);
}


CitizenList::CitizenList(const CitizenList& other) {
	const auto n = other.size();
	citizens.reserve(n);
	for (int i = 0; i < n; ++i) {
		citizens.push_back(other[i]->clone());
	}
}

CitizenList& CitizenList::operator=(const CitizenList& rhs) {
	CitizenList copy(rhs);
	copy.swap(*this);
	return *this;
}

CitizenPtr CitizenList::operator[](const int index) const {
	return citizens.at(index);
}

void CitizenList::swap(CitizenList& other) {
	std::swap(this->citizens, other.citizens);
}

int CitizenList::size() const {
	return static_cast<int>(citizens.size());
}


void CitizenList::add(CitizenPtr c) {
	citizens.push_back(c);
}

void CitizenList::insert(CitizenPtr c, int index) {
	citizens.insert(citizens.begin() + index, c);
}

void CitizenList::set(CitizenPtr c, int index) {
	citizens.erase(citizens.begin() + index);
	citizens.emplace(citizens.begin() + index, c);
}

void CitizenList::remove(int index) {
	citizens.erase(citizens.begin() + index);
}

void CitizenList::show() {
	setlocale(LC_ALL, "");
	cout << "Список:" << endl;
	cout << "№ " << setiosflags(ios::left) << setw(15) << "Имя " << setw(15) << "Соц.группа " << setw(15) << "Сумма выплаты " << setw(15) << "Другие данные " << endl;
	for (int i(0); i < size(); ++i) {
		cout << i << " ";
		citizens[i]->print_citizen();
	}
}

int CitizenNamespace::index_of_max_value(const CitizenList& citizens) {
	setlocale(LC_ALL, "");
	int max_index = -1;
	float max_value = 0;
	float value = 0;
	for (int i = 0; i < citizens.size(); ++i) {
		value = citizens[i]->calculate_payment();
		if (max_index == -1 || max_value < value) {
			max_index = i;
			max_value = value;
		}
	}
	if (max_index == -1) {
		cout << "Список пуст" << endl;
	}
	else {
		cout << "Наибольшее найденное значение " << max_value << " находится по индексу " << max_index << endl;
	}
	return max_index;
}




