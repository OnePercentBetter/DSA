//
//  Array Implementation
//
//  Created by Sal on 8/31/22.
//

#include <iostream>

//BASIC IMPLEMENTATION
class ArrayList {
private:
    int capacity; // Not to be mistook for size
    int numElements; // Size, not to be mistook for capacity
    int * arr; // Array that grows dynamically
public:
    ArrayList(int size) {
        capacity = size;
        //Because it's being initialized, we don't know the number of existing elements
        numElements = 0;
        arr = new int[size];
        
    }
    
    // Enlargen
    void resize() {
        int* temp = new int[capacity * 2];
        
        for(int i = 0; i < numElements; i++) {
            temp[i] = arr[i];
        }
        capacity *= 2;
        
        //Deleting existing memory
        delete [] arr;
        
        arr = temp;
    }
    
    void push(int num) {
        if(capacity > numElements) {
            arr[numElements++] = num;
        } else {
            resize();
            arr[numElements++] = num;
        }
    }
    
    int getAt(int i) {
        return arr[i];
    }
    
    int length() {
        return numElements;
    }
    
    void print() {
        for(int i = 0; i < numElements; i++) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    
};

//Removing Even Numbers
int * removeEven(int *& Arr, int size) {
    int odd = 0;
    for(int i = 0; i < size; i++) {
        if(Arr[i] % 2 != 0) {
            if(odd != i) {
                Arr[odd] = Arr[i];
            }
            ++odd;
        }
    }
    int * temp = new int[odd];
    for(int i = 0; i < odd; i++) {
        temp[i] = Arr[i];
    }
    delete [] Arr;
    Arr = temp;
    return Arr;
}

//Merging Sorted Arrays
int * mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size)
{
    int * arr3 = new int[arr1Size + arr2Size];
    int j = 0; int r = 0; int k = 0;

    while(j < arr1Size && r < arr2Size) {
        if(arr1[j] > arr2[r]) {
            arr3[k++] = arr2[r++];
        }else {
            arr3[k++] = arr1[j++];
        }
    }
     while (j < arr1Size)
        arr3[k++] = arr1[j++];

    while (r < arr2Size)
        arr3[k++] = arr2[r++];

    
    return arr3; // returning array
}

//Return 2 elements of arr that sum to the given value
int * findSum(int arr[], int value, int size) {
  sort(arr, 0, size -1); int p1 = 0; int p2 = size -1;
  int * vect = new int[2];

  while(p1 != p2) {
    if(arr[p1] + arr[p2] != value) {
      if(arr[p1] + arr[p2] > value) {
        p2--;
      }else{
        p1++;
      }
    }else {
      vect[0] = arr[p1];
      vect[1] = arr[p2];
      return vect;
    }
  }
    return arr;
}

//Find product of all elements excluding index i
int * findProduct(int arr[], int size) {
    int n = size; int temp = 1; int i;
    
    int * product = new int[n];
    
    // All Elements to the left
    for(i = 0; i < n; i++) {
        product[i] = temp;
        temp *= arr[i];
    }
    temp = 1;
    
    //All Elements to the right
    for(i = n-1; i >= 0; i--) {
        product[i] = temp;
        temp *= arr[i];
    }
    
    return product;
}

//Returns minimum value from given Array
int findMinimum(int arr[], int size) {
    int min = arr[0];
    for(int i = 1; i < size;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
//Return first unique number
int findFirstUnique(int arr[], int size) {
    //This is cheating a little, but it's better than bruteforce
    sort(arr, 0, size);
    for(int i = 0; i < size -1 ; i++) {
        if(arr[i] != arr[i+1]) {
            return arr[i];
        }
    }
    return - 1;
}

//Return 2nd maximum Value in an array
int findSecondMaximum(int arr[], int size) {
    int secondmax = INT_MIN;
    int index = 0;
    // Write your code here
    for(int i = 0; i < size; i++) {
        if(arr[i] > secondmax) {
            secondmax = arr[i];
            index = i;
        }
    }
    secondmax = INT_MIN;
    for(int i = 0; i < size; i++) {
        if(i != index && arr[i] > secondmax) {
            secondmax = arr[i];
        }
    }
    return secondmax;
}

//Rotate Array by 1 to the right
void rightRotate(int arr[], int size) {
  int last = arr[size-1];
  for(int i = size-2; i >= 0; i--) {
      arr[i+1] = arr[i];
  }
  arr[0] = last;
}

//Arrange All negative values to the left and Positive Values to the right
void reArrange(int arr[], int size)
{
    int j = 0;
    for (int i = 0; i < size; i++) {
        if(arr[i] < 0) {
          if(j != i) {
            swap(arr[j], arr[i]);
          }
          j++;
        }
    }
}

//Arrange Array by max/min/max/min/max...
void maxMin(int arr[], int size) {
  int p1 = 0, p2 = size -1; int k = 0;
  int * result = new int[size];
  while(p1 <= p2) {
    result[k++] = arr[p2--];
    result[k++] = arr[p1++];
  }
  for(int i = 0; i < size; i++) {
      arr[i] = result[i];
  }
  arr = result;

  delete [] result;

}

//MaximumSubArray via Kadane's Algo
int maximumSubArray(int arr[], int size) {
    if(size < 1) {
        return 0;
    }
    int cMax = arr[0];
    int gMax = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < 0) {
            cMax = arr[i];
        }else {
            cMax += arr[i];
        }
        if(gMax < cMax) {
            gMax = cMax;
        }
    }
    return gMax;
}

int main(int argc, const char * argv[]) {
    
    ArrayList arr(1);
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);
    arr.push(5);
    std::cout << "Length: " << arr.length() << std::endl;
    std::cout << "Output: "; arr.print();
    std::cout << "Index 4: " << arr.getAt(4) << std::endl;
    return 0;
}
