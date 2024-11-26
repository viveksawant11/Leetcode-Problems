#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) {                // No zigzag needed
        return s;                                       
    }

    vector<string> rows(numRows);
    int currentRow = 0;
    bool goingDown = false;

    for (char ch : s) {
        rows[currentRow] += ch; 

        if (currentRow == 0 || currentRow == numRows - 1) {     // Change direction at the top or bottom row
            goingDown = !goingDown;
        }

        currentRow += goingDown ? 1 : -1; 
    }

    string result;
    for (string row : rows) {
        result += row;
    }
    return result;
}

int main() {
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Input: " << s1 << ", numRows = " << numRows1 << endl;
    cout << "Output: " << convert(s1, numRows1) << endl;

    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Input: " << s2 << ", numRows = " << numRows2 << endl;
    cout << "Output: " << convert(s2, numRows2) << endl;

    string s3 = "A";
    int numRows3 = 1;
    cout << "Input: " << s3 << ", numRows = " << numRows3 << endl;
    cout << "Output: " << convert(s3, numRows3) << endl;

    string s4 = "PAYPALGPAY";
    int numRows4 = 3;
    cout << "Input: " << s4 << ", numRows = " << numRows4 << endl;
    cout << "Output: " << convert(s4, numRows4) << endl;

    return 0;
}
