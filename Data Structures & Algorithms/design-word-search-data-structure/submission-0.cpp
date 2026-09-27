class Node{
public:
    Node* children[26];
    bool isEnd;
    
    Node(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }

        isEnd = false;
    }

};

class WordDictionary {
public:
    
    Node* root;

    WordDictionary() {
        root = new Node();    
    }
    
    void addWord(string word) {
        Node* curr = root;

        for(char c : word){
            int index = c - 'a';
            if(curr->children[index] == nullptr){
                curr->children[index] = new Node();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(Node* node, string& word, int index) {

        // Finished matching the entire word
        if(index == word.size()) {
            return node->isEnd;
        }

        char c = word[index];

        // Normal character
        if(c != '.') {
            int i = c - 'a';

            if(node->children[i] == nullptr) {
                return false;
            }

            return dfs(node->children[i], word, index + 1);
        }

        // '.': try every possible character
        for(int i = 0; i < 26; i++) {

            if(node->children[i] != nullptr) {

                if(dfs(node->children[i], word, index + 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};
