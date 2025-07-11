#include <bits/stdc++.h>
using namespace std;

// Helper function to count substrings with at most k distinct characters
int countAtMostK(string& s, int k) {
    unordered_map<char, int> freq;
    int left = 0, right = 0, count = 0;

    for (right = 0; right < s.length(); ++right) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        // All substrings between left and right are valid
        count += right - left + 1;
    }

    return count;
}

// Function to count substrings with exactly k distinct characters
int countExactlyK(string s, int k) {
    if (k == 0) return 0;
    return countAtMostK(s, k) - countAtMostK(s, k - 1);
}

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    cout << "Number of substrings with exactly " << k << " different characters: ";
    cout << countExactlyK(s, k) << endl;

    return 0;
}
