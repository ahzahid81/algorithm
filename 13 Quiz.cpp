/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<char> st;
    st.push('a');
    st.push('b');
    st.push('b');
    st.push('a');
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = { 1,4,9 };
    v.clear();
    v.push_back(6);
    cout << v.size() << '\n';
    return 0;
}
