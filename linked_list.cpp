#include <iostream>
using namespace std;

struct node {
    int info;
    struct node* next;
};

struct node* start=NULL;

struct node* create() {
    struct node* newnode;
    newnode=new(struct node);
    newnode->next=NULL;
    return(newnode);
}

void insert_beg(int element) {
    struct node* temp;
    temp=create();
    temp->info=element;
    temp->next=start;
    start=temp;
}

void insert_btwn(int posn, int element) {
    struct node* temp;
    temp=create();
    temp->info=element;
    if (posn==1) {
        insert_beg(element);
    }
    else {
        int count=1;
        struct node* temp2=start;
        while(count<posn-1) {
            temp2=temp2->next;
            count++;
            }
        temp->next=temp2->next;
        temp2->next=temp;
        }
}

void insert_end(int element) {
    struct node *temp;
    temp=create();
    temp->info = element;
    if (start==NULL) start=temp;
    else {
        struct node* temp2=start;
        while(temp2->next!=NULL) {
            temp2=temp2->next;
            }
        temp2->next=temp;
        temp->next=NULL;
        }
}

void del_beg() {
    struct node* temp;
    if (start==NULL) cout<<"\nLinked list is empty";
    else {
        temp=start;
        start=temp->next;
        cout<<endl<<temp->info<<" is deleted.";
        delete(temp);
    }
}

void del_btwn(int posn) {
    if (start==NULL) {
        cout<<"\nLinked list is empty";
    }
    else if(posn==1) {
        del_beg();
    }
    else {
        int count=1;
        struct node* temp=start;
        struct node * temp1;
        while(count<posn-1) {
            temp=temp->next;
            count++;
        }
        temp1=temp->next;
        cout<<endl<<temp1->info<<" is deleted";
        temp->next=temp->next->next;
        delete(temp1);
    }
}

void del_end() {
    if (start==NULL) cout<<"\nLinked list is empty.";
    else {
            struct node* temp=start;
            while (temp->next->next!=NULL) {
                temp=temp->next;
            }
        struct node* temp1=temp->next;
        cout<<endl<<temp1->info<<" is deleted.";
        temp->next=NULL;
        delete(temp1);
    }
}

void display() {
    struct node* temp;
    if (start==NULL) cout<<"\nLinked list is empty";
    else {
        temp=start;
        while(temp!=NULL) {
            cout<<temp->info<<"  ";
            temp=temp->next;
        }
        cout<<"\n";
    }
}

int main() {
    int choice, element, posn;
    bool flag=1;
    while (flag) {
        cout<<"\nEnter 1 to insert at beginning\nEnter 2 to display\nPress 3 to delete at beginning\nPress 4 to insert at end\nPress 5 to delete at end\nPress 6 to insert in between\nPress 7 to delete in between\nPress 8 to exit\n";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"\nEnter an element to add: ";
                cin>>element;
                insert_beg(element);
                break;
            case 2:
                display();
                break;
            case 3:
                del_beg();
                break;
            case 4:
                cout<<"\nEnter an element to add: ";
                cin>>element;
                insert_end(element);
                break;
            case 5:
                del_end();
                break;
            case 6:
                cout<<"\nEnter the position where you want to insert an element: ";
                cin>>posn;
                cout<<"\nEnter the element you want to insert: ";
                cin>>element;
                insert_btwn(posn,element);
                break;
            case 7:
                cout<<"\nEnter the position where you want to delete an element: ";
                cin>>posn;
                del_btwn(posn);
                break;
            case 8:
                flag=0;
                break;
        }
    }
}