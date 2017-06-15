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

long long l[2000000];
ll r[2000000];
ll arr[2000000];

int main()
{
        int test; cin>>test; int t; int n;
        int i;
        ll sum=0;
        for(t=0; t<test; t++)
        {
                cin>>n;
                sum=0;
                memset(l,0,sizeof(l));
                memset(r,0,sizeof(r));
                for(i=1; i<=n; i++)
                {
                        cin>>arr[i];
                        sum=sum+arr[i];
                }
                ll c=0;
                for(i=1; i<=n; i++)
                {
                        if (arr[i]>=c+1)
                        {
                                l[i]=c+1;
                                c++;
                        }
                        else
                        {
                                l[i]=arr[i];
                                c=l[i];
                        }

                }

                c=0;
                for(i=n; i>=1; i--)
                {
                        if (arr[i]>=c+1)
                        {
                                r[i]=c+1;
                                c++;
                        }
                        else
                        {
                                r[i]=arr[i];
                                c=r[i];
                        }
                }
                ll m=0;
                for(i=1; i<=n; i++)
                {
                        m=max(m,min(l[i],r[i]));
                }
                cout<<sum-m*m<<"\n";
        }

        return 0;

}//main
