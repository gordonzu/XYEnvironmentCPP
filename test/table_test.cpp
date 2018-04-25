//
// Created by gordonzu on 4/4/18.
//

#include "gmock/gmock.h"
#include "util/datastructure/table.h"
#include "util/datastructure/table.cpp"

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
        t = Table<std::string, std::string, int>{row_headers, col_headers};
   	}

    Table<std::string, std::string, int> t;
    std::vector<std::string> row_headers;
    std::vector<std::string> col_headers;
};

TEST_F(TableTest, testTableSize)
{
	ASSERT_EQ(t.map_size(), unsigned(3));
}

TEST_F(TableTest, testTableInitialize)
{
    int n = 0;
    int y = 50;

    auto b = t.get_values("gordonzu", "iq", n);
    ASSERT_FALSE(b);
    ASSERT_EQ(n, 0);

    t.set_values("gordonzu", "iq", y);
    auto x = t.get_values("gordonzu", "iq",n);
    ASSERT_TRUE(x);
    ASSERT_EQ(n, y);
}














