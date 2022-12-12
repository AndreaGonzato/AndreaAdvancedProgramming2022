## Lecture 4    
### what's the main advantage of using templates?
with template you can write your code more general without specify the type of the variable.

### why do people usually put definitions of templated functions directly into `.hpp` files?
Templates need to be "instantiated" by the compiler at compile time, thus if you separate the declarations and definitions into different files as is done in C, you have to instatiate it manually. To not deal with this is better to write the code in the file .hpp
        
### except on types, what else can we template on?
Template can be used on fields of a class. But in this case when you init a class you need to specify the type like `CMyClass<int> var;`
        
### what is template specialization?
It is used to specialize a function based on the type of the template
        
### what is a variadic template?
is the concept of pass to a function different type of parameters and deal with all in the propper way. This is done with a definition of the function like this:
``` 
template <typename T>
void myPrint(const T& arg){
     std::cout<<arg<<" ";
}
        
template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
        
myPrint('c', 1.4, 9,0, "kjhkjhkjh");
 ```
        
### why using `push_back` for `std::vector` is a bad idea?
Because iy you use it many time, there are many possible reallocation of the size of the vector that is an operation that need to be avoided.
        
### how do you pass data from `std::vector` to a "C-style" function that needs a pointer?
You can use: `&myvec[0]` or `myvec.data()`
        
### why you shouldn't use a "vector of vectors"?
Because you want to be contiguous in memory.


# All the code snippets below have mistakes, find them:


## Snippet 1:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename T>
class CMyClass{
  T a;
  T b;
}

int main(){
  CMyClass var;
 ...
}
```
You need to specify the type of the template. If you choose to use int you need to write in the main:
```
CMyClass<int> var;
```

## Snippet 2:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename T, double S>
void add_number(T& var){
    T=T+S;
}
```

Here the type of the template are used as variable.
The correct version is:
```
template <typename T, typename S>
T add_number(T var, S add){
    return var+add;

}
```

## Snippet 3:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename... Types>
void myPrint(const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
```
Args is a group of parameters

The correct version is:
```
template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}

```

## Snippet 4:

```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
template <typename T>
void print(const T& var){
  std::cout<<var<<std::end;
}

struct MyClass{
  int a;
  int b;
}

int main(){
 MyClass var;
 print(var);
}

```

`var` of `MyClass` is only declared but not init. To solve that in the main use the line:
```
MyClass var = MyClass();
```
To properly print MyClass you need to define the operator <<. To do that the best way is to define a friend in the class

```
struct MyClass{
  int a;
  int b;
  friend std::ostream& operator<<(std::ostream& os, const MyClass& mc);
};

std::ostream& operator<<(std::ostream& os, const MyClass& mc)
{
    os <<"a: " <<mc.a << " b: " << mc.b;
    return os;
}
```

