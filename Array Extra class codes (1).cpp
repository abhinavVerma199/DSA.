Segregate Negative Positive Numbers:

#include <iostream>
using namespace std;

void shiftNegativeOneSide(int arr[], int n) {
  int j = 0;
  // j-> memory block -> jaha pr main negative 
  //number store kr skta hu

  for(int index=0; index<n; index++) {
    //index -> entire array ko traverse karne k liye 
    if(arr[index] < 0) {
      swap(arr[index], arr[j]);
      j++;
    }
  }
}

int main() {

  int arr[] = {1,7,12,10,11,40,0};
  int n = 7;

  shiftNegativeOneSide(arr, n);


  //print
  cout << "Printing the array " << endl;
  for(int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }


  return 0;
}

Sort COlors:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int left = 0;
        int right = n-1;

        while(index <= right) {

            if(nums[index] == 0) {
                swap(nums[index], nums[left]);
                left++;
                index++;
            }
            else if(nums[index] == 2) {
                swap(nums[index], nums[right]);
                right--;
                //catch -> no need of index++
                //index++
            }
            else {
                index++;
            }


        }

    }
};

Rotate Array:

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        
        for(int index=0; index<n; index++) {
            int newIndex = (index + k ) % n;
            ans[newIndex] = nums[index];
        }

        nums = ans;        
    }
};

Missing Number:

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(int index=0;index<n; index++) {
            sum = sum + nums[index];
        }

        int totalSum = ((n)*(n+1))/2;
        int ans = totalSum - sum;
        return ans;
    }
};

ReArrange Array: 


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int evenIndex = 0;
        int oddIndex = 1;
        vector<int> ans(n);

       while(index < n ) {
           if(nums[index] > 0) {
            ans[evenIndex] = nums[index];
            evenIndex += 2;
           }
           index++;
       }

       index = 0;
        while(index < n ) {
           if(nums[index] < 0) {
            ans[oddIndex] = nums[index];
            oddIndex += 2;
           }
           index++;
       }
       return ans;
    }
};

Row with Maximum Ones:


class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        //oneCOunt -> will store max number of 1's in a row
        int oneCount = INT_MIN;
        //rowNo -> will store index of max no. of 1's wali row
        int rowNo ;

        for(int i=0; i<n; i++) {
            //hr row start hone se phle initialise count with 0
            int count = 0;
            for(int j=0; j< mat[i].size(); j++) {
                //if 1 found, then increment count
                if(mat[i][j] == 1) {
                    count++;
                }
            }
            //after row completion, compare count with oneCount
            if(count > oneCount) {
                oneCount = count;
                rowNo = i;
            }

        }

        ans.push_back(rowNo);
        ans.push_back(oneCount);
        return ans;
        
    }
};


Rotate Image:

class Solution {
public:

    void reverseVector(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;

        while(start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        
    }
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        //transpose
        for(int i=0; i<n; i++) {
            for(int j=i; j<matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse -> 2D MATTIX ki ssaari rows ko 
        //kitni rows h -> 0 > (n-1)
        for(int i=0; i<n; i++) {
            //hr row ko reverse krna h 
            reverseVector(matrix[i]);
        }

        
    }
};