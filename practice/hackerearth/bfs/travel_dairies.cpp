//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/till-the-end-of-the-time-d73ba7d1/
//
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

struct node
{
    int x;
    int y;
    int dist;
};
int arr[2000][2000];
queue<node> q;
int mvx[] = {1, 0, -1, 0};
int mvy[] = {0, 1, 0, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    int i, j;
    memset(arr, -1, sizeof(arr));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == 2)
            {
                node n;
                n.x = i;
                n.y = j;
                n.dist = 0;
                q.push(n);
            }
        }
    }
    int result = 0;
    while (!q.empty())
    {
        node temp = q.front();
        q.pop();
        for (i = 0; i < 4; i++)
        {
            int new_x = temp.x + mvx[i];
            int new_y = temp.y + mvy[i];

            if (arr[new_x][new_y] == 1)
            {
                node n;
                n.x = new_x;
                n.y = new_y;
                n.dist = temp.dist + 1;
                q.push(n);
                arr[new_x][new_y] = 2;
                result = max(result, n.dist);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                result = -1;
        }
    }
    cout << result << "\n";
    return 0;

} //main
