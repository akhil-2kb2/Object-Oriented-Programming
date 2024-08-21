#include<stdio.h>
/*
->What is a pointer?
->pointer is a variable that stores the memory address of another variable.
->pointer is also said to "point to" the variable whose address it stores.

->How to declare a pointer?
->To declare a pointer, we use the '*' operator.
->Syntax: data_type *pointer_name;
->Example: int *p; //pointer to an integer variable

void f1()
{
    int a;  //value Type variable
    int *p; //NULLable Type variable
    p = &a; //&a is the address of a
    *p = 10; //*p is the value of a
    printf("%d\n",a); 
}
int main()
{
    f1();
    printf("\n");
    return 0;
}
*/
void f1()
{
    int *p; //Uninitialized pointer ==> wild pointer  Some Time it Work and Some Time it not work
    *p = 10; 
    printf("%d", *p); 
}   
int main()
{
    f1();
    printf("\nHello World");
    printf("\n");
    return 0;
}