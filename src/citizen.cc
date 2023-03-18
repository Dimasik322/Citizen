#include <citizen/citizen.h>

#include <exception>
#include <stdexcept>
#include <string.h>
#include <iostream>

using namespace CitizenNamespace;

Citizen::Citizen()
{
	type = Kid; 
	Name = "";
	Organization = "";
	Number = 0;
	LargeFamily = false;
	AveRating = 0;
	SNILS = 0;
	Exp = 0;
	MROT = 0;
}

void Citizen::set_type(Type type) {
	this->type = type;
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

void Citizen::set_mrot(int mrot) {
	this->MROT = mrot;
}


Type Citizen::get_type() {
	return type;
 }

string Citizen::get_name() {
	return Name;
}

string Citizen::get_org() {
	return Organization;
}

int Citizen::get_number() {
	return Number;
}

bool Citizen::get_family() {
	return LargeFamily;
}

float Citizen::get_rating() {
	return AveRating;
}

int Citizen::get_snils() {
	return SNILS;
}

int Citizen::get_exp() {
	return Exp;
}

float Citizen::get_payment() {
	return Payment;
}

int Citizen::get_mrot() {
	return MROT;
}

Citizen::Citizen(Type _type, string name, string org, int number, bool lf) {
	if (_type != Kid) {
		throw std::runtime_error("Wrong type of citizen");
	}
	type = _type;
	Name = name;
	Organization = org;
	Number = number;
	LargeFamily = lf;
}

Citizen::Citizen(Type _type, string name, string org, int number, float ar) {
	if (_type != Student) {
		throw std::runtime_error("Wrong type of citizen");
	}
	type = _type;
	Name = name;
	Organization = org;
	Number = number;
	AveRating = ar;
}

Citizen::Citizen(Type _type, string name, int snils, int exp) {
	if (_type != Oldman) {
		throw std::runtime_error("Wrong type of citizen");
	}
	type = _type;
	Name = name;
	SNILS = snils;
	Exp = exp;
}

void Citizen::calculate_payment() {
	switch (type) {
	case Kid:
		if ((this->LargeFamily) == true) {
			this->Payment = (0.5 * get_mrot());
		}
		else {
			this->Payment = 0;
		}
		break;
	case Student:
		if ((this->AveRating) < 3.5) {
			this->Payment = 0;
		}
		else {
			this->Payment = ((0.5 + 0.2 * ((this->AveRating) - 3.5)) * get_mrot());
		}
		break;
	case Oldman:
		if (this->Exp < 5) {
			this->Payment = 0;
		}
		else if (this->Exp > 30) {
			this->Payment = 5 * MROT;
		}
		else {
			this->Payment = (1 + 0.12 * ((this->Exp) - 5)) * get_mrot();
		}
		break;
	}
};



CitizenList::CitizenList() {
	Count = 9;
	for (int i(0); i <= Count; ++i) {
		citizens[i] = Citizen();
	}
}

CitizenList::CitizenList(Citizen citizen[], int count) {
	Count = count;
	for (int i(0); i < count; ++i) {
		citizens[i].set_type(citizen[i].get_type());
		citizens[i].set_name(citizen[i].get_name());
		citizens[i].set_org(citizen[i].get_org());
		citizens[i].set_number(citizen[i].get_number());
		citizens[i].set_family(citizen[i].get_family());
	}
}

CitizenList::CitizenList(Citizen citizen[], int count,float) {
	Count = count;
	for (int i(0); i < count; ++i) {
		citizens[i].set_type(citizen[i].get_type());
		citizens[i].set_name(citizen[i].get_name());
		citizens[i].set_org(citizen[i].get_org());
		citizens[i].set_number(citizen[i].get_number());
		citizens[i].set_rating(citizen[i].get_rating());
	}
}

CitizenList::CitizenList(Citizen citizen[], int count, int) {
	Count = count;
	for (int i(0); i < count; ++i) {
		citizens[i].set_type(citizen[i].get_type());
		citizens[i].set_name(citizen[i].get_name());
		citizens[i].set_snils(citizen[i].get_snils());
		citizens[i].set_exp(citizen[i].get_exp());
	}
}


void CitizenList::insert_citizen(int index, Citizen citizen) {
	if (Count == CAPACITY){
		throw std::runtime_error("The data array is full.");
	}
	if (index < 0 || index >= Count){
		throw std::runtime_error("Index out of range.");
	}
	for (int i = Count - 1; i >= index; --i) { 
		citizens[i] = citizens[i - 1]; 
	}
	citizens[index] = citizen;
	++Count;
};

void CitizenList::add_citizen(Citizen citizen) {
	if (Count == CAPACITY) {
		throw std::runtime_error("The data array is full.");
	}
	citizens[Count] = citizen;
	++Count;
};

void CitizenList::delete_citizen(int index)
{
	if (Count <= 0)
	{
		throw std::runtime_error("List of Citizen is empty.");
	}
	if (index > Count) {
		throw std::runtime_error("Not enough items in container");
	}
	for (int i = index; i < Count - 1; ++i)
	{
		citizens[i] = citizens[i + 1];
	}
	--Count;
}

int CitizenList::get_count() {
	return Count;
};

void CitizenList::set_count(int count) {
	Count = count;
};

Citizen CitizenList::get_citizen(int index) {
	return citizens[index];
};

void CitizenList::set_citizen(int index, Citizen c) {
	citizens[index] = c;
}

Citizen& CitizenList::operator[](int index)
{
	if (index < 0 || index >= Count)
	{
		throw std::runtime_error("Index out of range.");
	}
	return citizens[index];
};
