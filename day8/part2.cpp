/*
https://adventofcode.com/2020/day/8
*/
#include "../common.hpp"
    
vector<pair<string, string>> program;
int res_acc = -1;

bool solve(int pc, int acc, bool changed, int changedPC, set<int> visited, vector<int> order) {
    while(true) {
        if (pc >= program.size()) {
            cout << "Found solution:\n";
            for (auto o : order) cout << o << " ";
            cout << "\nACC: " << acc << "\n";
            cout << "Changed instruction: " << changedPC << "\n";
            res_acc = acc;
            return true;
        }

        auto curr = program[pc];
        if (visited.count(pc)) {
            return false;
        }

        visited.insert(pc);
        order.push_back(pc);
        string cmd = curr.first;
        string arg = curr.second;
        if (cmd == "nop") {
            // If we've not changed an instruction so far
            // try solving by treating this nop as a jmp instruction
            if (!changed && solve(pc + stoi(arg), acc, true, pc, visited, order)) {
                return true;
            }
            
            // nop
        } else if (cmd == "acc") {
            acc += stoi(arg);
        } else if (cmd == "jmp") {
            // If we've not changed an instruction so far
            // try solving by treating this jmp as a nop instruction
            if (!changed && solve(pc + 1, acc, true, pc, visited, order)) {
                return true;
            }
            pc += stoi(arg);
            continue;
        }
        pc++;
    }
}

int main() {
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
    vector<int> order;

    if (solve(pc, acc, false, 0, visited, order)) {
        cout << "Final ACC: " << res_acc << "\n";
    } else {
        cout << "Couldn't find an solution\n";
    }
}