#include <cassert>
#include <iostream>
#include "Stack.hpp"

void Test_stack_preload() {
  int data_length = 99;
  int data[99];

  for(int i=0; i<data_length; i++) {
    data[i] = i;
  }

  Stack s(data, data_length);
  int* stack = s.stack();
  assert(stack != nullptr);
  
  for(int i=0; i<data_length; i++) {
    assert(stack[i] == data[i]);
  }

  std::cout << "Test_stack_preload: PASSED" << std::endl;
}

void Test_stack_push() {
  Stack s;

  int data_length = 99;
  int data[99];

  for(int i=0; i<data_length; i++) {
    data[i] = i;
  }

  for(int i=0; i<data_length; i++) {
    s.push(data[i]);
  }

  int* stack = s.stack();

  for(int i=0; i<data_length; i++) {
    assert(stack[i] == data[i]);
  }

  std::cout<<"Test_stack_push: PASSED" << std::endl;
}

void Test_stack_pop() {
  int data_length = 99;
  int data[99];

  for(int i=0; i<data_length; i++) {
    data[i] = i;
  }

  Stack s(data, data_length);
  int og_stack_size = s.size();

  for(int i=0; i<data_length; i++) {
    s.pop();
  }
  assert(s.size() == 0); 
  assert(s.size() != og_stack_size); 

  std::cout << "Test_stack_pop: PASSED" << std::endl;
}

void Test_stack_clear() {
  int data_length = 99;
  int data[99];

  for(int i=0; i<data_length; i++) {
    data[i] = i;
  }

  Stack s(data, data_length);
  int og_stack_size = s.size();

  s.clear(); 
  
  assert(s.size() == 0); 
  assert(s.size() != og_stack_size); 

  std::cout << "Test_stack_clear: PASSED" << std::endl;
}

// master test suite
void Test_stack() {
  Test_stack_pop();
  Test_stack_push();
  Test_stack_pop();
  Test_stack_clear();
}
