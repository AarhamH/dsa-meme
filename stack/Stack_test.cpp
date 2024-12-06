#include <iostream>
#include "Stack.hpp"
#include <random>

int Test_stack_preload() {
  int data_length = 99;
  int data[99];

  for(int i=0; i<data_length; i++) {
    data[i] = i;
  }

  Stack s(data, data_length);
  int* stack = s.stack();
  if(stack == NULL) {
    std::cerr<<"Test_stack_preload: FAILED" << std::endl;
    std::cerr<<"Could not allocate stack"<< std::endl;
  }
  
  for(int i=0; i<data_length; i++) {
    if(stack[i] != data[i]) {
      std::cerr<<"Test_stack_preload: FAILED" << std::endl;
      std::cerr<<"Unexpected preloaded data: expected data: " << data[i] << " got data: " << stack[i] << std::endl;
      s.print_stack();
      return 1;
    }
  }

  std::cout << "Test_stack_preload: PASSED" << std::endl;
  return 0;
}

int Test_stack_push() {
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
    if(stack[i] != data[i]) {
      std::cerr<<"Test_stack_push: FAILED" << std::endl;
      std::cerr<<"Something failed when pushing: expected data: " << data[i] << " got data: " << stack[i] << std::endl;
      s.print_stack();
      return 1;
    }
  }

  std::cout<<"Test_stack_push: PASSED" << std::endl;
  return 0;
}

int Test_stack_pop() {
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
  
  if(s.size() != 0 && s.size() != og_stack_size) {
      std::cout<<"Test_stack_pop: FAILED";
      std::cerr<<"Something failed when popping: expected size: " << 0 << " got: " << s.size() << std::endl;
      s.print_stack();
      return 1;
  }

  std::cout << "Test_stack_pop: PASSED" << std::endl;
  return 0;
}

int Test_stack_clear() {
  int data_length = 99;
  int data[99];

  for(int i=0; i<data_length; i++) {
    data[i] = i;
  }

  Stack s(data, data_length);
  int og_stack_size = s.size();

  s.clear(); 
  
  if(s.size() != 0 && s.size() != og_stack_size) {
      std::cout<<"Test_stack_clear: FAILED";
      std::cerr<<"Something failed when clearing: expected size: " << 0 << " got: " << s.size() << std::endl;
      s.print_stack();
      return 1;
  }

  std::cout << "Test_stack_clear: PASSED" << std::endl;
  return 0;
}

// master test suite
int Test_stack() {
  Test_stack_pop();
  Test_stack_push();
  Test_stack_pop();
  Test_stack_clear();
  return 0;
}