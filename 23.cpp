#include <bits/stdc++.h>
using namespace std;

// Function to reverse words in a string
string reverseWords(string s) {
    int n = s.length();
    string ans = "";

    // Step 1: Reverse the entire string
    reverse(s.begin(), s.end());

    // Step 2: Traverse the reversed string word by word
    for (int i = 0; i < n; i++) {
        string word = "";

        // Step 3: Skip spaces and collect a word
        while (i < n && s[i] != ' ') {
            word = word + s[i];
            i++;
        }

        // Step 4: Reverse the current word back to correct order
        reverse(word.begin(), word.end());

        // Step 5: Append to final result if it's not empty
        if (word.length() > 0) {
            ans = ans + " " + word;
        }
    }

    // Step 6: Return the result without the first extra space
    return ans.substr(1);
}

int main() {
    string s;
    getline(cin, s);  // Read full line including spaces

    string result = reverseWords(s);
    cout << result << endl;

    return 0;
}
