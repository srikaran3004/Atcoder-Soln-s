#include <bits/stdc++.h>

using namespace std;
// autor: @Srikaran

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container,
          typename T = typename enable_if<!is_same<T_container, string>::value,
                                          typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n, m, c;
    if (!(cin >> n >> m >> c))
        return;
    vector<ll> A(n);
    for (auto &x : A)
        cin >> x;

    sort(A.begin(), A.end());
    vector<ll> p, q;
    for (auto x : A)
    {
        if (p.empty() || x != p.back())
        {
            p.push_back(x);
            q.push_back(1);
        }
        else
        {
            ++q.back();
        }
    }
    ll K = p.size();

    vector<ll> d(2 * K);
    for (ll i = 0; i < 2 * K; ++i)
        d[i] = q[i % K];

    ll ans = 0;
    ll r = -1;
    ll curr = 0;

    for (ll j = 0; j < K; ++j)
    {
        while (curr < c)
        {
            ++r;
            curr += d[r];
        }
        ll Tj = curr;
        ll prev = p[(j + K - 1) % K];
        ll gap = (p[j] - prev - 1 + m) % m;
        ll Sj = gap + 1;
        ans += Sj * Tj;
        curr -= d[j];
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}