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

# Lecture 3
### How do you create an object file with `g++`?
by using the comand `g++ -c main.cpp` this will generate a main.o file

### Why can't you just have eveything in one file?
You can but is bett tu use different file to better organize code structure

### What is the purpose of a "header guard"?
It is use for import a class only once to and higlit it to compile compile that class only once

### What does `-IFOLDER_NAME` mean when passed to `g++`?
it indicate in witch folder the compiler need to search for the file.

### Do tabs matter in a `Makefile`?
Yes they can’t be repleced by spaces. 

### What does `$@` mean in a `Makefile`?
`$@` is used as a placeholder for the target name.

### What does `$^` mean in a `Makefile`?
`$^` evaluates to filenames of all the prerequisites, separated by spaces.
Here is an example:
obj/%.o: src/%.cpp  
        $(CC) $(CFLAGS) $^ -o $@
        
### How to use `make` with a makefile that is not named `Makefile`?
Ypu need to pass to make some oprion like `make—file=MyMakefileName`

### What does it mean if a function is a friend of a class?
A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not member functions.

### Why should non-class member operators be friends of classes?
Because they need to access the private the variables of the class 

### Which header do you need to include to work with files?
First, you need to include the header <fstream>
  
### How do you open a file in append mode?
If you don't want to overwrite an existing file, use:
filevar.open("test.txt", std::ios_base::app);
