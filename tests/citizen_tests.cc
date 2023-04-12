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
    setlocale(LC_ALL, "ru");
    const auto c1 = Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true);
    EXPECT_EQ(c1->calculate_payment(), 8121);
    delete c1;
}

TEST(CitizenTests, CitizenTest3) {
    setlocale(LC_ALL, "ru");
    const auto c1 = Citizen::create_oldman("Maxim", 45345, 28);
    EXPECT_EQ(c1->calculate_payment(), 61069.92f);
    delete c1;
}

TEST(CitizenTests, CitizenTest4) {
    setlocale(LC_ALL, "ru");
    const auto c1 = Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true);
    const auto c2 = Citizen::create_oldman("Maxim", 45345, 28);
    EXPECT_EQ(c1 == c2, false);
    delete c1;
    delete c2;
}

TEST(CitizenTests, CitizenTest5) {
    CitizenList citizens;
    EXPECT_EQ(citizens.size(), 0);
}

TEST(CitizenTests, CitizenTest6) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    EXPECT_EQ(citizens.size(), 1);
}

TEST(CitizenTests, CitizenTest7) {
    CitizenList citizens;
    citizens.insert(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f), 0);
    EXPECT_EQ(citizens.size(), 1);
}

TEST(CitizenTests, CitizenTest8) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    citizens.delete_citizen(0);
    EXPECT_EQ(citizens.size(), 0);
}

TEST(CitizenTests, CitizenTest9) {
    CitizenList citizens1;
    CitizenList citizens2;
    citizens1.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    citizens2.add(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true));
    citizens2.add(Citizen::create_oldman("Maxim", 45345, 28));
    citizens2.swap(citizens1);
    EXPECT_EQ(citizens2.size(), 1);
}

TEST(CitizenTests, CitizenTest10) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    citizens.add(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true));
    citizens.add(Citizen::create_oldman("Maxim", 45345, 28));
    EXPECT_EQ(citizens.size(), 3);
}

TEST(CitizenTests, CitizenTest11) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    citizens.insert(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true), 0);
    citizens.insert(Citizen::create_oldman("Maxim", 45345, 28), 1);
    EXPECT_EQ(citizens.size(), 3);
}

TEST(CitizenTests, CitizenTest12) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.5f));
    citizens.insert(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true), 0);
    citizens.insert(Citizen::create_oldman("Maxim", 45345, 28), 1);
    citizens.delete_citizen(1);
    EXPECT_EQ(citizens.size(), 2);
}

TEST(CitizenTests, CitizenTest13) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 2.4f));
    citizens.insert(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true), 0);
    citizens.insert(Citizen::create_oldman("Maxim", 45345, 28), 1);
    citizens.show();
    EXPECT_EQ(citizens.size(), 3);
}

TEST(CitizenTests, CitizenTest14) {
    CitizenList citizens;
    citizens.add(Citizen::create_student("Dmitrii", "люнс тлк ╧38", 3421, 4.8f));
    citizens.insert(Citizen::create_kid("Ivan", "ланс янь ╧322", 45345, true), 0);
    citizens.insert(Citizen::create_oldman("Maxim", 45345, 28), 1);
    EXPECT_EQ(citizens.max_value(), 61069.92f);
}
