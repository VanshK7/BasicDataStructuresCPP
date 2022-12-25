#include <iostream>
using namespace std;
 
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        cout<<"\nArray after iteration number "<<i+1<<endl;
        printArray(arr, n);
    }
}

int main()
{
    int N;
    cout<<"Enter the number of elements: ";
    cin>>N;
    int arr[N];
    cout<<"Enter the elements of the array:\n";
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    } 
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}