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

int parent[200000];
int find_parent(int index)
{
        if (parent[index]==index)
        {
                return index;
        }
        else
        {
                parent[index]=find_parent(parent[index]);
                return parent[index];
        }
}
int arr[2000];
int dp[2000][2000];
int solve(int s,int e)
{
        if (s>e)
        {
                return 0;
        }
        else if (s==e)
        {
                dp[s][e]=1;
                return 1;
        }
        else if (dp[s][e]!=-1)
        {
                return dp[s][e];
        }
        else
        {
                int temp=0;
                if (find_parent(arr[s])==find_parent(arr[e]))
                {
                        temp=max(temp,2+solve(s+1,e-1));
                }
                temp=max(temp,solve(s+1,e));
                temp=max(temp,solve(s,e-1));
                dp[s][e]=temp;
                return dp[s][e];
        }
}
int main()
{
        int n,k,m;
        cin>>n>>k>>m;
        int i;
        int s,d;
        memset(dp,-1,sizeof(dp));
        for(i=0; i<=n; i++)
        {
                parent[i]=i;
        }
        for(i=0; i<k; i++)
        {
                cin>>s>>d;
                parent[find_parent(d)]=find_parent(s);
        }

        for(i=0; i<m; i++)
        {
                cin>>arr[i];
        }

        solve(0,m-1);
        int j;
        cout<<dp[0][m-1]<<"\n";
        return 0;
}
