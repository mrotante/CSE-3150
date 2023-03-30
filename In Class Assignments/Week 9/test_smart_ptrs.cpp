#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "smart_pointers.h"

TEST_CASE("Linked list with smart pointers") {
    SUBCASE("basic linked list") {
        List list;
        list.push(1);
        list.push(2);
        list.push(3);

        CHECK(list.head->data == 3);
        CHECK(list.head->next->data == 2);
        CHECK(list.head->next->next->data == 1); 
    };

    SUBCASE("empty list") {
        List list2;
        CHECK(list2.head == nullptr);
    };

    SUBCASE("large list") {
        List list3;
        for(int i = 0; i < 100; i++) {
            list3.push(i);
            CHECK(list3.head->data == i);
        }
    }
}