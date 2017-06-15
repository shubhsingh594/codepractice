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

int main()
{
        int test; cin>>test; int t;
        int x1s,y1s,x2s,y2s;
        int x1e,y1e,x2e,y2e;
        int x1,x2,y1,y2;
        char s1,s2; int flag=0;
        for(t=0; t<test; t++)
        {
                flag=0;
                cin>>x1>>y1>>x2>>y2;
                x1s=min(x1,x2); x1e=max(x1,x2);
                y1s=min(y1,y2); y1e=max(y1,y2);
                cin>>x1>>y1>>x2>>y2;
                x2s=min(x1,x2); x2e=max(x1,x2);
                y2s=min(y1,y2); y2e=max(y1,y2);
                int point=0;

                if (x1s==x1e && y1s==y1e)
                        s1='p';
                else if (y1s==y1e)
                        s1='r';
                else
                        s1='c';



                if (x2s==x2e && y2s==y2e)
                        s2='p';
                else if (y2s==y2e)
                        s2='r';
                else
                        s2='c';

                //cout<<s1<<" "<<s2<<"\n";
                if (s1=='p' && s2!='p')
                {
                        s1=s2;
                }
                else if (s2=='p' && s1!='p')
                {
                        s2=s1;
                }
                else if (s1=='p' && s2=='p')
                {
                        s1='r'; s2='r';
                }



                if (s1!=s2)
                {
                        if ((x1e==x2s && y1e==y2s)||(x1s==x2e && y1s==y2e)||(x1s==x2s && y1s==y2s)||(x1e==x2e && y1e==y2e))
                        {
                                flag=1;
                        }
                }
                else
                {
                        if (s1=='r')
                        {
                                if (y1s==y2s)
                                {
                                        if (x1s<=x2e && x1e>=x2s)
                                                flag=1;
                                }

                        }
                        else
                        {
                                if(x1s==x2s)
                                {
                                        if (y1s<=y2e && y1e>=y2s)
                                                flag=1;
                                }

                        }
                }

                if (flag==1)
                {
                        cout<<"yes\n";
                }
                else
                        cout<<"no\n";
        }
        return 0;

}//main
