# Stack Data Structure #

A Stack is a linear data structure that follows a particular order in which 
the operations are performed, The order may be *LIFO* (Last in, First out)

## Key operatuins on Stack Data Structures ##
-Push: Adds an element to the top of the stack.
-Pop: Removes the top element from the stack.
-Peek or Top: Returns the top element without removing it.
-IsEmpty: Checks if the stack is empty.
-IsFull: Checks if the stack is full (in case of fixed-size arrays).

## Types of Stack Data Structure ##

Fixed Size Stack
	A fixed-size stack has a set capacity and cannot change dynamically. Adding 
	an element to a full stack causes an _overflow_ error, while removing an element
	from an empty stack results in an _underflow_ error.

Dynamic Size Stack
	A dynamic size stack can automatically grow or shrink as needed. It expands when 
	full and contracts when empty, typically using a linked list for easy resizing.

There are two ways to implement a stack: using an array or a linked list. In an array-based 
implementation, the push operation increments the top index to store the new element, while 
the pop operation returns and decrements the top index. In a linked list-based implementation, 
push creates a new node and links it to the top, and pop updates the top to the next node, 
returning the previous top value.