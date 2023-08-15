#include<stdio.h>
#include<stdlib.h>

int np;
int nr;




void main(){

    //read process and resouce
    printf("Enter no of proceseses: ");
    scanf("%d",&np);
    printf("Enter no of resources: ");
    scanf("%d",&nr);
    
    int avR[nr];
    //read availabe of each resource
    printf("enter available instance of each resource: ");
    for(int i = 0; i< nr ; i++ ){
        scanf("%d",&avR[i]);
       
    }
    printf("\n");

    //read each resouce max for each process

   int pMax[np][nr];
   printf("Enter max matrix: ");
   for(int i = 0; i< np ; i++){
    for(int j = 0; j< nr ; j++){
        scanf("%d",&pMax[i][j]);
    }
   }

    //read allocaton matrix
   int aloc[np][nr];
   printf("Enter Allocation Matrix : ");
   for(int i = 0; i< np ; i++){
    for(int j = 0; j< nr ; j++){
        scanf("%d",&aloc[i][j]);
    }
   }

   

   //calculate need matrix

   int needM[np][nr];

   for(int i = 0 ; i< np; i++){
    for(int j = 0 ; j < nr ; j++){
        needM[i][j] = pMax[i][j] - aloc[i][j];
    }
   }

   printf("need matrix \n");
   for(int i = 0 ; i< np; i++){
    for(int j = 0 ; j < nr ; j++){
        printf("%d ",needM[i][j]);
    }
    printf("\n");
   }
  




   //bankers 

   // track completed , work 

   int sequence[np];

   int finished[np];
   for(int x =0 ; x<np;x++){
    finished[x] = 0;
   }
   int work[nr];
   for(int i = 0; i< nr; i++){
    work[i] = avR[i];
   
   }
   printf("\n");

   int check = 1;
   int arraP = 0;
   
   while(check == 1){
        check = 0;
        for( int i = 0 ; i< np ; i ++ ){
            int flag = 1;
            for(int x =0 ; x<nr; x++){
                if(needM[i][x]>work[x]){
                   
                    flag = 0;
                }else{
                    
                }
            }


            if(flag == 1  && finished[i]==0){
                finished[i]  = 1;
            
                sequence[arraP] = i;
                arraP+=1;
                for(int j = 0; j< nr; j++){
                    work[j] = work[j] + aloc[i][j];
                }
                check = 1;

            }
        }


   }

   check = 1;
   for(int k = 0; k < np ; k++){
    if(finished[k]==0){
        check = 0 ;
        break;
    }
   }

   if(check==1){
    printf("safe sequence: ");
    for(int l = 0; l < np ; l ++){
        printf("P%d ",sequence[l]);
    }
   }else{
    printf("no safe state available");
   }


}