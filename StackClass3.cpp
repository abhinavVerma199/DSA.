#include <bits/stdc++.h>
using namespace std;
// next smaller element
vector<int> nextSmaller(int *arr, int n)
{
    stack<int> st;
    vector<int> ans;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(curr);
    }
    return ans;
}
// prev Smaller
vector<int> prevSmaller(int *arr, int n)
{
    stack<int> st;
    vector<int> ans;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(curr);
    }
    return ans;
}

int main()
{
    int arr[5] = {8, 4, 6, 2, 3};
    int n = 5;
    vector<int> ans = nextSmaller(arr, n);
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> ans1 = prevSmaller(arr, n);

    for (auto i : ans1)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
// Largest rectangle in histogram
class Solution
{
public:
    vector<int> nextSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            if (st.top() == -1)
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    // prev Smaller
    vector<int> prevSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        // int n=heights.size();
        // if(n==1)return heights[0];
        // vector<int>  leftToRight=prevSmaller(heights,n);
        // vector<int> rightToLeft=nextSmaller(heights,n);
        // // rev krdo
        // // reverse(rightToLeft.begin(),rightToLeft.end());
        // vector<int>area(leftToRight.size());
        // for(int i=0;i<leftToRight.size();i++){
        //     int width=rightToLeft[i]-leftToRight[i]-1;
        //     int length=heights[i];
        //     area[i]=width*length;
        // }
        // int maxi=INT_MIN;
        // for(int i=0;i<area.size();i++){
        //     maxi=max(maxi,area[i]);
        // }
        // return maxi;
        int area = INT_MIN;

        for (int i = 0; i < heights.size(); i++)
        {
            int j = i;
            int k = i;
            int a = 1; // Reset 'a' for each histogram bar

            // Move left while the bar is higher
            while (j >= 0 && heights[j] >= heights[i])
            {
                a++;
                j--;
            }

            // Move right while the bar is higher
            while (k < heights.size() && heights[k] >= heights[i])
            {
                a++;
                k++;
            }

            int multi = heights[i] * a;
            area = std::max(area, multi);
        }

        return area;
    }
};