/*
https://adventofcode.com/2020/day/6
*/
#include <iostream>
#include <string>
#include <set>

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
                for (char& c : line) {
                    s.insert(c);
                }
            } else {
                // Insert into second set
                set<char> s2, s3;
                for (char& c : line) {
                    s2.insert(c);
                }

                for (auto& a : s) {
                    if (s2.count(a)) {
                        s3.insert(a);
                    }
                }
                s = s3;
            }
            first = false;
        }
        total += s.size();
    }
    cout << total << "\n";
}