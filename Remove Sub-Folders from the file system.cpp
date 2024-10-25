#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string lastFolder = ans.back();
            lastFolder.push_back('/');
            if (folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    vector<string> result = sol.removeSubfolders(folder);
    
    for (const string& f : result) {
        cout << f << endl;
    }
    
    return 0;
}
