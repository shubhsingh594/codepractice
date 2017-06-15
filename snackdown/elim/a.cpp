// template
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0; i<(int)(m); i++)
#define rep2(i,n,m) for(int i=n; i<(int)(m); i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin(); it!=c.end(); ++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define ff first
#define ss second
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)
#define mod 1000000007

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

ll arr[2000000];
ll dp[2000000][2];
ll result=0;
int main()
{
        int test; int t;
        int i;
        cin>>test;
        for(t=0; t<test; t++) {
                int n;
                cin>>n;
                result=0;
                for(i=0; i<n; i++)
                {
                        cin>>arr[i];
                }
                if (n==1)
                {
                        cout<<arr[0]<<"\n";
                        continue;
                }
                dp[0][0]=arr[0];
                dp[1][0]=0; ll temp=1;
                for(i=1; i<n; i++)
                {
                        if (i==1)
                        {
                                dp[i][0]=(dp[i-1][0]+arr[i])%mod;
                                dp[i][1]=(dp[i-1][0]*arr[i])%mod;
                        }
                        else if (i==2)
                        {
                                temp=(temp*2)%mod;
                                dp[i][0]=((dp[i-1][0]+dp[i-1][1])%mod+(temp*arr[i])%mod)%mod;
                                dp[i][1]=((dp[i-1][1]*arr[i])%mod+(dp[i-2][0]+dp[i-2][1])%mod+(arr[i-1]*arr[i])%mod)%mod;
                        }
                        else
                        {
                                temp=(temp*2)%mod;
                                dp[i][0]=(dp[i-1][0]+dp[i-1][1]+(temp*arr[i]))%mod;
                                dp[i][1]=((dp[i-1][1]*arr[i])%mod+(dp[i-2][0]+dp[i-2][1])%mod+2*(arr[i-1]*arr[i])%mod)%mod;
                        }

                }

                cout<<(dp[n-1][0]+dp[n-1][1])%mod<<"\n";

        }
        return 0;

}//main
