#ifndef DISHSTACK_H
#define DISHSTACK_H

#include <iostream>
#include "Dish.h"

using namespace std;

class DishStack {
private:
    static const int MAX_SIZE = 100;   // fixed capacity
    Dish* items[MAX_SIZE];             // array of pointers to Dishes
    int top_index;                     // index of the top element

public:
    DishStack();

    bool push(const Dish& dish);
    Dish pop();
    Dish peek() const;
    int size() const;
    bool is_empty() const;
    bool is_full() const;
};

#endif