//
// Created by zawawy on 4/4/20.
//

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T;
    int N[T];
    cin >> T;
    for (int i = 0; i<T; i++) {
        cin >> N[i];
        int M[N[i]][N[i]];
        for (int j = 0; j<N[i]; j++)
            for (int k = 0; k<N[i]; k++)
                cin >> M[j][k];

        int trace = 0;
        map<int, int> row_frequencies;
        map<int, int> col_frequencies;
        int row_repetition = 0;
        int col_repetition = 0;
        for (int j = 0; j<N[i]; j++) {
            for (int k = 0; k<N[i]; k++) {
                if (j==k)
                    trace += M[j][k];

                row_frequencies[M[j][k]]++;
                col_frequencies[M[k][j]]++;
            }
            for (auto& entry: row_frequencies)
                if (row_frequencies[entry.first]>1) {
                    row_repetition += 1;
                    break;
                }
            for (auto& entry: col_frequencies)
                if (col_frequencies[entry.first]>1) {
                    col_repetition += 1;
                    break;
                }
            row_frequencies.clear();
            col_frequencies.clear();
        }
        cout<<"Case #"<<i+1<<": "<<trace<<" "<<row_repetition<<" "<<col_repetition<<endl;
    }
}