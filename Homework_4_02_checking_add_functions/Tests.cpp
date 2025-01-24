#include <catch2/catch_test_macros.hpp>
#include "my_list.h"

TEST_CASE("Testing PushBack and PushFront") {
    List list;

    REQUIRE(list.Empty());

    list.PushBack(10);
    REQUIRE(list.Size() == 1);

    list.PushFront(5);
    REQUIRE(list.Size() == 2);

    REQUIRE(list.PopFront() == 5);
    REQUIRE(list.PopBack() == 10);

    REQUIRE(list.Empty());
}

TEST_CASE("Testing PopBack on empty list") {
    List list;

    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
}

TEST_CASE("Testing PopFront on empty list") {
    List list;

    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}

TEST_CASE("Complex operations") {
    List list;

    list.PushBack(1);
    list.PushFront(2);
    list.PushBack(3);

    REQUIRE(list.Size() == 3);
    REQUIRE(list.PopFront() == 2);
    REQUIRE(list.Size() == 2);

    list.PushFront(4);
    list.PushBack(5);
    REQUIRE(list.Size() == 4);

    REQUIRE(list.PopBack() == 5);
    REQUIRE(list.PopBack() == 3);
    REQUIRE(list.PopFront() == 4);
    REQUIRE(list.PopFront() == 1);

    REQUIRE(list.Empty());
}