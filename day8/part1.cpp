/*
https://adventofcode.com/2020/day/8
*/
#include "../common.hpp"

int main() {
    vector<pair<string, string>> program;
    while(!cin.eof()) {
        string cmd;
        string arg;
        cin >> cmd >> arg;
        program.push_back(make_pair(cmd, arg));
    }
    int programSize = program.size();
    debug(programSize);

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
    debug(acc);
}