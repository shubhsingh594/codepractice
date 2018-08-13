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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz size()
#define rep(i, m) for (int i = 0; i < (int)(m); i++)
#define rep2(i, n, m) for (int i = n; i < (int)(m); i++)
#define For(it, c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define mem(a, b) memset(a, b, sizeof(a))
#define mp make_pair
#define ff first
#define ss second
#define dot(a, b) ((conj(a) * (b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X, (V).Y))
#define vect(a, b) ((b) - (a))
#define cross(a, b) ((conj(a) * (b)).imag())
#define normalize(v) ((v) / length(v))
#define rotate(p, about, theta) ((p - about) * exp(point(0, theta)) + about)
#define pointEqu(a, b) (comp(a.X, b.X) == 0 && comp(a.Y, b.Y) == 0)
#define mod 1000000007

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int)1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

vector<ll> store;
vector<ll> g;
vector<ll> s;
stack<pair<ll, int>> stk;
stack<pair<ll, int>> stk1;
set<pair<int, int>> result;
int main()
{
    int n;
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        store.pb(temp);
        g.pb(-1);
        s.pb(-1);
    }
    for (i = 0; i < n; i++)
    {
        ll curr = store[i];
        while (!stk.empty())
        {
            pair<ll, int> top = stk.top();
            if (curr > top.first)
            {
                g[top.second] = i;
                stk.pop();
            }
            else
                break;
        }
        stk.push(mp(curr, i));
    }

    for (i = n-1; i >= 0; i--)
    {
        ll curr = store[i];
        while (!stk1.empty())
        {
            pair<ll, int> top = stk1.top();
            if (curr > top.first)
            {
                s[top.second] = i;
                stk1.pop();
            }
            else
                break;
        }
        stk1.push(mp(curr, i));
    }

    // for (i = 0; i < n; i++)
    //     cout << g[i] << " ";
    // cout << "\n";
    // for (i = 0; i < n; i++)
    //     cout << s[i] << " ";
    // cout << "\n";

    for (i = 0; i < n; i++)
    {
        if (g[i] != -1)
        {
            result.insert(mp(max(store[i], store[g[i]]), min(store[i], store[g[i]])));
        }
        if (s[i] != -1)
        {
            result.insert(mp(max(store[i], store[s[i]]), min(store[i], store[s[i]])));
        }
    }
    cout << result.size() << "\n";
    return 0;

} //main
