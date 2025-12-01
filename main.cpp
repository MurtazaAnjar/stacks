#include <iostream>

#include "src/dish.h"
#include "src/dishStack.h"

using namespace std;

int main() {
  DishStack stack;
  Dish one_dish = Dish("A dish with one fish pattern on it");
  Dish two_dish = Dish("A dish with two fish patterns on it");
  Dish red_dish = Dish("A dish with a red fish pattern on it");
  Dish blue_dish = Dish("A dish with a blue fish pattern on it");

  // The variable stack_size should equal zero.
  int stack_size = stack.size();

  stack.push(one_dish);
  stack.push(two_dish);
  stack.push(red_dish);
  stack.push(blue_dish);

  // The variable size_after_pushes should equal four.
  int size_after_pushes = stack.size();
  cout << "Size after pushes: " << size_after_pushes << endl;

  // The variable peeked_dish should have a description of "A dish with a blue fish pattern on it"
  Dish peeked_dish = stack.peek();
  cout << "Peeked: " << peeked_dish.get_description() << endl;

  // The variable popped_dish should have a description of "A dish with a blue fish pattern on it"
  Dish popped_dish = stack.pop();
  cout << "Popped: " << popped_dish.get_description() << endl;

  // The variable another_popped_dish should have a description of "A dish with a red fish pattern on it"
  Dish another_popped_dish = stack.pop();
  cout << "Popped again: " << another_popped_dish.get_description() << endl;

  // The variable final_size should equal two.
  int final_size = stack.size();
  cout << "Final size: " << final_size << endl;
}
