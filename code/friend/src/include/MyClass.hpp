#pragma once

#include <iostream>

class MyClass
{
private:
    int var;

public:
    MyClass(int par);
    ~MyClass();
    void print();
    friend MyClass sum(MyClass a, MyClass b);
    
};

MyClass::MyClass(int par)
{
    var = par;
}

MyClass::~MyClass()
{
}

void MyClass::print(){
    std::cout<<"var: "<<var<< std::endl;
}

MyClass sum(MyClass a, MyClass b){
    return MyClass(a.var + b.var);
}
