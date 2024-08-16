//Given a string S of lowercase English letters, the task is to find the index of the first non-repeating
//character. If there is no such character, return -1
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int firstNonRepeatingCharacter(string S) {
    int charCount[26] = {0}; // Array to store the frequency of each character
    stack<char> charStack;   // Stack to store characters

    // Count the frequency of each character in the string and push onto stack
    for (int i = 0; i < S.length(); ++i) {
        char c = S[i];
        charCount[c - 'a']++;
        charStack.push(c);
    }

    // Find the first character with a frequency of 1
    while (!charStack.empty()) {
        char c = charStack.top();
        charStack.pop();
        if (charCount[c - 'a'] == 1) {
            // Need to return the first occurrence, so traverse the string again
            for (int i = 0; i < S.length(); ++i) {
                if (S[i] == c) {
                    return i;
                }
            }
        }
    }

    // If there is no non-repeating character
    return -1;
}

int main() {
    string S;
    cout << "Enter the string: ";
    cin >> S;

    int index = firstNonRepeatingCharacter(S);

    if (index == -1) {
        cout << "There is no non-repeating character in the string." << endl;
    } else {
        cout << "The index of the first non-repeating character is: " << index << endl;
    }

    return 0;
}
