#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "8.txt";
string line;

void part1(vector<vector<pair<int, bool>>> grid) {
    // from left
    for (int i = 0; i < grid.size(); i++) {
        int m = grid[i][0].first;
        grid[i][0].second = true;

        for (int j = 1; j < grid[i].size() - 1; j++) {
            if (grid[i][j].first > m) {
                m = grid[i][j].first;
                grid[i][j].second = true;
            }
        }
    }

    // from right
    for (int i = 0; i < grid.size(); i++) {
        int m = grid[i][grid[i].size()-1].first;
        grid[i][grid[i].size()-1].second = true;

        for (int j = grid[i].size() - 2; j > 0; j--) {
            if (grid[i][j].first > m) {
                m = grid[i][j].first;
                grid[i][j].second = true;
            }
        }
    }

    // from top
    for (int j = 0; j < grid[0].size(); j++) {
        int m = grid[0][j].first;
        grid[0][j].second = true;

        for (int i = 0; i < grid.size() - 1; i++) {
            if (grid[i][j].first > m) {
                m = grid[i][j].first;
                grid[i][j].second = true;
            }
        }
    }

    // from bottom
    for (int j = 0; j < grid[0].size(); j++) {
        int m = grid[grid.size()-1][j].first;
        grid[grid.size()-1][j].second = true;

        for (int i = grid.size() - 1; i > 0; i--) {
            if (grid[i][j].first > m) {
                m = grid[i][j].first;
                grid[i][j].second = true;
            }
        }
    }

    int tally = 0;
    for (auto x : grid) {
        for (auto y : x) {
            tally += y.second;
        }
    }
    cout << tally << '\n';
}

void part2(vector<vector<pair<int, bool>>> grid) {
    int best = 0;
    for (int i = 1; i < grid.size() - 1; i++) {
        for (int j = 1; j < grid[i].size() - 1; j++) {
            int r = 0, l = 0, d = 0, u = 0;
            int height = grid[i][j].first;

            // right
            for (int k = j + 1; k < grid[i].size(); k++) {
                if (grid[i][k].first >= height) {
                    r++;
                    break;
                }
                r++;
            }

            // left 
            for (int k = j - 1; k >= 0; k--) {
                if (grid[i][k].first >= height) {
                    l++;
                    break;
                }
                l++;
            }

            // down
            for (int k = i + 1; k < grid.size(); k++) {
                if (grid[k][j].first >= height) {
                    d++;
                    break;
                }
                d++;
            }

            // up
            for (int k = i - 1; k >= 0; k--) {
                if (grid[k][j].first >= height) {
                    u++;
                    break;
                }
                u++;
            }
            best = max(best, r*l*d*u);
        }
    }
    cout << best << '\n';
}

int main() {
    ifstream file(INPUT_STREAM_NAME);
    vector<vector<pair<int, bool>>> grid;

    // parse input
    while (getline(file, line)) {
        vector<pair<int, bool>> l;
        for (auto &x : line) {
            pair<int, bool> p(x - '0', false);
            l.push_back(p);
        }
        grid.push_back(l);
    }

    part1(grid);
    part2(grid);
}