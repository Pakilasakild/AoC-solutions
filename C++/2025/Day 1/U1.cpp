#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("U1.txt");
    vector<string> op;
    int dial = 50, dialCount = 0;
    string temp;
    while (in >> temp)
    {
        op.push_back(temp);
    }
    for (int i = 0; i < op.size(); i++)
    {
        bool hasCrossed = false;
        char lr = op[i][0];
        int temp = stoi(op[i].substr(1));
        dialCount += temp / 100;
        temp %= 100;
        if (lr == 'R')
        {
            dial += temp;
            if (dial >= 100)
            {
                dialCount++;
                hasCrossed = true;
                dial -= 100;
            }
        }
        if (lr == 'L')
        {
            dial -= temp;
            if (dial < 0 && dial + temp != 0)
            {
                dialCount++;
                hasCrossed = true;
                dial += 100;
            }
            else if (dial < 0 && dial + temp == 0){
                dial += 100;
                hasCrossed = true;
            }
        }
        if (dial == 0 && !hasCrossed)
        {
            dialCount++;
        }
    }
    cout << dialCount;
    return 0;
}
