#include <iostream>
using namespace std;

void binary_search(int arr[], int size, int x) {
    int mid=size/2, start=0, end=size-1;
    bool found=false;

    while(start<=end) {
        if (x==arr[mid]) {
            cout<<"\nElement "<<x<<" found at position: "<<mid+1;
            found=true;
            break;
        }

        else if (x>arr[mid]) {
            start=mid+1;
            end=size-1;
            mid=(start+end)/2;
        }
        
        else {
            start=0;
            end=mid-1;
            mid=(start+end)/2;
        }
    }

    if (!found) cout<<"\nElement not found!";
}

int main() {
    int size, x;
    cout<<"\nEnter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array in ascending order:\n";
    for (int i=0; i<size; i++) {
        cin>>arr[i];
    }

    cout<<"\nEnter an element to search: ";
    cin>>x;

    binary_search(arr, size, x);
}