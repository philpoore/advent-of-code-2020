/*

find t such that:
t % 17  == 0
t % 13  == 11
t % 19  == 16

*/
#include "../common.hpp"

inline int offset(const ll& curr, const int& busId) {
    return (busId - (curr % busId));
}

int main() {
    int ts;
    string line;
    cin >> ts >> line;
    
    vector<string> busses = split(line, ',');
    int n = busses.size();

    ll sum = 1;
    int id = -1;
    map<int, int> m;

    for(auto& bus : busses) {
        id++;
        if (bus == "x") continue;
        m[id] = stoi(bus);
    }

    int i = 1;
    ll step = m[0];
    ll curr = 0;
    
    while(true) {
        if (i >= n) break;
        if (!m.count(i)) {
            i++;
            continue;
        }
        int& busId = m[i];
        
        int ans = offset(curr, busId);
        if (ans == i % busId) {
            // Found match, move onto the next character
            step *= busId;
            i++;
        } else {
            curr += step;
        }
    }
    ll& answer = curr;
    debug(answer);

#if 0
    // Verify the answer
    for (auto& it : m) {
        int i = it.first;
        int busId = it.second;
        int o = offset(answer, busId);
        cout << i << " -> " << busId << " ";
        cout << answer << " % " << busId << " = " << answer % busId << " ";
        cout << o << " " << (o % busId == i % busId ? "true" : "false") << "\n";
    }
#endif
}