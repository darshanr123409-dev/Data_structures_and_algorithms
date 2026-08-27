#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void reverseStack_btm(stack<int>& st, int val) {

        if (st.empty()) {
            st.push(val);
            return;
        }

        int temp = st.top();
        st.pop();

        reverseStack_btm(st, val);

        st.push(temp);
    }

    void reverseStack(stack<int>& st) {

        if (!st.empty()) {

            int temp = st.top();
            st.pop();

            reverseStack(st);

            reverseStack_btm(st, temp);
        }
    }
};