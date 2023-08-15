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
        count[i] =1000;
    }

    for(int i = 0; i< n; i++){
       int flag = 0;
        for(int k = 0; k< f; k++){
            if(frame[k]==reference[i]){
                flag = 1;
                int max = 999;
                count[k] = max;
                for(int j = i + 1;j<n;j++){
                    if(reference[j] == reference[i]){
                        count[k] = j;
                        break;
                    }
                }
                break;
            }
        }
       
        if(flag==0){
            faults++;
           int large = 0;
            for(int k = 1; k<f;k++){
                if(count[large]<count[k])large = k;
            }
            
            frame[large] = reference[i];
            int max = 999;
            count[large] = max;
                for(int j = i + 1;j<n;j++){
                    if(reference[j] == reference[i]){
                        count[large] = j;
                        break;
                    }
                }
           


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