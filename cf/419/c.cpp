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
int result[600][600];
int row[600];
int col[600];
vector<int>r;
vector<int>c;
int main()
{
  int n,m;int i;int j;
  cin>>n>>m;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      cin>>result[i][j];
    }
  }

  int t;

  if (n<m)
  {
    for(i=1;i<=n;i++)
    {
      row[i]=result[i][1];
      for(j=1;j<=m;j++)
      {
        row[i]=min(row[i],result[i][j]);
      }
    }

  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      result[i][j]=result[i][j]-row[i];
    }
    if (row[i]!=0)
    {
      for(t=0;t<row[i];t++)
      r.pb(i);
    }
  }


  for(i=1;i<=m;i++)
  {
    col[i]=result[1][i];
    for(j=1;j<=n;j++)
    {
      col[i]=min(col[i],result[j][i]);
    }
  }

  for(i=1;i<=m;i++)
  {
    for(j=1;j<=n;j++)
    {
      result[j][i]=result[j][i]-col[i];
    }
    if (col[i]!=0)
    {
      for(t=0;t<col[i];t++)
      c.pb(i);
    }
  }
}
else
{

  for(i=1;i<=m;i++)
  {
    col[i]=result[1][i];
    for(j=1;j<=n;j++)
    {
      col[i]=min(col[i],result[j][i]);
    }
  }

  for(i=1;i<=m;i++)
  {
    for(j=1;j<=n;j++)
    {
      result[j][i]=result[j][i]-col[i];
    }
    if (col[i]!=0)
    {
      for(t=0;t<col[i];t++)
      c.pb(i);
    }
  }
  for(i=1;i<=n;i++)
  {
    row[i]=result[i][1];
    for(j=1;j<=m;j++)
    {
      row[i]=min(row[i],result[i][j]);
    }
  }


  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      result[i][j]=result[i][j]-row[i];
    }
    if (row[i]!=0)
    {
      for(t=0;t<row[i];t++)
      r.pb(i);
    }
  }

}

int flag=0;

  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      if (result[i][j]!=0)
      flag=1;
    }
  }
  if (flag==1)
  {
    cout<<"-1\n";
  }
  else
  {
    cout<<r.size()+c.size()<<"\n";
    for(i=0;i<r.size();i++)
    {
      cout<<"row "<<r[i]<<"\n";
    }
    for(i=0;i<c.size();i++)
    {
      cout<<"col "<<c[i]<<"\n";
    }
  }


        return 0;

}//main
