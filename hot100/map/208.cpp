#include<bits/stdc++.h>
using namespace std;


//结构体：定义26个指针用来指向下一个字母，在出现字母的位置创建节点实体，isend标记是否结束，所有单词公用一个树
struct TrieNode{
    TrieNode* children[26];
    bool isend;
    TrieNode() {
        for(auto& i: children){
            i=NULL;
        }
        isend=false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(char i: word){
            if(!cur->children[i-'a']) cur->children[i-'a']=new TrieNode();
            cur=cur->children[i-'a'];
        }
        cur->isend=true;
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(char i:word){
            if(!cur->children[i-'a']) return false;
            cur=cur->children[i-'a'];
        }
        return cur->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(char i:prefix){
            if(!cur->children[i-'a']) return false;
            cur=cur->children[i-'a'];
        }
        return true;
    }
};
