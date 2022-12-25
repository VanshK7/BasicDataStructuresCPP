#include <iostream>
using namespace std;
#define size 5

struct Queue {
    int Q[size];
    int front, rear;
} q1;

int isFull() {
    if ((q1.rear==q1.front-1) || (q1.rear==size-1) && (q1.front==0)) {
        cout<<"Queue is full.\n";
        return(1);
    }
    else {
        return(0);
    }
}

int isEmpty() {
    if (q1.front==-1 && q1.rear==-1) {
        cout<<"Queue is empty.\n";
        return(1);
    }
    else {
        return(0);
    }
}

int enqueue(int element) {
    if (isFull()) {
        return 0;
    }
    else {
        if (isEmpty()) {
            q1.front=0;
            q1.rear=0;
        }
        else if (q1.rear==size-1) {
            q1.rear=0;
        }
        else {
            q1.rear++;
        }
        q1.Q[q1.rear]=element;
        return(1);
    }
}

void dequeue() {
    int element;
    if (isEmpty()) {
        cout<<"Queue is empty, element can't be deleted.\n";
    }
    else {
        element=q1.Q[q1.front];
        if (q1.front==q1.rear) {
            q1.front=-1;
            q1.rear=-1;
        }
        else if (q1.front==size-1) {
            q1.front=0;
        }
        else {
            q1.front++;
        }
        cout<<"Element deleted: "<<element<<endl;
    }
}

void display() {
    if (q1.front<=q1.rear) {
        for (int i=q1.front; i<=q1.rear; i++) {
            cout<<q1.Q[i]<<" ";
        }
        cout<<"\n";
    }
    else {
        for (int i=q1.front; i<=size-1; i++) {
            cout<<q1.Q[i]<<" ";
        }
        for (int i=0; i<=q1.rear; i++) {
            cout<<q1.Q[i]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    q1.front=-1, q1.rear=-1;
    int flag=1;
    while (flag) {
        int choice;
        cout<<"Enter your choice:\n1. Insert Element   2. Delete Element   3. Display   4. Exit\n";
        cin>>choice;
        switch (choice) {
            case 1:
                int element_to_insert;
                cout<<"Enter the element to insert: ";
                cin>>element_to_insert;
                enqueue(element_to_insert);
                break;
            
            case 2:
                dequeue();
                break;
            
            case 3:
                display();
                break;
            
            case 4:
                flag=0;
        }
    }
}