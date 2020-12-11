/*
--- Day 4: Passport Processing ---
You arrive at the airport only to realize that you grabbed your 
North Pole Credentials instead of your passport. While these 
documents are extremely similar, North Pole Credentials aren't 
issued by a country and therefore aren't actually valid 
documentation for travel in most of the world.

It seems like you're not the only one having problems, though;
 a very long line has formed for the automatic passport scanners,
  and the delay could upset your travel itinerary.

Due to some questionable network security, you realize you might
 be able to solve both of these problems at the same time.

The automatic passport scanners are slow because they're having 
trouble detecting which passports have all required fields. The
 expected fields are as follows:

byr (Birth Year)
iyr (Issue Year)
eyr (Expiration Year)
hgt (Height)
hcl (Hair Color)
ecl (Eye Color)
pid (Passport ID)
cid (Country ID)
Passport data is validated in batch files (your puzzle input).
Each passport is represented as a sequence of key:value pairs
 separated by spaces or newlines. Passports are separated by 
 blank lines.

Here is an example batch file containing four passports:

ecl:gry pid:860033327 eyr:2020 hcl:#fffffd
byr:1937 iyr:2017 cid:147 hgt:183cm

iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884
hcl:#cfa07d byr:1929

hcl:#ae17e1 iyr:2013
eyr:2024
ecl:brn pid:760753108 byr:1931
hgt:179cm

hcl:#cfa07d eyr:2025 pid:166559648
iyr:2011 ecl:brn hgt:59in
The first passport is valid - all eight fields are present. The second
 passport is invalid - it is missing hgt (the Height field).

The third passport is interesting; the only missing field is cid, so it
 looks like data from North Pole Credentials, not a passport at all! 
 Surely, nobody would mind if you made the system temporarily ignore 
 missing cid fields. Treat this "passport" as valid.

The fourth passport is missing two fields, cid and byr. Missing cid is 
fine, but missing any other field is not, so this passport is invalid.

According to the above rules, your improved system would report 2 valid
 passports.

Count the number of valid passports - those that have all required fields.
Treat cid as optional. In your batch file, how many passports are valid?

*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> allowed_keys = {
    "byr",
    "iyr",
    "eyr",
    "hgt",
    "hcl",
    "ecl",
    "pid",
    "cid",
};

vector<string> split(string input, char delim) {
    vector<string> output;
    string curr;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == delim) {
            output.push_back(curr);
            curr = "";
        } else {
            curr += input[i];
        }
    }
    if (curr != "") output.push_back(curr);
    return output;
}

pair<string, string> process_part(string &part) {
    auto bits = split(part, ':');
    return make_pair(bits[0], bits[1]);
}

bool is_valid_passport(map<string, string> &passport) {
    int size = passport.size();
    if (size < 7 || size > 8) {
        return false;
    }
    if (size == 8) {
        return true;
    }
    // 7
    if (!passport.count("cid")) {
        return true;
    }
    return false;
}

int main() {
    int count_valid = 0;
    int count_total = 0;
    while (!cin.eof()) {
        string line;
        map<string, string> passport;
        while(true) {
            getline(cin, line);
            if (line == "") break;
            cout << "line: " << line << "\n";

            vector<string> parts = split(line, ' ');
            for (auto& part : parts) {
                pair<string, string> res = process_part(part);
                if (find(allowed_keys.begin(), allowed_keys.end(), res.first) == allowed_keys.end()) {
                    cout << "Not allowed key: " << res.first << "\n";
                    exit(1);
                }
                passport[res.first] = res.second;
            }
        }

        bool valid = is_valid_passport(passport);
        count_total++;
        if (valid) count_valid++;
        cout << "passport : " << (valid ? "valid" : "not valid") << "\n\n";
    }
    cout << "valid count: " << count_valid << "\n";
    cout << "total count: " << count_total << "\n";
}