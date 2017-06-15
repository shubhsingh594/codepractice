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

int arr[600][600];
int mark[600][600];
stack<pair<int,int> >stk1,stk2;
int main()
{
        int test; scanf("%d",&test); int t;
        int n,m; int i,j;
        int maxi=0;
        int x[]={0,0,-1,-1,-1,1,1,1};
        int y[]={-1,1,-1,0,1,-1,0,1};
        int result=0;
        for(t=0; t<test; t++)
        {
                int maxi=-1;
                result=0;
                while(!stk1.empty())
                {
                        stk1.pop();
                }
                while(!stk2.empty())
                {
                        stk2.pop();
                }
                scanf("%d %d",&n,&m);
                for(i=0; i<n; i++)
                {
                        for(j=0; j<m; j++)
                        {
                                scanf("%d",&arr[i][j]);
                                maxi=max(maxi,arr[i][j]);
                        }
                }
                for(i=0; i<n; i++)
                {
                        for(j=0; j<m; j++)
                        {
                                if (arr[i][j]==maxi)
                                {
                                        stk1.push(mp(i,j));
                                        mark[i][j]=1;
                                }
                        }
                }
                pair<int,int>temp;
                int x1,y1;
                while(1)
                {
                        while(!stk1.empty())
                        {
                                temp=stk1.top();
                                stk1.pop();
                                for(i=0; i<8; i++)
                                {
                                        x1=temp.ff+x[i];
                                        y1=temp.ss+y[i];
                                        if (x1>=0 && y1>=0 && x1<n && y1<m)
                                        {
                                                if (arr[x1][y1]<maxi)
                                                {
                                                        arr[x1][y1]=maxi;
                                                        stk2.push(mp(x1,y1));
                                                }
                                        }
                                }
                        }
                        if(stk2.empty())
                        {
                                printf("%d\n",result);
                                break;
                        }
                        else
                        {
                                result++;
                                while(!stk2.empty())
                                {
                                        stk1.push(stk2.top());
                                        stk2.pop();
                                }
                        }
                }

        }//tests
        return 0;

}//main
