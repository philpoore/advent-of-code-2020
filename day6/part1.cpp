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
        while(true) {
            getline(cin, line);
            if (line == "") break;
            for (char& c : line) {
                s.insert(c);
            }
        }
        total += s.size();
    }
    cout << total << "\n";
}