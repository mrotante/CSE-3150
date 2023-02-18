#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"


TEST_CASE("Testing linked list functions") {
    SUBCASE("Build linked list") {
        CHECK(build_linked_list(0) == NULL);
        struct node* linked_list1 = build_linked_list(15);
        CHECK(linked_list1->number == 0);
        CHECK(linked_list1->next->number == 1);

        delete_linked_list(linked_list1, 15);

    };

    SUBCASE("Delete linked list") {
        struct node* linked_list2 = build_linked_list(10);
        CHECK(delete_linked_list(linked_list2, 10) == 10);

        struct node* linked_list3 = build_linked_list(1);
        CHECK(delete_linked_list(linked_list3, 1) == 1);
        
        struct node* linked_list4 = build_linked_list(0);
        CHECK(delete_linked_list(linked_list4, 0) == 0);
    };

    SUBCASE("Sum values") {
        struct node* linked_list5 = build_linked_list(11);
        CHECK(sum_values_in_linked_list(linked_list5, 11) == 55);
        
        struct node* linked_list6 = build_linked_list(0);
        CHECK(sum_values_in_linked_list(linked_list6, 0) == 0);

        struct node* linked_list7 = build_linked_list(1);
        CHECK(sum_values_in_linked_list(linked_list7, 1) == 0);

        delete_linked_list(linked_list5, 11);
        delete_linked_list(linked_list6, 0);
        delete_linked_list(linked_list7, 1);
    };
}