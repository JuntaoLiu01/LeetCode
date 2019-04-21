struct  Trie
{
    bool isWord;
    Trie *children[26];
};

Trie* create(){
    Trie* node = new Trie();
    node->isWord = false;
    for(int i = 0;i < 26;i++)
        node->children[i] = NULL;
    return node;
}
void insert(Trie* root,string& s){
    Trie* node = root;
    for(int i = s.size()-1;i >= 0;i--){
        if(!node->children[s[i]-'a'])
            node->children[s[i]-'a'] = create();
        node = node->children[s[i]-'a'];
    }
    node->isWord = true;
}

bool search(Trie* root,string& s){
    Trie* node = root;
    for(int i = s.size()-1;i >= 0;i--){
        Trie* next = node->children[s[i]-'a'];
        if(next){
            if(next->isWord)
                return true;
            node = next;
        }
        else
            return false;
    }
    return false;
}

class StreamChecker {
public:
    Trie* root;
    string str;
    StreamChecker(vector<string>& words) {
        root = create();
        for(string w:words)
            insert(root,w);
    }
    
    bool query(char letter) {
        str.push_back(letter);
        return search(root,str);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */