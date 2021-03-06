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

int mark[2000000];

int main()
{
        int test; cin>>test; int t;
        string str; int i;
        for(t=0; t<test; t++)
        {
                cin>>str;
                memset(mark,0,sizeof(mark));
                for(i=0; i<str.size(); i++)
                {
                        if (i>0)
                        {
                                if (str[i]=='s' && str[i-1]=='m' && mark[i-1]==0)
                                {
                                        str[i]='*';
                                        mark[i-1]=1;
                                }
                                if (str[i]=='m' && str[i-1]=='s' && mark[i]==0)
                                {
                                        str[i-1]='*';
                                        mark[i]=1;
                                }
                        }
                }
                int s=0; int m=0;
                for(i=0; i<str.size(); i++)
                {
                        if (str[i]=='s')
                                s++;
                        if (str[i]=='m')
                                m++;
                }
                if (s>m)
                {
                        cout<<"snakes\n";
                }
                else if (m>s)
                {
                        cout<<"mongooses\n";
                }
                else
                        cout<<"tie\n";

        }
        return 0;

}//main
