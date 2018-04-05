//
// Created by gordonzu on 4/4/18.
//

#include "gmock/gmock.h"
#include "table.h"
#include "table.cpp"

using namespace::testing;

class TableTest: public Test {
public:
    void SetUp() override {
        row_headers.emplace_back("row1");
        row_headers.emplace_back("gordonzu");
        row_headers.emplace_back("diana");
        col_headers.emplace_back("col1");
        col_headers.emplace_back("iq");
        col_headers.emplace_back("age");
        t = Table<int>{row_headers, col_headers};
   	}

    Table<int> t;
    std::vector<std::string> row_headers;
    std::vector<std::string> col_headers;
};

TEST_F(TableTest, testTableSize) {
	ASSERT_EQ(t.map_size(), unsigned(3));
}

TEST_F(TableTest, testTableInitialize) {
    ASSERT_EQ(t.get_values("gordonzu", "iq"), nullptr);

    t.set_values("gordonzu", "iq", 50);
    auto x = t.get_values("gordonzu", "iq");
    if (x) {
        ASSERT_EQ(*x, 50);
    } else {
        ASSERT_TRUE(false);
    }
}

TEST_F(TableTest, testNullAccess) {
    ASSERT_EQ(t.get_values("row1", "col2"), nullptr);

    t.set_values("row1", "col2", 1);
    int* x = t.get_values("row1", "col2");

    if (x) {
        ASSERT_EQ(*(t.get_values("row1", "col2")), 1);
    } else {
        ASSERT_TRUE(false);
    }
}

TEST_F(TableTest, testTalk) {
    ASSERT_STREQ(t.talk(), "Hello Table.");
}














