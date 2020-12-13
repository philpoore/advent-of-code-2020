/*

*/
#include "../common.hpp"

int main() {
    int ts;
    string line;
    cin >> ts >> line;
    
    vector<string> busses = split(line, ',');

    auto wait_time = [&](int id){
        return id - (ts % id);
    };

    int minWait = INT32_MAX;
    int answer = -1;
    for (auto& bus : busses) {
        if (bus == "x") continue;

        int busID = stoi(bus);
        int wait = wait_time(busID);
        if (wait < minWait) {
            minWait = wait;
            answer = wait * busID;
        }
    }
    debug(answer);
}