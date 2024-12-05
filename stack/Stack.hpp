#ifndef STACK_H
#define STACK_H

class Stack {
  private:
    int* m_stack;
    int m_size;
  
  public:
    // construct an empty stack instance
    Stack();

    bool is_empty();
    
    ~Stack();
};


#endif