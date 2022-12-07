# Lecture 01
## name at least 5 variable types in c++
bool, double, float, int, short int.
```
bool var{true};
double x{3.5};
float  xx{3.5f};
int a{1};
short int b{2};
long int c{3};
long long int d{4};
char s{'a'};
```
## what is "int overflow"?
In computer programming, an integer overflow occurs when an arithmetic operation attempts to create a numeric value that is outside of the range that can be represented with a given number of digits. Either higher than the maximum or lower than the minimum representable value.

## why `using namespace std` might not be a good idea?
While this practice is okay for example code, pulling in the entire std namespace into the global namespace is not good as it defeats the purpose of namespaces and can lead to name collisions. This situation is called namespace pollution.

## which header do you have to include for the access to std::cout?
You need to include the header iostream. So write this line at the beginning of your program:

```
#include <iostream>
```

## what would be the simplest "legal" program in c++?
It would be:
```
int main(){}
```

## what is the difference in c++ between `struct` and `class`?
The two constructs are identical in C++ except that in structs the default accessibility is public, whereas in classes the default is private.
Classes and structs are the constructs whereby you define your own types.

## what does `break` statement do in a loop?
`break` exit to the loop. If you have nested loop break exit only for the inner loop.

## what does `continue` statement do in a loop?
It go to the next iteration of the loop

## how do you define a static array of type int and size 7?
```
int arr[7];
```
Remember that the value in the array are not initalized so can be not zero like it happen in Java.

## what can you use to read interactive user input?
```
#include <iostream>
 ......
int x{0};
std::cin >> x;
```
The `>>` is called "extraction operator

\
&nbsp;
\
&nbsp;

# All the code snippets below have mistakes, find them:

## Snippet 1:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
int a{8},b{8};
if (a=b){
    std::cout<<"equal"<<std::endl
}
```
Add a semicolon athe the end of the longest line.

The intent of the script is not correct, to compare you need to use the doble equal operator `==`


## Snippet 2:
```
{int a{2};}
a=4;
```
`a` is not declared in the scope of the second line.

## Snippet 3
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
double x{0.5},y{0.5};
if(x==y){
    std::cout<<"x is equal to y"<<std::endl;
}
```
Never do comparison of double only using the `==` operator. Is better to accept a range of error. So do something like:
```
#include <cmath>
...

if(std::abs(x-y) < 0.001){
 std::cout<<"x is equal to y"<<std::endl;
}
```

## Snippet 4:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
int x{1},y{1};
while (x<10){
   std::cout<<x<<" "<<std::endl;
   y++;
}
```
To correct it in the last line you need to increment x and not y.


## Snippet 5:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
int ar[10];
for (int i=0;i<=10;i++){
  ar[i]=i;
}
```
Index out of bound for the array. The condition of the loop (`<=`) need to be correct as: `i < 10`  

## Snippet 6:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
struct mystruct{
private:
  int a;
  int b;
}
int main(){
  mystruct S;
  S.a=8;
  S.b=7;
  return 0;
}
```
You can not acess private variable of a struct in the main. To correct this code change the qualifier to public in the struct.




# Actual Exercises:

#### Exercise 0:
Read the lecture notes and run all the examples mentioned in them. If you have little experience, it's better if you re-type rather than copy.

#### Exercise 1:
Write a program that asks the user to input 3 parameters for a quadratic equation `ax^2+bx+c=0`, then solve it (complex roots included). Modify it to store the coefficients in a class `CCoeffs`.

#### Exercise 2:
Write a program to convert integers to a binary system.

#### Exercise 3 (bisection):
Find a root of equation `x^3-6x^2+11x-6=0` at the interval [-10,10] by the following method:

 - check the signs of the function at the borders of the interval and its middle
 - modify the interval such that the function has different signs at borders (middle becomes one of the new borders)
 - repeat until the interval is smaller than 10^(-9)

#### Exercise 4:
Write a program that asks the user to fill in a small array, then sort it by whatever way you can think of and print the result on the screen.





