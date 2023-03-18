#pragma once
#include <string>
#include <stdexcept>

using namespace std;

namespace CitizenNamespace {
	//const float MROT = 16242;
	//const int strlenght = 255;
	const int CAPACITY = 10;

	enum Type {
		Kid,
		Student,
		Oldman
	};

	class Citizen {

	private:
		Type type;
		string Name;
		string Organization;
		int Number;
		int SNILS;
		float AveRating;
		int Exp;
		bool LargeFamily;
		float Payment;

	public:
		int MROT;

		Citizen();
		Citizen(Type type, string Name, string Organization, int Number, bool LargeFamily);
		Citizen(Type type, string Name, string Organization, int Number, float AveRating);
		Citizen(Type type, string Name, int SNILS, int Exp);

		void set_type(Type type);
		void set_name(string name);
		void set_org(string org);
		void set_number(int number);
		void set_family(bool lf);
		void set_rating(float ar);
		void set_exp(int exp);
		void set_snils(int snils);
		void set_payment(float payment);
		void set_mrot(int mrot);

		float get_payment();
		string get_name();
		string get_org();
		int get_number();
		Type get_type();
		bool get_family();
		float get_rating();
		int get_snils();
		int get_exp();
		int get_mrot();

		void calculate_payment();
	};

	class CitizenList {
	private:
		int Count = 0;
		Citizen citizens[CAPACITY];

	public:
		CitizenList();
		//CitizenList(const char* name);
		CitizenList(Citizen citizen[], int count);
		CitizenList(Citizen citizen[], int count, float);
		CitizenList(Citizen citizen[], int count, int);

		Citizen get_citizen(int index);
		int get_count();
		void set_count(int count);

		void set_citizen(int index ,Citizen c);
		void add_citizen(Citizen c);
		void insert_citizen(int index, Citizen c);
		void delete_citizen(int index);

		Citizen& operator[](int index);
	};

};
