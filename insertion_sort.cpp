x#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i=0; i<size; i++) cout<<arr[i]<<" ";
}

void insertionSort(int arr[], int size) {
    int i;
    for (i=1; i<size; i++) {
        int current=arr[i];
        int j;
        for (j=i-1; j>=0 && arr[j]>current; j--) {
            arr[j+1]=arr[j];
        }
        arr[j+1]=current;
        cout<<"\nAfter iteration number "<<i<<endl;
        printArray(arr, size);
    }
    cout<<"\n\nThe sorted array is"<<endl;
    printArray(arr, size);
}

int main() {
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array:\n";
    for (int i=0; i<size; i++) {
        cin>>arr[i];
    }
    insertionSort(arr, size);
}