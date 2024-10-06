#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(string &a, string &b) {
        return a + b > b + a;
    }

    string toBinary(int num) {
        string binary = "";

        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }

        return binary;
    }

    int maxGoodNumber(vector<int>& nums) {
        vector<string> binaries;

        for (int num : nums) {
            binaries.push_back(toBinary(num));
        }

        sort(binaries.begin(), binaries.end(), comp);

        string result = "";
        for (string str : binaries) {
            result += str;
        }

        return stoi(result, nullptr, 2);                        // stoi = string to integer
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 8, 16};
    int maxGoodNumber = solution.maxGoodNumber(nums);
    cout << "The maximum good number is: " << maxGoodNumber << endl;

    return 0;
}
