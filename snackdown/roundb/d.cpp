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

int parent[2000000];
vector<int>graph[2000000];
vector<pair<int,int> >edge[200000];
int result[2000000];
vector<pair<int,int> >e;
map<pair<int,int>,int>mark;

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
int main()
{
        int test; cin>>test; int t; int s,d; int i,j;

        for(t=0; t<test; t++)
        {
                int n,m;
                cin>>n>>m;
                e.clear(); mark.clear();
                for(i=0; i<=n; i++)
                {
                        parent[i]=i;
                        result[i]=0;
                        graph[i].clear();
                        edge[i].clear();
                }
                result[n-1]=n-1;
                for(i=0; i<m; i++)
                {
                        cin>>s>>d;
                        graph[s].push_back(d);
                        graph[d].push_back(s);
                        e.push_back(mp(s,d));
                }
                for(i=0; i<e.size(); i++)
                {
                        s=e[i].ff; d=e[i].ss;
                        edge[min(graph[s].size(),graph[d].size())].push_back(e[i]);

                }
                int c;
                for(i=n-1; i>0; i--)
                {
                        c=result[i];
                        for(j=0; j<edge[i].size(); j++)
                        {
                                s=edge[i][j].ff;
                                d=edge[i][j].ss;
                                if (find_parent(s)!=find_parent(d))
                                {
                                        c--;
                                        parent[find_parent(s)]=find_parent(d);
                                }
                        }
                        result[i-1]=c;
                }

                for(i=0; i<n; i++)
                {
                        cout<<result[i]<<" ";
                }
                cout<<"\n";
        }//test
        return 0;

}//main
