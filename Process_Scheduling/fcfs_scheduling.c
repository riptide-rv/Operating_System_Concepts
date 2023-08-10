#include<stdio.h>
#include<stdlib.h>

// making structure for each process

struct Process{
    int pid , at, bt , st, et, wt , tt;
    struct Process *next;
}*head,*ptr,*new,*newnode,*prev;


//intialize required variables
int n;


//declaring fuctions
struct Process *getNode();
void addNewProcess(int i , int iat , int ibt);
void calculate(struct Process *p);
void showResult();
void calculateData();

//main function
void main(){

    //reading process details
    printf("Enter no:of processes: ");
    scanf("%d",&n);
    head  = getNode();
     ptr = head;
    for( int i = 0 ; i < n ; i++ ){
        int iat , ibt;
        printf("Enter arrival time and burst time of process %d: ",i+1);
        scanf("%d",&iat);
        scanf("%d",&ibt);
        addNewProcess(i,iat,ibt);
    }

    //setting data of initial process
    ptr = head -> next;
    ptr -> st = ptr -> at;
    ptr -> et = ptr -> st + ptr -> bt;
    ptr -> tt = ptr -> et - ptr -> at;
    ptr -> wt = ptr -> tt - ptr -> bt;
  

    //calculate data for remaining processes
    prev = ptr;
    ptr = ptr -> next;
    while(ptr!=NULL){
        calculateData(ptr);
        prev = ptr;
        ptr = ptr -> next;
    }

    //gnatt chart
    showResult();
    


    
}

//function implementaions
struct Process *getNode()
{
    newnode = (struct Process *)malloc(sizeof(struct Process));
    newnode -> next = NULL;
    return newnode;
};

void addNewProcess(int i ,  int iat , int ibt){
    new = getNode();
    new -> pid = i+1;
    new -> at = iat;
    new -> bt = ibt;
    ptr -> next = new;
    ptr = new ;
   
}
void calculateData(struct Process *p){
    p -> st = prev -> et;
    p -> et = p -> st + p -> bt;
    p -> tt = p -> et - p -> at;
    p -> wt = p -> tt - p -> bt;
 
}
void showResult(){
    float totalwt = 0;
    float totaltt = 0;

    ptr = head -> next;
    printf("pid\tat\tbt\tst\tet\twt\ttt\n");
    while(ptr!=NULL){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",ptr->pid,ptr->at,ptr->bt,ptr->st,ptr->et,ptr->wt,ptr->tt);
        totaltt = totaltt + ptr->tt;
        totalwt = totalwt + ptr->wt;
        ptr = ptr ->next;
    }
   
    printf("Average waiting time: %.2f\n",totalwt/n);
    printf("Average turn around time: %.2f\n",totaltt/n);
}

