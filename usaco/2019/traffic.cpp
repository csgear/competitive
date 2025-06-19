#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n ;
    cin >> n ;

    vector<string> type(n) ;
    vector<int> low(n), high(n) ;

    for(int i = 0 ; i < n ; i++) {
        cin >> type[i] ;
        cin >> low[i] >> high[i] ;
    }

    int l1 = -1e9, h1 = 1e9 ;
    for(int i = n - 1 ; i >= 0 ; i--) {
        if(type[i] == "none") {
            l1 = max(l1, low[i]) ;
            h1 = min(h1, high[i]) ;
        } else if(type[i] == "on") {
            l1 = max(0, l1 - high[i]) ;
            h1 = h1 - low[i] ;
        } else if(type[i] == "off") {
            l1 = l1 + low[i] ;
            h1 = h1 + high[i] ;
        }
    }

    int l2 = -1e9, h2 = 1e9 ;
    for(int i = 0 ; i < n ; i++) {
        if(type[i] == "none") {
            l2 = max(l2, low[i]) ;
            h2 = min(h2, high[i]) ;
        } else if(type [i] == "on") {
            l2 = l2 + low[i] ;
            h2 = h2 + high[i] ;
        } else if(type[i] == "off") {
            l2 = max(0, l2 - high[i]) ;
            h2 = h2 - low[i] ;
        }
    }

    cout << l1 << " " << h1 << endl ;
    cout << l2 << " " << h2 << endl ;
    return 0 ;
}