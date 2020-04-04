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
        int S[N[i]], E[N[i]];
        for (int j = 0; j<N[i]; j++)
            cin >> S[j] >> E[j];

        set<int> assignment_C;
        set<int> assignment_J;
        vector<int> overlap[N[i]];
        for (int j = 0; j<N[i]; j++)
            for (int k = 0; k<N[i]; k++)
                if ( (S[j]<E[k] and E[j]>S[k]))
                    overlap[k].push_back(j);


        for (int l = 0; l<N[i]; l++) {
            int flag_C = true, flag_J = true;
            for (auto& elm: overlap[l]) {
                if (assignment_C.count(elm)>0) {
                    flag_C = false;
                    break;
                }
            }
            if(flag_C) {
                assignment_C.insert(l);
                continue;
            }

            for (auto& elm: overlap[l]) {
                if (assignment_J.count(elm)>0) {
                    flag_J = false;
                    break;
                }
            }
            if(flag_J)
                assignment_J.insert(l);
        }
        vector<char> result;
        result.resize(static_cast<unsigned long>(N[i]));
        if (assignment_C.size()+assignment_J.size()!=N[i])
            cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl;
        else {
            for (auto& element: assignment_C)
                result[element] = 'C';
            for (auto& element: assignment_J)
                result[element] = 'J';
            cout << "Case #" << i+1 << ": " << string(result.begin(), result.end()) << endl;
        }
    }

}