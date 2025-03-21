#include<bits/stdc++.h>
using namespace std;


void printArr(vector<int>&arr) {
    int n = arr.size();
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
}

// selection sort

void selectionSort(vector<int>&arr) {
    int n = arr.size();
    for(int i = 0;i < n;i++) {
        int miniIndex = i;
        int j = i + 1;
        while(j < n) {
            if(arr[j] < arr[miniIndex]) {
                miniIndex = j;
            }
            j++;
        }
        swap(arr[miniIndex],arr[i]);
    }
}


/// merge sort

void mergeTwoSortedArrays(vector<int>&arr,int low,int mid,int high) {
    int i = low;
    int j = mid + 1;

    vector<int>temp;
    while( i <= mid && j <= high) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;
    for(int i = low;i <= high; i++) {
        arr[i] = temp[k];
        k++;
    }
}

void mergeSort(vector<int>&arr,int low,int high) {
    if(low >= high) {
        return ;
    }
    int mid = (low + high)/2;
    mergeSort(arr,0,mid);
    mergeSort(arr,mid+1,high);
    mergeTwoSortedArrays(arr,low,mid,high);
}


// insertion sort
void insertionSort(vector<int>&arr) {
    int n = arr.size();
    for(int i = 0;i < n;i++) {
        int j = i;
        while( j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j] , arr[j-1]);
            j--;
        }
    }
}


// bubble sort
void bubbleSort(vector<int>&arr) {
    int n = arr.size();
    for(int i = 0;i<n ;i++) {
       for(int j = 0 ; j < n - i -1; j++) {
        if(arr[j] > arr[j+1]) {
            swap(arr[j],arr[j+1]);
        }
    }
} 
}


// quick sort

int partition(vector<int>&arr,int low,int high) {
    int i = low;
    int j = high;
    int pivot = arr[low];

    while(i < j) {
        while(arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while(arr[j] >= pivot && j >= low + 1) {
            j--;
        }

        if(i < j) {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int>&arr,int low,int high) {
    if(low < high) {
        int pivotIndex = partition(arr,low,high);
        quickSort(arr,low,pivotIndex - 1);
        quickSort(arr,pivotIndex + 1, high);
    }
}

int powerXN(int x, int n) {
    if(n == 0) {
        return 1;
    }
    return powerXN(x,n-1) * x;
}

// brute force O(n^2);
int missingNumber(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= n; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i;
        }
    }
    return -1;
}

// using XOR O(n);
// xor of same number is always 0
// eg 3 ^ 3  = 0 etc etc.

int XorMissingNumber(vector<int>& arr) {
    int n = arr.size();
    int Xor = 0;

    for (int i = 0; i < n; i++) {
         Xor ^= i^arr[i];
    }
    return Xor^n;
}


int main() {
    int n;
    cin >> n;
    // vector<int>arr;
    // for(int i=0;i<n;i++) {
    //     int ele;
    //     cin >> ele;
    //     arr.push_back(ele);
    // }

    // quickSort(arr,0,n-1);
    // printArr(arr);

    // int x,n;
    // cin >> x >> n;
    // cout << powerXN(x,n);
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << XorMissingNumber(arr);
    return 0;
}