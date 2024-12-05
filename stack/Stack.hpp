#ifndef STACK_H
#define STACK_H

class Stack {
  private:
    int* m_stack;
    int m_size;
    int m_buffer_length;
  
  public:
    // construct an empty stack instance
    Stack();

    /// @brief Checks if the stack is empty (size is 0)
    /// @return True if empty, false otherwise
    bool is_empty();

    /// @brief  Pushes an item to the front of the stack
    /// @param item is the item to be pushed into stack
    void push(int item);

    /// @brief Prints the stack data structure
    void print_stack();

    /// @brief Prints the full buffer allocated in the heap (for debugging)
    void print_full_buffer();
    
    ~Stack();
};


#endif