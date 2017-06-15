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

vector<int>graph[6000];
vector<int>cost[6000];
long dp[5002][5002];
int parent[5100][5100];
stack<pair<int,int> >stk;
ll visit[6000];
int main()
{
        ll n,m,t;
        cin>>n>>m>>t; ll i; ll s,d,ti;
        memset(dp,-1,sizeof(dp));
        memset(visit,0,sizeof(visit));
        for(i=0; i<m; i++)
        {
                cin>>s>>d>>ti;
                graph[s].pb(d);
                cost[s].pb(ti);
        }
        dp[1][1]=0; int add=0;
        stk.push(mp(1,1)); int j; int curr; int temp; long long ttemp=mod;
        while(!stk.empty())
        {
                curr=stk.top().ff;
                i=stk.top().ss;
                stk.pop();
                if (dp[curr][i]!=-1)
                {

                        for(j=0; j<graph[curr].size(); j++)
                        {
                                temp=graph[curr][j];
                                ttemp=dp[curr][i]+cost[curr][j];
                                if (ttemp>t)
                                {
                                        ttemp=t+1;
                                }

                                if (dp[temp][i+1]==-1 )
                                {
                                        dp[temp][i+1]=ttemp;
                                        parent[temp][i+1]=curr;
                                        stk.push(mp(temp,i+1));
                                }
                                else if ((ttemp)<dp[temp][i+1])
                                {
                                        dp[temp][i+1]=min(dp[temp][i+1],(long)ttemp);
                                        parent[temp][i+1]=curr;
                                        stk.push(mp(temp,i+1));
                                }

                        }
                }


        }
        int p;
        int res;
        for(i=n; i>0; i--)
        {
                if (dp[n][i]<=t && dp[n][i]!=-1)
                {
                        cout<<i<<"\n";
                        p=parent[n][i];
                        res=i;
                        break;

                }

        }
        vector<int>result;
        result.pb(n);
        while(p!=1)
        {
                result.pb(p);
                res--;
                p=parent[p][res];
        }
        result.pb(1);
        for(i=result.size()-1; i>=0; i--)
        {
                cout<<result[i]<<" ";
        }
        cout<<"\n";


        return 0;

}//main
