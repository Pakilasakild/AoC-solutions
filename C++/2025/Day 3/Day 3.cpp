#include <bits/stdc++.h>
using namespace std;

long long best_k_value(const string &s, int k) {
    int n = (int)s.size();
    int start = 0;
    long long value = 0;

    while (k > 0) {
        int end = n - k;
        char bestDigit = '0';
        int bestIdx = start;

        for (int i = start; i <= end; ++i) {
            if (s[i] > bestDigit) {
                bestDigit = s[i];
                bestIdx = i;
            }
        }

        value = value * 10 + (bestDigit - '0');
        start = bestIdx + 1;
        --k;
    }

    return value;
}

int main() {
    ifstream in("U3.txt");

    vector<string> banks;
    string input;
    while (in >> input) {
        banks.push_back(input);
    }

    long long total = 0;
    for (int i = 0; i < banks.size(); i++) {
        total += best_k_value(banks[i], 12);
    }

    cout << total << endl;
    return 0;
}
