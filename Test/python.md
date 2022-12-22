[I consider c++ more important, so there are less python questions than c++ ones, and no advanced questions. I will compile all the c++ questions into one file before New Year. At the exam, the questions will come in random order (to make it harder to cheat).]

# How do you create markdown cell in Jupyter? (with keyboard commands)
esc + m

# How do you delete a cell in Jupyter (with keyboard command)?
esc + dd (or d?)

# How do you add a cell above the current one in Jupyter (with keyboard command)?
esc + a

# What advantage does conda environment provide over a system-wide installation of python?
conda's main advantage is that it allows the creation of isolated virtual environments, in which installed packages are private,
thus allowing installing multiple versions of the same package if required by differen projects.

# What does it mean that variables are dynamically typed in python?
It means that the type of a variable is determined at runtime rather than at compile time.

# What's the difference between python and C/C++ integers?
In python there is no such thing as integer overflow. In python, integers are always signed ('unsigned' ints do not exist).

# Explain the difference between lists, sets and tuples in python.
Lists: modifiable, ordered, can have duplicates
Sets: modifiable, unordered, cannot have duplicates
Tuples: not modifiable, ordered, can have duplicates

# What does negative index mean when accessing list elements?
The index is applied as an offset starting from the end of the list, rather than from the beginning.

# How do you print the first N elements of a list?
print(mylist[0:N])

# How do you print every Nth element of a list?
print(mylist[0::N])

# How do you print the reverse list?
print(mylist[::-1])

# Give an example of a list comprehension.
mylist = [i*5 for i in range(40)]

# Give an example of cell and line magic commands in Jupyter.
cell: %%timeit
line: %timeit

# Write a "hello world" function in python (syntax errors are not ok in hello world even on paper).
def myfunc():
    print("Hello world!")

# What are keyword function arguments in python and what is their advantage?
They are key=value pairs and add clarity to the way arguments are passed to functions, avoiding ambiguity when some arguments
are left to their default values and allowing for different ordering of arguments.

# Why shouldn't you do `from numpy import *`?
Because it imports too many elements into the current 'namespace', with the risk of collisions with other pre-existing elements.

# What is the advantage of using numpy arrays over lists? What are the dangers?
numpy arrays are compiled to native code allowing for better performance. numpy array elements are susceptible to overflows.

# What's the most widely used package for plotting in python?
matplotlib

# What's the purpose of `__str__` method in a python class?
it gives a string representation of a class.

# What package can you use in python for symbolic calculations?
sympy

# What are decorators? Write an example (minor syntax errors are ok here)
Decorators are useful to extend the functionality of a functions.

def logger(func):
    def wrapper(*args, **kwargs):
        print("calling {}".format(func))
        result = func(*args, **kwargs)
        print("done")
        return result
    return wrapper

@logger
def hello(string):
    print(string)

# Name two ways of calling c++ code from python.
pybind, cython

# What is pandas? Name at least 5 functions from that package.
A package for creating and managing dataframes. Series(), DataFrame(), read_csv(), dropna(), head()

Wrong code snippets:

Snippet 1
```
if x==0:
print('x is zero')
elif x>0:
print('x is greater then zero')
elif x<0:
print('x is smaller than zero')
```

indentation is missing.

Snippet 2:
```
t = tuple(range(10))
t[5]=100
print(t[5])
```

tuples cannot be modified

Snippet 3:
```
class MySecondClass:
    def __init__(number):
        self.number = number
a=MySecondClass(4)
```

self is missing from __init__'s args.
