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

int visit[200000];
vector<int> graph[200000];
int entrynumber[200000];
int exitnumber[200000];
int dfsnumber = 0;

void dfs(int index)
{
    if (visit[index] == 0)
    {
        visit[index] = 1;
        dfsnumber++;
        entrynumber[index] = dfsnumber;
        for (int i = 0; i < graph[index].size(); i++)
        {
            dfs(graph[index][i]);
        }
        dfsnumber++;
        exitnumber[index] = dfsnumber;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int x, a, b;
        scanf("%d %d %d", &x, &a, &b);
        if (x == 0)
        {
            if (entrynumber[a] < entrynumber[b] && exitnumber[a] > exitnumber[b])
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if (entrynumber[b] < entrynumber[a] && exitnumber[b] > exitnumber[a])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;

} //main
