#include <gtest/gtest.h>

#include <citizen/citizen.h>

using namespace std;
using namespace CitizenNamespace;


TEST(CitizenTests, Test1) {
    const auto c1 = make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true);
    const auto c2 = make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, false);

    EXPECT_EQ(c1->calculate_payment(), 8121);
    EXPECT_EQ(c2->calculate_payment(), 0);
}

TEST(CitizenTests, Test2) {
    const auto c1 = make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f);
    const auto c2 = make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 2.5f);

    EXPECT_EQ(c1->calculate_payment(), 11369.4f);
    EXPECT_EQ(c2->calculate_payment(), 0);
}

TEST(CitizenTests, Test3) {
    const auto c1 = make_shared<CitizenOldman>("ִלטענטי", 345346, 30);
    const auto c2 = make_shared<CitizenOldman>("ִלטענטי", 345346, 20);
    const auto c3 = make_shared<CitizenOldman>("ִלטענטי", 345346, 4);

    EXPECT_EQ(c1->calculate_payment(), 64968);
    EXPECT_EQ(c2->calculate_payment(), 45477.6f);
    EXPECT_EQ(c3->calculate_payment(), 0);
}

TEST(CitizenTests, Test4) {
    const auto c1 = make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true);
    const auto c2 = make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true);
    const auto c3 = make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, false);

    EXPECT_TRUE(c1->equals(c2));
    EXPECT_FALSE(c1->equals(c3));
}

TEST(CitizenTests, Test5) {
    const auto c1 = make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f);
    const auto c2 = make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f);
    const auto c3 = make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 2.5f);

    EXPECT_TRUE(c1->equals(c2));
    EXPECT_FALSE(c1->equals(c3));
}

TEST(CitizenTests, Test6) {
    const auto c1 = make_shared<CitizenOldman>("ִלטענטי", 345346, 20);
    const auto c2 = make_shared<CitizenOldman>("ִלטענטי", 345346, 20);
    const auto c3 = make_shared<CitizenOldman>("ִלטענטי", 345346, 4);

    EXPECT_TRUE(c1->equals(c2));
    EXPECT_FALSE(c1->equals(c3));
}

TEST(CitizenTests, Test7) {
    const auto c1 = make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f);

    EXPECT_EQ(c1->get_name(), "ִלטענטי");
    EXPECT_EQ(c1->get_org(), "ֱּ־׃ׁ־״");
    EXPECT_EQ(c1->get_num(), 12434);
    EXPECT_EQ(c1->get_rating(), 4.5f);
}

TEST(CitizenTests, Test8) {
    const auto c1 = make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true);

    EXPECT_EQ(c1->get_name(), "ִלטענטי");
    EXPECT_EQ(c1->get_org(), "ֱּ־׃ׁ־״");
    EXPECT_EQ(c1->get_num(), 12434);
    EXPECT_EQ(c1->get_lf(), true);
}

TEST(CitizenTests, Test9) {
    const auto c1 = make_shared<CitizenOldman>("ִלטענטי", 345346, 20);

    EXPECT_EQ(c1->get_name(), "ִלטענטי");
    EXPECT_EQ(c1->get_snils(), 345346);
    EXPECT_EQ(c1->get_exp(), 20);
}



TEST(CitizenListTests, Test1) {
    CitizenList citizens;

    const auto index = index_of_max_value(citizens);

    ASSERT_EQ(index, -1);
}

TEST(CitizenListTests, Test2) {
    CitizenList citizens;
    citizens.add(make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true));
    citizens.add(make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f));
    citizens.add(make_shared<CitizenOldman>("ִלטענטי", 345346, 20));

    const auto index = index_of_max_value(citizens);
    const auto n = citizens.size();

    ASSERT_EQ(n, 3);
    ASSERT_EQ(index, 2);
}

TEST(CitizenListTests, Test3) {
    CitizenList citizens;
    citizens.add(make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true));
    citizens.add(make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f));
    citizens.insert(make_shared<CitizenOldman>("ִלטענטי", 345346, 20), 1);

    const auto index = index_of_max_value(citizens);
    const auto n = citizens.size();

    ASSERT_EQ(n, 3);
    ASSERT_EQ(index, 1);

}

TEST(CitizenListTests, Test4) {
    CitizenList citizens;
    citizens.add(make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true));
    citizens.add(make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f));
    citizens.set(make_shared<CitizenOldman>("ִלטענטי", 345346, 20), 1);

    const auto index = index_of_max_value(citizens);
    const auto n = citizens.size();

    ASSERT_EQ(n, 2);
    ASSERT_EQ(index, 1);
}

TEST(CitizenListTests, Test5) {
    CitizenList citizens;
    citizens.add(make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true));
    citizens.add(make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f));
    citizens.remove(1);

    const auto n = citizens.size();

    ASSERT_EQ(n, 1);
}

TEST(CitizenListTests, Test6) {
    CitizenList citizens;
    citizens.add(make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true));
    citizens.add(make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f));
    citizens.add(make_shared<CitizenOldman>("ִלטענטי", 345346, 20));

    CitizenList citizens_1;
    citizens_1 = citizens;

    const auto n = citizens_1.size();

    ASSERT_EQ(n, 3);
}

TEST(CitizenListTests, Test7) {
    CitizenList citizens;
    citizens.add(make_shared<CitizenKid>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, true));
    citizens.add(make_shared<CitizenStudent>("ִלטענטי", "ֱּ־׃ׁ־״", 12434, 4.5f));
    citizens.add(make_shared<CitizenOldman>("ִלטענטי", 345346, 20));

    citizens.show();
}




