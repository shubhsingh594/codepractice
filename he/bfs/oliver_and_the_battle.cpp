https ://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/oliver-and-the-battle-1/
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
map<int,int>mpi;
queue<pair<int,int> >q;
int main()
{
        int i,j;
        pair<int,int>p;
        int test; cin>>test; int t;
        int xmove[]={1,1,1,0,0,-1,-1,-1};
        int ymove[]={-1,0,1,-1,1,-1,0,1};
        for(t=0; t<test; t++)
        {
                int n,m; int m1;
                cin>>n>>m;
                int arr[n][m];
                int visit[n][m];
                for(i=0; i<n; i++)
                {
                        for(j=0; j<m; j++)
                        {
                                cin>>arr[i][j];
                                visit[i][j]=-1;
                        }
                }
                int mark=1;
                int result=0; int x,y; int x1,y1;
                for(i=0; i<n; i++)
                {
                        for(j=0; j<m; j++)
                        {
                                if (arr[i][j]==1 && visit[i][j]==-1)
                                {
                                        visit[i][j]=mark;
                                        q.push(mp(i,j));
                                        mpi[mark]=1;
                                        while(!q.empty())
                                        {
                                                x=q.front().ff;
                                                y=q.front().ss;
                                                q.pop();
                                                for(m1=0; m1<8; m1++)
                                                {
                                                        x1=x+xmove[m1];
                                                        y1=y+ymove[m1];
                                                        if (x1>=0 && x1<n && y1>=0 && y1<m)
                                                        {
                                                                if (arr[x1][y1]==1 && visit[x1][y1]==-1)
                                                                {
                                                                        visit[x1][y1]=mark;
                                                                        q.push(mp(x1,y1));
                                                                        mpi[mark]++;
                                                                }
                                                        }
                                                }
                                        }
                                        result=max(result,mpi[mark]);
                                        mark++;
                                }
                        }
                }

                //   for(i=0;i<n;i++)
                //   {
                //       for(j=0;j<m;j++)
                //       cout<<visit[i][j];
                //       cout<<"\n";
                //   }
                // cout<<"answer\n";
                cout<<mark-1<<" "<<result<<"\n";

        }
        return 0;

}//main
