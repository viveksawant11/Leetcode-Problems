#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xorr = nums[0], maxxorr = pow(2, maximumBit) - 1;
        
        for(int i = 1 ; i < n ; i++) 
            xorr ^= nums[i];
        
        vector<int> ans(n);
        
        for(int i = 0 ; i < n ; i++) {
            ans[i] = xorr ^ maxxorr;
            xorr ^= nums[n - 1 - i];
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 1, 3};
    int maximumBit = 2;
    
    vector<int> result = solution.getMaximumXor(nums, maximumBit);
    for(int val : result)
        cout << val << " ";
    
    return 0;
}
