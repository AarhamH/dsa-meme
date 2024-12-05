#include "Stack.hpp"
#include <stdlib.h>
#include <iostream>

Stack::Stack() : m_stack(nullptr), m_size(0), m_buffer_length(0) {
  m_buffer_length += 5;
  m_stack = (int*)calloc(0, m_buffer_length * sizeof(int));
};

bool Stack::is_empty() {
  return m_size == 0;
}

int Stack::size() {
  return m_size;
}

void Stack::push(int item) {
  if(m_size >= m_buffer_length) {
    m_buffer_length += STACK_GROW_SHRINK_LIMIT;
    m_stack = (int*)realloc(m_stack, m_buffer_length * sizeof(int));
  }

  m_stack[m_size] = item;
  m_size++;
}

void Stack::pop() {
  if(m_size > 0) {
    m_stack[m_size] = 0;
    m_size--;
  
    if(m_size <= (m_buffer_length - STACK_GROW_SHRINK_LIMIT) || m_size <= 0) {
      m_buffer_length = m_size;
      m_stack = (int*)realloc(m_stack, m_buffer_length * sizeof(int));
    }
  }
}

void Stack::clear() {
  m_size = 0;
  m_buffer_length = 0;
  m_stack = (int*)realloc(m_stack, 0);
}

void Stack::print_stack() {
  std::cout << '[';
  for(int i = 0; i < m_size; i++) {
    std::cout << m_stack[i] << " ";
  }
  std::cout << ']' << std::endl;
}

void Stack::print_full_buffer() {
  std::cout << '[';
  for(int i = 0; i < m_buffer_length; i++) {
    std::cout << m_stack[i] << " ";
  }
  std::cout << ']' << std::endl;
}

Stack::~Stack() {
  delete[] m_stack;
}
