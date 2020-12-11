/*
https://adventofcode.com/2020/day/7
*/
#include "../common.hpp"

vector<pair<string, string>> edges;

map<string, vector<pair<int, string>>> rules;

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

    const std::regex base_regex2("([0-9]+) ([a-z ]+) bags?");
    std::smatch base_match2;
    while (std::regex_search(line, base_match2, base_regex2)) {
        int amt = stoi(base_match2[1]);
        string other_color = base_match2[2];
        edges.push_back(make_pair(color, other_color));
        
        rules[color].push_back(make_pair(amt, other_color));
        line = base_match2.suffix().str();
    }
}

int main() {
    // parse input line by line
    while(!cin.eof()) {
        string line;
        getline(cin, line);
        debug(line);
        parse_line(line);
    }

    int numEdges = edges.size();
    debug(numEdges);

    // bfs to find all downstream nodes, count as we go
    stack<pair<int, string>> s;

    s.push(make_pair(1, "shiny gold"));
    int count = 0;
    while(s.size()) {
        string current = s.top().second;
        int amt = s.top().first;
        s.pop();

        if (current != "shiny gold") {
            count += amt;
        }

        for (auto& rule : rules[current]) {
            s.push(make_pair(rule.first * amt, rule.second));
        }
    }
    debug(count);
    return 0;
}
