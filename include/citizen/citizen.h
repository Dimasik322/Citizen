#pragma once

#include <stdexcept>

using namespace std;

namespace CitizenNamespace {
	const float MROT = 16242;

	enum Type {
		Kid,
		Student,
		Oldman
	};

	class Citizen;

	using CitizenPtr = Citizen*;

	class Citizen {

	private:
		Type _type;
		string Name;
		string Organization;
		int Number;
		int SNILS;
		float AveRating;
		int Exp;
		bool LargeFamily;
		float Payment;

	public:
		Citizen(Type type, string Name, string Organization, int Number, bool LargeFamily);
		Citizen(Type type, string Name, string Organization, int Number, float AveRating);
		Citizen(Type type, string Name, int SNILS, int Exp);
		Citizen(Type type, string name, float payment);

		void set_type(Type type);
		void set_name(string name);
		void set_org(string org);
		void set_number(int number);
		void set_family(bool lf);
		void set_rating(float ar);
		void set_exp(int exp);
		void set_snils(int snils);
		void set_payment(float payment);

		float get_payment() const;
		string get_name() const;
		string get_org() const;
		int get_number() const;
		Type get_type() const;
		bool get_family() const;
		float get_rating() const;
		int get_snils() const;
		int get_exp() const;

		static CitizenPtr create_kid(string name, string org, int number, bool lf);
		static CitizenPtr create_student(string name, string org, int number, float ar);
		static CitizenPtr create_oldman(string name, int snils, int exp);
		float calculate_payment() const;

		//static CitizenPtr calculate_payment();

		CitizenPtr clone() const;
	};

	bool operator==(const Citizen& lhs, const Citizen& rhs);
	bool operator!=(const Citizen& lhs, const Citizen& rhs);

	class CitizenList {

	private:
		CitizenPtr* ptr;
		int _size;

	public:
		CitizenList();
		CitizenList(const CitizenList& other);

		int size() const;

		CitizenList& operator=(const CitizenList& rhs);
		CitizenPtr operator[](int index) const;

		void add(CitizenPtr c);
		void swap(CitizenList& other);

		~CitizenList();
	};

};

