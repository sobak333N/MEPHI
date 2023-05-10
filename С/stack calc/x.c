 #include <stdio.h>
int size_of_string(char x[101]){
    int size = 0;
    int q = 0;
    while(x[q] != '='){
        q++;
        size++;
    }
    return size;
    
}

int priority (char op) {
    char c = op;
    switch (c) {
             case  '^':
                return 2;
                 break;
              case '(':
                 return 0;
                 break;
            case ')':
                 return 1;
                 break;    
             case '+':
                return 5;
                break;
             case '-':
               return 5;
                break;
             case '*':
               return 4;
                break;
             case '/':
              return 4;
                break;
	
}
}
float ansi(char tmp){
    int i = 57;
    float one = 1.000;
    for(i; i > 47; i--){
        if(tmp == i){
            i = i -48;
            break;
        }
    }
    return i*one ;
}

         
        
int main(){

    char tmp[100];
    scanf("%s", tmp);
    char new[size_of_string(tmp)];
    char stack[size_of_string(tmp)];
    int sp = 0;
    int size = 0;
    printf("%d \n", size_of_string(tmp));
    for(int i = 0; i < size_of_string(tmp) ; i++){
         if(i== size_of_string(tmp)){
                for(int j = 0; j > sp ;j++){
                    new[size+j] = stack[sp-1-j];
                }
            }
        char c = tmp[i];
            if(tmp[i]<58 && tmp[i] > 47){
             
                int vr = i;
                int count=0;
                /*while((tmp[i]<58 )&& (tmp[i] > 47)){
                    count++;
                    i++;
                }
                for(int j = 0 ; j < count ; j++){
                    new[size_of_string(new)+j] = tmp[vr+j];
                }
                new[count + size_of_string(new)-1] = 46;
                i = vr;*/
                new[size] = tmp[i];
                size++;
            }
            else {
                if(sp==0){
                    stack[sp] = tmp[i];
                    sp++;
                }
                else{
                    if(priority(tmp[i]) == 1){
                        int k = 0;
                        for(k; stack[k] != 40; k++){
                        new[size_of_string(new)-1+k] = stack[sp-1-k]; 
                        size++;
                        stack[sp-1-k] = 0;
                        }
                        sp = sp - k;
                    }
                    else if(priority(tmp[i]) == 0){
                        stack[sp] = tmp[i];
                        sp++;
                    }
                    else if(priority(tmp[i]) < priority(stack[sp])){
                        new[size_of_string(new)-1] = stack[sp];
                        size++;
                        stack[sp] = 0;
                        sp--;
                    }
                    else{
                        stack[sp] = tmp[i];
                        sp++;
                    }
                }
            }

         }
    
    printf("%s \n", new);
}