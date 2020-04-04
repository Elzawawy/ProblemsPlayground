//
// Created by zawawy on 4/4/20.
//
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int N[T];
    for (int i = 0; i<T; i++) {
        cin >> N[i];
        vector<pair<pair<int, int>,int>> activities;
        for (int j = 0; j<N[i]; j++) {
            int temp_start, temp_end;
            cin >> temp_start;
            cin >> temp_end;
            activities.emplace_back(make_pair(temp_start, temp_end),j);
        }
        sort(activities.begin(),activities.end());

        int c_flag=-1, j_flag=-1;
        bool is_impossible = false;
        vector<char> result;
        result.resize(static_cast<unsigned long>(N[i]));
        for(int j=0;j<activities.size();j++){
            // update flags each iteration on the activities.
            if(activities[j].first.first >= c_flag)
                c_flag = -1;
            if(activities[j].first.first >= j_flag)
                j_flag = -1;

            if(c_flag == -1){
                result[activities[j].second] = 'C';
                c_flag = activities[j].first.second;
            }
            else if(j_flag == -1){
                result[activities[j].second] = 'J';
                j_flag = activities[j].first.second;
            }
            else{
                is_impossible = true;
                break;
            }
        }
        if(is_impossible)
            cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl;
        else
            cout << "Case #" << i+1 << ": " << string(result.begin(), result.end()) << endl;
    }
}