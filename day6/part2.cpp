/*
https://adventofcode.com/2020/day/6
*/
#include "../common.hpp"

using namespace std;
int main() {
    int total = 0;
    cin >> noskipws;
    while (!cin.eof()) {
        string line;
        set<char> s;
        bool first = true;
        while(true) {
            getline(cin, line);
            if (line == "") break;
            if (first) {
                foreach (line) {
                    s.insert(it);
                }
            } else {
                // Insert into second set
                set<char> s2, s3;
                foreach(line) {
                    s2.insert(it);
                }

                foreach(s) {
                    if (s2.count(it)) {
                        s3.insert(it);
                    }
                }

                s = s3;
            }
            first = false;
        }
        total += s.size();
    }
    debug(total);
}