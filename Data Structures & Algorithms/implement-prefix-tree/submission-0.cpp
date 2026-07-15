class Node{
    public:
        char c;
        unordered_map<char, Node*> next;

        Node(char ch){
            c = ch;
            next = {};
        }
};

class PrefixTree {
    Node* start;
public:
    PrefixTree() {
        start = new Node('#');
    }
    
    void insert(string word) {
        int i = 0;
        Node* temp = start;
        while(i<word.size()){
            if(temp->next.find(word[i]) != temp->next.end()){
                temp = temp->next[word[i]];
                i++;
            } else {
                break;
            }
        }
        while(i<word.size()){
            Node* node = new Node(word[i]);
            temp->next[word[i]] = node;
            temp = node;
            i++;        
        }
        Node* end = new Node('#');
        temp->next['#'] = end;
        return;
    }
    
    bool search(string word) {
        int i = 0;
        Node* temp = start;
        while(i<word.size()){
            if(temp->next.find(word[i]) != temp->next.end()){
                temp = temp->next[word[i]];
                i++;
            } else {
                break;
            }
        }
        if(i!=word.size()) return false;
        return temp->next.find('#') != temp->next.end();
    }
    
    bool startsWith(string prefix) {
        int i = 0;
        Node* temp = start;
        while(i<prefix.size()){
            if(temp->next.find(prefix[i]) != temp->next.end()){
                temp = temp->next[prefix[i]];
                i++;
            } else {
                break;
            }
        }
        if(i!=prefix.size()) return false;
        return true;
    }
};
