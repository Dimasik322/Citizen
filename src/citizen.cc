#include <citizen/citizen.h>

#include <exception>
#include <stdexcept>
#include <string.h>
#include <iostream>

using namespace CitizenNamespace;
using namespace std;

Citizen::Citizen(Type _type) {
	try {
		switch (_type) {
		case Type::Kid:
			type = Type::Kid;
			LargeFamily = false;
			break;
		case Type::Student:
			type = Type::Student;
			AveRating = 0;
			break;
		case Type::Oldman:
			type = Type::Oldman;
			Exp = 0;
			break;
		default:
			break;
		}
		if (type != _type) {
			throw runtime_error("Class type is invalid");
		}
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
}

Citizen::Citizen(Type _type, float payment) {
	type = _type;
	Payment = payment;
}

void Citizen::calculate_payment() {
	try {
		switch (type) {
		case Type::Kid:
			if ((this->LargeFamily) == true) {
				Payment = 0.5 * MROT;
			}
			else {
				Payment = 0;
			}
		case Type::Student:
			if ((this->AveRating) < 3.5) {
				Payment = 0;
			}
			else {
				Payment = (0.5 + 0.2 * ((this->AveRating) - 3.5)) * MROT;
			}
		case Type::Oldman:
			if (this->Exp < 5) {
				Payment = 0;
			}
			else if (this->Exp > 30) {
				Payment = 5 * MROT;
			}
			else {
				Payment = (1 + 0.12 * ((this->Exp) - 5)) * MROT;
			}
		default:
			throw runtime_error("Type of object is invalid");
			break;
		}
	}
	catch (const runtime_error& e)
	{
		cerr << e.what() << endl;
	}
};

float Citizen::get_payment() {
	return this->Payment;
}

CitizenList::CitizenList() {
	strcpy(Names, "-\0");
};

CitizenList::CitizenList(const char* name) {
	strcpy(Names, name);
};

char* CitizenList::get_names() {
	return this->Names;
};

bool CitizenList::add_citizen(Type type, float payment) {
	try
	{
		if (Count < CAPACITY) {
			if (type == Type::Kid && (payment<0 || payment>(MROT * 0.5))) {
				throw runtime_error("Payment for type 'Kid' is incorrect");
			}
			else if (type == Type::Student && (payment != 0 && !((0.5 * MROT) <= payment <= (0.8 * MROT)))) {
				throw runtime_error("Payment for type 'Student' is incorrect");
			}
			else if (type == Type::Oldman && (payment != 0 && !((1 * MROT) <= payment <= (5 * MROT)))) {
				throw runtime_error("Payment for type 'Oldman' is incorrect");
			}
			citizens[Count] = Citizen(type, payment);
			Count += 1;
			return true;
		}
		else {
			throw runtime_error("List is full");
		}
	}
	catch (const runtime_error& e)
	{
		cerr << e.what() << endl;
		return false;
	}
};
