//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/connected-horses-10/

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
int arr[2000][2000];
int visit[2000][2000];
vector<pair<int,int> >points;
queue<pair<int,int> >q;
ll factors[1000001];
int main()
{
        int movesx[]={2,1,2,1,-2,-1,-2,-1};
        int movesy[]={1,2,-1,-2,1,2,-1,-2};
        int test; cin>>test; int t;
        int n,m; int x,y; int pos;
        factors[1]=1; int i; int j;
        for(i=2; i<1000000; i++)
        {
                factors[i]=(factors[i-1]*i)%mod;
                factors[i]=factors[i]%mod;
        }
        for(t=0; t<test; t++)
        {
                memset(arr,0,sizeof(arr));
                memset(visit,0,sizeof(visit));
                points.clear();
                cin>>n>>m;
                cin>>pos;
                for(i=0; i<pos; i++)
                {
                        cin>>x>>y;
                        arr[x][y]=1;
                        points.pb(mp(x,y));
                }
                int x1,y1;
                pair<int,int>p; map<int,int>store; int mark=1;
                for(i=0; i<points.size(); i++)
                {
                        if (visit[points[i].ff][points[i].ss]==0)
                        {
                                q.push(mp(points[i].ff,points[i].ss));
                                visit[points[i].ff][points[i].ss]=mark;
                                store[mark]=1;
                                while(!q.empty())
                                {
                                        p=q.front();
                                        q.pop();
                                        x=p.ff;
                                        y=p.ss;
                                        for(j=0; j<8; j++)
                                        {
                                                x1=x+movesx[j];
                                                y1=y+movesy[j];
                                                if (x1<=n && y1<=m && x1>0 && y1>0)
                                                {
                                                        if (visit[x1][y1]==0 && arr[x1][y1]==1)
                                                        {
                                                                q.push(mp(x1,y1));
                                                                visit[x1][y1]=mark;
                                                                store[mark]++;
                                                        }
                                                }
                                        }

                                }
                                mark++;
                        }
                }

                ll result=1;
                for(i=1; i<mark; i++)
                {
                        result=(result*factors[store[i]])%mod;
                }
                cout<<result<<"\n";
        }

        return 0;

}//main
