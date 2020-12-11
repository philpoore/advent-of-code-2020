/*
https://adventofcode.com/2020/day/10
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

map<ll, ll> cache;

ll count_ways(const vector<ll> &v, const set<ll> &s, ll max, ll i) {
    if (i == max) return 1;
    if (i > max) {
        return 0;
    }
    if (i != 0) {
        if (!s.count(i)) {
            return 0;
        }
    }
    if (cache.count(i)) return cache[i];
    
    
    ll res = count_ways(v, s, max, i + 1)
        + count_ways(v, s, max, i + 2)
        + count_ways(v, s, max, i + 3);

    cache[i] = res;
    return res;
}

int main() {
    vector<ll> input;
    set<ll> s;
    while(!cin.eof()) {
        ll a;
        cin >> a;
        s.insert(a);
        input.push_back(a);
    }

    sort(input.begin(), input.end());
    ll max = input.back();

    for (auto a : input) {
        cout << a << " ";
    }
    cout << "\n";
    
    ll num_ways = count_ways(input, s, max, 0);
    cout << "num ways: " << num_ways << "\n";
}