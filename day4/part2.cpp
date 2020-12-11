/*

--- Part Two ---
The line is moving more quickly now, but you overhear airport security talking 
about how passports with invalid data are getting through. Better add some data 
validation, quick!

You can continue to ignore the cid field, but each other field has strict rules 
about what values are valid for automatic validation:

byr (Birth Year) - four digits; at least 1920 and at most 2002.
iyr (Issue Year) - four digits; at least 2010 and at most 2020.
eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
hgt (Height) - a number followed by either cm or in:
If cm, the number must be at least 150 and at most 193.
If in, the number must be at least 59 and at most 76.
hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
pid (Passport ID) - a nine-digit number, including leading zeroes.
cid (Country ID) - ignored, missing or not.
Your job is to count the passports where all required fields are both present 
and valid according to the above rules. Here are some example values:

byr valid:   2002
byr invalid: 2003

hgt valid:   60in
hgt valid:   190cm
hgt invalid: 190in
hgt invalid: 190

hcl valid:   #123abc
hcl invalid: #123abz
hcl invalid: 123abc

ecl valid:   brn
ecl invalid: wat

pid valid:   000000001
pid invalid: 0123456789
Here are some invalid passports:

eyr:1972 cid:100
hcl:#18171d ecl:amb hgt:170 pid:186cm iyr:2018 byr:1926

iyr:2019
hcl:#602927 eyr:1967 hgt:170cm
ecl:grn pid:012533040 byr:1946

hcl:dab227 iyr:2012
ecl:brn hgt:182cm pid:021572410 eyr:2020 byr:1992 cid:277

hgt:59cm ecl:zzz
eyr:2038 hcl:74454a iyr:2023
pid:3556412378 byr:2007
Here are some valid passports:

pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980
hcl:#623a2f

eyr:2029 ecl:blu cid:129 byr:1989
iyr:2014 pid:896056539 hcl:#a97842 hgt:165cm

hcl:#888785
hgt:164cm byr:2001 iyr:2015 cid:88
pid:545766238 ecl:hzl
eyr:2022

iyr:2010 hgt:158cm hcl:#b6652a ecl:blu byr:1944 eyr:2021 pid:093154719
Count the number of valid passports - those that have all required fields and 
valid values. Continue to treat cid as optional. In your batch file, how many 
passports are valid?

*/

#include "../common.hpp"

vector<string> allowed_keys = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid" };

vector<string> alllowed_eye_colors = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

pair<string, string> process_part(string &part) {
    auto bits = split(part, ':');
    return make_pair(bits[0], bits[1]);
}

bool is_valid_passport(map<string, string> &passport) {
    int size = passport.size();
    if (size < 7 || size > 8) {
        return false;
    }
    if (size == 8 || !passport.count("cid")) {
        // Validate data
        // Byr
        if (passport["byr"].size() != 4) return false;
        if (passport["byr"] < "1920" || passport["byr"] > "2002") {
            return false;
        }

        // Iyr
        if (passport["iyr"].size() != 4) return false;
        if (passport["iyr"] < "2010" || passport["iyr"] > "2020") {
            return false;
        }

        // Eyr
        if (passport["eyr"].size() != 4) return false;
        if (passport["eyr"] < "2020" || passport["eyr"] > "2030") {
            return false;
        }

        // Hgt
        if (passport["hgt"].size() <= 2) {
            return false;
        }
        if (passport["hgt"].substr(passport["hgt"].size() - 2, 2) == "cm") {
            int hgt = stoi(passport["hgt"]);
            if (hgt < 150 || hgt > 193) return false;
        } else if (passport["hgt"].substr(passport["hgt"].size() - 2, 2) == "in") {
            int hgt = stoi(passport["hgt"]);
            if (hgt < 59 || hgt > 76) return false;
        } else {
            return false;
        }

        // Hcl
        if (passport["hcl"].size() != 7) return false;
        if (passport["hcl"][0] != '#') return false;
        for (int i = 1; i < 7; i++) {
            char& c = passport["hcl"][i];
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))) {
                return false;
            }
        }
        
        // Ecl
        auto it = find(alllowed_eye_colors.begin(), alllowed_eye_colors.end(), passport["ecl"]);
        if (it == alllowed_eye_colors.end()) return false;
        
        // Pid
        if (passport["pid"].size() != 9) return false;
        for (int i = 0; i < 9; i++) {
            char& c = passport["pid"][i];
            if (c < '0' || c > '9') {
                return false;
            }
        }

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
            debug(line);

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
    
    debug(count_valid);
    debug(count_total);
}