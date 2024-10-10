#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        // Build the stack with possible decreasing sequence indices
        for (int i = 0 ; i < n ; i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        int maxWidth = 0;

        // Traverse from the back and calculate the ramp width
        for (int j = n - 1 ; j >= 0 ; j--) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {6, 0, 8, 2, 1, 5}; 
    cout << "Maximum width ramp: " << sol.maxWidthRamp(nums) << endl;
    return 0;
}
