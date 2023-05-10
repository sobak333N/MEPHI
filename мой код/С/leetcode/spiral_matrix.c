#include<stdio.h>
#include<stdlib.h>

#define M 3
#define N 1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int** arr = matrix;
    int m = matrixSize;
    int n = *matrixColSize;
    
    
    int ans = 0;
    int counter ;
    int max;
    *returnSize = m*n;
    int i = 0;
    int j = 0;
    int tmpN = n;
    int tmpM = m;

    // int answer[m*n];
    int *answer = malloc(m*n*sizeof(int));

    if(m > n){
        max = m;
    }
    else{
        max = n;
    }
    if(max % 2 == 0){
        counter = max / 2;
    }
    else{
        counter = (max / 2) + 1;
    }



    if(matrixSize == 1){
        return *matrix;
    }
    else{
        for(int k = 0 ; k < counter ; k++){
            for(j ; j < tmpN  ; j++){
                answer[ans] = arr[i][j] ;
                ans++;
                if(ans > 11){
                    return answer;
                }
            }
            j = tmpN - 1;
            i++;
            for(i ; i < tmpM ; i++){
                answer[ans] = arr[i][j] ;
                ans++;
                if(ans > 11){
                    return answer;
                }
            }
            i = tmpM -1;
            j--;
            for(j ; j >= n - tmpN   ; j--){
                answer[ans] = arr[i][j] ;
                ans++;
                if(ans > 11){
                    return answer;
                }
            }
            j = n - tmpN;
            i--;
            for(i ; i >= m - tmpM +1 ; i--){
                answer[ans] = arr[i][j] ;
                ans++;
                if(ans > 11){
                    return answer;
                }
                }
            tmpN = n - k - 1 ;
            tmpM = m - k - 1 ;

            i = m - tmpM;
            j = n - tmpN;
            }
        printf("%d \n", ans);
        return answer;
    }
}
// int* spiralOrder(int** arr, int m, int n){
//     int ans = 0;
//     int counter ;
//     int max;
//     if(m > n){
//         max = m;
//     }
//     else{
//         max = n;
//     }
//     if(max % 2 == 0){
//         counter = max / 2;
//     }
//     else{
//         counter = (max / 2) + 1;
//     }
//     int i = 0;
//     int j = 0;
//     int tmpN = n;
//     int tmpM = m;
//     int *answer = malloc(m*n*sizeof(int));

//     for(int k = 0 ; k < counter ; k++){
//         for(j ; j < tmpN  ; j++){
//             answer[ans] = arr[i][j] ;
//             ans++;
//         }
//         j = tmpN - 1;
//         i++;
//         for(i ; i < tmpM ; i++){
//             answer[ans] = arr[i][j] ;
//             ans++;
//         }
//         i = tmpM -1;
//         j--;
//         for(j ; j >= n - tmpN  ; j--){
//             answer[ans] = arr[i][j] ;
//             ans++;
//         }
//         j = n - tmpN;
//         i--;
//         for(i ; i >= m - tmpM + 1 ; i--){
//             answer[ans] = arr[i][j] ;
//             ans++;
//             }
//         tmpN = n - k - 1 ;
//         tmpM = m - k - 1 ;

//         i = m - tmpM;
//         j = n - tmpN;
//         }
//     return answer;
// }




int main(){

    int **arr = malloc( M * sizeof( int * ) );
    for ( int i = 0; i < M; i++ )   
        arr[i] = malloc( N * sizeof( int ) );


    int *answer = malloc(N*M*sizeof(int));
    for ( int i = 0; i < M; i++ ){
        for ( int j = 0; j < N; j++ ) 
            arr[i][j] = i * N + j + 1;
    }

    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    int x = 4;
    int *px = &x;
    answer = spiralOrder(arr, M, px, px);

        for(int i = 0 ; i < M*N ; i++){
            printf("%d ", answer[i]);
        }
    
}
