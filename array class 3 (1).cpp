#include <iostream>
#include<limits.h>
#include<vector>
using namespace std;

void printArray(int arr[][4], int row, int col) {
  for(int i=0; i<row; i++ ) {
    for(int j=0; j<col; j++) {

      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void colWisePrint(int arr[][4], int row, int col ){
  for(int i=0; i<col; i++) {
    for(int j=0; j<row; j++) {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

bool findTarget(int arr[][4], int row, int col, int target ) {
  
  for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {
      if(arr[i][j] == target) {
        //if found, return true
        return true;
      }
    }
  }
  //iss line pr tabhi aa skte ho,
  //jab saare k saare elements check
  //ho chuke honge and target nahi mila hoga
  //return krdo false;
  return false;
}

int findMax(int arr[][4], int row, int col) {
  int maxAns = INT_MIN;

  for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {
      
      if(arr[i][j] > maxAns ) {
        maxAns = arr[i][j];
      }
      
    }
  }
  return maxAns;
}

int findMin(int arr[][4], int row, int col ){
  int minAns = INT_MAX;
  for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {

      if(arr[i][j] < minAns) {
        minAns = arr[i][j];
      }
      
    }
  }
  return minAns;
}

void rowWiseSum(int arr[][4], int row, int col ){
  for(int i=0; i<row; i++) {
    
    int sum = 0;
    
    for(int j=0;j<col;j++) {
      
      sum = sum + arr[i][j];
      
    }
    
    cout << sum << endl;
  }
}

void transpose(int arr[][4], int row, int col ) {
  
  for(int i=0; i<row; i++) {
    
    for(int j=i; j<col; j++) {
      
      swap(arr[i][j], arr[j][i]);
      
    }
  }
}

int main() {


  //create a 2D array 
  //int arr[3][3];


  //iniitialse
  // int arr[3][4] = {
  // {1,2,3,4},
  // {5,6,7,8},
  // {9,10,1,11}
  // };

  // int brr[] = {1,2,3,4};

  // int crr[][4] = {
  // {1,2,3,4},
  // {5,6,7,8},
  // {9,10,1,11}
  // };

  // int drr[][4] = {
  // {1,2,3,4},
  // {5,6,7,8},
  // {9,10,1,11}
  // };

  // int arr[3][4] = {
  //        {1,2,3,4},
  //        {5,6,7,8},
  //        {9,10,1,11}
  //        };

  // int row = 3;
  // int col = 4;
  // printArray(arr, row, col);
  // colWisePrint(arr,  row,  col);

  //input
  // int arr[3][3];
  // int row = 3;
  // int col = 3;

  // for(int i=0; i<row; i++) {
  //  for(int j=0; j<col; j++) {
  //    cout << "Enter the input for row index: " << i << " column index: " << j << endl;
  //    cin >> arr[i][j] ;
  //  }
  // }

  // int arr[4][4] = {
  //        {1,2,3,4},
  //        {5,6,70,8},
  //        {9,10,1,11},
  //        {12,24,46,89}
  //        };
  // int row = 4;
  // int col = 4;
  
  // cout<< endl << "Printing before transpose" << endl;
  // printArray(arr, row, col);

  // cout<< endl  << "Doing transpose" << endl;
  // transpose(arr, row,  col);

  // cout<< endl  << "Printing after transpose" << endl;
  // printArray(arr, row, col);

  //rowWiseSum(arr, row,  col);
  
  //cout << "Printing the max No. : " << findMax(arr, row, col ) << endl;

  // int target = 110;

  // cout << "Found or Not: " << findTarget(arr, row, col, target) << endl;


  //int arr[5];
  
  // vector<int> arr;
  // vector<int> arr(5);
  // vector<int> arr(5,101);


  //insert
  // arr.push_back(4);
  // arr.push_back(8);
  // arr.push_back(12);
  // arr.push_back(11);
  // arr.push_back(4);

  // cout << arr.size() << endl;

  // cout << arr.empty() << endl;
  

  // cout << "Sizxe of vector: " << v.size();

  // cout << endl << "Printing vector" << endl;
  // for(int i=0; i<v.size(); i++) {
  //  cout << v[i] <<" ";
  // }cout << endl;

  //2D Array
  // vector< vector<int> > arr(5, vector<int>(10,-1));
  // //row size -> arr.size()
  // for(int i=0; i<arr.size(); i++) {
  //  for(int j=0; j<arr[i].size(); j++) {
  //    cout << arr[i][j] << " ";
  //  }
  //  cout << endl;
  // }

  //Jagged Array  - HW

  vector< vector<int> > brr;


  vector<int> vec1(10,0);
  vector<int> vec2(5,1);
  vector<int> vec3(7,0);
  vector<int> vec4(8,1);
  vector<int> vec5(20,0);

  brr.push_back(vec1);
  brr.push_back(vec2);
  brr.push_back(vec3);
  brr.push_back(vec4);
  brr.push_back(vec5);

  for(int i=0; i<brr.size(); i++) {
    for(int j=0; j<brr[i].size(); j++) {
      cout << brr[i][j] << " ";
    }
    cout << endl;
  }
  
  
  return 0;
}