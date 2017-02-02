#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<pair<string, string>, bool> cache;

bool match(const string &pattern, const string &str) {
    unsigned p_pos = 0, s_pos = 0;

    if (pattern == "*")
        return true;

    while (p_pos < pattern.size() || s_pos < str.size()) {
        if (pattern[p_pos] == '?') {
            p_pos++;
            s_pos++;
            continue;
        }

        if (pattern[p_pos] == '*') {
            if (s_pos == str.size())
                return match(pattern.substr(p_pos + 1), "");

            if (p_pos == pattern.size() - 1)
                return true;

            for (unsigned pos = s_pos; pos < str.size(); ++pos) {
                string p = pattern.substr(p_pos + 1);
                string s = str.substr(pos);
                pair<string, string> key(p, s);

                if (cache.find(key) == cache.end())
                    cache[key] = match(p, s);

                if (cache[key])
                    return true;
            }
            return false;
        }

        if (pattern[p_pos] != str[s_pos]) {
            return false;
        } else {
            p_pos++;
            s_pos++;
        }
    }

    return true;
}

bool wildcard(string &pattern, vector<string> &names) {
    for (int i = 0; i < names.size(); ++i)
        if (match(pattern, names[i]))
            cout << names[i] << '\n';
}

int main(int argc, char **argv) {
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        vector<string> names;
        unsigned num_names;
        string pattern;

        cin >> pattern >> num_names;
        names.resize(num_names);

        for (int j = 0; j < num_names; ++j)
            cin >> names[j];

        sort(names.begin(), names.end());
        wildcard(pattern, names);
    }

    return 0;
}
