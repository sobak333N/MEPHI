#include<stdio.h>
#include <stdlib.h>
 

int func(int num ,int times){
    int n = num;
    int t = times;
    int tmp = n;
    int min = 9, max = 0;
    int ost;
    t--;
    if(t != -1){
        while(n / 10 != 0){
            ost = n % 10;
            n = n / 10;
            if(ost >= max){
                max = ost;
            }
            if(ost <= min){
                min = ost;
            }
        }
        if(n >= max){
            max = n;
        }
        if(n <= min){
            min = n;
        }
        if(min == 0){
          return tmp;
        }
        else{
          num = tmp + max * min;
          return func(num , t);
        }
    }
    else{
      return tmp;
    }
}

int main()
{
    int t;
    int ans;
    scanf("%d", &t);
    int num[t] , times[t];
    for(int i =  0 ; i < t ; i ++){
        scanf("%d %d", &num[i] , &times[i]);
    }
    for(int i = 0 ; i < t ; i ++){
        ans = func(num[i], times[i]);
        printf("%d \n", ans);
    }
  return 0;
}