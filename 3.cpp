#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "3.txt";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    ifstream file(INPUT_STREAM_NAME);
    int part1 = 0;
    int part2 = 0;
    int no_lines = 0;
    map<char, int> hm;

    while (getline(file, line)) {
        set<char> s1;
        set<char> s2;
        set<char> intersect;
    
        // part 1
        for (int i = 0; i < line.length() / 2; i++) {
            s1.insert(line[i]);
        }
        for (int j = line.length() / 2; j < line.length(); j++) {
            s2.insert(line[j]);
        }
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), 
            inserter(intersect, intersect.begin()));    

        for (auto &x : intersect) {
            part1 += (x >= 97 ? x - 'a' + 1 : x - 'A' + 27);
        }

        // part 2
        for (char x : line) {
            if (hm[x] == no_lines) {
                hm[x]++;
            }
        }

        if (++no_lines == 3) {
            for (auto &x : hm) {
                if (x.second == 3) {
                    part2 += (x.first >= 97 ? x.first - 'a' + 1 : x.first - 'A' + 27);
                }
            }
            no_lines = 0;
            hm.clear();
        }
    }
    cout << part1 << '\n';
    cout << part2 << '\n';
}