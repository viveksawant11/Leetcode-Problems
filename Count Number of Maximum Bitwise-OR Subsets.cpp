#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        
        int count = 0;
        countSubsets(nums, 0, 0, maxOr, count);
        return count;
    }

private:
    void countSubsets(const vector<int>& nums, int index, int currentOr, int maxOr, int& count) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        
        countSubsets(nums, index + 1, currentOr | nums[index], maxOr, count);
        countSubsets(nums, index + 1, currentOr, maxOr, count);
    }
};

int main() {
    vector<int> nums = {3, 1};
    Solution solution;
    int result = solution.countMaxOrSubsets(nums);
    cout << "Number of subsets with the maximum OR: " << result << endl;
    return 0;
}
