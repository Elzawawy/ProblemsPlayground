//
// Created by zawawy on 4/4/20.
//

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <bitset>

using namespace std;


#define cosRule(a,b,c) (acos(((a)*(a)+(b)*(b)-(c)*(c))/(2*(a)*(b))))
#define pb push_back
#define ll long long
#define F first
#define S second
#define f first
#define s second
#define PI acos(-1)
#define EPS 1e-9
//#define ld long double
#define MAX 1000000000
#define NIL 0
#define INF 1e15
#define infi 1000000000
#define rd(a) scanf("%d",&a)
#define rd2(a,b) scanf("%d %d",&a,&b)
#define rd3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define rdll(a) scanf("%I64d",&a)
#define sz(a) (int) a.size()
#define lp(i,a,n) for(int i=(a); i<=(n) ; ++i)
#define lpd(i,n,a) for(int i=(n); i>=(a) ; --i)
#define pi acos(-1)
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define angle(a)                (atan2((a).imag(), (a).real()))
#define X real()
#define Y imag()
#define vec(a,b)                ((b)-(a))
#define vvi vector<vector<int>>
#define clr(a,b) memset(a,b,sizeof a)
#define all(a) a.begin(), a.end()
#define infll 1000000000000000000ll

#define mod1 1000500001ll
#define mod2 1000300001ll
#define base1 137ll
#define base2 31ll

typedef pair<int,int>ii;
typedef pair<ii,int> data;
typedef pair<ii,ii> line;
typedef pair<double,double>point;
typedef pair<ll, ll> pll;
typedef vector<int> vi;



ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
bool is_vowel(char c){if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return 1;return 0;}
ll extended_euclidean(ll a,ll b,ll &x,ll &y){if(b==0){x=1;y=0;return a;}ll g = extended_euclidean(b,a%b,y,x);y -= (a/b)*x;return g;}
ll power(ll base,ll p,ll mod){if(p==1)return base;if(!p)return 1ll;ll ret=power(base,p/2,mod);ret*=ret;ret%=mod;if(p&1)ret*=base;return ret%mod;}
float Trianglearea(int x1, int y1, int x2, int y2, int x3, int y3) {return abs((x1 * (y2 - y3) + x2 * (y3 - y1) +  x3 * (y1 - y2)) / 2.0);}
ii operator + (ii a,ii b){ii ret = a;ret.F += b.F;ret.S += b.S;return ret;}

const int N = 200 + 1;

//int main(){

//  freopen("test.in","r",stdin);
    // ios_base::sync_with_stdio(false);
    int t;
    rd(t);
    lp(x,1,t){
        printf("Case #%d: ",x);

        int n;
        rd(n);
        vector<data>v(n);
        vector<int>sol(n);
        lp(i,0,n-1){
            rd2(v[i].f.f,v[i].f.s);
            v[i].s = i;
        }
        sort(v.begin(),v.end());

        int a=-1, b=-1;
        bool imp = false;

        lp(i,0,n-1){
            if(v[i].f.f >= a) a = -1;
            if(v[i].f.f >= b) b = -1;

            if(a == -1){
                sol[v[i].s] = 0;
                a = v[i].f.s;
            }
            else if(b == -1){
                sol[v[i].s] = 1;
                b = v[i].f.s;
            }
            else{
                imp = true;
                break;
            }
        }
        if(imp)printf("IMPOSSIBLE");
        else{
            string s = "CJ";
            lp(i,0,n-1)printf("%c",s[sol[i]]);
        }
        printf("\n");
    }
    return 0;
//}