// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/capture-castle/
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
class comp
{
public:
bool operator()(const pair<pair<int,int>,int>a,const pair<pair<int,int>,int>b)
{
        return a.ss>b.ss;
}

};
priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,comp>pq;
int visit[2000][2000];
int main()
{
        int test; cin>>test; int t;
        int n,m; int i,j;
        int movesx[]={0,0,1,-1};
        int movesy[]={-1,1,0,0};
        for(t=0; t<test; t++)
        {
                cin>>n>>m;
                memset(visit,-1,sizeof(visit));
                memset(arr,0,sizeof(arr));
                while(!pq.empty())
                {
                        pq.pop();
                }
                for(i=1; i<=n; i++)
                {
                        for(j=1; j<=m; j++)
                        {
                                cin>>arr[i][j];
                        }
                }
                int fx,fy,ti;
                cin>>fx>>fy>>ti;
                pq.push(mp(mp(1,1),arr[1][1]));
                visit[1][1]=arr[1][1]; int x,y,x1,y1;
                pair<pair<int,int>,int>temp;
                while(!pq.empty())
                {
                        temp=pq.top();
                        pq.pop();
                        if (temp.ff.ff==fx && temp.ff.ss==fy)
                        {
                                break;
                        }
                        x=temp.ff.ff; y=temp.ff.ss;
                        for(i=0; i<4; i++)
                        {
                                x1=x+movesx[i];
                                y1=y+movesy[i];
                                if (x1>0 && y1>0 && x1<=n && y1<=m && visit[x1][y1]==-1)
                                {
                                        visit[x1][y1]=temp.ss+arr[x1][y1];
                                        pq.push(mp(mp(x1,y1),visit[x1][y1]));
                                }
                        }

                }//while
                if (visit[fx][fy]<=ti)
                {
                        cout<<"YES\n";
                        cout<<ti-visit[fx][fy]<<"\n";
                }
                else
                        cout<<"NO\n";

        }
        return 0;

}//main
