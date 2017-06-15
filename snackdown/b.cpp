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

int arr[200000];
int main()
{
        int test; cin>>test; int t; int n;
        int flag=0; int i;
        for(t=0; t<test; t++)
        {
                flag=0;
                cin>>n;
                for(i=0; i<n; i++)
                {
                        cin>>arr[i];
                }
                if (n%2==0)
                {
                        flag=1;
                }
                if (arr[0]!=arr[n-1] || arr[0]!=1)
                {
                        flag=1;
                }
                for(i=0; i<n/2; i++)
                {
                        if (arr[i]!=arr[n-1-i])
                                flag=1;
                }
                for(i=0; i<n/2; i++)
                {
                        if (arr[i+1] !=(arr[i]+1))
                        {
                                flag=1;
                        }
                }
                if (flag==1)
                        cout<<"no\n";
                else
                        cout<<"yes\n";

        }
        return 0;

}//main
