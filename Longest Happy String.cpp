#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, int>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";

        while (!pq.empty()) {
            auto firstPair = pq.top();
            pq.pop();

            if (result.size() >= 2 && result.back() == firstPair.second && result[result.size() - 2] == firstPair.second) {
                if (pq.empty()) break;

                auto secondPair = pq.top();
                pq.pop();

                result += secondPair.second;
                secondPair.first--;

                if (secondPair.first > 0) 
                    pq.push(secondPair);
                
                pq.push(firstPair);
            } else {
                result += firstPair.second;
                firstPair.first--;

                if (firstPair.first > 0) 
                    pq.push(firstPair);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int a = 1, b = 1, c = 7;
    cout << "Input: a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "Output: " << solution.longestDiverseString(a, b, c) << endl;

    a = 7; b = 1; c = 0;
    cout << "\nInput: a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "Output: " << solution.longestDiverseString(a, b, c) << endl;

    return 0;
}
