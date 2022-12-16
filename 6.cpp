#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "6.txt";
string line;

void solve(int distinct) {
    deque<char> q;
    int elems = 0;
    for (auto &x : line) {
        if (q.size() == distinct - 1) {
            unordered_set<char> s;
            for (auto &y : q) {
                s.insert(y);
            }
            s.insert(x);
            if (s.size() == distinct) {
                cout << elems + 1 << '\n';
                break;
            }
            q.pop_front();
        }
        q.push_back(x);
        elems++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file(INPUT_STREAM_NAME);
    getline(file, line);
    solve(4); // part 1
    solve(14); // part 2
}