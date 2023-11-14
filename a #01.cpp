#include<iostream>
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
// below funcation is used to display the result .
	void linkTrav(struct node*ptr)
	{
	while(ptr!=NULL){
	printf("Element : %d\n",ptr->data);
	ptr=ptr->next;
	}
// funcation is used to update the value at given index .
}
void updateNode(struct node *head, int index, int newValue){
    struct node *ptr=head;
    for (int i=0;i<index;i++){
        if(ptr==NULL){
            printf("Index out of bounds\n");
            return;
        }
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        ptr->data=newValue;
        printf("Value at index %d updated to %d\n",index,newValue);
    } else {
        printf("Index out of bounds\n");
    }
}
// Search a value in given node .
void solve( node*head,int val){
	while(head){
		// here if condition is used to give entered data to head's data .
		if(head->data==val){
			printf("Value found \n");
			return;
		}
		head=head->next;
	}
	printf("Value Not Found \n");
}
// Insert at an index in linkList .
struct node*insertAtIndex(struct node*head,int data,int index){
		struct node*ptr;
			ptr=(struct node*)malloc(sizeof(struct node));
			struct node*p=head;
		int i=0;
		while(i!=index-1){
			p=p->next;
			i++;
		}
		ptr->data=data;
		ptr->next=p->next;
		p->next=ptr;
		return head;
}
// Delete  the first node of given linklist .
struct node*DelFirst(struct node*head){
		struct node*ptr=head;
		head=head->next;
		free(ptr);
		return head;
	}
// Delete  the  node at given index  of given linklist .
struct node*DelAtIndex(struct node*head,int index){
	struct node*p=head;
	struct node*q=p->next;
	for(int i=0;i<index-1;i++){
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
		return head;
}
// Delete  te last  node of given linklist .
struct node*DelLast(struct node*head){
	struct node*p=head;
	struct node*q=p->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
		free(q);
		return p;
}	
int main(){
	// making the nodes for saving data according to their needs .
	struct node*head;
	struct node*first;
	struct node*sec;
	struct node*thrd;
	//here given the Dynamic Memory to node .
	head=(struct node*)malloc(sizeof(struct node));
	first=(struct node*)malloc(sizeof(struct node));
	sec=(struct node*)malloc(sizeof(struct node));
	thrd=(struct node*)malloc(sizeof(struct node));
	// Give data to each node and point's to next .
	head->data=4;
	head->next=first;
	first->data=23;
	first->next=sec;
	sec->data=42;
	sec->next= thrd;
	thrd->data=56;
	thrd->next= NULL;
	// Display funcation Used .
	linkTrav(head);
	// funcation is used to update the value at given index .
	printf("Updating the given value at given index \n");
	updateNode(head, 2, 99);
    linkTrav(head);
	printf("Search Performed !\n");
	// Search funcation called.
	solve(head,56);
	printf("Insert a node at given index \n");
	// InsertAtIndex  funcation called.
	head=insertAtIndex(head,25,1);
	linkTrav(head);
	printf("delete  a node at  first node \n");
	// Delete  funcation called.
	head=DelFirst(head);
	linkTrav(head);
	printf("delete a node at given index \n");
	// DeleteAtIndex funcation called.
	DelAtIndex(head,2);
    linkTrav(head);
 	printf("delete a node at End \n");  
	// DelLast funcation called.	 
    DelLast(head);
    linkTrav(head);
}

