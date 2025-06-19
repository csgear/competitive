#include <bits/stdc++.h>

using namespace std ;

int main() {
    int n ;
    cin >> n ;

    vector<int> nums(2 * n) ;

    for(int i = 0 ; i < 2 * n ; i++) {
        cin >> nums[i] ;
    }

    int min_instability = INT_MAX ;

    sort(nums.begin(), nums.end()) ;

    for(int i = 0 ; i < 2 * n ; i++) {
        for(int j = i + 1 ; j < 2 * n ; j++) {
            vector<int> r ;
            
            for(int k = 0 ; k < 2 * n ; k++) {
                if(k != i && k != j) {
                    r.push_back(nums[k]) ;
                }
            }

            int instability = 0 ;

            for(int k = 0 ; k < r.size() ; k+=2) {
                instability += abs(r[k] - r[k+1]) ;
            }

            min_instability = min(min_instability, instability) ;
            
        }
    }

    cout << min_instability << endl ;
    
    return 0 ;
}