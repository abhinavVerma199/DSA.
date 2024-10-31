#include <bits/stdc++.h>
using namespace std;
void reverseQueue(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}
void reverseQueueRec(queue<int> &q)
{
    // base case
    if (q.empty())
        return;
    int top = q.front();
    q.pop();
    reverseQueueRec(q);
    q.push(top);
}
void reverseKEle(queue<int> &q, int k)
{
    int n = q.size();
    // edge case
    if (k > n || k == 0)
        return;
    stack<int> st;
    while (k--)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // cout << n << endl;
    // n-k elements are still in front unhe piche krdo
    for (int i = 0; i <= (n - k); i++)
    {
        int front = q.front();
        q.pop();
        q.push(front);
    }
}
void interleaveQueue(queue<int> &first)
{
    queue<int> second;
    // push first half in second
    int n = first.size();
    for (int i = 0; i < n / 2; i++)
    {
        int temp = first.front();
        first.pop();
        second.push(temp);
    }
    // merge in original QUeue
    // for (int i = 0; i < n / 2; i++)
    while (!second.empty())
    {
        int temp = second.front();
        second.pop();
        first.push(temp);
        temp = first.front();
        first.pop();
        first.push(temp);
    }
}

// first -ve integer in every k window
void PintFirstNeg(int *arr, int n, int k = 3)
{
    deque<int> dq;
    // process first k elements
    for (int i = 0; i < k; i++)
    {
        int ele = arr[i];
        if (ele < 0)
            dq.push_back(i);
    }
    // print ans

    // process remaining window
    //  ->removal and addition
    for (int i = k; i < n; i++)
    {
        if (dq.empty())
            cout << "0" << endl;
        else
        {
            cout << arr[dq.front()] << " ";
        }
        // purani window ka ans->
        // cout << arr[dq.front()] << " ";
        // removal
        // out of range index ko q mai se remove krdo

        if (i - dq.front() >= k)
            dq.pop_front();

        // addition
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // last window ka alag se process kro
    if (dq.empty())
        cout << "0" << endl;
    else
    {
        cout << arr[dq.front()] << " ";
    }
    cout << endl;
}
int main()
{
    // reverse a queue
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    // reverseQueue(q);
    // reverseQueueRec(q);
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    // reverse k element
    // reverseKEle(q, 3);
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    // interleave first and second half of queue
    // interleaveQueue(q);
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    // sliding window
    int arr[7] = {2, -5, 4, -1, -2, 0, 5};
    int n = 7;
    int k = 3;
    PintFirstNeg(arr, n, k);
    return 0;
}