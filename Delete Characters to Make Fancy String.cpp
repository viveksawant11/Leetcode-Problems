#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int n = s.size();
        int cnt = 1;

        res += s[0];

        for (int i = 1 ; i < n ; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }

            if (cnt < 3)
                res += s[i];
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "aaabaaaa";
    string result = solution.makeFancyString(s);
    cout << result << endl;
    return 0;
}
