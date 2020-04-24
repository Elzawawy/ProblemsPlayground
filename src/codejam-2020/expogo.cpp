//
// Created by zawawy on 4/19/20.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <tgmath.h>

using namespace std;
typedef pair<int,int> pii;

string dfs(pii current, pii target,string path_so_far, int num_units){
    // base case
    if(current == target)
        return path_so_far;
    //recursive step
    dfs(make_pair(current.first,current.second-num_units), target, path_so_far+'S', num_units*2);
    dfs(make_pair(current.first,current.second+num_units), target, path_so_far+'N', num_units*2);
    dfs(make_pair(current.first+num_units,current.second), target, path_so_far+'E', num_units*2);
    dfs(make_pair(current.first-num_units,current.second), target, path_so_far+'W', num_units*2);
}

int main(){
    int T;
    cin >> T;
    pii target, current= make_pair(0,0);
    int num_units = 1;
    string result;

    for (int i = 0; i<T; i++) {
        cin >> target.first;
        cin >> target.second;
        int min_cost = 0, min_units = abs(target.first + target.second);
        for(int j=1; min_cost<min_units; j++)
            min_cost += pow(2,j-1);

        while(current != target){
            // south
            pii south = current;
            int south_units = num_units;

        }




        cout << "Case #" << i+1 << ": "<< endl;
    }
}
