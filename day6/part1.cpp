/*
https://adventofcode.com/2020/day/6
*/
#include "../common.hpp"

int main() {
    int total = 0;
    cin >> noskipws;
    while (!cin.eof()) {
        string line;
        set<char> s;
        while(true) {
            getline(cin, line);
            if (line == "") break;
            foreach(line) {
                s.insert(it);
            }
        }
        total += s.size();
    }
    debug(total);
}