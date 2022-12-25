#include <iostream>
using namespace std;

struct node {
    int info;
    struct node* next;
};

struct node* create() {
    struct node* newnode;
    newnode=new(struct node);
    newnode->next=NULL;
    return(newnode);
}

struct node* top=NULL;

void push(int element) {
    struct node* temp;
    temp=create();
    temp->info=element;
    temp->next=top;
    top=temp;
}

void pop() {
    struct node* temp;
    if (top==NULL) cout<<endl<<"Stack underflow";
    else {
        temp=top;
        top=temp->next;
        cout<<endl<<temp->info<<" is deleted.";
        delete(temp);
    }
}

void peek() {
    struct node* temp=top;
    cout<<endl<<temp->info<<" is the topmost element.";
}

void display() {
    if (top==NULL) cout<<endl<<"Stack underflow";
    else {
        struct node* temp;
        temp=top;
        while (temp!=NULL) {
            cout<<endl<<temp->info;
            temp=temp->next;
        }
    }
}

int main() {
    int flag=1, choice;
    while (flag) {
        cout<<endl<<"Enter 1 to push\nEnter 2 to pop\nEnter 3 to peek\nEnter 4 to display\nEnter 5 to exit\n";
        cin>>choice;
        switch (choice) {
            case 1:
                int element;
                cout<<endl<<"Enter an element: ";
                cin>>element;
                push(element);
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                peek();
                break;
            
            case 4:
                display();
                break;
            
            case 5:
                flag=0;
        }
    }
}