//
//  main.cpp
//  SearchingAlgorithms
//
//  Created by Sal on 1/7/23.
//

#include <iostream>
int binarySearch(int n, int arr[], int s) {
    if(s <= 1) {
        return -1;
    }
    int start = 0;
    int end = s -1;
    int mid;
    
    while(start <= end) {
        mid = start + (end + start) / 2;
        if(arr[mid] > n) {
            end = mid -1;
        }else if(arr[mid] < n) {
            start = mid +1;
        }else{
            return mid;
        }
    }
    return -1;
}
int main() {
  int arr[] = {-100, 0, 0, 1, 4, 4, 5, 5, 95, 200};
    int arrSize = 11;
  int searchee = 0;
    int index = binarySearch(searchee, arr, arrSize);
  if(index != -1) std::cout << "Found at: " << index << std::endl;
}
