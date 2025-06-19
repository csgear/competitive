#include <bits/stdc++.h>

using namespace std ;

int main() {
    
    vector<int> p(3) ;

    for(int i = 0 ; i < 3 ; i++) {
        cin >> p[i] ;
    }

    sort(p.begin(), p.end()) ;
    
    int l = 0 ;
    int m = 0 ;

    if(p[2] - p[0] == 2) {
        l = 0 ;
    }
    else if(p[1] - p[0] == 2 || p[2] - p[1] == 2) {
        l = 1 ;
    }
    else {
        l = 2 ;
    }

    m = max(p[2] - p[1], p[1] - p[0]) - 1 ;

    cout << l << endl ;
    cout << m << endl ;

    return 0 ;
}