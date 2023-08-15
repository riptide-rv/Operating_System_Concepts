#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Process{
    int pid,at,bt,st,et,wt,tt,rbt;
    struct Process *next;
}*head,*new,*newnode,*ptr,*chead,*cend,*cptr,*ptr2,*prev;

int n,at,bt;

int time;

struct Process * getNode();


void main(){
    head = getNode();
    ptr = head;
    printf("Enter no of processes: ");
    scanf("%d",&n);
    printf("Enter process details as matrix each row \n(at bt)\n");
    for(int i = 0 ; i< n ; i++ ){
        scanf("%d",&at);
        scanf("%d",&bt);
        new = getNode();
        new -> pid = i+1;
        new -> at = at;
        new -> bt = bt;
        new -> rbt = bt;
        ptr -> next = new;
        ptr = new;


    }
    cend = ptr;

    ptr -> next = head -> next;
    printf("Enter time quantom: ");
    scanf("%d",&time);

    int finished[n];
    for(int i = 0 ; i < n ; i++){
        finished[i] = 0;
    }

    int current;
    int duration;

    ptr = head->next;
  bool flag = false;
    current = ptr -> at;
   while(ptr!=NULL && !flag){
    printf("%d",ptr->bt);
    if(finished[ptr->pid -1]==2){
        ptr = ptr -> next;
        continue;
        }
    if(finished[ptr->pid - 1]==0){
        ptr -> st = current;
        finished[ptr->pid - 1]=1;
      
    }
    if(ptr->rbt<=time){
        duration = ptr->rbt;
        finished[ptr->pid -1] = 2;
    }else{
        duration = time;
    }
    ptr -> rbt = ptr -> rbt - duration;
    printf("\n");
    printf("rbt %d %d",ptr->pid,ptr->rbt);
    printf("\n");
    current = current+ duration;
      ptr -> et = current;
    flag = true ;
    for(int i = 0 ; i< n ; i++ ){
        if(finished[i]!=2){
            flag = false;
            
        }
    }
     ptr = ptr -> next;

   }
  cend -> next = NULL;
  ptr= head -> next;
  while(ptr!=NULL){
    int wt,tt;
    tt  = (ptr -> et) - (ptr -> at);
    wt = ( tt) - (ptr -> bt);
    printf("%d %d",wt,tt);
    printf("\n");
    ptr = ptr -> next;


  }





    



}

struct Process *getNode(){
    newnode = (struct Process *)malloc(sizeof(struct Process));
    newnode -> next = NULL;
    return newnode;

}



