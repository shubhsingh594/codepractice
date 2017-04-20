// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/we-are-on-fire/
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
map<int,int>check;
map<int,int>store;
vector<pair<int,int> >points;
queue<pair<int,int> >q;
int main()
{
        int n,m,query;
        int mark=1;
        int movesx[]={0,0,1,-1};
        int movesy[]={1,-1,0,0};
        scanf("%d %d %d",&n,&m,&query);
        int i,j;
        for(i=1; i<=n; i++)
        {
                for(j=1; j<=m; j++)
                {
                        scanf("%d",&arr[i][j]);
                        if (arr[i][j]==1)
                                points.pb(mp(i,j));
                }
        }
        int x,y,x1,y1; pair<int,int>temp;
        for(i=0; i<points.size(); i++)
        {
                x=points[i].ff; y=points[i].ss;
                if (visit[x][y]==0)
                {
                        visit[x][y]=mark;
                        q.push(mp(x,y));
                        store[mark]=1;
                        while(!q.empty())
                        {
                                temp=q.front();
                                q.pop();
                                for(j=0; j<4; j++)
                                {
                                        x1=temp.ff+movesx[j];
                                        y1=temp.ss+movesy[j];
                                        if (x1>0 && x1<=n && y1>0 && y1<=m)
                                        {
                                                if (visit[x1][y1]==0 && arr[x1][y1]==1)
                                                {
                                                        visit[x1][y1]=mark;
                                                        store[mark]++;
                                                        q.push(mp(x1,y1));
                                                }
                                        }
                                }
                        }//while
                        mark++;
                }

        }
        int result=points.size(); int ch;
        for(i=0; i<query; i++)
        {
                scanf("%d %d",&x,&y);
                if (visit[x][y]!=0)
                {
                        ch=visit[x][y];
                        if (check[ch]==0)
                        {
                                check[ch]=1;
                                result=result-store[ch];
                        }

                }
                printf("%d\n",result);
        }

        return 0;

}//main
