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
#define ll long long
#define rep(i,m) for(ll i=0; i<(ll)(m); i++)
#define rep2(i,n,m) for(ll i=n; i<(ll)(m); i++)
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
#define rotate(p,about,theta) ((p-about)*exp(poll(0,theta))+about)
#define pollEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)
#define mod 1000000007

typedef stringstream ss;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef vector<vector<ll> > vii;
typedef long double ld;
typedef complex<double> poll;
typedef pair<poll, poll> segment;
typedef pair<double, poll> circle;
typedef vector<poll> polygon;

const ll oo = (ll) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

ll arr[200000];
ll sum[200000];
ll calc(ll s,ll e,ll k,ll last)
{
        //cout<<s<<" "<<e<<"\n";
        ll mid=0;
        if (s<=e)
        {
                mid=(s+e)/2;
                ll num=sum[last]-sum[mid]+arr[mid];
                ll val = last-mid+1;
                ll temp = mid-(val*k-num);

                if (temp>=0)
                {
                        if (mid-1<0)
                        {
                                if (temp>=0)
                                {
                                        return val;
                                }
                                else
                                        return 0;
                        }
                        ll num1=sum[last]-sum[mid-1]+arr[mid-1];
                        ll val1 = last-mid+1+1;
                        ll temp1 = mid-1-(val1*k-num1);
                        if (temp1<0)
                        {
                                return val;
                        }
                        else
                        {
                                return calc(s,mid-1,k,last);
                        }
                }
                else
                {
                        return calc(mid+1,e,k,last);
                }




        }
        return 0;


}
int main()
{
        ll test; ll t;
        cin>>test; ll n,q; ll i; ll k; ll index;
        ll result=0; ll balance=0; ll j;
        for(t=0; t<test; t++)
        {
                cin>>n>>q;
                result=0; balance=0;
                for(i=0; i<n; i++)
                {
                        cin>>arr[i];
                }
                sort(arr,arr+n);
                sum[0]=arr[0];
                for(i=1; i<n; i++)
                {
                        sum[i]=sum[i-1]+arr[i];
                }
                for(i=0; i<q; i++)
                {
                        cin>>k;
                        ll *p = lower_bound(arr,arr+n,k);
                        index = p-arr;
                        result=n-index;
                        index--;

                        result+=calc(0,index,k,index);
                        cout<<result<<"\n";

                }

        }
        return 0;

}//main
