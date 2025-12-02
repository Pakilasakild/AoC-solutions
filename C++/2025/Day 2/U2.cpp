#include <bits/stdc++.h>
using namespace std;
int digitCount(long long a)
{
    if (a == 0) return 1;
    int c = 0;
    while (a != 0)
    {
        c++;
        a /= 10;
    }
    return c;
}

bool isTwiceRepeated(long long x)
{
    string s = to_string(x);
    int n = s.size();
    if (n % 2 != 0) return false;

    int half = n / 2;
    for (int i = 0; i < half; ++i)
    {
        if (s[i] != s[i + half]) return false;
    }
    return true;
}

bool isRepeatedAtLeastTwice(long long x)
{
    string s = to_string(x);
    int n = s.size();

    for (int len = 1; len <= n / 2; ++len)
    {
        if (n % len != 0) continue;
        int times = n / len;
        if (times < 2) continue;

        bool ok = true;
        for (int t = 1; t < times && ok; ++t)
        {
            for (int i = 0; i < len; ++i)
            {
                if (s[i] != s[t * len + i])
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) return true;
    }

    return false;
}

int main()
{
    int part;
    cin >> part;
    ifstream in("U2.txt");

    string text;
    if (!getline(in, text))
    {
        cerr << "Failed to read line from U2.txt\n";
        return 1;
    }

    vector<long long> nums;
    stringstream ss(text);
    string rangeStr;

    while (getline(ss, rangeStr, ','))
    {
        if (rangeStr.empty()) continue;
        stringstream rs(rangeStr);
        string numStr;
        while (getline(rs, numStr, '-'))
        {
            if (!numStr.empty())
                nums.push_back(stoll(numStr));
        }
    }

    long long sum = 0;

    for (size_t i = 0; i + 1 < nums.size(); i += 2)
    {
        long long a = nums[i];
        long long b = nums[i + 1];

        for (long long j = a; j <= b; j++)
        {
            if (part == 1)
            {
                if (isTwiceRepeated(j)) sum += j;
            }
            else
            {
                if (isRepeatedAtLeastTwice(j)) sum += j;
            }
        }
    }

    cout << sum;
    return 0;
}
