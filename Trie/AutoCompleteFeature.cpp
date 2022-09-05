//Auto complete of search engines using Trie

#include <bits/stdc++.h> 
using namespace std;
#define fastio           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll               long long
#define pb               push_back
#define sz(x)             (int)((x).size())


struct Trienode{
    char data;
    int we;
    int pc;
    Trienode *child[26];
    Trienode(char ch){
        data=ch;
        we=0; // we(wordend) at end of word we+=1
        pc=0; // pc(prefixcount) at every char of word pc+=1
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

void insert(Trienode *root, string s){
    Trienode *cur=root;
    int n=s.length();
    for(char ch:s){
        int pos=ch-'a';
        if(cur->child[pos] == NULL){
            cur->child[pos] = new Trienode(ch);
        }
        cur=cur->child[pos];
        cur->pc+=1;
    }
    cur->we+=1;
}

bool search(Trienode *root,string s){
    Trienode *cur=root;
    for(char ch:s){
        int pos=ch-'a';
        if(cur->child[pos]==NULL){
            return false;
        }
        cur=cur->child[pos];
    }
    if(cur->we == 0){
        return false;
    }

    return true;
}


void suggestions(Trienode *cur,string curans){
    //Base
    if(cur->we > 0){
        cout<<curans<<endl;
    }

    //Compute
    for(int i=0;i<26;i++){
        if(cur->child[i]!=NULL){
            char ch='a'+i;
            suggestions(cur->child[i],curans+ch);
        }
    }
}


int printsuggestions(Trienode *root, string query){
    Trienode *cur = root;
    int n=query.length();
    for(int i=0;i<n;i++){
        int pos=query[i]-'a';
        if(cur->child[pos]==NULL){
            return 0;
        }
        cur=cur->child[pos];
    }

    suggestions(cur,query);
}


void solve(){

    Trienode *root=new Trienode('*');
    string s[5]={"aba","abc","ab","bab","baba"};

    for(int i=0;i<5;i++){
        insert(root,s[i]);
    }

    printsuggestions(root,"ab");


}

int main()
{
    fastio;
    solve();
}
