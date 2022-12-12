## Lecture 05

### how do you allocate a dynamic array in C++?
For example if you want to allocate an array of size 10 of int you do:
`int* p =new int[10];`

### whats the difference between `delete` and `delete[]`?
If you are only allocating one object and not an array, use delete without brackets.

### when do you need to overload assignment operator for your class?
When you want to assigna an object to a reference or you want to make a "deep copy", you need to define the assigment operator

### when do you need to create a copy constructor for your class?
When you pass a variable of your class to other functions

### when do you need to create a move constructor for your class?
Sometimes you might want to "move" your object instead of copying it (for example, if the object was temporary). 
In  this case you need the move e constructor. The object that you move after is empty.


### what should you do if your class allocates resources, but you are sure you will never need a copy constructor?
You need to mark the copy constructor as delete.
Otherwise you or someone else later might try to do unexpected things with your class and get a strange crash instead of a clear error message.
