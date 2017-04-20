// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/permutation-swaps/
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
int a[200000];
int b[200000];
int visit[200000];
vector<int>graph[200000];
queue<int>q;
int main()
{
        int test; cin>>test; int t;
        int n,m; int i; int j;
        for(t=0; t<test; t++)
        {
                cin>>n>>m;
                memset(visit,0,sizeof(visit));
                for(i=0; i<=n; i++)
                        graph[i].clear();
                for(i=1; i<=n; i++)
                {
                        cin>>a[i];
                }
                for(i=1; i<=n; i++)
                {
                        cin>>b[i];
                }
                int s,d;
                for(i=0; i<m; i++)
                {
                        cin>>s>>d;
                        graph[s].pb(d);
                        graph[d].pb(s);
                }
                int mark=1; int pos;
                for(i=1; i<=n; i++)
                {
                        if (graph[i].size()!=0 && visit[i]==0)
                        {
                                q.push(i);
                                visit[i]=mark;
                                while(!q.empty())
                                {
                                        pos=q.front();
                                        q.pop();
                                        for(j=0; j<graph[pos].size(); j++)
                                        {
                                                if (visit[graph[pos][j]]==0)
                                                {
                                                        visit[graph[pos][j]]=mark;
                                                        q.push(graph[pos][j]);
                                                }
                                        }

                                }
                                mark++;
                        }
                }
                // for(i=1; i<=n; i++)
                //         cout<<visit[i]<<" ";
                // cout<<"\n";
                map<int,int>store;
                for(i=1; i<=n; i++)
                {
                        store[a[i]]=visit[i];
                }
                int flag=0;
                for(i=1; i<=n; i++)
                {
                        if (a[i]!=b[i])
                        {
                                //  cout<<a[i]<<" "<<b[i]<<store[a[i]]<<" "<<store[b[i]]<<"\n";
                                if (store[a[i]]==store[b[i]] && store[a[i]]!=0)
                                {
                                        continue;
                                }
                                else
                                {
                                        flag=1;
                                        break;
                                }

                        }
                }
                if (flag==0)
                {
                        cout<<"YES\n";
                }
                else
                        cout<<"NO\n";


        }//test
        return 0;

}//main
