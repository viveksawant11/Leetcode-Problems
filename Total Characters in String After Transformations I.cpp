#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            vector<int> temp(26, 0);

            for (int j = 0; j < 26; j++) {
                if (j == 25) {
                    temp[0] = (temp[0] + freq[j]) % MOD;
                    temp[1] = (temp[1] + freq[j]) % MOD;
                } else {
                    temp[j + 1] = (temp[j + 1] + freq[j]) % MOD;
                }
            }

            freq = temp;
        }

        int len = 0;
        for (int cnt : freq) {
            len = (len + cnt) % MOD;
        }

        return len;
    }
};

int main() {
    Solution solution;
    string s = "abcyy";
    int t = 2;
    cout << solution.lengthAfterTransformations(s, t) << endl;
    return 0;
}
