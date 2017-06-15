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
int l=200000;
map<pair<int,int>,int>visit;
queue<pair<int,int> >q;
int main()
{
        int x1,y1,x2,y2;
        int x_moves[]={1,1,-1,-1};
        int y_moves[]={1,-1,1,-1};
        cin>>x1>>y1>>x2>>y2;
        q.push(mp(x1,y1)); int i;
        visit[mp(x1,y1)]=1;
        int a,b;
        cin>>a>>b;
        int count1=0;
        while(!q.empty())
        {
                count1++;
                if (count1>=9000000)
                        break;
                pair<int,int>curr=q.front();
                if (curr.ff==x2 && curr.ss==y2)
                {
                        cout<<"YES\n";
                        return 0;
                }
                q.pop();
                int tempx,tempy;
                for(i=0; i<4; i++)
                {
                        tempx=curr.ff+x_moves[i]*a;
                        tempy=curr.ss+y_moves[i]*b;
                        if (tempx<=l && tempx>=-1*l && tempy<=l && tempy>=-1*l)
                        {
                                if (visit[mp(tempx,tempy)]==0)
                                {
                                        q.push(mp(tempx,tempy));
                                        visit[mp(tempx,tempy)]=1;
                                }
                        }
                }
        }

        cout<<"NO\n";
        return 0;

}//main
