#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

using namespace std;

TEST_CASE("Testing pointer jumping functions") {
    SUBCASE("Testing array of pointers function") {
        struct node* linked_list1 = build_linked_list(15);
        struct node* array1 = array_of_pointers(linked_list1, 15);
        for(int i = 0; i < 15; i++) {
            CHECK(array1[i].number == i);
        }

        struct node* linked_list2 = build_linked_list(0);
        struct node* array2 = array_of_pointers(linked_list2, 0);
        CHECK(array2 == NULL);
    };

    SUBCASE("Testing change_pointers function") {
        struct node* linked_list4 = build_linked_list(3);
        struct node* array4 = array_of_pointers(linked_list4, 3);
        change_pointers(array4, 3);
        CHECK(array4[0].next == array4[1].next);
        CHECK(array4[0].next == array4[2].next);

        struct node* linked_list5 = build_linked_list(15);
        struct node* array5 = array_of_pointers(linked_list5, 15);
        change_pointers(array5, 15);
        struct node* ptr = array5[0].next;
        for(int i = 0; i < 15; i++) {
            CHECK(array5[i].next == ptr);
        }
    };
}