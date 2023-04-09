#include <gtest/gtest.h>

#include <citizen/citizen.h>

using namespace std;
using namespace CitizenNamespace;

TEST(CitizenTests, CitizenTest1) {
    setlocale(LC_ALL, "ru");
    const auto c1 = Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f);
    EXPECT_EQ(c1->calculate_payment(), 11369.4f);
    delete c1;
}

TEST(CitizenTests, CitizenTest2) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    citizens.add(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true));
    citizens.add(Citizen::create_oldman("Maxim", 45345, 28));
    EXPECT_EQ(citizens.size(), 3);
}

TEST(CitizenTests, CitizenTest3) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    citizens.insert(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true), 0);
    citizens.insert(Citizen::create_oldman("Maxim", 45345, 28), 1);
    EXPECT_EQ(citizens.size(), 3);
}

TEST(CitizenTests, CitizenTest4) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    citizens.insert(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true), 0);
    citizens.insert(Citizen::create_oldman("Maxim", 45345, 28), 1);
    citizens.delete_citizen(1);
    EXPECT_EQ(citizens.size(), 2);
}

TEST(CitizenTests, CitizenTest5) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    citizens.insert(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true), 0);
    citizens.insert(Citizen::create_oldman("Maxim", 45345, 28), 1);
    citizens.show();
    EXPECT_EQ(citizens.size(), 3);
}
