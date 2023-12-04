#include<iostream>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    int cap;
    unordered_map <int, node*> mp;   //key, address
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node *newnode){
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node *delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        //if key is present in the map
        if(mp.find(key) != mp.end()){
            node *resnode = mp[key];
            int res = resnode->val;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key] = head->next;
            return res;
        }
        //if key is not present in the map
        return -1;
    }
    
    void put(int key, int value) {
        //if key is present in the map we have to delete it
        if(mp.find(key) != mp.end()){
            node *delnode = mp[key];
            mp.erase(key);
            deletenode(delnode);
        }
        
        //if capacity is full we have to remove LRU node, which is prev of tail
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key,value));
        mp[key] = head->next;
    }
};


class LRUCache() {
    public:
    
}




int main() {
    
    return 0;
}