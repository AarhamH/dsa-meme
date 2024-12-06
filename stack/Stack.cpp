#include "Stack.hpp"
#include <stdlib.h>
#include <iostream>

Stack::Stack() : m_stack(nullptr), m_size(0) {};
Stack::Stack(int stack[], int len) : m_stack(nullptr), m_size(0) {
  m_stack = new int[len];
  for(int i=0; i<len; i++) {
    m_stack[i] = stack[i];
  }
  m_size = len;
};

bool Stack::is_empty() {
  return m_size == 0;
}

int Stack::size() {
  return m_size;
}

int* Stack::stack() {
  return m_stack;
}

void Stack::push(int item) {
  m_stack = (int*)realloc(m_stack, (m_size + 1) * sizeof(int));
  m_stack[m_size] = item;
  m_size++;
}

void Stack::pop() {
  if(m_size > 0) {
    m_size--;
    m_stack[m_size] = 0;
    m_stack = (int*)realloc(m_stack, m_size * sizeof(int));
  }
}

void Stack::clear() {
  m_size = 0;
  m_stack = (int*)realloc(m_stack, 0);
}

void Stack::print_stack() {
  std::cout << '[';
  for(int i = 0; i < m_size; i++) {
    std::cout << m_stack[i] << " ";
  }
  std::cout << ']' << std::endl;
}

Stack::~Stack() {
  delete[] m_stack;
}
