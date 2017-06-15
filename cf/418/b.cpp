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

int a[200000];
int b[200000];
int mark[100000];
int result[100000];
vector<int>pos;
vector<int>val;
int main()
{
        int n;
        cin>>n; int i;
        memset(mark,0,sizeof(mark));
        for(i=0; i<n; i++)
        {
                cin>>a[i];
        }
        for(i=0; i<n; i++)
        {
                cin>>b[i];
        }
        int count1=0;
        for(i=0; i<n; i++)
        {
                if (a[i]==b[i] && mark[a[i]]==0)
                {
                        result[i]=a[i];
                        mark[a[i]]=1;
                }
                else
                {
                        count1++;
                        pos.push_back(i);
                }
        }
        // cout<<count1<<"\n";
        // for(i=0; i<count1; i++)
        // {
        //         cout<<pos[i]<<" ";
        // }
        // cout<<"\n";
        if (count1==1)
        {
                for(i=1; i<=n; i++)
                {
                        if (mark[i]==0)
                        {
                                result[pos[0]]=i;
                                break;
                        }
                }
        }
        else
        {
                for(i=1; i<=n; i++)
                {
                        if (mark[i]==0)
                        {
                                val.pb(i);
                        }
                }
                int flag=0;
                int count1=0;
                result[pos[0]]=val[0];
                result[pos[1]]=val[1];
                for(i=0; i<n; i++)
                {
                        if (a[i] !=result[i])
                                count1++;
                }
                if (count1==1)
                {
                        count1=0;
                        for(i=0; i<n; i++)
                        {
                                if (b[i] !=result[i])
                                        count1++;
                        }
                        if (count1==1)
                                flag=1;
                }
                if (flag==0)
                {
                        result[pos[0]]=val[1];
                        result[pos[1]]=val[0];
                }
        }

        for(i=0; i<n; i++)
        {
                cout<<result[i]<<" ";
        }
        cout<<"\n";


        return 0;

}//main
