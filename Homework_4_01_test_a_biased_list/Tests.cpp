#include <catch2/catch_test_macros.hpp>
#include "main.cpp"

TEST_CASE("List functionality", "[List]")
{
    List list;

    SECTION("Empty list should be empty")
    {
        REQUIRE(list.Empty());
        REQUIRE(list.Size() == 0);
    }

    SECTION("Adding elements updates size and emptiness")
    {
        list.PushBack(10);
        REQUIRE_FALSE(list.Empty());
        REQUIRE(list.Size() == 1);

        list.PushFront(20);
        REQUIRE(list.Size() == 2);
    }

    SECTION("Clear empties the list")
    {
        list.PushBack(10);
        list.PushFront(20);
        list.Clear();
        REQUIRE(list.Empty());
        REQUIRE(list.Size() == 0);
    }
}
