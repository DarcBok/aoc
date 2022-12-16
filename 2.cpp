#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "2.txt";

int main() {
    string line;
    int score = 0;
    int score2 = 0;

    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!file.is_open()) {
        cout << "Unable to open file\n";
        return 0;
    }
    while (getline(file, line)) {
        if (line.length()) {
            if (line[0] == 'A' && line[2] == 'X') {
                score += 4;
                score2 += 3;
            }
            if (line[0] == 'A' && line[2] == 'Y') {
                score += 8;
                score2 += 4;
            }
            if (line[0] == 'A' && line[2] == 'Z') {
                score += 3;
                score2 += 8;
            }
            if (line[0] == 'B' && line[2] == 'X') {
                score += 1;
                score2 += 1;
            }
            if (line[0] == 'B' && line[2] == 'Y') {
                score += 5;
                score2 += 5;
            }
            if (line[0] == 'B' && line[2] == 'Z') {
                score += 9;
                score2 += 9;
            }
            if (line[0] == 'C' && line[2] == 'X') {
                score += 7;
                score2 += 2;
            }
            if (line[0] == 'C' && line[2] == 'Y') {
                score += 2;
                score2 += 6;
            }
            if (line[0] == 'C' && line[2] == 'Z') {
                score += 6;
                score2 += 7;
            }
        }
    }
    cout << score << '\n';
    cout << score2 << '\n';
}