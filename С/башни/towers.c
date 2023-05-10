#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct info{
    int q;
    int sizes[6];
}info;

typedef struct stick{
    char* left[7];
    char* right[7];
}stick;

void output(info *firstinfo , info *secondinfo , info *thirdinfo){
    int i ;
    int j;

    stick *first = malloc(sizeof(stick));
    stick *second = malloc(sizeof(stick));
    stick *third = malloc(sizeof(stick));
    
    char* disks[7][2];
    char *lefttmp;
    char *righttmp;
    for(i = 1 ; i < 7 ; i++){
        lefttmp = malloc(sizeof(char)*6);
        righttmp = malloc(sizeof(char)*6);
        for(j = 0; j < 6 ; j++){
            if(j - i >= 0){
                righttmp[j] = 32;
            }
            else{
                righttmp[j] = 42;
            }
            if(i - j > 1){
                lefttmp[j] = 32;
            }
            else{
                lefttmp[j] = 42;
            }
        }
        righttmp[j] = '\0';
        lefttmp[j] = '\0';
        disks[7-i][0] = lefttmp;
        disks[i][1] = righttmp;
    }
    disks[0][0] = "      ";
    disks[0][1] = "      ";




    for(i = 0 ; i < 7 ; i++){
        if (i < firstinfo->q){
            first->left[i] = disks[ firstinfo->sizes[i]  ][0];
            first->right[i] = disks[ firstinfo->sizes[i] ][1];
        }
        else{
            first->left[i] = disks[0][0];
            first->right[i] = disks[0][1];
        }
    }

    for(i = 0 ; i < 7 ; i++){
        if (i < secondinfo->q){
            second->left[i] = disks[ secondinfo->sizes[i] ][0];
            second->right[i] = disks[ secondinfo->sizes[i] ][1];
        }
        else{
            second->left[i] = disks[0][0];
            second->right[i] = disks[0][1];
        }
    }

    for(i = 0 ; i < 7 ; i++){
        if (i < thirdinfo->q){
            third->left[i] = disks[ thirdinfo->sizes[i] ][0];
            third->right[i] = disks[ thirdinfo->sizes[i] ][1];
        }
        else{
            third->left[i] = disks[0][0];
            third->right[i] = disks[0][1];
        }
    }


    printf("--------------------------------------------------------- \n");
    for(i = 0 ; i < 7 ; i++){
        printf("   %sI%s      %sI%s      %sI%s   \n", first->left[6-i], first->right[6-i] , second->left[6-i], second->right[6-i], third->left[6-i], third->right[6-i]);

    }
    printf("--------------------------------------------------------- \n");
}

void hanoi(int n, info *firstinfo , info *secondinfo , info *thirdinfo , info *firstshow , info *secondshow , info *thirdshow){
    
    
    if (n==1){
        secondinfo->sizes[ secondinfo->q ] = firstinfo->sizes [ firstinfo->q -1];
        firstinfo->sizes [ firstinfo->q -1] = 0;
        secondinfo->q++;
        firstinfo->q--;
        output(firstshow, secondshow , thirdshow);
    }
    else{
        
        hanoi(n-1, firstinfo , thirdinfo , secondinfo , firstshow , secondshow , thirdshow);

        secondinfo->sizes[ secondinfo->q ] = firstinfo->sizes [ firstinfo->q -1];
        firstinfo->sizes [ firstinfo->q -1] = 0;
        secondinfo->q = secondinfo->q+1;
        firstinfo->q = firstinfo->q-1;
        output(firstshow, secondshow , thirdshow);

        hanoi(n-1, thirdinfo , secondinfo , firstinfo , firstshow , secondshow , thirdshow);
        
    }
    
}








int main(int argv , char* argc[]){


    int n;
    int i;
    info *firstinfo = malloc(sizeof(info));
    info *secondinfo = malloc(sizeof(info));
    info *thirdinfo = malloc(sizeof(info));
    printf("input number from 1 to 6 \n");
    scanf("%d", &n);
    firstinfo->q = n;
    secondinfo->q = 0;
    thirdinfo->q = 0;

    for(i = 0 ; i < 6 ; i++){
        if( i < n){
            firstinfo->sizes[n-1-i] = i+1;
            secondinfo->sizes[n-1-i] = 0;
            thirdinfo->sizes[n-1-i] = 0;
        }
        else{
            firstinfo->sizes[i] = 0;
            secondinfo->sizes[i] = 0;
            thirdinfo->sizes[i] = 0;
        }
    }
    output(firstinfo, secondinfo,thirdinfo);
    hanoi(n , firstinfo, secondinfo,thirdinfo , firstinfo, secondinfo,thirdinfo);
    return 0;
}