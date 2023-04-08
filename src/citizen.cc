#include <citizen/citizen.h>

#include <stdexcept>
#include <iostream>

using namespace std;
using namespace CitizenNamespace;

void Citizen::set_type(Type type) {
	this->_type = type;
}

void Citizen::set_name(string name)
{
	this->Name = name;
}

void Citizen::set_org(string org)
{
	this->Organization = org;
}

void Citizen::set_number(int num)
{
	this->Number = num;
}

void Citizen::set_snils(int snils)
{
	this->SNILS = snils;
}

void Citizen::set_family(bool lf) {
	this->LargeFamily = lf;
}

void Citizen::set_rating(float ar) {
	this->AveRating = ar;
}

void Citizen::set_exp(int exp) {
	this->Exp = exp;
}

void Citizen::set_payment(float payment) {
	this->Payment = payment;
}



Type Citizen::get_type() const {
	return _type;
}

string Citizen::get_name() const {
	return Name;
}

string Citizen::get_org() const {
	return Organization;
}

int Citizen::get_number() const {
	return Number;
}

bool Citizen::get_family() const {
	return LargeFamily;
}

float Citizen::get_rating() const {
	return AveRating;
}

int Citizen::get_snils() const {
	return SNILS;
}

int Citizen::get_exp() const {
	return Exp;
}

float Citizen::get_payment() const {
	return Payment;
}


Citizen::Citizen(Type type, string name, string org, int number, bool lf) {
	if (type != Kid) {
		throw std::runtime_error("Wrong type of citizen");
	}
	_type = type;
	Name = name;
	Organization = org;
	Number = number;
	LargeFamily = lf;
}

Citizen::Citizen(Type type, string name, string org, int number, float ar) {
	if (type != Student) {
		throw std::runtime_error("Wrong type of citizen");
	}
	_type = type;
	Name = name;
	Organization = org;
	Number = number;
	AveRating = ar;
}

Citizen::Citizen(Type type, string name, int snils, int exp) {
	if (type != Oldman) {
		throw std::runtime_error("Wrong type of citizen");
	}
	_type = type;
	Name = name;
	SNILS = snils;
	Exp = exp;
}

Citizen::Citizen(Type type, string name, float payment) :_type(type), Name(name), Payment(payment) {};

CitizenPtr Citizen::create_kid(string name, string org, int number, bool lf) {
	return new Citizen(Type::Kid, name, org, number, lf);
}

CitizenPtr Citizen::create_student(string name, string org, int number, float ar) {
	return new Citizen(Type::Student, name, org, number, ar);
}

CitizenPtr Citizen::create_oldman(string name, int snils, int exp) {
	return new Citizen(Type::Oldman, name, snils, exp);
}

float Citizen::calculate_payment() const {
	float value = 0;
	switch (_type) {
	case Kid:
		if ((LargeFamily) == true) {
			value = (0.5 * MROT);
			}
		else {
			value = 0;
		}
		return value;
		break;
	case Student:
		if ((AveRating) < 3.5) {
			value = 0;
		}
		else {
			value = ((0.5 + 0.2 * ((AveRating)-3.5)) * MROT);
		}
		return value;
		break;
	case Oldman:
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
		break;
	default:
		throw runtime_error("[Function::compute_value] Invalid function type.");
	}
}
////CitizenPtr Citizen::calculate_payment(){
//	float value = 0;
//	switch (_type) {
//	case Kid:
//		if ((LargeFamily) == true) {
//			value = (0.5 * MROT);
//		}
//		else {
//			value = 0;
//		}
//		return new Citizen(Type::Kid, Name, value);
//		break;
//	case Student:
//		if ((AveRating) < 3.5) {
//			value = 0;
//		}
//		else {
//			value = ((0.5 + 0.2 * ((AveRating)-3.5)) * MROT);
//		}
//		return new Citizen(Type::Student, Name, value);
//		break;
//	case Oldman:
//		if (Exp < 5) {
//			value = 0;
//		}
//		else if (Exp > 30) {
//			value = 5 * MROT;
//		}
//		else {
//			value = (1 + 0.12 * (Exp - 5)) * MROT;
//		}
//		return new Citizen(Type::Oldman, Name, value);
//		break;
//	}
//};

CitizenPtr Citizen::clone() const {
	return new Citizen(_type, Name, Payment);
}

bool CitizenNamespace::operator==(const Citizen& lhs, const Citizen& rhs) {
	return
		lhs.get_type() == rhs.get_type() &&
		lhs.calculate_payment() == rhs.calculate_payment();
}

bool CitizenNamespace::operator!=(const Citizen& lhs, const Citizen& rhs) {
	return !(lhs == rhs);
}



CitizenList::CitizenList() : ptr(nullptr), _size(0){ }

CitizenList::CitizenList(const CitizenList& other) : ptr(new CitizenPtr[other._size]), _size(other._size){
	for (int i = 0; i < _size; ++i) {
		ptr[i] = other[i]->clone();
	}
}

CitizenList& CitizenList::operator=(const CitizenList& rhs) {
	CitizenList copy(rhs);
	copy.swap(*this);
	return *this;
}

int CitizenList::size() const {
	return _size;
}

CitizenPtr CitizenList::operator[](const int index) const {
	if (index < 0 || _size <= index) {
		throw out_of_range("[CitizenList::operator[]] Index is out of range.");
	}

	return ptr[index];
}

void CitizenList::add(CitizenPtr const c) {
	auto new_ptr = new CitizenPtr[_size + 1];

	for (int i = 0; i < _size; ++i) {
		new_ptr[i] = ptr[i];
	}
	new_ptr[_size] = c;

	delete[] ptr;
	ptr = new_ptr;

	++_size;
}

void CitizenList::swap(CitizenList& other) {
	std::swap(this->ptr, other.ptr);
	std::swap(this->_size, other._size);
}

CitizenList::~CitizenList() {
	for (int i = 0; i < _size; ++i) {
		delete ptr[i];
	}
	delete[] ptr;
}