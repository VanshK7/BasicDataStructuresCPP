#include <iostream>
using namespace std;
#define maxsize 3;

struct stack{
    int top;
    int e_stk[3];
}stk;

int underflow() {
    if (stk.top==-1) {
        return 1;
    }
    else {
        return 0;
    }
}

int overflow() {
    if (stk.top<2) {
        return 0;
    }
    else {
        return 1;
    }
}

void push(int n) {
    if (overflow()) {
        cout<<endl<<"Stack overflow!"<<endl;
    }
    else {
        stk.top++;
        stk.e_stk[stk.top]=n;
    }
}

int pop() {
    if (underflow()) {
        cout<<endl<<"Stack underflow!"<<endl;
    }
    else {
        int x=stk.e_stk[stk.top];
        cout<<"\nThe popped element is "<<x<<endl;    
        stk.top--;
    }
}

void peek() {
    if (underflow()) {
        cout<<endl<<"Stack underflow!";
    }
    else {
        cout<<endl<<stk.e_stk[stk.top]<<endl;
    }
}

int main() {
    stk.top=-1;
    int will, cont_end=1;
    while (cont_end) {
    cout<<"Enter 1 to push\nEnter 2 to pop\nEnter 3 to peek\nEnter 4 to end"<<endl;
    cin>>will;
    switch(will) {
        case 1: {
            int n;
            cout<<"\nEnter the number to be pushed: ";
            cin>>n;
            push(n);
            break;}

        case 2: {
            int i=pop();
            break;}

        case 3: {
            peek();
            break; }

        case 4: {
            cont_end=0;
            break;
        }
        
        default: {
            cout<<"\nError! Enter valid input."; }
    }
    }
}