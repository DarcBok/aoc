#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "7.txt";
string line;

class File 
{
    public:
        File *parent;
        vector<File *> children;
        string name;
        int size;

        File() {
            size = 0;
            name = "";
            parent = NULL;
        }

        const int computeSize() {    
            if (children.size() == 0) return size;
            int total = size;
            for (auto x : children) {
                total += x->computeSize();
            }
            return total;
        }

        void addFile(const string newFileName) {
            File *newFile = new File();
            newFile->name = newFileName;
            newFile->parent = this;
            children.push_back(newFile);
        }

        File *findFile(const string &findName) {
            for (auto x : children) {
                if (x->name == findName) return x;
            }
            return NULL;
        }


};

int part1(File *f) {
    int total = 0;
    for (auto x : f->children) {
        total += part1(x);
    }
    int s = f->computeSize();
    if (s <= 100000) total += s;
    return total;
}

void part2(File *f, int *min, int required) {
    int s = f->computeSize();
    if (s > required && s < *min) {
        *min = s;
    }
    for (auto x : f->children) {
        part2(x, min, required);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file(INPUT_STREAM_NAME);
    getline(file, line); // ignore first line
    File home;
    home.name = "/";
    File *current = &home;

    while (getline(file, line)) {
        if (line[0] == 'd') {
            current->addFile(line.substr(4));
        }
        else if (line.substr(0,4) == "$ cd") {
            if (line.substr(5) == "..") {
                current = current->parent;
            }
            else {
                current = current->findFile(line.substr(5));
            }

        }
        else if (line[0] != '$') {
            current->size += stoi(line.substr(0, line.find(' ')));
        }
    }

    int count1 = part1(&home);
    cout << count1 << '\n';

    int required = home.computeSize() - 40000000;
    int min = home.computeSize();
    part2(&home, &min, required);
    cout << min << '\n';
}