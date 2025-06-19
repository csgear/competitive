#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n ;
    cin >> n ;
    vector<int> num(n) ;

    for(int i = 0 ; i < n ; i++) {
        cin >> num[i] ;
    }

    sort(num.begin(), num.end()) ;

    int distinct = 1 ;

    for(int i = 1 ; i < n ; i++) {
        if(num[i] != num[i-1]) {
            distinct += 1 ;
        }
    }

    cout << distinct << endl ;

    return 0 ;
}