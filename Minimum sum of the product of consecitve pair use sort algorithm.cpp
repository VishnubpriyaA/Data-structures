//We are given an array of even size, we have to sort the array in such a way that the sum of product of consecutive pair elements is minimum also we have to find that minimum sum . 
//Input : arr[] = {9, 2, 8, 4, 5, 7, 6, 0}
//Output : Minimum sum of the product of 
//         consecutive pair elements: 74
//         Sorted arr[] for minimum sum: 
//         {9, 0, 8, 2, 7, 4, 6, 5}
//Explanation : We get 74 using below
//calculation in rearranged array.
//9*0 + 8*2 + 7*4 + 6*5 = 74

#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int minSumProduct(int arr[], int n) {
    bubbleSort(arr, n);
    int minSum = 0;
    for (int i = 0; i < n / 2; ++i) {
        minSum += arr[i] * arr[n - i - 1];
    }
    return minSum;
}
int main() {
    int arr[10],n;
    cout<<"Enter the no of elements of the array:";
    cin>>n;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int minSum = minSumProduct(arr, n);
    cout << "Minimum sum of the product of consecutive pair elements: " << minSum << endl;
    cout << "Sorted arr[] for minimum sum: ";
    for (int i = 0; i < n / 2; ++i) {
        if (i != 0) cout << ", ";
        cout << arr[n - i - 1] << ", " << arr[i];
    }
    return 0;
}
