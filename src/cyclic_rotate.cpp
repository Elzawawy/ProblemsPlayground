//
// Created by zawawy on 4/9/19.
//

/* Problem Statement:
 * An array A consisting of N integers is given.
 * Rotation of the array means that each element is shifted right by one index,
 * and the last element of the array is moved to the first place.
 *
 * More about the problem can be found from: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
 *
 */

/*********Attempt 1: Working 100% on all test cases.**********/

vector<int> cyclicRotate(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result;
    if(A.empty()) return result;
    for (int j = 0; j < K; ++j) {
        result.insert(result.begin(), A[A.size() - 1]);
        for (int i = 0; i < A.size() - 1; ++i) {
            result.insert(result.begin() + i + 1, A[i]);
        }
        A = result;
        result.clear();
    }
    return A;
}
