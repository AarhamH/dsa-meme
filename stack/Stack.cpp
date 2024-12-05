#include "Stack.hpp"

Stack::Stack() : m_stack(nullptr), m_size(0) {};

bool Stack::is_empty() {
  return m_size == 0;
}

Stack::~Stack() {
  delete[] m_stack;
}
