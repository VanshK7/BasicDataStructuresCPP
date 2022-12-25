#include <iostream>
using namespace std;

void search(int arr[], int size, int x) {
    int i;
    bool flag=false;
    for (i=0; i<size; i++) {
        if (arr[i]==x) {
            flag=true;
            break;
        }
    }
    if (flag) cout<<"\nElement "<<x<<" found! Position: "<<i+1;
    else cout<<"\nElement not found!";
}

int main() {
    int size, x;
    cout<<"Enter the number of elements: ";
    cin>>size;
    int arr[size];
    cout<<"\nEnter the elements of the array:\n";
    for (int i=0; i<size; i++) {
        cin>>arr[i];
    }
    cout<<"\nEnter the element to search: ";
    cin>>x;

    search(arr, size, x);
}