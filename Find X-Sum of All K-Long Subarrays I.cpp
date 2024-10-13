#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int calculateXSum(unordered_map<int, int> &freq, int x) {
        priority_queue<pair<int, int>> pq;
        
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        int sum = 0;
        for (int i = 0; i < x && !pq.empty(); i++) {
            auto top = pq.top();
            pq.pop();
            sum += top.second * top.first;
        }

        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> freq;

        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }

        result.push_back(calculateXSum(freq, x));
        
        for (int i = 1; i <= n - k; i++) {
            freq[nums[i - 1]]--;

            if (freq[nums[i - 1]] == 0) {
                freq.erase(nums[i - 1]);
            }

            freq[nums[i + k - 1]]++;

            result.push_back(calculateXSum(freq, x));
        }

        return result;
    }
};
