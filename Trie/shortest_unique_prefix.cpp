#include<iostream>
#include<vector>

using namespace std;

class TrieNode{
    public: 
    char ch;
    int we = 0;
    TrieNode* child[26] = {NULL};
    void increment(){
        this->we = this->we + 1;
    }
    TrieNode(char ch){
        this->ch = ch;
        this->increment();
    }
    TrieNode* insert(char ch){
        if(child[ch - 'a']==NULL){
            child[ch - 'a'] = new TrieNode(ch);
        }else{
            child[ch - 'a']->increment();
        }
        return child[ch - 'a'];
    }
    
};

string triePrefix(TrieNode* node, string s){
        string o = "";
        for(char ch : s){
            node = node->child[ch-'a'];
            o.push_back(ch);
            if(node!=NULL){
                if(node->we == 1){
                    return o;
                }
            }
        }
        return o;
}
vector<string> prefix(vector<string> &A) {
    TrieNode* root = new TrieNode(' ');
    for(string s : A){
        TrieNode* temp = root;
        for(int i=0; i<s.size(); i++){
             temp = temp->insert(s[i]);
        }
    }
    vector<string> res;
    for(string s : A){
        TrieNode* temp = root;
        string ret = triePrefix(temp, s);
        res.push_back(ret);
    }
    return res;
}

int main(){
    vector<string> s = {"zebra", "dog", "duck", "dove"};
    s = prefix(s);
    for(string k : s) cout<<k<<" ";
    cout<<endl;
}
//g++ -std=c++11 shortest_unique_prefix.cpp -o .output/shortest_unique_prefix.o && ./.output/shortest_unique_prefix.o