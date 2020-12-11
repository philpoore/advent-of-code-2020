/*
https://adventofcode.com/2020/day/10
*/
#include "../common.hpp"

map<ll, ll> cache;

ll count_ways(const vector<ll> &v, const set<ll> &s, ll max, ll i) {
    if (i == max) return 1;
    if (i > max) return 0;
    if (i != 0 && !s.count(i)) return 0;
    if (cache.count(i)) return cache[i];
    
    ll res = count_ways(v, s, max, i + 1)
        + count_ways(v, s, max, i + 2)
        + count_ways(v, s, max, i + 3);

    cache[i] = res;
    return res;
}

int main() {
    vector<ll> input = get_input<ll>();

    // Create set of elements.
    set<ll> s;
    foreach (input)
        s.insert(it);

    sort(input.begin(), input.end());

    ll max = input.back();

#if 0
    // Display sorted array.
    for (auto a : input) cout << a << " "; cout << "\n";
#endif
    
    ll num_ways = count_ways(input, s, max, 0);
    debug(num_ways);
}