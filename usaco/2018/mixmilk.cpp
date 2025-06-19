#include <bits/stdc++.h>

using namespace std ;

int main() {
    int m[3], c[3] ;
    for(int i = 0 ; i < 3 ; i++) {
        cin >> c[i] >> m[i] ;
    }

    int k = 0 ;
    int r = k + 1 ;
    for(int i = 0 ; i < 100 ; i++) {
        int p = min(m[k], c[r] - m[r]) ;
        m[k] = m[k] - p ;
        m[r] = m[r] + p ;
        k = (k + 1) % 3 ;
        r = (k + 1) % 3 ;
    }

    cout << m[0] << endl ;
    cout << m[1] << endl ;
    cout << m[2] << endl ;
}