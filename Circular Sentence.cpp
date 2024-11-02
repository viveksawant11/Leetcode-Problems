#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        
        if (sentence[0] != sentence[n - 1])
            return false;
        
        for (int i = 1; i < n; i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1])
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string sentence;
    getline(cin, sentence);
    if (solution.isCircularSentence(sentence))
        cout << "The sentence is circular." << endl;
    else
        cout << "The sentence is not circular." << endl;
    return 0;
}
