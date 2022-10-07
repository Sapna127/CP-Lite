# Table of content
- [Stack](##stack)
- [Linked List](#linked-list)

## Stack 

<h2>Stack can be defined as a container in which insertion and deletion can be done from the one end known as the top of the stack.</h2>

### Some key points related to stack
It is called as stack because it behaves like a real-world stack, piles of books, etc.
A Stack is an abstract data type with a pre-defined capacity, which means that it can store the elements of a limited size.
It is a data structure that follows some order to insert and delete the elements, and that order can be LIFO or FILO.
### Working of Stack
Stack works on the LIFO pattern. As we can observe in the below figure there are five memory blocks in the stack; therefore, the size of the stack is 5.

![image](https://user-images.githubusercontent.com/91309280/194521845-61888137-885e-47db-bd40-fa1919254231.png)

Suppose we want to store the elements in a stack and let's assume that stack is empty. We have taken the stack of size 5 as shown below in which we are pushing the elements one by one until the stack becomes full.

DS Stack Introduction
Since our stack is full as the size of the stack is 5. In the above cases, we can observe that it goes from the top to the bottom when we were entering the new element in the stack. The stack gets filled up from the bottom to the top.

When we perform the delete operation on the stack, there is only one way for entry and exit as the other end is closed. It follows the LIFO pattern, which means that the value entered first will be removed last. In the above case, the value 5 is entered first, so it will be removed only after the deletion of all the other elements.

### Standard Stack Operations
#### The following are some common operations implemented on the stack:

```
push(): When we insert an element in a stack then the operation is known as a push. If the stack is full then the overflow condition occurs.

pop(): When we delete an element from the stack, the operation is known as a pop. If the stack is empty means that no element exists in the stack, this state is known as an underflow state.

isEmpty(): It determines whether the stack is empty or not.

isFull(): It determines whether the stack is full or not.'

peek(): It returns the element at the given position.

count(): It returns the total number of elements available in a stack.

change(): It changes the element at the given position.

display(): It prints all the elements available in the stack.
```
