struct Node* head,*ptr1=a,*ptr2=b,*n,*h;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->next=NULL;
    head->data=-1;
    h=head;
    while(ptr1 && ptr2){
        if(ptr1->data > ptr2->data){
            n = (struct Node*)malloc(sizeof(struct Node)) ;
            n->next=NULL;
            n->data=ptr2->data;
            h->next=n;
            h=h->next;
            ptr2=ptr2->next;
            continue;
        }
        else if(ptr1->data<ptr2->data){
            n = (struct Node*)malloc(sizeof(struct Node)) ;
            n->next=NULL;
            n->data=ptr1->data;
            h->next=n;
            h=h->next;
            ptr1=ptr1->next;
        }
        
    }
        while(ptr2){
            n = (struct Node*)malloc(sizeof(struct Node)) ;
            n->next=NULL;
            n->data=ptr2->data;
            h->next=n;
            h=h->next;
            ptr2=ptr2->next;
        }
        while(ptr1){
            n = (struct Node*)malloc(sizeof(struct Node)) ;
            n->next=NULL;
            n->data=ptr1->data;
            h->next=n;
            h=h->next;
            ptr1=ptr1->next;
        }
        return head->next;
    
