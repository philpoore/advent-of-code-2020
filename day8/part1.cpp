/*
https://adventofcode.com/2020/day/8
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<pair<string, string>> program;
    while(!cin.eof()) {
        string cmd;
        string arg;
        cin >> cmd >> arg;
        program.push_back(make_pair(cmd, arg));
    }

    cout << "program length: " << program.size() << "\n";

    int pc = 0;
    int acc = 0;
    set<int> visited;

    while(true) {
        auto curr = program[pc];
        if (visited.count(pc)) {
            break;
        }
        visited.insert(pc);
        string cmd = curr.first;
        string arg = curr.second;
        if (cmd == "nop") {
            // nop
        } else if (cmd == "acc") {
            acc += stoi(arg);
        } else if (cmd == "jmp") {
            pc += stoi(arg);
            continue;
        }
        pc++;
    }
    cout << "acc: " << acc << "\n";
}