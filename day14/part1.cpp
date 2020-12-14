/*

*/
#include "../common.hpp"

inline void set_bit(ll& value, int i) {
    value |= (1ll << i);
}

pair<ll, ll> parse_mask(string mask) {
    pair<ll, ll> res = {0ll, 0ll};
    int n = mask.size();
    for (int i = 0; i < mask.size(); i++) {
        if (mask[i] == '1') {
            set_bit(res.first, n - i - 1);
        } else if (mask[i] == '0') {
            set_bit(res.second, n - i - 1);
        }
    }
    return res;
}

ll mask_value(pair<ll, ll> &mask, ll value) {
    return (value | mask.first) & (~mask.second);
}

int main() {
    map<ll, ll> memory;
    pair<ll, ll> mask;

    while(!cin.eof()) {
        string line;
        getline(cin, line);

        if (line.substr(0, 4) == string("mask")) {
            // mask line
            mask = parse_mask(line.substr(7));
        } else {
            // mem line
            
            ll addr = -1;
            ll value = -1;
            sscanf(line.c_str(), "mem[%lld] = %lld", &addr, &value);
            memory[addr] = mask_value(mask, value);
        }
    }
    ll answer = 0;
    for (auto& it : memory) {
        answer += it.second;
    }
    debug(answer);
}