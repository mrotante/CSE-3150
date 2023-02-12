#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "data_structs.h"

#include <queue>
#include <stack>
#include <string>


TEST_CASE("Testing stack/queue functions") {
    SUBCASE("stack") {
        stack<int> stack1 = stack_push("data/1.txt");
        CHECK(stack1.top() == 5);

        stack<int> stack2 = stack_push("data/2.txt");
        CHECK(stack2.top() == 2);

        stack<int> stack3 = stack_push("data/3.txt");
        CHECK(stack3.top() == 0);

        stack<int> stack4 = stack_push("data/4.txt");
        CHECK(stack4.top() == 0);

        stack1.pop();
        stack3.pop();
        stack4.pop();

        try {
            stack2.pop();
        } catch(invalid_argument e) {
            cout << e.what() << endl;
        }
    };

    SUBCASE("queue") {
        queue<int> queue1 = queue_push("data/1.txt");
        CHECK(queue1.front() == 12);

        queue<int> queue2 = queue_push("data/2.txt");
        CHECK(queue2.front() == 1);

        queue<int> queue3 = queue_push("data/3.txt");
        CHECK(queue3.front() == 19);

        queue<int> queue4 = queue_push("data/4.txt");
        CHECK(queue4.front() == 0);

        queue1.pop();
        queue3.pop();
        queue4.pop();

        try {
            queue2.pop();
        } catch(invalid_argument e) {
            cout << e.what() << endl;
        }
    };
}