#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    string result = "";  
    int carry = 0;       
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int bitA = (i >= 0) ? a[i] - '0' : 0; // If index i is valid, take bit from `a`, else 0
        int bitB = (j >= 0) ? b[j] - '0' : 0; // If index j is valid, take bit from `b`, else 0

        int sum = bitA + bitB + carry;     
        result += (sum % 2) + '0';            // Append the result bit (0 or 1)
        carry = sum / 2;                      // Update the carry (0 or 1)

        i--; 
        j--; 
    }

    reverse(result.begin(), result.end()); // The result is built in reverse, so reverse it
    return result;
}

int main() {
    string a = "1010", b = "1011";
    cout << "Sum of binary strings: " << addBinary(a, b) << endl;

    return 0;
}
