#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int cnt = 0;

        for (string str : words) {
            bool isConsistent = true;

            for (char ch : str) {
                if (allowedSet.find(ch) == allowedSet.end()) {
                    isConsistent = false;
                    break;
                }
            }

            if (isConsistent)
                cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    string allowed = "abc";
    vector<string> words = {"a", "b", "c", "ab", "ac", "abc", "abcd"};
    cout << "Number of consistent strings: " << solution.countConsistentStrings(allowed, words) << endl;
    return 0;
}
