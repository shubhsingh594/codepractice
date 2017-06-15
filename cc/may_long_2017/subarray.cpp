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
int mark[200000];
char ops[200000];

vector<pair<int,pair<int,int> > > store;
int main()
{
        int n,k,p;
        cin>>n>>k>>p; int i,j;
        if (k>n)
                k=n;
        for(i=1; i<=n; i++)
        {
                scanf("%d",&arr[i]);
        }
        scanf("%s",ops);
        mark[0]=0;
        for(i=1; i<=n; i++)
        {
                mark[i]=mark[i-1]+arr[i];
        }
        int l,h; int val=0;
        for(i=1; i<=n; i++)
        {
                l=i-1;
                h=i+k-1;
                if (h>n)
                {
                        val=mark[n]-mark[l]+mark[h%n];
                }
                else
                {
                        val=mark[h]-mark[l];
                }
                store.push_back(mp(val,mp(i,h)));
        }
        sort(store.begin(),store.end());

        int count=0;
        int l1,h1;
        for(i=0; i<p; i++)
        {
                if(ops[i]=='?')
                {

                        for(j=store.size()-1; j>=0; j--)
                        {
                                l1=store[j].ss.ff+count;
                                h1=store[j].ss.ss+count;
                                l1=l1%n; h1=h1%n;
                                if (l1==0)
                                        l1=n;
                                if (h1==0)
                                        h1=n;
                                if (l1<=h1)
                                {
                                        printf("%d\n",store[j].ff);
                                        break;
                                }
                        }
                }
                else
                {
                        count++;

                }
        }



        return 0;

}//main
