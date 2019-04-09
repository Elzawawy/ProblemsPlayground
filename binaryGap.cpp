//
// Created by zawawy on 4/9/19.
//

/* Problem Statement:
 * A binary gap within a positive integer N is any maximal sequence
 * of consecutive zeros that is surrounded by ones at both ends
 * in the binary representation of N.
 *
 * More about the problem can be found from: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
 *
 */

/*********Attempt 1: Working 100% correct on all test cases*********/

std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    std::string binary = toBinary(N);
    bool flag=false; int countGap = 0;
    int maxGap =0;
    for(char& c : binary) {
        if(c == '1'){
            maxGap = std::max(maxGap,countGap);
            countGap=0;
        }
        else if(c =='0')
            countGap++;
    }
    return maxGap;
}