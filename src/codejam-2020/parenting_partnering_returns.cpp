////
//// Created by zawawy on 4/4/20.
////
//#include <iostream>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <climits>
//
//#define start first.first
//#define finish first.second
//#define id second
//using namespace std;
//
//int main()
//{
//    int T;
//    cin >> T;
//    int N[T];
//    for (int i = 0; i<T; i++) {
//        cin >> N[i];
//        vector<pair<pair<int, int>, int>> activities;
//        for (int j = 0; j<N[i]; j++) {
//            int temp_start, temp_end;
//            cin >> temp_start;
//            cin >> temp_end;
//            activities.emplace_back(make_pair(temp_start, temp_end), j);
//        }
//        sort(activities.begin(), activities.end());
//
//        int c_min_val = INT_MIN, j_min_val = INT_MIN;
//        bool is_impossible = false;
//        vector<char> result(N[i]);
//        for (auto& activity : activities) {
//            // update flags each iteration on the activities.
//            if (activity.start>=j_min_val)
//                j_min_val = INT_MIN;
//            if (activity.start>=c_min_val)
//                c_min_val = INT_MIN;
//
//            // assign activity to either Jaime or Cameron or No-one (Impossible Case)
//            if (c_min_val==INT_MIN) {
//                result[activity.id] = 'C';
//                c_min_val = activity.finish;
//            }
//            else if (j_min_val==INT_MIN) {
//                result[activity.id] = 'J';
//                j_min_val = activity.finish;
//            }
//            else {
//                is_impossible = true;
//                // early break to improve performance.
//                break;
//            }
//        }
//        // print-out output according to activity status.
//        if (is_impossible)
//            cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl;
//        else
//            cout << "Case #" << i+1 << ": " << string(result.begin(), result.end()) << endl;
//    }
//}