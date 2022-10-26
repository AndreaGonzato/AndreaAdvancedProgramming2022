## Lecture 05

### how do you allocate a dynamic array in C++?
`int* p =new int[10];`

### whats the difference between `delete` and `delete[]`?
If you are only allocating one object and not an array, use delete without brackets.

### when do you need to overload assignment operator for your class?
When you want to assigna an object to an reference or you want to make a "deep copy", you need to define the assigment operator

### when do you need to create a copy constructor for your class?

### when do you need to create a move constructor for your class?

### what should you do if your class allocates resources, but you are sure you will never need a copy constructor?

