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
vector<string>blk;
vector<string>ublk;
vector<string>result;
struct node
{
        int letters[26];
        int bcount;
        int ubcount;
};
node trie[2000000];
int ncount; int flag;
void init(int ncnount)
{
        int i;
        for(i=0; i<26; i++)
        {
                trie[ncount].letters[i]=0;
        }
        trie[ncount].bcount=0;
        trie[ncount].ubcount=0;
}
int add(string str,int index,int pos,int sg)
{

        if (pos<str.size())
        {

                if (trie[index].letters[str[pos]-'a']==0)
                {
                        ncount++;
                        init(ncount);
                        trie[index].letters[str[pos]-'a']=ncount;
                }
                if (add(str,trie[index].letters[str[pos]-'a'],pos+1,sg)==1)
                {
                        trie[index].ubcount++;
                }
                else
                        trie[index].bcount++;
                //cout<<index<<" "<<str<<" "<<pos<<" "<<str[pos]<<" "<<trie[index].bcount<<" "<<trie[index].ubcount<<"\n";
        }
        return sg;
}

void calc(string r,int index)
{
        int i;
        //cout<<index<<" "<<trie[index].ubcount<<" "<<trie[index].bcount<<" "<<r<<"\n";

        if (trie[index].bcount==1 && r.size()>0 && trie[index].ubcount==0)
        {
                result.pb(r);
        }
        else
        {
                int f=0; int temp=0;
                for(i=0; i<26; i++)
                {
                        if (trie[index].letters[i]!=0)
                        {
                                temp=trie[index].letters[i];
                                if (trie[temp].bcount>0)
                                {
                                        f=1;
                                        calc(r+((char)('a'+i)),trie[index].letters[i]);
                                }
                        }
                }
                if (f==0)
                {
                        //  cout<<r<<" flag\n";
                        flag=1;
                }
        }


}
int main()
{
        int n; ncount=0; flag=0;
        cin>>n; int i; char ch; string str;
        init(0);
        for(i=0; i<n; i++)
        {
                cin>>ch>>str;
                if (ch=='-')
                {
                        blk.push_back(str);
                        add(str,0,0,-1);

                }
                else
                {
                        ublk.push_back(str);
                        add(str,0,0,1);
                }
        }
        calc("",0);
        if (flag==1)
        {
                cout<<"-1\n";
                return 0;
        }
        //cout<<"flag : "<<flag<<"\n";
        cout<<result.size()<<"\n";
        sort(result.begin(),result.end());
        for(i=0; i<result.size(); i++)
        {
                cout<<result[i]<<"\n";
        }
        return 0;

}//main
