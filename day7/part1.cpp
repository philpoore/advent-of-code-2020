/*
https://adventofcode.com/2020/day/7
*/
#include "../common.hpp"

vector<pair<string, string>> edges;

void parse_line(string line) {
    const std::regex base_regex("([a-z ]+) bags contain ");
    std::smatch base_match;
    string color;
    if (regex_search(line, base_match, base_regex)) {
        color = base_match[1].str();
    } else {
        return;
    }

    if (line.find("no other bags") != string::npos) {
        return;
    }

    const std::regex base_regex2("[0-9]+ ([a-z ]+) bags?");
    std::smatch base_match2;
    while (std::regex_search(line, base_match2, base_regex2)) {
        edges.push_back(make_pair(base_match2[1], color));
        line = base_match2.suffix().str();
    }
}

int main() {
    // parse input line by line
    while(!cin.eof()) {
        string line;
        getline(cin, line);
        parse_line(line);
    }
    int numEdges = edges.size();
    debug(numEdges);

#if 0
    // Display edges
    for (auto& e : edges) {
        cout << e.first << " -> " << e.second << "\n";
    }
    return 0;
#endif

    // bfs to find all downstream nodes, count as we go
    stack<string> s;
    set<string> visited;

    s.push("shiny gold");
    int count = 0;
    while(s.size()) {
        string current = s.top();
        s.pop();
        if (visited.count(current)) continue;

        visited.insert(current);
        if (current != "shiny gold") {
            count++;
        }

        for (auto& edge : edges) {
            if (edge.first != current) continue;
            if (!visited.count(edge.second)) {
                s.push(edge.second);
            }
        }
    }
    debug(count);
    return 0;
}
