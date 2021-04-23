#include<bits/stdc++.h>
using namespace std;
struct Trie {
    Trie* next[26];
    int cnt;
    Trie() {
        memset(next, 0, sizeof(next));
        cnt = 1;
    }
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i]) delete next[i];
    }
    void insert(const char* key) {
        if (*key == '\0') {
            return;
        }
        int nowKey = *key - 'a';
        if (!next[nowKey]) next[nowKey] = new Trie;
        else next[nowKey]->cnt++;
        next[nowKey]->insert(key + 1);
        return;
    }
    int query(const char* key) {
        if (*key == '?') {
            int now = 0;
            for (int i = 0; i < 26; i++) {
                if (next[i]) now += next[i]->cnt;
            }
            return now;
        }
        int nowKey = *key - 'a';
        if (!next[nowKey]) return 0;
        return next[nowKey]->query(key + 1);
    }
};
Trie* trie1[10001];
Trie* trie2[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    int size = words.size();
    for (int i = 0; i < size; i++) {
        int len = words[i].length();
        const char* s1 = words[i].c_str();
        string tmp = words[i];
        reverse(begin(tmp), end(tmp));
        const char* s2 = tmp.c_str();
        if (trie1[len] == NULL) trie1[len] = new Trie;
        if (trie2[len] == NULL) trie2[len] = new Trie;
        trie1[len]->insert(s1);
        trie2[len]->insert(s2);
    }
    for (int i = 0; i < queries.size(); i++) {
        bool flag = true;
        string now = queries[i];
        int len = now.length();
        if (now[0] == '?') {
            flag = false;
            reverse(begin(now), end(now));
        }
        const char* k = now.c_str();
        if (!trie1[len] || !trie2[len]) answer.push_back(0);
        else if (flag) {
            answer.push_back(trie1[len]->query(k));
        }
        else {
            answer.push_back(trie2[len]->query(k));
        }
    }
    return answer;
}