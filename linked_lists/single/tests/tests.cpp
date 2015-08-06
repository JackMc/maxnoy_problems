#include "single.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Linked list insertion/deletion", "[singly]") {
    singly_linked_list<int> numbers;

    SECTION("inserting a new element") {
        int myInt = 1;
        numbers.insert(myInt, 0);
        REQUIRE(numbers[0] == 1);
    }

    SECTION("deleting an element") {
        int myInt = 1;
        numbers.insert(myInt, 0);
        REQUIRE(numbers[0] == 1);
        numbers.delete_item(myInt);
        REQUIRE(numbers.size() == 0);
    }
}
