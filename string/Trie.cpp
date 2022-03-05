struct Node {
    int c;
    Node *chd[26];
    int cont = 0;
    int dist = 0;

    Node(int cha, int d) : c(cha), dist(d) {
        for (int i = 0; i < 26; ++i) {
            chd[i] = nullptr;
        }
    }
};

Node *rt = new Node(-1, 0);
for (string word:words) {
    Node *curr = rt;
    for (int i = word.length()-1; i >= 0; --i) {
        if (curr->chd[word[i] - 'a'] == nullptr) {
            curr->chd[word[i] - 'a'] = new Node(word[i] - 'a', curr->dist + 1);
        }
        curr = curr->chd[word[i] - 'a'];
        path.push_back(curr);
        curr->cont++;
        }
    }
 }