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
int temp[10];
int main()
{
        int i; int p=0; int num; int d;
        int t;
        int n;
        cin>>n;
        for(t=1; t<=1000000; t++)
        {
                num=t;
                for(i=0; i<10; i++)
                {
                        temp[i]=0;
                }
                d=0;
                while(num)
                {
                        d++;
                        temp[num%10]=1;
                        num=num/10;
                }
                int flag=1;
                for(i=1; i<=d; i++)
                {
                        if (temp[i]==0)
                        {
                                flag=0;
                                break;
                        }
                }
                if (flag==1)
                {
                        mark[t]=1;
                }
        }
        for(i=1; i<=1000000; i++)
        {

                mark[i]= mark[i]+mark[i-1];
        }

        int l,r;
        for(i=0; i<n; i++)
        {
                cin>>l>>r;
                cout<<mark[r]-mark[l-1]<<"\n";
        }

        return 0;

}//main
