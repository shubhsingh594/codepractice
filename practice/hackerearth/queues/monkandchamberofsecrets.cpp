// https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/
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

queue<pair<int, int>> store;
queue<pair<int, int>> save;
vector<int> result;
int main()
{
    int n, x;
    cin >> n >> x;
    int i;
    int temp;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        store.push(mp(temp, i));
    }
    for (i = 0; i < x; i++)
    {
        int c = 0;
        int m = -1;
        while (!store.empty() && c < x)
        {
            pair<int, int> curr = store.front();
            store.pop();
            save.push(curr);
            m = max(m, curr.first);
            c++;
        }
        int flag = 0;
        while (!save.empty())
        {
            pair<int, int> curr = save.front();
            if (flag == 1)
            {
                curr.first = max(0, curr.first - 1);
                store.push(curr);
            }
            else
            {
                if (curr.first == m)
                {
                    flag = 1;
                    result.pb(curr.second + 1);
                }
                else
                {
                    curr.first = max(0, curr.first - 1);
                    store.push(curr);
                }
            }
            save.pop();
        }
    }
    for (i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;

} //main
