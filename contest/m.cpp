#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned n, m;
    while (cin >> n >> m)
    {
        vector<string> myVector = {};
        for (unsigned i = n; i < m; i++)
        {
            string myString = to_string(i);
            string reversedString = myString;
            reverse(reversedString.begin(), reversedString.end());
            if (myString == reversedString)
            {
                myVector.push_back(myString);
            }
        }
        if (myVector.size() > 0)
        {
            int i;
            for (i = 0; i < myVector.size() - 1; i++)
            {
                cout << myVector.at(i) << " ";
            }
            cout << myVector.at(i) << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}