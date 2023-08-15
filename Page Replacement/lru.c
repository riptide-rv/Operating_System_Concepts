#include<stdio.h>
#include<stdlib.h>

int n;
int f;

void main(){


    printf("Enter length of reference string: ");
    scanf("%d",&n);
    int reference[n];
    printf("Enter reference string: ");
    for(int i = 0; i< n ;i++){
        scanf("%d",&reference[i]);
    }
    printf("Enter no of frames: ");
    scanf("%d",&f);
    int frame[f];
    int count[f];
    int faults = 0;
    for(int i = 0; i< f ;i++){
        frame[i] = -1;
        count[i] = -1;
    }

    for(int i = 0; i< n; i++){
       int flag = 0;
        for(int k = 0; k< f; k++){
            if(frame[k]==reference[i]){
                flag = 1;
                count[k] = i;
            }
        }
        if(flag==0){
            faults++;
           int small = 0;
            for(int k = 1; k<f;k++){
                if(count[small]>count[k])small = k;
            }
            frame[small] = reference[i];
            count[small] = i;


        }
        for(int j = 0; j < f ; j++){
            printf("%d\t",frame[j]);
        }
        if(flag == 0)printf("page miss");
        printf("\n");
    }


    printf("no of faults = %d",faults);
    printf("\n");


}