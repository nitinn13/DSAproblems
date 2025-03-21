#include <queue>
#include <vector>
#include <string>

using namespace std;

class Info {
public:
    char val;
    int count;  

    Info(char ch, int cnt) {
        this->val = ch;
        this->count = cnt;
    }
};

class compare {
public:
    bool operator()(Info* a, Info* b) {
        return a->count < b->count; 
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info*, vector<Info*>, compare> pq;

        if (a > 0) pq.push(new Info('a', a));
        if (b > 0) pq.push(new Info('b', b));
        if (c > 0) pq.push(new Info('c', c));

        string ans = "";

        while (pq.size() > 1) {
            Info* first = pq.top(); pq.pop();
            Info* second = pq.top(); pq.pop();

            int firstAppend = min(2, first->count);
            ans.append(firstAppend, first->val);
            first->count -= firstAppend;

            int secondAppend = (second->count >= first->count) ? min(2, second->count) : 1;
            ans.append(secondAppend, second->val);
            second->count -= secondAppend;

            if (first->count > 0) pq.push(first);
            if (second->count > 0) pq.push(second);
        }

        if (!pq.empty()) {
            Info* last = pq.top(); pq.pop();
            int lastAppend = min(2, last->count);
            ans.append(lastAppend, last->val);
        }

        return ans;
    }
};
