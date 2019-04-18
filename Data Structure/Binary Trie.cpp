//Binary Trie
//without deletion, comment all val change and trie.check condition
//Don't forget to check maxval
struct node{
    node *kiri = NULL;
    node *kanan = NULL;
    int val = 0; //Can be deleted
};

struct btrie{
    node *head = new node;
    node *cur = head;
    void insert(int x){
        for(int i = 30; i >= 0; i--){
            if((x&(1<<i)) == 0){
                if(head->kanan == NULL)head->kanan = new node;
                head = head->kanan;
            } else{
                if(head->kiri == NULL)head->kiri = new node;
                head = head->kiri;
            }
            head->val += 1; // Can be deleted
        }
        head = cur;
    }
    void del(int x){
        for(int i = 30; i >= 0; i--){
            if((x&(1<<i)) == 0){
                head = head->kanan;
            } else{
                head = head->kiri;
            }
            head->val -= 1; //Can be deleted
        }
        head = cur;
    }
    int max(int x){
        int res = 0;
        for(int i = 30; i >= 0; i--){
            if((x&(1<<i)) == 0){
                if(check(head->kiri)){
                    res += (1<<i);
                    head = head->kiri;
                } else if(check(head->kanan)){
                    head = head->kanan;
                }//Break can be placed here

            } else {
                if(check(head->kanan)){
                    head = head->kanan;
                } else if(check(head->kiri)){
                    head = head->kiri;
                    res += (1<<i);
                }//Break can be placed here
            }
        }
        head = cur;
        return (res^x);
    }
private:
    bool check(node *x){
        if(x != NULL and x->val > 0)return true; //Condition may be changed
        else return false;
    }
};