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

int arr[2000000];
stack<pair<int,int> >stk1,stk2;
int large[2000000];
int low[2000000];
int main()
{
        int n; cin>>n; int i;
        for(i=1; i<=n; i++)
        {
                cin>>arr[i];
        }
        int pos=0;
        for(i=1; i<=n; i++)
        {
                pos=0;
                if (!stk1.empty())
                {
                        while(!stk1.empty())
                        {
                                if (stk1.top().ff<=arr[i])
                                        stk1.pop();
                                else
                                {
                                        pos=stk1.top().ss;
                                        break;
                                }
                        }
                        stk1.push(mp(arr[i],i));

                }
                else
                        stk1.push(mp(arr[i],i));
                low[i]=pos;
        }

        for(i=n; i>0; i--)
        {
                pos=0;
                if (!stk2.empty())
                {
                        while(!stk2.empty())
                        {
                                if (stk2.top().ff<=arr[i])
                                        stk2.pop();
                                else
                                {
                                        pos=stk2.top().ss;
                                        break;
                                }
                        }
                        stk2.push(mp(arr[i],i));

                }
                else
                        stk2.push(mp(arr[i],i));
                large[i]=pos;
        }

        long long result=0;
        for(i=1; i<=n; i++)
        {
                //cout<<low[i]<<" "<<large[i]<<"\n";
                if (large[i]!=0)
                {
                        if (large[i]-low[i]>=2)
                        {
                                result++;
                        }
                }
        }
        cout<<result<<"\n";
        return 0;

}//main
