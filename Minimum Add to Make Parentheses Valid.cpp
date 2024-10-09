#include <iostream>
#include <stack>
using namespace std;

int minAddToMakeValid(string s) {
    stack<char> st;

    for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')' && !st.empty() && st.top() == '(') {           // T = O(n) , S = O(n)
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    return st.size();
}

int minAddToMakeValid(string s) {
    int open = 0, close = 0;

    for (char ch : s) {
        if (ch == '(')
            open++;
        else {                                                              // T = O(n) , S = O(1)
            if (open > 0)
                open--;
            else {
                close++;
            }
        }
    }

    return open + close;
}

int main() {
    string s = "())(";
    cout << "Minimum additions to make valid: " << minAddToMakeValid(s) << endl;
    return 0;
}
