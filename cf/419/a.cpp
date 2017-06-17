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
#include <string>
#include<bits/stdc++.h>

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

int check_palin(string str)
{
//  cout<<str<<"\n";
  string rstr="";int i;
    for(i=str.size()-1;i>=0;i--)
    {
      rstr=rstr+str[i];
    }
    if (rstr==str)
    return 1;
    else
    return 0;
}

string int_to_str(int num)
{
    stringstream ss;

    ss << num;

    return ss.str();
}
int main()
{
  string ch;
  cin>>ch;
  int a=((ch[0]-'0')*10 + (ch[1]-'0'));
  int b=((ch[3]-'0')*10 + (ch[4]-'0'));
//  cout<<a<<" "<<b<<"\n";
  int result=0;string temp;
  while(1)
  {
    string str="";
    if (a>=10)
    {
      temp=""+int_to_str(a);
      str=str+temp;
    }
    else
    {
      temp="0"+int_to_str(a);
      str=str+temp;
    }


    if (b>=10)
    {
      temp=""+int_to_str(b);
      str=str+temp;
    }
    else
    {
      temp="0"+int_to_str(b);
      str=str+temp;
    }



    if (check_palin(str))
    {
      break;
    }
    result++;
    b++;
    if (b==60)
    {
      b=0;
      a++;
    }
    if (a==24)
    {
      a=0;
    }
  }
  cout<<result<<"\n";
        return 0;

}//main
