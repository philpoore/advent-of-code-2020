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
        } else if (mask[i] == 'X') {
            set_bit(res.second, n - i - 1);
        }
    }
    return res;
}

vector<ll> mask_memory(pair<ll, ll> &mask, ll addr) {
    ll new_addr = (addr & ~mask.second) | mask.first;
    vector<ll> offsets = {new_addr};
    for (ll i = 0, num = 1ll; i < 36; i++, num <<= 1) {
        if (mask.second & num) {
            vector<ll> offsets_tmp;
            for (auto& offset : offsets) {
                offsets_tmp.push_back(offset);
                offsets_tmp.push_back(offset + num);
            }
            offsets = offsets_tmp;
        }
    }

    return offsets;
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
            auto addrs = mask_memory(mask, addr);
            for (auto& addr : addrs)
                memory[addr] = value;
        }
    }
    ll answer = 0;
    for (auto& it : memory) {
        // cout << it.first << " " << it.second << "\n";
        answer += it.second;
    }
    debug(answer);
}