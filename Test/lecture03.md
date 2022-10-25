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
```
obj/%.o: src/%.cpp  
        $(CC) $(CFLAGS) $^ -o $@
```
        
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

