//
//  main.cpp
//  Sorting Algorithms
//
//  Created by Sal on 1/7/23.
//
#include "AuxiliaryFunctions.hpp"
#include <iostream>

void selectionSort(int* arr, int s) {
  for(int i = 0; i < s; i++) {
      int smallest = INT_MAX;
      int index = 0;
      for(int j = i; j < s; j++) {
          if(arr[j] < smallest) {
              smallest = arr[j];
              index = j;
          }
      }
      swap(arr[i], arr[index]);
  }
}
void bubbleSort(int* arr, int s) {
  for(int i = 0; i < s - 1; i++) {
    for(int j = 0; j < s - i - 1; j++) {
      if(arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j+1]);
      }
    }
  }
}
void insertionSort(int* arr, int s) {
    for(int i = 1; i < s; i++) {
        int element = arr[i];
        int index = i-1;
        // 2 7 5 3
        // 2   7 5
        while(index >= 0 && arr[index] > element) {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index +1] = element;
    }
}
void merge(int* arr, int left, int right, int mid) {
    /*
     1. Set Size of new Arrays
     2. Initialize Arrays
     3. Copy data into new array
     4. initialize the starting point for subarray 1 and 2
     5. initialize starting index of the actual array
     6. Start comparing from the two temporary arrays */
    
    int subLeft = mid - left + 1;
    int subRight = right - mid;
    
    int *leftArray = new int[subLeft];
    int *rightArray = new int[subRight];
    
    for(int i = 0; i < subLeft; i++) {
        leftArray[i] = arr[left + i];
    }
    for(int i = 0; i < subLeft; i++) {
        rightArray[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < subLeft && j < subRight) {
        if(leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }else{
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    //One of either arrays hasn't finished
    while( i < subLeft) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while( j < subRight) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
    
}
void mergeSort(int* arr, int left, int right) {
    if(left < 0 || right < 0) {
        return;
    }
    if(left < right) {
        int mid = (left + right) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, right, mid);
    }
}
int pickingPivot(int start, int end) {
    int first = start + (std::rand() % (end - start + 1));
    int second = start + (std::rand() % (end - start + 1));
    int third  = start + (std::rand() % (end - start + 1));
    return max(min(first, second), min(max(first, second), third));
    
}
int partition(int arr[], int start, int end) {
    int pivot = pickingPivot(start, end);
    // Put Pivot at the end
    std::swap(arr[end], arr[pivot]);
    pivot = arr[end];
    int i = start, j;
    for(j = start; j < end -1; j++) {
        if(arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[end]);
    return i;
    
}
void quickSort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot -1);
    quickSort(arr, pivot + 1, end);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {5,4,1,0,5,95,4,-100,200,0};
    quickSort(arr, 0, 9);
    cout << "Sorted array: ";
    for(int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
