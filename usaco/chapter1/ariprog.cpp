/*
ID: juniory1
LANG: C++
TASK: ariprog
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;


vector<string> do_solution_from_end(int length, int number) {
    // Create set of bisquares
    set<int> sum_set;
    for (int i = 0; i <= number; i++) {
        for (int j = 0; j <= number; j++) {
            sum_set.insert(i*i + j*j);
        }
    }

    // Convert to sorted vector for easier access
    vector<int> sum_list(sum_set.begin(), sum_set.end());
    int length_list = sum_list.size();

    // Store results as pairs of [start, difference]
    vector<pair<int, int>> result_list;

    // Search from end of list
    for (int i = length_list - 1; i >= length - 2; i--) {
        int list_end = sum_list[i];
        int delta = 1;
        int max_step = list_end / (length - 1);
        int list_next = sum_list[i - delta];
        int now_step = list_end - list_next;

        while (now_step <= max_step) {
            bool in_set = true;
            int current = list_next;
            
            // Check if sequence exists
            for (int n = 0; n < length - 2; n++) {
                current -= now_step;
                if (sum_set.find(current) == sum_set.end()) {
                    in_set = false;
                    break;
                }
            }

            if (in_set) {
                result_list.push_back({list_end - now_step * (length - 1), now_step});
            }
            delta++;
            list_next = sum_list[i - delta];
            now_step = list_end - list_next;
        }
    }

    // Sort results by difference, then by start value
    sort(result_list.begin(), result_list.end(), 
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second < b.second || (a.second == b.second && a.first < b.first);
         });

    // Format output
    vector<string> ret;
    if (result_list.empty()) {
        ret.push_back("NONE\n");
        return ret;
    }

    for (const auto& result : result_list) {
        ret.push_back(to_string(result.first) + " " + to_string(result.second) + "\n");
    }
    return ret;
}

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    
    int length, number;
    fin >> length >> number;
    
    vector<string> result = do_solution_from_end(length, number);
    for (const string& line : result) {
        fout << line;
    }
    
    return 0;
} 