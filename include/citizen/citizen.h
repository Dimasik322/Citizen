#pragma once

#include <stdexcept>
#include <memory>
#include <vector>

namespace CitizenNamespace {
	float MROT = 16242;
	void set_mrot(float mrot);

	class Citizen;

	using CitizenPtr = std::shared_ptr<Citizen>;

	class Citizen {
	public:
		virtual float calculate_payment() const = 0;
		virtual void print_citizen() const = 0;

		virtual CitizenPtr clone() const = 0;
		virtual bool equals(CitizenPtr other) const = 0;

		virtual ~Citizen() = default;

	protected:
		Citizen() = default;
		Citizen(const Citizen&) = default;
		Citizen& operator=(const Citizen&) = default;
	};

	class CitizenKid : public Citizen {
	private:
		std::string Name;
		std::string Organization;
		int Number;
		bool LargeFamily;

	public:
		CitizenKid(std::string name, std::string org, int num, bool lf);
		std::string get_name() const;
		std::string get_org() const;
		int get_num() const;
		bool get_lf() const;

		float calculate_payment() const override;
		void print_citizen() const override;
		CitizenPtr clone() const override;
		bool equals(CitizenPtr other) const override;
	};

	class CitizenStudent : public Citizen {

	private:
		std::string Name;
		std::string Organization;
		int Number;
		float AveRating;

	public:
		CitizenStudent(std::string name, std::string org, int num, float ar);
		std::string get_name() const;
		std::string get_org() const;
		int get_num() const;
		float get_rating() const;

		float calculate_payment() const override;
		void print_citizen() const override;
		CitizenPtr clone() const override;
		bool equals(CitizenPtr other) const override;
	};

	class CitizenOldman : public Citizen {

	private:
		std::string Name;
		int Snils;
		int Exp;

	public:
		CitizenOldman(std::string name, int snils, int exp);
		std::string get_name() const;
		int get_snils() const;
		int get_exp() const;

		float calculate_payment() const override;
		void print_citizen() const override;
		CitizenPtr clone() const override;
		bool equals(CitizenPtr other) const override;
	};

	class CitizenList {
	private:
		std::vector<CitizenPtr> citizens;

	public:
		CitizenList() = default;

		CitizenList(const CitizenList& other);

		CitizenList& operator=(const CitizenList& rhs);

		int size() const;

		CitizenPtr operator[](int index) const;

		void add(CitizenPtr c);
		void insert(CitizenPtr c, int index);
		void set(CitizenPtr c, int index);
		void remove(int index);

		void show();
		void swap(CitizenList& other);
	};

	int index_of_max_value(const CitizenList& citizens);
}