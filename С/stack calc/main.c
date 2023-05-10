 #include <stdio.h>
int size_of_string(char x[101]){
    int size = 0;
    int q = 0;
    while(x[q] != 0 ){
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
// char poland(char tmp){
//     char new[size_of_string(tmp)];
//     char stack[size_of_string(tmp)];
//     int sp = 0;
//     for(int i = 0; i < size_of_string(tmp) ; i++){
//         char c = tmp[i];
//             if(str[i]<58 && str[i] > 47){
             
//                 int vr = i;
//                 while(str[i]<58 && str[i] > 47){
//                     count++;
//                     size++;
//                     i++
//                 }
//                 for(int j = 0 ; j < count ; j++){
//                     new[size_of_string(new)+j-1] = str[vr+j];
//                 }
//                 new[count + size_of_string(new)] = 32;
//                 i = vr;
//             }
//             else if(tmp[i] == 32){
//                 i++
//             }
//             else {
//                 if(size_of_string(stack) == 0){
//                     stack[sp] = tmp[i];
//                     sp++
//                 }
//                 else{
//                     if(priority(tmp[i]) == 1){
//                         for(int k = 0; stack[k] != 40; k++){
//                         new[size_of_string(new)-1+k] = stack[sp-1-k]; 
//                         stack[sp-1-k] = '\0'
//                         }
//                         sp = sp - k;
//                     }
//                     if(priority(tmp[i]) == 0){
//                         stack[sp] = tmp[i];
//                         sp++
//                     }
//                     else if(priority(tmp[i]) < priority(stack[sp])){
//                         new[size_of_string(new)-1] = stack[sp];
//                         stack[sp] = 0;
//                         sp--;
//                     }
//                     else{
//                         stack[sp] = tmp[i];
//                         sp++;
//                     }
//                 }
//             }
//          }
//          return new;
//         }
    





 int main()
 {
     float stack[1000];  
     char str[] = "2 31 + =";
     //char str[] = "2 3 4 5 6 * + - / =";
     int sp =0;   
     printf("%d \n", ansi(str[0]));   
     for(int i = 0 ; i <size_of_string(str) ; i++) {
         char c = str[i];
         printf("%d \n", c);
         int x;
         switch (c) {
             case  ' ':
             case '\n':
                 break;
             case '=':
                 printf("Result = %.4f\n", stack[sp - 1]);  sp--;
                 break;
             case '+':
                stack[sp-2] = stack[sp-2] + stack[sp-1];  sp--;
                break;
             case '-':
                stack[sp-2] = stack[sp-2] - stack[sp-1];  sp--;
                break;
             case '*':
                stack[sp-2] = stack[sp-1] * stack[sp-2];  sp--;
                break;
             case '/':
               stack[sp-2] = stack[sp-2] / stack[sp-1];   sp--;
                break;
             default:
            stack[sp] = ansi(str[i]);
            sp++;
         }
     }
     return 0;
 }