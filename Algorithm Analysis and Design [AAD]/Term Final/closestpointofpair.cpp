#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll get_rand(ll L, ll R) {
    if(L > R) swap(L, R);
    return L + (rnd() % (R - L + 1));
}

// Returns the Euclidean distance between two points (x1, y1) and (x2, y2).
double distancePts(const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
    long long dx = p1.first - p2.first;
    long long dy = p1.second - p2.second;
    return sqrt((long double)(dx * dx + dy * dy));
}

// O(n^2) approach to find the smallest distance among n points.
double bruteForceClosestPair(const vector<pair<ll, ll>>& points) {
    double minDist = numeric_limits<double>::infinity();
    ll n = points.size();
    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            double dist = distancePts(points[i], points[j]);
            if(dist < minDist){
                minDist = dist;
            }
        }
    }
    return minDist;
}

// Function to check strip befire combining
double stripClosest(vector<pair<ll, ll>>& strip, double d) {
    double minDist = d;
    ll n = strip.size();

    // Since strip is sorted by Y, we only check up to ~7 points ahead
    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n && (strip[j].second - strip[i].second) < minDist; j++){
            double dist = distancePts(strip[i], strip[j]);
            if(dist < minDist){
                minDist = dist;
            }
        }
    }
    return minDist;
}

// The main recursive function
double closestPairRec(vector<pair<ll, ll>>& px, vector<pair<ll, ll>>& py, ll left, ll right) {
    // If there are <= 3 points, just use brute force in this segment
    ll size = right - left + 1;
    if(size <= 3) {
        // Initialize minDist to a very large value
        double minDist = numeric_limits<double>::infinity();
        for(ll i = left; i <= right; i++){
            for(ll j = i + 1; j <= right; j++){
                double dist = distancePts(px[i], px[j]);
                if(dist < minDist) {
                    minDist = dist;
                }
            }
        }
        return minDist;
    }

    // Midpoint
    ll mid = (left + right) / 2;
    ll midX = px[mid].first; // We'll use this to build the strip

    // Build L_py and R_py (points in left side sorted by y, points in right side sorted by y)
    vector<pair<ll, ll>> L_py, R_py;
    L_py.reserve(size);
    R_py.reserve(size);
    for(auto &p : py) {
        if(p.first <= midX) L_py.push_back(p);
        else R_py.push_back(p);
    }

    // Recur left and right
    double dLeft = closestPairRec(px, L_py, left, mid);
    double dRight = closestPairRec(px, R_py, mid+1, right);
    double d = min(dLeft, dRight);

    // Build the strip: points whose x is within d of midX
    vector<pair<ll, ll>> strip;
    strip.reserve(size);
    for(auto &p : py) {
        if(fabsl((long double)(p.first - midX)) < d) {
            strip.push_back(p);
        }
    }

    // Check the strip
    double dStrip = stripClosest(strip, d);
    return min(d, dStrip);
}

// this function initiates solving
double divideAndConquerClosestPair(vector<pair<ll, ll>>& points) {
    // Sort points by x
    vector<pair<ll, ll>> px = points;
    sort(px.begin(), px.end(), [&](auto &a, auto &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    // Sort points by y
    vector<pair<ll, ll>> py = points;
    sort(py.begin(), py.end(), [&](auto &a, auto &b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    // Call the recursive helper
    return closestPairRec(px, py, 0, (ll)points.size() - 1);
}

void solve() {
    vector<ll> sizes;
    for(int i = 1; i < 14; i++){
        sizes.push_back(1 << i);
    }

    // Output files
    ofstream fileBF("BruteForceResult.txt"); 
    ofstream fileDC("DnCResult.txt");

    for (auto &n : sizes) {
        cout << "Number of points: " << n << "\n";

        // Generate n random points
        vector<pair<ll, ll>> points(n);
        for(ll i = 0; i < n; i++){
            ll x = get_rand(1, 1000000000);
            ll y = get_rand(1, 1000000000);
            points[i] = make_pair(x, y);
        }

        // Brute Force
        auto startBF = chrono::high_resolution_clock::now();
        double distBF = bruteForceClosestPair(points);
        auto endBF   = chrono::high_resolution_clock::now();
        ll timeBF = chrono::duration_cast<chrono::microseconds>(endBF - startBF).count();

        // Divide and Conquer
        auto startDC = chrono::high_resolution_clock::now();
        double distDC = divideAndConquerClosestPair(points);
        auto endDC   = chrono::high_resolution_clock::now();
        ll timeDC = chrono::duration_cast<chrono::microseconds>(endDC - startDC).count();

        // Verify correctness (allow a tiny epsilon for floating comparisons)
        if (fabs(distBF - distDC) > 1e-9) {
            cout << "Mismatch in results! BF: " << distBF << ", DC: " << distDC << "\n";
        }

        cout << "Brute Force Time           : " << timeBF << " microseconds\n";
        cout << "Divide & Conquer Time      : " << timeDC << " microseconds\n";
        cout << fixed << setprecision(8) << "Minimum Distance (Both)    : " << distDC << "\n";
        cout << "--------------------------------------------------\n";

        if (fileBF.is_open() && fileDC.is_open()) {
            fileBF << timeBF << "\n";
            fileDC << timeDC << "\n";
        } else {
            cout << "Unable to open output file(s).\n";
        }
    }
    fileBF.close();
    fileDC.close();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
