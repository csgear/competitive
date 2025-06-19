#include <bits/stdc++.h>

using namespace std ;

int main() {
    int N, X ;
    cin >> N >> X ;

    vector<int> a(N) ;

    for(int i = 0 ; i < N ; i++) {
        cin >> a[i] ;
    }

    sort(a.begin(), a.end()) ;

    int n = 0 ;

    for(int i = 0 ; i < N ; i++) {
        if(a[i] <= X) {
            n++ ;
            X = X - a[i] ;
        }
    }
    
    cout << n << endl ;
    return 0 ;
}