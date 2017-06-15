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
int bars1[2000000];
int bars2[2000000];
int bars3[2000000];
int bars4[2000000];
int main()
{
        int n; int i;
        cin>>n;
        for(i=0; i<n; i++)
        {
                bars1[i]=1;
                bars2[i]=1;
                bars3[i]=1;
                bars4[i]=1;
        }
        for(i=0; i<n-1; i++)
        {
                cin>>arr[i];
        }
        for(i=n-2; i>=0; i--)
        {
                if (arr[i]==1)
                {
                        // ->
                        bars1[i]=bars1[i]+bars1[i+1];
                }
        }
        for(i=1; i<n; i++)
        {
                // <-
                if(arr[i-1]==0)
                {
                        bars2[i]=bars2[i-1]+bars2[i];
                }
        }
        for(i=0; i<n; i++)
        {
                if (arr[i]==1)
                        arr[i]=0;
                else
                        arr[i]=1;
        }

        for(i=n-2; i>=0; i--)
        {
                if (arr[i]==1)
                {
                        bars3[i]=bars3[i]+bars3[i+1];
                }
        }
        for(i=1; i<n; i++)
        {
                if(arr[i-1]==0)
                {
                        bars4[i]=bars4[i-1]+bars4[i];
                }
        }

        int q; cin>>q;
        char ch;
        int use=0; int val;
        int result=0;
        for(i=0; i<q; i++)
        {
                cin>>ch;
                if (ch=='U')
                        use=(use+1)%2;
                else
                {

                        result=1;
                        cin>>val;
                        val--;
                        if (val-1>=0)
                        {
                                if (use==0)
                                {
                                        if (arr[val-1]==1)
                                                result=result+bars2[val-1];
                                }
                                else
                                {
                                        if (arr[val-1]==0)
                                                result=result+bars4[val-1];
                                }
                        }
                        if (val+1<n)
                        {
                                if (use==0)
                                {         if (arr[val]==0)
                                                  result = result+bars1[val+1]; }
                                else
                                {
                                        if (arr[val]==1)
                                                result=result+bars3[val+1];
                                }
                        }

                        cout<<result<<"\n";

                }

        }

        return 0;
}//main
