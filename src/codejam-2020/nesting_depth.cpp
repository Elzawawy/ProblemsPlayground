//
// Created by zawawy on 4/4/20.
//

#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int N[T];
    for (int i = 0; i<T; i++) {
        string s;
        string s_new;
        cin >> s;
        for (int j = 0; j<s.size(); j++) {
            if (s[j]-'0'==0)
                s_new += '0';

            else if (s[j+1]-'0'!=0) {
                int old_j = j;
                while (s[j]-'0'!=0 and j<s.size()) {
                    j++;
                }
                int still_open = 0;
                int open_brackets = 0;
                int remainder = 0;
                for (int m = old_j; m<j; m++) {
                    open_brackets = still_open;
                    for (int k = 0; k<(s[m]-'0')-open_brackets; k++) {
                        s_new += {'('};
                        still_open++;
                    }

                    s_new += s[m];
                    open_brackets = still_open;
                    if (m==j-1)
                        remainder = 0;
                    else
                        remainder = abs((s[m]-'0')-(s[m+1]-'0')-open_brackets);

                    for (int n = 0; n<((s[m]-'0')-remainder); n++) {
                        s_new += {')'};
                        still_open--;
                    }
                }
                j--;
            }
            else {
                for (int k = 0; k<s[j]-'0'; k++)
                    s_new += {'('};
                s_new += s[j];
                for (int k = 0; k<s[j]-'0'; k++)
                    s_new += {')'};
            }

        }
        cout << "Case #" << i+1 << ": " << s_new << endl;
    }
}