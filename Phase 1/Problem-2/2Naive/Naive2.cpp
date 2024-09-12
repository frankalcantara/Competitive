#include <iostream>
#include <vector>

using namespace std;

using ps = vector<int>;  // Alias for prefix_sum as a vector of long long
using ts = int;          // Alias for total_sum as long long
using pl = vector<int>;        // Alias for plates as a vector of int
using vi = vector<int>;        // Alias for vector of int (similar to vi)

int main() {
    vi pl;
    int n;
    vi ps;
    int ts;

    pl = { 3, 1, 5, 2, 2 };
    n = pl.size();
    ps = vi(n + 1, 0);
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + pl[i - 1];
    ts = ps[n];
    for (int i = 1; i <= n; ++i) {
        int ls = ps[i - 1], rs = ts - ps[i];
        if (ls == rs) {
            cout << i - 1 << endl;
            break;
        }
        if (i == n) cout << -1 << endl;
    }

    pl = { 1, 2, 3 };
    n = pl.size();
    ps = vi(n + 1, 0);
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + pl[i - 1];
    ts = ps[n];
    for (int i = 1; i <= n; ++i) {
        int ls = ps[i - 1], rs = ts - ps[i];
        if (ls == rs) {
            cout << i - 1 << endl;
            break;
        }
        if (i == n) cout << -1 << endl;
    }

    pl = { 2, 1, -1 };
    n = pl.size();
    ps = vi(n + 1, 0);
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + pl[i - 1];
    ts = ps[n];
    for (int i = 1; i <= n; ++i) {
        int ls = ps[i - 1], rs = ts - ps[i];
        if (ls == rs) {
            cout << i - 1 << endl;
            break;
        }
        if (i == n) cout << -1 << endl;
    }

    return 0;
}