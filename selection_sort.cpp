#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void selectionSort(int arr[], int n)
{
    int i,j,min_in;
    for(i=0;i<n;i++)
    {
        min_in = i;
        for(j=i+1;j<n;j++)
            if (arr[j] < arr[min_in])
                min_in = j;
        int temp=arr[i];
        arr[i]=arr[min_in];
        arr[min_in]=temp;
        cout<<"\nArray after iteration number "<<i+1<<endl;
        print(arr, n);
    }
}
int main()
{
    int size;
    cout<<"Enter the number of elements: ";
    cin>>size;
    int arr[size];
    cout<<"\nEnter the elements of the array:\n";
    for (int i=0; i<size; i++) cin>>arr[i];

    int i,j,temp;
    cout<<"Unsorted Array :";
    print(arr,size);
    selectionSort(arr,size);
    cout<<"Sorted Array :";
    print(arr,size);
    return(0);
}