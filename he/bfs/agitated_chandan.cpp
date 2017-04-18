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
vector<int>graph[200000];
vector<int>cost[200000];
int visit[200000];
int dist[200000];
void dfs(int index,int d)
{
        int i; int n;
        if (visit[index]==0)
        {
                visit[index]=1;
                dist[index]=d;

                for(i=0; i<graph[index].size(); i++)
                {
                        n=graph[index][i];
                        if (visit[n]==0)
                        {
                                dfs(n,d+cost[index][i]);
                        }
                }//for
        }//if
}
int main()
{
        int test; cin>>test; int t;
        int i;
        for(t=0; t<test; t++)
        {
                memset(visit,0,sizeof(visit));
                memset(dist,0,sizeof(dist));
                int nodes;
                cin>>nodes;
                int s,d,c;
                for(i=0; i<=nodes; i++)
                {
                        graph[i].clear();
                        cost[i].clear();
                }
                for(i=0; i<nodes-1; i++)
                {
                        cin>>s>>d>>c;
                        graph[s].pb(d);
                        graph[d].pb(s);
                        cost[s].pb(c);
                        cost[d].pb(c);
                }
                dfs(1,0);
                int snode; int dest=0;
                for(i=1; i<=nodes; i++)
                {
                        if (dist[i]>dest)
                        {
                                dest=dist[i];
                                snode=i;
                        }
                }
                //cout<<snode<<"\n";
                memset(visit,0,sizeof(visit));
                memset(dist,0,sizeof(dist));
                dfs(snode,0);
                int result=0;
                for(i=1; i<=nodes; i++)
                {
                        result=max(result,dist[i]);
                }
                int rcost=0;
                if (result>10000)
                        rcost=10000;
                else if (result>1000)
                        rcost=1000;
                else if (result>=100)
                        rcost=100;
                cout<<rcost<<" "<<result<<"\n";
        }//test
        return 0;

}//main
