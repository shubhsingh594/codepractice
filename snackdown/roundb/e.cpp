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

int arr[60][60];
int dist[60][60];
int main()
{
        int test; cin>>test; int t; int n;
        int xs,ys,xe,ye;
        int x1,y1,x2,y2; int i;
        char type; int x,y;
        for(t=0; t<test; t++)
        {
                cin>>n;
                memset(arr,0,sizeof(arr));
                memset(dist,0,sizeof(dist));
                for(i=0; i<n; i++)
                {
                        cin>>x1>>y1>>x2>>y2;
                        xs=min(x1,x2);
                        xe=max(x1,x2);
                        ys=min(y1,y2);
                        ye=max(y1,y2);

                        if (xs==xe)
                        {
                                type='c';
                        }
                        else
                                type ='r';

                        for(x=0; x<=50; x++)
                        {
                                for(y=0; y<=50; y++)
                                {

                                        if (type=='r')
                                        {
                                                if (x<xs)
                                                {
                                                        dist[x][y]=max(dist[x][y],abs(xs-x)+abs(y-ys));
                                                }
                                                else if (x>xe)
                                                {
                                                        dist[x][y]=max(dist[x][y],abs(x-xe)+abs(y-ys));
                                                }
                                                else
                                                {
                                                        dist[x][y]=max(dist[x][y],abs(y-ys));
                                                }
                                        }
                                        else
                                        {

                                                if (y<ys)
                                                {
                                                        dist[x][y]=max(dist[x][y],abs(ys-y)+abs(xs-x));
                                                }
                                                else if (y>ye)
                                                {
                                                        dist[x][y]=max(dist[x][y],abs(y-ye)+abs(xs-x));
                                                }
                                                else
                                                {
                                                        dist[x][y]=max(dist[x][y],abs(xs-x));
                                                }

                                        }



                                }
                        }
                }

                int result=dist[0][0];

                for(x=0; x<=50; x++)
                {
                        for(y=0; y<=50; y++)
                        {
                                result=min(result,dist[x][y]);
                        }
                }
                cout<<result<<"\n";




        }//test
        return 0;

}//main
