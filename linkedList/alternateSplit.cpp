void alternatingSplitList(struct Node* head) 
{
    Node* aa=head,*bb=head->next,*t;
    a=new Node(aa->data);
    t=a;
    while(aa && aa->next && aa->next->next){
        t->next=new Node(aa->next->next->data);
        aa=aa->next->next;
        t=t->next;
    }
    
    if(bb){
    b=new Node(bb->data);
    t=b;
    while(bb && bb->next && bb->next->next){
        t->next=new Node(bb->next->next->data);
        bb=bb->next->next;
        t=t->next;
    }
        
    }
}
