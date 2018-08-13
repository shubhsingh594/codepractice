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

vector<vector<int>> store;
stack<int> mstore;
int main()
{
    int n;
    cin >> n;
    int i;
    int j;
    int mn = oo;
    for (i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vector<int> st;
        for (j = 0; j < num; j++)
        {
            int temp;
            cin >> temp;
            st.pb(temp);
        }
        store.pb(st);
    }
    mstore.push(store[0][0]);
    for (i = 1; i < store[0].size(); i++)
    {
        if (store[0][i] < mstore.top())
        {
            mstore.push(store[0][i]);
        }
        else
            mstore.push(mstore.top());
    }
    int q;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        int h, k;
        if (op == 0)
        {
            cin >> k;
            k--;
            int ch = store[k].back();
            store[k].pop_back();
            if (k == 0)
            {
                mstore.pop();
            }
        }
        else if (op == 1)
        {
            cin >> k >> h;
            k--;
            store[k].push_back(h);
            if (k == 0)
            {
                if (h < mstore.top())
                {
                    mstore.push(h);
                }
                else
                {
                    mstore.push(mstore.top());
                }
            }
        }
        else
        {
            if (n == 1)
            {
                if (store[0].size() > 0)
                    cout << "YES\n";
                else
                    cout << "NO\n";
                continue;
            }
            mn = mstore.top();
            int flag = 1;
            for (j = 1; j < store.size(); j++)
            {
                int pos = upper_bound(store[j].begin(), store[j].end(), mn) - store[j].begin();
                // cout << pos << " " << mn << " <-- position \n";
                if (store[j][pos] <= mn)
                {
                    cout << "NO\n";
                    flag = 0;
                    break;
                }
                mn = store[j][pos];
            }
            if (flag)
                cout << "YES\n";
        }
    }
    return 0;
} //main
