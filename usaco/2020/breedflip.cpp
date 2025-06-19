#include <bits/stdc++.h>

using namespace std ;

int main() {
    int N ;
    cin >> N ;

    string s1, s2 ;
    cin >> s1 >> s2 ;
    int t = 0 ;
    
    bool flip = false ;
    for(int i = 0 ; i < N ; i++) {
        if(s1[i] != s2[i]) {
            flip = true ;
        }
        else {
            if(flip == true) {
                t = t + 1 ;
                flip = false ;
            }
        }
    }
    cout << t << endl ;
    return 0 ;
}