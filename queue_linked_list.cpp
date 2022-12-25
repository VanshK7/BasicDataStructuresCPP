#include <iostream>
using namespace std;

struct node {
    int info;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;

struct node* create() {
    struct node* newnode;
    newnode=new(struct node);
    newnode->next=NULL;
    return(newnode);
}

void enqueue(int element) {
    struct node* temp=create();
    temp->next=NULL;
    temp->info=element;

    if (front==NULL) {
        front=temp;
        rear=temp;
    }

    else {
        rear->next=temp;
        rear=rear->next;
    }
}

void dequeue () {
    if (front==NULL) cout<<"\nQueue is empty.";
    else {
        struct node* temp;
        temp=front;
        cout<<endl<<front->info<<" is deleted.";
        front=temp->next;
        delete(temp);
    }
}

void display() {
    if (front==NULL) cout<<"\nQueue is empty.";
    struct node* temp=front;
    while (temp!=NULL) {
        cout<<temp->info<<" ";
        temp=temp->next;
    }
}

int main() {
    int flag=1, choice;
    while (flag) {
        cout<<"\nEnter 1 to insert an element\nEnter 2 to delete an element\nEnter 3 to display the queue\nEnter 4 to exit\n";
        cin>>choice;
        switch(choice) {
            case 1:
                int element;
                cout<<"\nEnter an element: ";
                cin>>element;
                enqueue(element);
                break;
            
            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                flag=0;
                break;
        }
    }
}