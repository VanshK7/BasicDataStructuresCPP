#include <iostream>
#include <string.h>
using namespace std;
#define size 50
struct Stack
{
    char stk[size];
    int top;
}s1;

int stackoverflow()
{
    if (s1.top == size - 1)
    {
        cout << "Stack overflow" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

int stackunderflow()
{
    if (s1.top == -1)
    {
        cout << "Stack underflow" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char val)
{
    s1.top++;
    s1.stk[s1.top] = val;


}

char pop()
{
    char val = s1.stk[s1.top];
    s1.top--;
    return val;
}

int main()
{
    int j;
    s1.top = -1;
    char str[50], str2[50];
    cout << "Enter the string : " << endl;
    cin >> str;
    for (int i = 0; i < strlen(str); i ++)
    {
        push(str[i]);
    }
    for (j = 0; j <strlen(str); j ++)
    {
        str2[j] = pop();
    }
    str2[j] = '\0';
    if (strcmp(str, str2)==0)
    {
        cout << "String is palindrome." << endl;
    }
    else
    {
        cout << "String is not a palindrome." << endl;
    }
}