struct node2{
    node2 *children[26] = {NULL};
};

struct trie{
    node2 *head = new node2;
    node2 *cur = head;
    void insert(string x){
        head = cur;
        for(int i = 0; i < x.size(); i++){
            int val = x[i]-'a';
            if(head->children[val] == NULL){
                head->children[val] = new node2;
            }
            head = head->children[val];
        }
    }

    bool find(string x){
        head = cur;
        for(int i = 0; i < x.size(); i++){
            int val = x[i]-'a';
            if(head->children[val] == NULL)return false;
            head = head->children[val];
        }
        return true;
    }
};