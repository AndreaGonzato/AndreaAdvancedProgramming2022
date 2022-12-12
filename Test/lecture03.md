# Lecture 3
### How do you create an object file with `g++`?
by using the comand `g++ -c main.cpp` this will generate a `main.o` file.

Then you need to link the files `.o` by using the command `g++ -o hello.x hello.o` to create a file `hello.x`tha you can execute

### Why can't you just have eveything in one file?
You can but is better tu use different file to better organize code structure

### What is the purpose of a "header guard"?
It is use for import a class only once to notify the compiler to compile that class only once. 

In order to do that write this at the beginnig of your header files. 
```
#pragma once
```

### What does `-IFOLDER_NAME` mean when passed to `g++`?
it indicate in witch folder the compiler need to search for the include file.

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
You need to pass to make some option like `--file=MyMakefileName` or `-f MyMakefileName`.

### What does it mean if a function is a friend of a class?
A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. 
Even though the prototypes for friend functions appear in the class definition, friends are not member functions.

### Why should non-class member operators be friends of classes?
* Because they need to access the private variables of the class.


### Which header do you need to include to work with files?
First, you need to include the header <fstream>

```azure
#include <fstream>
```
  
### How do you open a file in append mode?
If you don't want to overwrite an existing file, use:
```
filevar.open("test.txt", std::ios_base::app);
```


# All the code snippets below have mistakes, find them:

## Snippet 1
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
CCoords CCoords::operator+(const int& b) {
        CCoords result;
        result.x = x + b;
        result.y = y + b;
        return result;
    }
int main(){
    CCoords c;
    c.x=0;c.y=3;
    auto cc=2+c;
}

```
Here is defined an addiction where the first operand is an CCords and the second one is an int.
But in the main the order of the operand are exchanged.
To correct it do:
```
auto cc = c+2;
```

In general is always better to use friend for this type of definition

## Snippet 2
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class MyClass{
  int x;
  MyClass():x(0){};
}
std::ostream& operator<<(std::ostream& os, const MyClass& m){
    os<<m.x<<std::endl;
    return os;
};
int main(){
    MyClass m;
    std::cout<<m<<std::endl;
}

```
Here we need to define the `operetor<<` as a friend.

## Snippet 3:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
int result;
for(int i=0;i<N;i++){
   result=calculate_result();//valid function defined somewhere else
   std::ofstream filevar("results.txt");
   filevar<<result<<std::endl;
   filvar.close();
}
```
N is not defined

ofstream is repeated N times but every time it overwrite the content of the file so only the last time persist the information on the file.

To correct this behavior use the  

```azure
std::ofstream filevar;
filevar.open("result.txt", std::ios_base::app);
```