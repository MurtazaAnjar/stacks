#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/dish.h"
#include "../src/dishStack.h"

TEST_CASE("DishStack initializes empty") {
    DishStack stack;
    REQUIRE(stack.size() == 0);
}

TEST_CASE("Push increases size and top is correct") {
    DishStack stack;

    Dish d1("One");
    Dish d2("Two");

    stack.push(d1);
    REQUIRE(stack.size() == 1);
    REQUIRE(stack.peek().get_description() == "One");

    stack.push(d2);
    REQUIRE(stack.size() == 2);
    REQUIRE(stack.peek().get_description() == "Two");
}

TEST_CASE("Pop returns items in LIFO order") {
    DishStack stack;

    Dish d1("Red");
    Dish d2("Blue");
    Dish d3("Green");

    stack.push(d1);
    stack.push(d2);
    stack.push(d3);

    REQUIRE(stack.size() == 3);

    Dish popped1 = stack.pop();
    REQUIRE(popped1.get_description() == "Green");
    REQUIRE(stack.size() == 2);

    Dish popped2 = stack.pop();
    REQUIRE(popped2.get_description() == "Blue");
    REQUIRE(stack.size() == 1);
}

TEST_CASE("Peek does not remove element") {
    DishStack stack;

    Dish d1("TopDish");
    stack.push(d1);

    Dish peeked = stack.peek();
    REQUIRE(peeked.get_description() == "TopDish");
    REQUIRE(stack.size() == 1);
}

TEST_CASE("Pop on empty stack returns placeholder") {
    DishStack stack;

    Dish popped = stack.pop();
    REQUIRE(popped.get_description() == "EMPTY");
    REQUIRE(stack.size() == 0);
}

TEST_CASE("Peek on empty stack returns placeholder") {
    DishStack stack;

    Dish peeked = stack.peek();
    REQUIRE(peeked.get_description() == "EMPTY");
    REQUIRE(stack.size() == 0);
}

TEST_CASE("Push fails gracefully when stack is full") {
    DishStack stack;

    // Fill stack manually to MAX_SIZE
    for (int i = 0; i < 100; i++) {
        stack.push(Dish("Dish #" + std::to_string(i)));
    }

    REQUIRE(stack.size() == 100);

    // Attempt to push one more
    bool result = stack.push(Dish("Overflow Dish"));
    REQUIRE(result == false);  // push should fail

    // Size should remain unchanged
    REQUIRE(stack.size() == 100);

    // Top should still be the last valid dish
    REQUIRE(stack.peek().get_description() == "Dish #99");
}