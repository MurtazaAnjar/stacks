#include "DishStack.h"

// Constructor
DishStack::DishStack() {
    top_index = -1;
}

// Push operation
bool DishStack::push(const Dish& dish) {
    if (is_full()) {
        cout << "Stack is full. Cannot push new item." << endl;
        return false;
    }

    // Store a copy on the heap because Dish has no default constructor
    items[++top_index] = new Dish(dish);
    return true;
}

// Pop operation
Dish DishStack::pop() {
    if (is_empty()) {
        cout << "Stack is empty. Returning a placeholder Dish." << endl;
        return Dish("EMPTY");
    }

    Dish popped = *(items[top_index]);
    delete items[top_index];
    top_index--;
    return popped;
}

// Peek operation
Dish DishStack::peek() const {
    if (is_empty()) {
        cout << "Stack is empty. Returning a placeholder Dish." << endl;
        return Dish("EMPTY");
    }
    return *(items[top_index]);
}

// Size
int DishStack::size() const {
    return top_index + 1;
}

bool DishStack::is_empty() const {
    return top_index == -1;
}

bool DishStack::is_full() const {
    return top_index == MAX_SIZE - 1;
}
