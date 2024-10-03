#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty())
            return {};

        vector<int> dup = arr;              
        sort(dup.begin(), dup.end());  

        unordered_map<int, int> mp;  

        mp[dup[0]] = 1;  // The smallest element gets rank 1
        for (int i = 1; i < dup.size(); i++) {
            if (dup[i] > dup[i - 1])          // Only increment rank if current element is greater than previous
                mp[dup[i]] = mp[dup[i - 1]] + 1;
            else
                mp[dup[i]] = mp[dup[i - 1]];  // Same rank for equal elements
        }

        vector<int> res;  
        for (int num : arr)
            res.push_back(mp[num]);

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {40, 10, 20, 30};
    vector<int> result1 = sol.arrayRankTransform(arr1);
    cout << "Rank transformation of [40, 10, 20, 30] -> ";
    for (int rank : result1) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}
