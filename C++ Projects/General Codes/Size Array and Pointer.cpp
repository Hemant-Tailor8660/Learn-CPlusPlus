/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<cstring>
using namespace std;
void fun(char* str)
{
    std::cout<<"fun sizeof str: "<< sizeof(str)<<", fun strlen(str):"<<strlen(str)<<std::endl;
}
int main()
{   
    int arr[]={1,2,3,4,5};
    std::cout<<"sizeof arr: "<<sizeof arr<<", sizeof int datatype: "<<sizeof(int)<<std::endl;
    
    char str[] = "Hemant";// {' ','a','b','a','b','a','b','a','b','a','b','a','b','a','b','a','b'};
    //char* str = new char[100]{' ','a','b','a','b','a','b','a','b','a','b','a','b','a','b','a','b'};
    std::cout<<"sizeof str: "<< sizeof str<<", strlen(str):"<<strlen(str)<<std::endl;
    fun(str);
    
    char st[] = "hemant";
    char* ch=strdup(st);   
    //cout<<"Hello World";

    return 0;
}
