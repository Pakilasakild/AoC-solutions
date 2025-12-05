#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("U5.txt");
    if (!in) {
        cerr << "Could not open file\n";
        return 1;
    }

    vector<pair<long long, long long> > ranges;

    string line;
    // Read only the ranges part (until the first blank line)
    while (getline(in, line)) {
        if (line.empty()) {
            break; // blank line: end of ranges section
        }

        // remove whitespace
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        if (line.empty()) {
            break;
        }

        size_t dash = line.find('-');
        long long a = stoll(line.substr(0, dash));
        long long b = stoll(line.substr(dash + 1));
        ranges.push_back(make_pair(a, b));
    }

    if (ranges.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    // Sort ranges by start
    sort(ranges.begin(), ranges.end());

    // Merge overlapping ranges
    vector<pair<long long, long long> > merged;

    for (int i = 0; i < (int)ranges.size(); i++) {
        if (merged.empty()) {
            merged.push_back(ranges[i]);
        } else {
            pair<long long, long long> &last = merged.back();
            long long currStart = ranges[i].first;
            long long currEnd   = ranges[i].second;

            if (currStart <= last.second) {
                // Overlaps: extend the last interval if needed
                if (currEnd > last.second) {
                    last.second = currEnd;
                }
            } else {
                // No overlap: add new interval
                merged.push_back(ranges[i]);
            }
        }
    }

    // Count total fresh IDs
    unsigned long long totalFresh = 0;
    for (int i = 0; i < (int)merged.size(); i++) {
        long long start = merged[i].first;
        long long end   = merged[i].second;
        totalFresh += (unsigned long long)(end - start + 1);
    }

    cout << totalFresh << "\n";
    return 0;
}
