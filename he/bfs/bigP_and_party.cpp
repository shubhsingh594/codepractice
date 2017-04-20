https ://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/big-p-and-party-1/
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
vector<int>graph[200000];
int dist[200000];
queue<pair<int,int> >q;
int main()
{
        int n,m; int i;
        cin>>n>>m; int s,d;
        for(i=0; i<=n; i++)
        {
                dist[i]=-1;
        }
        dist[0]=0;
        for(i=0; i<m; i++)
        {
                cin>>s>>d;
                graph[s].pb(d);
                graph[d].pb(s);
        }
        q.push(mp(0,0)); pair<int,int>temp;
        while(!q.empty())
        {
                temp=q.front();
                q.pop();
                for(i=0; i<graph[temp.ff].size(); i++)
                {
                        if (dist[graph[temp.ff][i]]==-1)
                        {
                                dist[graph[temp.ff][i]]=temp.ss+1;
                                q.push(mp(graph[temp.ff][i],dist[graph[temp.ff][i]]));
                        }
                }
        }//while
        for(i=1; i<n; i++)
        {
                cout<<dist[i]<<"\n";
        }
        return 0;
}//main
