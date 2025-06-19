#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n ;
    cin >> n ;

    vector<int> a(n), b(b), g(n) ;

    for(int i = 0 ; i < n : i++) {
        cin >> a[i] >> b[i] >> g[i] ;
    }

    int max_correct = 0 
    for(int initial_pos = 1 ; initial_pos <=3 ; initial_pos++) {
        int current_pos = initial_pos ;
        int correct_guesses = 0 ;

        for(i = 0 ; i < n ; i++) {
            if(a[i] == current_pos) {
                current_pos = b[i] ;
            }
            else if(b[i] == current_pos) {
                current_pos = a[i] ;
            }

            if(g[i] == current_pos) {
                correct_guesses += 1;
            }
        }

        max_correct = max(max_correct, correct_guesses) ;
    }

    cout << max_correct << "\n" ;

    return 0 ;
}