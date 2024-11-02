// Question 1: first non repeating character in a stream
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "ababc";
    queue<char> q;
    int freq[26] = {0};
    // har char ko pakdo frequency store kro queue mai dalo aur check kro
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch - 'a']++;
        // queue ke ander push taki track rakh pao
        q.push(ch);

        // answer find kro
        while (!q.empty())
        {
            char frontChar = q.front();
            // check freq
            if (freq[frontChar - 'a'] > 1)
            {
                // not an answer
                q.pop();
            }
            else
            {
                //==1 vala case
                // unique character
                cout << frontChar << " ";
                break;
            }
        }
        if (q.empty())
        {
            // no answer found
            cout << '#' << " ";
        }
    }
    return 0;
}
// Question 2: Gas Station Leetcode->134
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        balance = balance + gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }
    if (balance - deficit >= 0)
        return start;
    else
        return -1;
}

// Question 3:Sliding windows Maximum
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;
    int size = nums.size();
    // first window process till k size
    for (int i = 0; i < k; i++)
    {
        int ele = nums[i];
        // push elements in the queue and remove chote vale elements
        while (!dq.empty() && ele > nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // processs the remaining window Removal and Insertion
    for (int i = k; i < size; i++)
    {

        ans.push_back(nums[dq.front()]);

        // remove
        if (i - dq.front() >= k)
            dq.pop_front();
        int ele = nums[i];
        // push elements in the queue and remove chote vale elements
        while (!dq.empty() && ele > nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // handle last window
    ans.push_back(nums[dq.front()]);

    return ans;
}
