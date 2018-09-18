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

stack<int> stk;
int visit[1000];
int rvisit[1000];
vector<int> graph[2000];
vector<int> rgraph[2000];
int pills[2000];
void dfs(int index)
{
    if (visit[index] == -1)
    {
        visit[index] = 1;
        for (int i = 0; i < graph[index].size(); i++)
        {
            dfs(graph[index][i]);
        }
        stk.push(index);
    }
}
int rdfs(int index)
{
    if (rvisit[index] == -1)
    {
        rvisit[index] = 1;
        int val = pills[index];
        for (int i = 0; i < rgraph[index].size(); i++)
        {
            val += rdfs(rgraph[index][i]);
        }
        return val;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    int n, m;
    int i;
    for (int test = 0; test < t; test++)
    {
        while (!stk.empty())
        {
            stk.pop();
        }
        memset(visit, -1, sizeof(visit));
        memset(rvisit, -1, sizeof(rvisit));
        cin >> n >> m;
        for (i = 0; i <= n; i++)
        {
            graph[i].clear();
            rgraph[i].clear();
        }
        for (i = 0; i < n; i++)
        {
            cin >> pills[i];
        }
        int j, a, b;
        for (j = 0; j < m; j++)
        {
            cin >> a >> b;
            graph[a].pb(b);
            rgraph[b].pb(a);
        }
        for (i = 0; i < n; i++)
        {
            if (visit[i] == -1)
            {
                dfs(i);
            }
        }
        int result = 0;
        while (!stk.empty())
        {
            int curr = stk.top();
            stk.pop();
            result = max(result, rdfs(curr));
        }
        cout << result << "\n";
    }

    return 0;

} //main
