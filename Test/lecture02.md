# Lecture 2
### What is a reference?
A reference is defined with the `&` simbol and should be initialized at declaration. 

It is like an alians to a variable.
```
int a{77};
int& c{a}; //c becomes an alias for a
```

To define a function where a aparameter is passed by reference you need to write like this:
```
void add_two_ref(int& a){
    a=a+2;
}

int main(){
    int a{4};
    add_two_ref(a);
    return 0;
}

```


### What is a difference between passing variables to functions by reference and by value?
If you pass by reference the modification outside the function are still present after the termination of the calling function.

### Why do we want to pass variables to functions by reference rather than by pointer?
Becuase has a more simpler sintax

### If the function accepts pointers (signature `int function(int* a)`), how do you pass a variable defined as `int x` to it?
You pass like:  
`function(&a);`

### Why do we want to use `const` modifier whenever possible?
To not allow to modify the variable/reference inside a function.

### If you have a pointer named `p`, how do you access a value it points to? What is the name of that process?
You access to the value by: `*p`. This is call dereference

### What value is stored in the pointer variable itself?
The address of the memory to wich the pointer point. It is the adress of the of variable to wiche the pointer point.

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
By using setters methods or other function that change the the variable of the class.


# All the code snippets below have mistakes, find them:

## Snippet 1:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
void add_two(int* a){
    a=a+2;
}
int main(){
    int var{0};
    add_two(&var);
    std::cout<<var<<std::endl;
    return 0;
}
```

Here in tha function we are not incrementing the value of the pointer but the pointer so we are changing the adress since `a` is a pointer`.

To correct it you need to write in the function:
```
*a=*a+2;
```
## Snippet 2:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
void swap(int a, int b){
   int temp{a};
   a=b;
   b=a; 
}
int main(){
   int var1{8}, var2{9};
   swap(var1,var2);
   std::cout<<var1<<" "<<var2<<std::endl;
   return 0;
}
```

Here since we are passing the variable as value we are only swapping tha variable in the dunction but when we return to the main the variable are unchanged.

Another error is that the temp variable is not used.

To correct it we need to pass the variable by reference

```
void swap(int& a, int& b){
   int temp{a};
   a=b;
   b=temp; 
}
```

## Snippet 3:
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class CMyClass{
    int a;
    CMyClass(int x):a(x){};
}

int main(){
   CMyClass c(7);
   std::cout<<"this won't work"<<std::endl;
   return 0;
}
```

The error here is that the constructor is private by default and so in unacessible. Futhemore we need to add a semicolun to the end of the definition of the class.

The correc t version is:

```
class CMyClass{
    public:
        int a;
        CMyClass(int x):a(x){};
};
```

## Snippet 4:
```
int main(){
int x=4;
int& y;

......
}
```

When you define a referenc e you need to assign it immidiatly.

Correct it like:

```
int& y{x};
```
