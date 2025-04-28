#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <queue>
#include <map>
#include <fstream>
using namespace std;

string toLow(const string& s) {
    string rez = s;
    for (size_t i = 0; i < rez.length(); i++)
        rez[i] = tolower(rez[i]);
    return rez;
}

bool separator(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '?' || c == '!';
}

vector<string> split(const string& text) {
    vector<string>words;
    size_t i = 0;
    while (i < text.length()) {
        while (i < text.length() && separator(text[i])) {
            i++;
        }
        size_t start = i;

        while (i < text.length() && !separator(text[i])) {
            i++;
        }
        size_t end = i;
        if (end > start) {
            string word = text.substr(start, end - start);
            words.push_back(toLow(word));
        }
    }
    return words;
}

struct compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int main() {
    //string text = "I bought an apple. Then I eat an apple. Apple is my favorite.";
    string text;
    ifstream file("in.txt");
    if (!file)
    {
        printf("err");
        return 0;
    }
    if (!getline(file, text))
    {
        printf("err");
        return 0;
    }
    vector<string> words = split(text);

    map<string, int> wordCount;

    for (int i = 0; i < words.size(); i++) {
        wordCount[words[i]]++;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
    map<string, int>::iterator it;

    for (it = wordCount.begin(); it != wordCount.end(); it++) {
        pq.push({ it->second, it->first });  // Push pair (freq, word)
    }


    while (!pq.empty()) {
        printf("%s => %d\n", pq.top().second.c_str(), pq.top().first);
        pq.pop();
    }

    return 0;
}