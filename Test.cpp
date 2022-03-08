//
// Created by rivka on 06/03/2022.
//
#include "doctest.h"
#include "mat.hpp"
#include <string>

using namespace ariel;
using namespace std;

#include <algorithm>
using namespace std;
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}
TEST_CASE("even mat size") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(2, 2, '$', '%'));
    CHECK_THROWS(mat(8, 5, '$', '%'));
    CHECK_THROWS(mat(3, 10, '$', '%'));
    CHECK_THROWS(mat(20, 30, '$', '%'));
    CHECK_THROWS(mat(1000, 5, '@', '%'));
}

TEST_CASE("zero inputs") {
    CHECK_THROWS(mat(0, 0, '$', '%'));
    CHECK_THROWS(mat(2, 0, '$', '%'));
    CHECK_THROWS(mat(0, 5, '$', '%'));
    CHECK_THROWS(mat(0, 100, '$', '%'));

}

TEST_CASE("Negative inputs") {
    CHECK_THROWS(mat(-1, 5, '$', '%'));
    CHECK_THROWS(mat(-1, -3, '$', '%'));
    CHECK_THROWS(mat(-2, 0, '$', '%'));
    CHECK_THROWS(mat(3, -3, '$', '%'));
}

TEST_CASE("Good input") {
CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                                                      "@-------@\n"
                                                                                      "@-@@@@@-@\n"
                                                                                      "@-@---@-@\n"
                                                                                      "@-@@@@@-@\n"
                                                                                      "@-------@\n"
                                                                                      "@@@@@@@@@"));
CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                                                       "@-----------@\n"
                                                                                       "@-@@@@@@@@@-@\n"
                                                                                       "@-----------@\n"
                                                                                       "@@@@@@@@@@@@@"));
CHECK(nospaces(mat(5, 13, '$', '-')) == nospaces("$$$$$\n"
                                                                                       "$---$\n"
                                                                                       "$-$-$\n"
                                                                                       "$-$-$\n"
                                                                                       "$-$-$\n"
                                                                                       "$-$-$\n"
                                                                                       "$-$-$\n"
                                                                                       "$-$-$\n"
                                                                                       "$-$-$\n"
                                                                                       "$-$-$\n"
                                                                                       "$-$-$\n"
                                                                                       "$---$\n"
                                                                                       "$$$$$"));
CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
                                                                                      "$+$\n"
                                                                                      "$+$\n"
                                                                                      "$+$\n"
                                                                                      "$$$"));
CHECK(nospaces(mat(5, 5, '$', '+')) == nospaces("$$$$$\n"
                                                                                      "$+++$\n"
                                                                                      "$+$+$\n"
                                                                                      "$+++$\n"
                                                                                      "$$$$$"));
CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#"));
CHECK(nospaces(mat(1, 5, '#', ')')) == nospaces("#####"));


}
