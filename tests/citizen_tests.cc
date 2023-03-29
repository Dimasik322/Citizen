#include <gtest/gtest.h>

#include <citizen/citizen.h>

#include <string>

using namespace std;
using namespace CitizenNamespace;

TEST(CitizenTests, CitizenTest1) {
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Kid, "Ivan", "ланс янь ╧322", 45345, true);
    c1.set_mrot(16242);
    EXPECT_EQ(c1.get_name(), "Ivan");
    EXPECT_EQ(c1.get_org(), "ланс янь ╧322");
    EXPECT_EQ(c1.get_family(), true);
}

TEST(CitizenTests, CitizenTest2) {
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Student, "Dmitrii", "люнс тлк ╧38", 3421, 4.5f);
    c1.set_mrot(16242);
    EXPECT_EQ(c1.get_name(), "Dmitrii");
    EXPECT_EQ(c1.get_org(), "люнс тлк ╧38");
    EXPECT_EQ(c1.get_rating(), 4.5f);
}

TEST(CitizenTests, CitizenTest3) {
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Oldman, "Maxim", 45345, 28);
    c1.set_mrot(16242);
    EXPECT_EQ(c1.get_name(), "Maxim");
    EXPECT_EQ(c1.get_snils(), 45345);
    EXPECT_EQ(c1.get_exp(), 28);
}

TEST(CitizenTests, CitizenTest4) {
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Kid, "Ivan", "ланс янь ╧322", 45345, true);
    c1.set_mrot(16242);
    c1.calculate_payment();
    EXPECT_EQ(c1.get_payment(), 8121);
}

TEST(CitizenTests, CitizenTest5) {
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Student, "Dmitrii", "люнс тлк ╧38", 3421, 4.5f);
    c1.set_mrot(16242);
    c1.calculate_payment();
    EXPECT_EQ(c1.get_payment(), 11369.4f);
}

TEST(CitizenTests, CitizenTest6) {
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Oldman, "Maxim", 45345, 4);
    c1.set_mrot(16242);
    c1.calculate_payment();
    EXPECT_EQ(c1.get_payment(), 0);
}

TEST(CitizenTests, CitizenTest7) {
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Kid, "Ivan", "ланс янь ╧322", 45345, false);
    c1.set_mrot(16242);
    c1.calculate_payment();
    EXPECT_EQ(c1.get_payment(), 0);
}

TEST(CitizenTests, CitizenTest8) {
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Student, "Dmitrii", "люнс тлк ╧38", 3421, 3.0f);
    c1.set_mrot(16242);
    c1.calculate_payment();
    EXPECT_EQ(c1.get_payment(), 0);
}

TEST(CitizenTests, CitizenTest9) {
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Oldman, "Maxim", 45345, 28);
    c1.set_mrot(16242);
    c1.calculate_payment();
    EXPECT_EQ(c1.get_payment(), 61069.92f);
}

TEST(CitizenTests, CitizenT1est10)
{
    setlocale(LC_ALL, "ru");

    Citizen citizens[CAPACITY];
    citizens[0] = Citizen(Kid, "Ivan", "ланс янь ╧322", 45345, true);
    citizens[1] = Citizen(Student, "Dmitrii", "люнс тлк ╧38", 3421, 4.5f);
    citizens[2] = Citizen(Oldman, "Maxim", 45345, 28);
    CitizenList List = CitizenList(citizens, 3);
    EXPECT_EQ(List.get_count(), 3);
    EXPECT_EQ(List[0].get_type(), Kid);
    EXPECT_EQ(List[1].get_type(), Student);
    EXPECT_EQ(List[2].get_type(), Oldman);
}

TEST(CitizenTests, CitizenTest11)
{
    CitizenList List = CitizenList();
    Citizen c2 = Citizen(Student, "Dmitrii", "люнс тлк ╧38", 3421, 4.5f);
    c2.set_mrot(16242);
    c2.calculate_payment();
    List.insert_citizen(2, c2);
    EXPECT_EQ(List[2].get_name(), "Dmitrii");
    EXPECT_EQ(List[2].get_payment(), 11369.4f);
}

TEST(CitizenTests, CitizenTest12)
{
    CitizenList List = CitizenList();
    Citizen c2 = Citizen(Student, "Dmitrii", "люнс тлк ╧38", 3421, 4.5f);
    List.insert_citizen(2, c2);
    EXPECT_EQ(List[2].get_name(), "Dmitrii");
    List.delete_citizen(2);
    EXPECT_EQ(List[2].get_name(), "");
}

TEST(CitizenTests, CitizenTest13)
{
    setlocale(LC_ALL, "ru");
    Citizen c1 = Citizen(Oldman, "Maxim", 45345, 28);
    c1.set_mrot(16242);
    EXPECT_EQ(c1.get_mrot(), 16242);
}

TEST(CitizenTests, CitizenTest14)
{
    CitizenList List = CitizenList();
    Citizen c2 = Citizen(Student, "Dmitrii", "люнс тлк ╧38", 3421, 4.5f);
    List.set_citizen(2, c2);
    EXPECT_EQ(List[2].get_name(), "Dmitrii");
}