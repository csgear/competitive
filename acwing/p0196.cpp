// https://www.acwing.com/problem/content/198/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;


const int LIMIT = (1 << 16 ) + 10;

const int N = 1000010;

int primes[N];
bool st[N];
int cnt;
int l, r;

void init(int n)
{
    memset(st, 0, sizeof st);
    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (st[i] == false) primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[i*primes[j]] = true;
            if (i%primes[j] == 0) break;
        }
    }
}


int main()
{
    while (cin >> l >> r) {
        init(LIMIT);
        memset(st, 0, sizeof st);
        for (int i = 0; i < cnt; i++) {
            LL p = primes[i];
            for (LL j = max(2 * p, (l + p - 1) / p * p); j <= r; j += p)
                st[j - l] = true;
        }
        cnt = 0;

        for (int i = 0; i <= r - l; i++) {
            if (!st[i] && i + l >= 2)
                primes[cnt++] = i + l;
        }

        if (cnt < 2) puts("There are no adjacent primes.");
        else
        {
            int minp = 0, maxp = 0;
            for (int i = 0; i + 1 < cnt; i++)
            {
                int d = primes[i + 1] - primes[i];
                if (d < primes[minp + 1] - primes[minp]) minp = i;
                if (d > primes[maxp + 1] - primes[maxp]) maxp = i;
            }

            cout << primes[minp] << "," << primes[minp + 1] << " are closest, " << primes[maxp]
                 << "," << primes[maxp + 1] << " are most distant." << endl;
        }

    }

    return 0;
}
