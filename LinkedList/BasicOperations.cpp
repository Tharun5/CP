class Node{
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
    
};



struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

--------------------------------------

void printList(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

Node *insertBegin(Node *head, int ele){
    Node *temp=new Node(ele);
    temp->next=head;
    return temp;
}

Node *insertEnd(Node *head, int ele){
    Node *temp=new Node(ele);
    if(head==NULL){
        return temp;
    }
    Node *curr=head;
    while(curr->next != NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

Node *insertPos(Node *head, int pos, int ele){
    Node *temp=new Node(ele);
    if(pos==1){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    for(int i=1;i<pos-1 && curr!=NULL;i++){
        curr=curr->next;
    }
    if(curr==NULL) 
        return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

Node *delHead(Node *head){
    if(head==NULL){
        return NULL;
    }
    else{
        Node *temp=head->next;
        delete(head);
        return temp;
    }
}

Node *delEnd(Node *head){
    if(head==NULL){
        return NULL;
    }else if(head->next==NULL){
        delete(head);
        return NULL;
    }else{
        Node *curr=head;
        while(curr->next->next != NULL){
            curr=curr->next;
        }
        delete(curr->next);
        curr->next=NULL;
        return head;
    }
}

void middleEle(Node *head){
    if(head==NULL) return;
    Node *first=head;
    Node *second=head;
    while(second!=NULL && second->next!=NULL){
        first=first->next;
        second=second->next->next;
    }
    cout<<first->data<<endl;

}

int search(Node *head, int ele){
    Node *curr=head;
    int pos=0;
    while(curr!=NULL){
        pos++;
        if(curr->data == ele){
            return pos;
        }
        curr=curr->next;
    }
    return -1;
}

void solve(){
    Node *head=new Node(10);
    Node *first=new Node(20);
    Node *se=new Node(30);
    Node *th=new Node(40);
    Node *fo=new Node(60);
    head->next=first;
    first->next=se;
    se->next=th;
    th->next=fo;

    int ele;cout<<"Enter ele: ";
    cin>>ele;

    printList(head);
    middleEle(head);
    printList(head);
}
