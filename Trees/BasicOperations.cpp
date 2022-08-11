

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int height(Node *root){
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

void levelorder(Node *root){
    if(root==NULL) return;
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *top=q.front();
        cout<<top->data<<" ";
        q.pop();
        if(top->left!=NULL){
            q.push(top->left);
        }
        if(top->right!=NULL){
            q.push(top->right);
        }
    }
}

void solve(){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(50);
    root->right->right=new Node(40);

    levelorder(root);

}

int main()
{
    fastio;
    solve();

}
