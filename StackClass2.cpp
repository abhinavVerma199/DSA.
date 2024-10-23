#include <bits/stdc++.h>
using namespace std;
// implement 2stack using 1 array
class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size)
    {
        this->size = size;
        this->arr = new int[size];

        this->top1 = -1;
        this->top2 = size;
    }
    void push1(int data)
    {
        top1++;
        if (abs(top2 - top1) == 1)
        {
            cout << "Stack OverFlow!" << endl;
            return;
        }

        arr[top1] = data;
    }
    void push2(int data)
    {
        top2--;
        if (abs(top2 - top1) == 1)
        {
            cout << "Stack OverFlow!" << endl;
            return;
        }

        arr[top2] = data;
    }
    void pop1()
    {
        if (arr[top1] == -1)
        {
            cout << "Stack underFlow!" << endl;
            return;
        }
        arr[top1] = 0;
        top1--;
    }
    void pop2()
    {
        if (arr[top2] == size)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        arr[top2] = 0;
        top2++;
    }
    int getTop1()
    {
        return arr[top1];
    }
    int getTop2()
    {
        return arr[top1];
    }
};
// check for redundant bracjet
bool checkRedundantBracket(string s)
{
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (st.size() != 0 && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                    operatorCount++;
                st.pop();
            }
            st.pop();
            if (operatorCount == 0)
                return 1;
        }
    }
    return 0;
}
int main()
{
    // Stack st(5);
    // st.push1(1);
    // st.push1(2);
    // st.push1(3);
    // st.push2(4);
    // cout << st.getTop1() << endl;
    string str = "((a+b)*(a+b))";
    cout << checkRedundantBracket(str) << endl;
    return 0;
}