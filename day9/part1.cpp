/*
https://adventofcode.com/2020/day/9
*/
#include "../common.hpp"

bool is_valid(vector<ll> v, ll target) {
    set<ll> s;
    for (auto& i : v) {
        if (s.count(target - i)) {
            return true;
        }
        s.insert(i);
    }
    return false;
}

int main() {
    int preamble = 25;
    vector<ll> input = get_input<ll>();

    vector<ll> v;
    for (int i = 0; i < preamble; i++) {
        v.push_back(input[i]);
    }

    for (int i = preamble; i < input.size(); i++) {
        if (!is_valid(v, input[i])) {
            cout << input[i] << " is invalid\n";
            return 0;
        }
        v = vector<ll>(v.begin() + 1, v.end());
        v.push_back(input[i]);
    }
    cout << "All input is valid\n";
    return 0;
}