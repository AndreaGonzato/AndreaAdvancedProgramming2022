# Lecture 2
### What is a reference?
A reference is defined with the & and should be initialized at declaration. It is like an alians to variable.
### What is a difference between passing variables to functions by reference and by value?
If you pass by reference the modification outside the function are still present. 
### Why do we want to pass variables to functions by reference rather than by pointer?
Becuase has a more simpler sintax
### If the function accepts pointers (signature `int function(int* a)`), how do you pass a variable defined as `int x` to it?
You pass like:  `function(&a)`
### Why do we want to use `const` modifier whenever possible?
To not allow to modify the variable/reference.
### If you have a pointer named `p`, how do you access a value it points to? What is the name of that process?
You access to the value by: *p. This is call dereference
### What value is stored in the pointer variable itself?
The address of the memory where the variable is stored
### What can you say about a function that has signature `void function()`?
That do not return nothing
### What is an `auto` keyword?
Is a keyword to automatically assing the correct type to the variable. This is used to when you are not sure what is the retun type or the return type is too long to write and you are lazy.
### What is function overloading?
Is when you define multiple functions with different parameter type.
### What is a recursive function?
A function that call itself multiple times.
### What is the role of a constructor in a class?
It is used to assign the local variable of the class
### How can we change private member variables of a class?
By using setters methods/functions.
