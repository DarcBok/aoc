#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "5.txt";
typedef vector<deque<char>> Cargo;

Cargo initialise() {
    Cargo cargo(9);
    string line;
    ifstream file(INPUT_STREAM_NAME);

    while (getline(file, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '[') {
                cargo[i / 4].push_back(line[i + 1]);
            }
        }
    }

    return cargo;
}

void part1(Cargo cargo) {
    string line;
    ifstream file(INPUT_STREAM_NAME);
    int n, from, to;
    while (getline(file, line)) {
        if (line[0] != 'm') continue;
        sscanf(line.c_str(), "move %d from %d to %d", &n, &from, &to);
        
        while (n--) {
            char tmp = cargo[from-1].front();
            cargo[to-1].push_front(tmp);
            cargo[from-1].pop_front();
        }
    }

    for (auto &x : cargo) {
        cout << x.front();
    }
    cout << '\n';
}

void part2(Cargo cargo) {
    string line;
    ifstream file(INPUT_STREAM_NAME);
    int n, from, to;
    while (getline(file, line)) {
        if (line[0] != 'm') continue;
        sscanf(line.c_str(), "move %d from %d to %d", &n, &from, &to);
        
        stack<char> temp;
        while (n--) {
            char tmp = cargo[from-1].front();
            temp.push(tmp);
            cargo[from-1].pop_front();
        }

        while(!temp.empty()) {
            cargo[to-1].push_front(temp.top());
            temp.pop();
        }
    }

    for (auto &x : cargo) {
        cout << x.front();
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Cargo cargo;
    cargo = initialise();
    part1(cargo);
    cargo = initialise();
    part2(cargo);
}