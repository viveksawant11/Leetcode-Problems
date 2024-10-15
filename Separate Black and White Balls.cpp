#include <iostream>
#include <string>
using namespace std;

long long minimumSteps(string s) {
    long long steps = 0;
    int count1 = 0;

    for (char ch : s) {
        if (ch == '1') 
            count1++;
        else
            steps += count1;
    }

    return steps;
}

int main() {
    string s;
    cout << "Enter the binary string: ";
    cin >> s;

    long long result = minimumSteps(s);
    cout << "Minimum number of steps: " << result << endl;

    return 0;
}
