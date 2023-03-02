#pragma once


namespace CitizenNamespace {
	const float MROT = 16242;
	const int strlenght = 255;
	const int CAPACITY = 10;

	enum Type {
		none = 0,
		Kid,
		Student,
		Oldman
	};

	class Citizen {

	private:
		Type type = Type::none;
		float AveRating = 0;
		int Exp = 0;
		bool LargeFamily = false;
		float Payment = 0;

	public:
		Citizen();
		Citizen(Type _type);
		Citizen(Type _type, float _payment);

		float get_payment();
		void calculate_payment();

	};

	class CitizenList {
	private:
		char Names[strlenght * 2];
		int Count = 0;

	public:
		Citizen citizens[CAPACITY];

		CitizenList();
		CitizenList(const char* name);

		int get_count();
		char* get_names();
		bool add_citizen(Type type, float payment);
	};

};
