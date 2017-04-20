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

vector<pair<int,int> >edges;
vector<int>graph[200000];
int visit[200000];
map<int,vector<int> >dis;
map<pair<int,int>,int>rem;
queue<pair<int,int> >q;

int main()
{
        int n,m,k;
        cin>>n>>m>>k;
        int s,d; int i;
        for(i=0; i<=n; i++)
        {
                visit[i]=-1;
        }
        for(i=0; i<m; i++)
        {
                cin>>s>>d;
                edges.pb(mp(s,d));
                graph[s].pb(d);
                graph[d].pb(s);
        }
        int t,e; int ti=0;
        for(i=0; i<k; i++)
        {
                cin>>t>>e;
                dis[t].pb(e);
        }
        q.push(mp(1,0));
        visit[1]=0;
        pair<int,int>temp; int x,y; int a,b;
        while(!q.empty())
        {
                temp=q.front();
                q.pop();
                if (temp.ss>ti)
                {
                        ti=temp.ss;
                        for(i=0; i<dis[ti].size(); i++)
                        {
                                rem[edges[dis[ti][i]-1]]=1;
                        }
                }
                a=temp.ff;
                for(i=0; i<graph[temp.ff].size(); i++)
                {
                        b=graph[temp.ff][i];
                        if (rem[mp(a,b)]==1 || rem[mp(b,a)]==1)
                        {
                                continue;
                        }
                        if (visit[b]==-1)
                        {
                                visit[b]=temp.ss+1;
                                q.push(mp(b,visit[b]));
                        }
                }

        }
        cout<<visit[n]<<"\n";
        return 0;

}//main
