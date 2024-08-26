#include <iostream>
using namespace std;

void solve(int& a) {
  a++;

  cout<< "Printing inside solve function: " << a << endl;
}

void solve(int arr[], int n) {
  arr[0] = 100;
}

int getUnique(int arr[], int n) {
  int ans = 0;
  for(int i=0; i<n; i++) {
    ans = ans^arr[i];
  }
  return ans;
}

void sortZeroOne(int arr[], int n) {
  int zeroCount = 0;
  int oneCount = 0;
  //stepA: Count 0 and 1
  for(int i=0; i<n; i++) {
    if(arr[i] == 0) 
      zeroCount++;
    if(arr[i] ==1) 
      oneCount++; 
  }

  //Step B: place all zeroes first
  // int i;
  // for(i =0; i<zeroCount; i++) {
  //  arr[i] = 0;
  // }
  // //Step B: place all ones first
  // for(int j = i; j<n ;j++) {
  //  arr[j] = 1;
  // }

  //EASY WAY
  int index = 0;

  while(zeroCount--) {
    arr[index] = 0;
    index++;
  }

  while(oneCount--) {
    arr[index] = 1;
    index++;
  }
  
}


//right ki disha me shift
void shiftArray(int arr[], int n) {
  //Step 1
  int temp = arr[n-1];

  //step2
  //shift -> arr[i] = arr[i-1]
  for(int i= n-1; i>=1; i--) {
    arr[i] = arr[i-1];
  }

  //step3 copy temp into 0th indecx
  arr[0] = temp;
}

int main() {


  int arr[] = {10,20,30,40,50,60};
  int n= 6;

  shiftArray(arr, n);

  //printy
  for(int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }


  // int arr[] = {0,1,0,1,0,1,1,1,1,0,0,0,0,0};
  // int n = 14;

  // sortZeroOne(arr, n);

  // //printing the array
  // for(int i=0; i<n; i++) {
  //  cout << arr[i] << " ";
  // }

  
  // int arr[] = {1,2,3,4,};
  // int n = 4;

  // for(int i=0; i<n; i++ ) {
  //  for(int j=0; j<n; j++) {
  //    for(int k=0; k<n; k++) {
  //      cout << arr[i] <<" " << arr[j] << " " << arr[k] << endl;
  //    }
  //  }
  // }


  // int arr[] = {10,20, 30};
  // int n = 3;

  // for(int i=0; i<n; i++) {
  //  for(int j=0; j<n; j++) {
  //    cout << arr[i] <<", " << arr[j] << endl;
  //  }
  // }

  // int arr[] = {2,10,11,10,2,13,15,13,15};
  // int n = 9;

  // int finalAns = getUnique(arr, n) ;
  // cout << "Final answer is: " << finalAns << endl;

  
  // int arr[] = {1,2,4};
  // int size = 3;

  // solve(arr, size);

  // ///printing the array
  // for(int i=0; i<size; i++) {
  //  cout << arr[i] << " ";
  // }
  // cout << endl;
  
  // int a = 50;
  // cout << a << endl;
  // //int *b= &a;
  // int& b = a;
  // //reference variable -> same memory location, different names
  // cout << b << endl;

  
  // int a = 5;
  // solve(a) ;

  // cout << "Printing inside main function: " << a << endl;

  
  return 0;
}};