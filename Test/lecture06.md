## what are protected class members?
Protected class member are function and variables that are visible to only class that extend.

## what are virtual functions?
A virtual function is a member function in the base class that we expect to redefine in derived classes

## what is an abstract class?
An abstract class is a class that is designed to be specifically used as a base class.
By definition, an abstract class in C++ is a class that has at least one pure virtual function (i.e., a function that has no definition). 
The classes inheriting the abstract class must provide a definition for the pure virtual function otherwise, the subclass would become an abstract class itself.

If a class has a pure virtual function (declared with =0), then it's an "abstract class" and you cannot have an object of it. It's used for interface only purposes. 
Virtual functions must be overriden in derived classes, otherwise they become abstract too.
## explain dynamic (runtime) polymorphism
Runtime polymorphism is also known as dynamic polymorphism or late binding. 
In runtime polymorphism, the function call is resolved at run time. 
In contrast, to compile time or static polymorphism, the compiler deduces the object at run time and then decides which function call to bind to the object.
Mark the member function of the base class as virtual in order to resolve the at run time the function definition based o the real type of the object an not only by his reference



## why destructors should be made virtual?
Because if you will (or even might) destroy objects of a derived class through a base class pointer, you need a virtual destructor.

# All the code snippets below have mistakes, find them:

## Snippet 1
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class Shape{
 public:
  virtual void print()=0;
  virtual ~Shape(){};
}

class Circle: public Shape{
  double r;
  void print() override {std::cout<<r<<std::endl};
  }

int main(){
  Shape s;
  Circle c; 
}
```

Shape is an abstract class because it hase a function virtual that has body `=0`.
Since Shape is abstract we can not have an object of it (first line of main)

## Snippet 2
```
//BAD CODE AHEAD, DO NOT COPY BY ACCIDENT!
class Shape{
 public:
  virtual void print(){};
  ~Shape(){};
}

class Polygon: public Shape{
  double* v;
  void print() override {std::cout<<"hi"<<std::endl};
  Polygon(const int&N){v=new double[N];};
  ~Polygon(){delete[] v;};
  }

int main(){
  Shape* s = new Circle(7);
  s.print();
}
```
in the main, Circle change it with Polygon.

All the function in the class Polygon are defined as private. Change it to public:
```
class Polygon: public Shape{
public:
    ....
}
```

When you call a function on a pointer you need to use the arrow (`->`) instead of the point.
So the last line of the main is:
```
s->print();
```

The destructor is better to be virtual in the base class (Shape)