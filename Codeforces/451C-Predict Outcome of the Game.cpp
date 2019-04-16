#include <bits/stdc++.h>

using namespace std;

int main()
{
    //   freopen("data.in", ",r", stdin);

    int t;
    cin >> t;
    while (t--)
    {

        long long n, k, d1, d2, rem;
        cin >> n >> k >> d1 >> d2;
        rem = n - k;

        if (n % 3 != 0)
        {
            cout << "no" << endl;
            continue;
        }

        if (d1 + d2 + d2 <= k && (d1 + d2 + d2) % 3 == k % 3)
        {
            long long needed = d1 + d1 + d2;
            if ((rem - needed) >= 0 && (rem - needed) % 3 == 0)
            {
                cout << "yes" << endl;
                continue;
            }
        }

        if ((d1 + d2) <= k && (d1 + d2) % 3 == k % 3)
        {
            long long needed = abs(d1 - d2);
            needed += max(d1, d2);
            if ((rem - needed) >= 0 && (rem - needed) % 3 == 0)
            {
                cout << "yes" << endl;
                continue;
            }
        }

        if ((max(d1, d2) + abs(d1 - d2)) <= k && (max(d1, d2) + abs(d1 - d2)) % 3 == k % 3)
        {
            long long needed = d1 + d2;
            if ((rem - needed) >= 0 && (rem - needed) % 3 == 0)
            {
                cout << "yes\n";
                continue;
            }
        }

        if (d1 + d2 + d1 <= k && (d1 + d1 + d2) % 3 == k % 3)
        {
            long long needed = d2 + d1 + d2;
            if ((rem - needed) >= 0 && (rem - needed) % 3 == 0)
            {
                cout << "yes" << endl;
                continue;
            }
        }

        cout << "no" << endl;
    }
}
