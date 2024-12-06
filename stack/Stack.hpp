#ifndef STACK_H
#define STACK_H
#define STACK_GROW_SHRINK_LIMIT 5

class Stack {
  private:
    int* m_stack;
    int m_size;
  
  public:
    /// @brief Allocates an empty stack 
    Stack();

    /// @brief Allocates a preloaded stack 
    /// @param stack: Preloaded stack to be loaded
    /// @param len: Length of the preloaded stack
    Stack(int* stack, int len);

    /// @brief Checks if the stack is empty (size is 0)
    /// @return True if empty, false otherwise
    bool is_empty();

    /// @brief Returns the size of the stack
    /// @return An integer value, representing the size
    int size();

    /// @brief  Pushes an item to the front of the stack, if there is overflow, the stack grows
    /// @param item is the item to be pushed into stack
    void push(int item);

    /// @brief Pops the item from the front of the stack
    void pop();

    /// @brief Clears the stack
    void clear();

    /// @brief Prints the stack data structure
    void print_stack();
    
    ~Stack();
};


#endif