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

vector<pair<double,pair<double,double> > >store;
int mark[1000000];
double dist(int x1,int y1,int x2,int y2)
{
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
        int n;
        cin>>n; int i,j;
        double x,y,r;
        for(i=0; i<n; i++)
        {
                cin>>x>>y>>r;
                store.pb(mp(r,mp(x,y)));
        }
        sort(store.begin(),store.end());
        for(i=n-1; i>=0; i--)
        {
                for(j=i+1; j<n; j++)
                {
                        if (dist(store[i].ss.ff,store[i].ss.ss,store[j].ss.ff,store[j].ss.ss)<=store[j].ff)
                        {
                                cout<<store[i].ss.ff<<" "<<store[i].ss.ss<<" "<<store[j].ss.ff<<" "<<store[j].ss.ss<<"\n";
                                mark[i]=mark[j]+1;
                                break;
                        }
                }
        }
        double sum1=0.0; double sum2=0.0;
        int flag1=0; int flag2=0;
        for(i=0; i<n; i++)
        {
                cout<<mark[i]<<" ";
        }
        cout<<"\n";
        for(i=0; i<n; i++)
        {
                if (mark[i]%4==0 || mark[i]%4==1)
                {
                        sum1+=PI * store[i].ff*store[i].ff;
                }
                else
                {
                        sum1-=PI * store[i].ff*store[i].ff;
                }
        }
        cout<<sum1<<"\n";

        return 0;

}//main
