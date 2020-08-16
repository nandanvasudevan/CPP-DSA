># Mastering Data Structures   
    
Source: [Udemy](https://www.udemy.com/course/datastructurescncpp/)

> Date: 09 February 2020
#   Basics of C/C++

## Arrays 
    Stores similar type of data
    Syntax -> int A[10];
    Use loop to manipulate data
    Stored in stack frame of main()

## Structures
Related data members under the same name.
The data members can be of dissimilar type.
        
    <keyword>   <Name of structure>
    struct      Rectangle
    {
        * Data members            
        int length; int breadth;
    };
        
* Creating a "variable" of type struct
    *   Declaration
        struct Rectangle rectangle;
    *   Initialization
        struct Rectangle rectangle = {5,5};

* Size of a structure?  
    It's the total memory consumed by all of it's members.
    *   Here "rectangle" takes up 4 bytes.
        int length - 2 bytes
        int breadth - 2 bytes
    
* Memory space - Stack frame of main()

* Accessing members of a structure  
    The dot(.) operator is used to modify the value of a member.
    Syntax -> rectangle.length = 10;

* Accessing with a pointer
    struct Rectangle *Pointer2Rectangle = &rectangle;
    * Pointer2Rectangle.length      &rarr; **Incorrect**
    * Pointer2Rectangle.length     &rarr; **Incorrect**
    * (*Pointer2Rectangle).length   &rarr; **Correct**  
        This is because the dot(.) operator has higher precedence than the star(*) operator.
    * Pointer2Rectangle -> length   &rarr; **Correct**
        The arrow(->) operator.    

## Pointers (*)
* Address variable - indirect accessing
* Does not store the data of a variable

### Memory sections
    1. Code
    2. Stack
    3. Heap
    
    Program can access code and stack memory. Only a pointer can access heap memory.  
     * Accessing files on the hard drive which are external to a program -> using a pointer of type file.
     * In general for accessing resources.
    
> Pointers for passing parameters &rarr; pass by reference

### Declaring and initializing  
    ```
    int a = 10;  
    int *pointer; <-- declaration  
    *pointer = &a <-- initialization  
    ```

### Dereferencing
   
    `printf("%d", a);    <--` This line will print the value of "a", which is 10.

    `printf("%d", p);    <--` This line will print the address where variable "a" is stored (stack memory)  

    `*printf("%d", *p);  <--` This line will print the value of "a", which is 10. This is called dereferencing.
    

### Accessing heap memory
Every variable will be in stack memory.  
`!malloc <stdlib.h>`
* Used for accessing heap memory.  
* Syntax -> `malloc(<required quantity> * <size of data type required>)`  
*  `malloc(5 * sizeof(int))` - allocates memory in heap for storing 5 integers in heap memory
* Returns -> pointer of type `void`
```
int *p = (int*) malloc(5 * sizeof(int));
Pointer2Rectangle = (struct Rectangle) malloc(sizeof(struct   Rectangle));    

//CPP
int *p = new int[5];
```
## Reference (&)
> CPP exclusive
* Used for providing an alternate alias for an existing variable
All the aliases share the same address location.
Modifying one will modify the value associated with all of them.

Syntax `-> int &ref = <variable>;`  
* A reference variable **must be initialized**

## Functions

> Functions are a group of instructions that perform a particular task.  
`Functions:instructions :: Structure:data`  

Aka Modules | Procedures

* Three sections
    1. Prototype  
        `<return type> <function name>(parameters...);`
        * Formal parameters  
            `int sum(int a, int b);`  
        **aka header**
    2. Definition  
        Instructions to be performed by the function  
        ```
        {
            /*Must be within curly braces*/            
            int result = a + b;            
            return result;
        }
        ```
        **aka body, elaboration**
    3. Function call
        <variable> = <function name>(parameters...);
            int c = sum(a, b);
        Here a and b are the parameters. 
        * Actual parameters.

* Pass by value  
    In the above example the actual and formal parameters occupy unique memory spaces in the stack memory.  
    Changes made in one are not reflected anywhere else.  
    `int sum(int a, int b);`

* Pass by reference  
    The actual parameter that is passed as reference will retain all changes made to it in the formal variable counterpart of the function.  
    `int sum(int &a, int &b);`  
    > The function is converted to inline code at the place of call.
        Not advisable

* Pass by address  
    The actual parameter is an address of the variable or a pointer. The formal parameter must be a pointer.  
    > Pass by reference does not exist in C.

    Therefore pass by address is the only other choice.  
    `int sum(int *a, int *b);`

* Passing an array  
    An array is always passed by address. The starting address of the array is passed.  
    The formal parameter receiving the array is essentially a pointer.  
    ```
    int sum(int a[], int b);`  
    or `int sum(int *a, int b); <- Do not use if you're sure the parameter will be an array - clarity - easier to manipulate.
    ```  
    As the array is passed by address, it is also **important to pass the length of the array**.
    > Arrays cannot be passed by value

* Returning an array  
    An array, as is the case while passing, can be returned just by returning the starting address.  
    In effect the returned variable must be a pointer.
    ```
    int[] sum(int a[], int n);
    or int* sum(int a[], int n);
    ```
    * Defining the pointer  
        `int *p = (int*) malloc(n*sizeof(int));`
    
    * Return  
        `return p;`

* Passing a structure  
    `int sum(struct Rectangle r);`  
    The above line receives a parameter of type Rectangle.
    ```
    sum(rectangle); // where rectangle is a variable of structure Rectangle
    ```
 > Date: 12.02.2020

# Introduction to data structures
A data structure is an arrangement of collection of data items for efficient utilization.
The data structures are stored inside the main memory during the execution of a program.

## Database  
Data structures differ from a database due to the fact that a database is stored in the secondary memory of a system like the HDD.
Whereas a data structure is always stored in the primary memory or RAM.

## Static vs Dynamic Memory Allocation
----
The memory in RAM (which is used by a program during execution) is not completely made available to a single program.  
Instead, it is divided into chunks called segments.

### Segments
* A segment usually stores 64kB of data.  
A segment is divided into the following **sections**:
    1. Code
    2. Stack
    3. Heap
#### Sections
* Code section  
    The area occupied by the program in main memory during execution.
* Stack   
    The variables in a program occupy the stack memory.
    * The section of stack memory utilized by a program is called stack frame or activation record.
    Every function utilizes a separate stack frame.
    The top most activation record will be used by the function being currently executed.
    The activation record will be deleted as soon as execcution leaves the scope of a function.
    * The process of deleting the last created instance or last in first out constitutes a stack, which is aplty named.
* Heap  
    Heap, in this context is unorganized, whereas stack is organized.
    Heap memory is a resource, the programmer is responsible for freeing the memory allocated in heap.
    * A program cannot directly access heap memory. Pointers are used.
        ```
        int *C_HeapPointer;
        C_HeapPointer = (int*)malloc(10*sizeof(int)); 
        int *Cpp_HeapPointer = new int[5];
        ```
    The memory allocated in heap is never deleted even if the pointer goes out of scope. Therefore it **has to be de-allocated** to avoid memory leaks.
    ```
    delete Cpp_HeapPointer;
    Cpp_HeapPointer = null;
    free(C_HeapPointer);
    realloc(C_HeapPointer);
    Cpp_HeapPointer = null;
    C_HeapPointer = null;
    ```
* Physical vs logical data structures
    * Physical  
        Physical data structures define the memory is organized or allocated.
        * Linked list  
        A linked list is an array in heap memory and is dynamic in nature.
    * Logical  
        Logical data structures define the utilization of the physical data structures.  
        They define the process of adding an element or modifying an element but never it's arrangement in the physical memory.  
        * Linear data structures  
            Stack (LIFO) and queues (FIFO).
        * Non-linear data structures  
            Tree or graph  
        * Tabular  
            Hash tables

## Abstract Data Types  
        A data type consists of it's representation and the operations that can be performed on it.  
        Primarily used in object oriented programming where a class is constructed to contain a physical data type along with all the required operation needed for the data type. The actual data type or details about it are abstracted.  

> Date: 12.02.2020
# Time and Space Complexity
Time complexity depends on the "procedure" or algorithm used for doing a particular task.

> Date: 01 March 2020
## Recursion
The process in which a function calls itself is known as recursion and the corresponding function is called the recursive function.
### Head Recursion
    void RecursiveFunction(int n)
    {
        if(n > 0)
        {
            RecursiveFunction(n-1);
            /* task 1 */           
        }
    }
In head recursion, the recursive function is called before executing any tasks.

### Tail Recursion
    void RecursiveFunction(int n)
    {
        if(n > 0)
        {                
            /* task 1 */           
            RecursiveFunction(n-1);
        }
    }
In head recursion, the recursive function is called after executing any tasks.

#### Time and space complexity
----
```
void RecursiveFunction(int n)
{
    if(n > 0)
    {
        /* task 1 */               
        
        RecursiveFunction(n-1);
    }
}
```
In the above example, let RecursiveFunction() have a time complexity of T(n).
Task 1 - 3 have a time complexity of 1 each, so 3.  
  * The function call to `RecursiveFunction(n-1)` is not just another task, it's a call to a function that has a time complexity of `T(n)`.
Therefore this function must have a time complexity of T(n-1).

* Total time complexity,
  * `T(n) = T(n-1) + 1 -> n > 0`
  * `T(n) = 1          -> n = 0`
* For first recursive call,
  * `T(n) = T(n-1) + 1`
* For second recursive call,
  * `T(n) = T(n-2) + 2`
* For kth recursive call
  * `T(n) = T(n-k) + k`
* When k = n,
  * `T(n) = T(n-n) + n`
  * `T(n) = T(0) + n`
  * `T(n) = 1 + n`
  * `T(n) = O(n)`

#### Tail recursion vs Loop
----
For a simple recursion given below,
```
void RecursiveFunction(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        RecursiveFunction(n-1);
    }
}
```
*   Time complexity = `O(n)`
*   Space complexity = `O(n)`
*   Space complexity is `O(n)` because for each function call, a separate activation record is created in stack.

On the other hand, for a loop,
```
void Loop(int n)
{
    while(n > 0)
    {
        printf("%d", n--);
    }
}
```

*   Time complexity = `O(n)`
*   Space complexity = `O(1)`
    Space complexity is `O(1)` because only one activation record is created in stack.

#### Head recursion vs Loop
----
For a simple recursion given below,
```
void RecursiveFunction(int n)
{
    if (n > 0)
    {                
        RecursiveFunction(n-1);
        printf("%d", n);
    }
}
```
*   Time complexity = O(n)
*   Space complexity = O(n)
    Space complexity is O(n) because for each function call, a separate activation record is created in stack.
    Some compilers at higher optimization levels, convert tail recursion to a simple loop to save space.

On the other hand, for a loop,
```
void Loop(int n)
{
    int i = 0;
    while(i < n)
    {
        printf("%d", i++);
    }
}
```
Note that it cannot be converted to a loop as easy as that for tail recursion.
*   Time complexity = `O(n)`
*   Space complexity = `O(1)`
*   Space complexity is `O(1)` because only one activation record is created in stack.

### Tree recursion
*   Linear recursion  
        If in a recursive function, the function is only called once, then it's called a **linear recursion**.
*   Tree recursion  
        The recursive function is calling itself more than once.
        It cannot be categorized as tail or head recursion.
    ```
    void RecursiveFunction(int n)
    {
        if(n>0)
        {
            printf("%d", n);
            RecursiveFunction(n-1);
            RecursiveFunction(n-1);
        }
    }
    ```
    *   Time complexity = `O(2^n)`
    *   Space complexity = `O(n)`

### Indirect Recursion
*  A recursive cycle consisting of multiple recursive functions.
```
void Second_RF(int n)
{
    if(n > 0)
    {
        /* Some code */
        First_RF(n-1);
    }
}
void First_RF(int n)
{
    if(n > 0)
    {
    /* Some code */
    Second_RF(n/2);
    }
}
```
> Date: 07 March 2020
#  Array representation
Arrays are used to store values of similar type together.

## Initializing an array
In C language, an array of length 'l' can be initialized only in compile time and not during run time.

    void array()
    {
        const int l = 10;
        int A[l];       <-- The above statement will throw a compile 
                                time error
        scanf("%d", &l);
        int arr[l];     <-- The above statement will throw a compile 
                                time error
        int arr2[10];   <-- The above statement works
    }
  
However, in CPP
    
    void array()
    {
        const int A = 10;
        int arr[A];     <-- The above expression is valid
    }

## Dynamic initialization of arrays
*   In CPP and C it is possible to create arrays at run time.
>   You cannot increase the size of an array at run time.

The alternative is to create a new **dynamic array** of larger size of then copy existing elements from the old array.

    void dynamicArray()
    {
        /*<-- CPP language -->*/
        int *P = new int [5]; // Creates an int array of size 5
        delete(P); // de-allocates heap memory

        /*<-- C language -->*/
        int *p = (int*)malloc(5 * sizeof(int));
        free(p);           

        /*<-- Array of Pointers -->*/
        int *arrayOfPointers[3];
        *arrayOfPointers[0] = new int[5];

        int **doublePointer;
        doublePointer = new int*[4];
        doublePointer[0] = new int[5];

    /*   Here the double pointer exists in stack. All the others created with the "new" keyword exist in heap. 
    */

    }

##   Row major formula
  For `A[m][n]` -> m rows and n columns  
  `&A[i][j] = startingAddress + (nxi + j)*sizeofDataType`

##   Column major formula
  `&A[i][j] = startingAddress + (mxj + i)*sizeofDataType`

##  3D array formula
  For `A[l][m][n];`
  ###   Row major        
  `A[i][j][k] = startingAddress + (ixmxn + jxn + k)*sizeofDataType`

  ###   Column major
  `A[i][j][k] = startingAddress + (kxmxl + jxl + i)*sizeofDataType`

> Date: 07 March 2020
##  Array as Abstract Data Type (ADT)

> Date: 22 March 2020
#  Strings

##  ASCII Codes

    