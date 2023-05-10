#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>


#define M 65000
#define N 33
#define X 15

unsigned int hash(char *str){
  unsigned int i = 1 , h = 0;
  while(str[i-1]){
    //h+=(unsigned int)str[i];

    h+= (unsigned int)str[i-1]*(unsigned int)str[i]*(unsigned int)str[i+1];
    i++;
  }
  return h % (M/10);
}


typedef struct HT_bucle{
  char* key;
  char* value;
}HTB_t;

typedef struct HashTable{
  HTB_t **items;
  int size;
  int count;
} HT_t;

HT_t* create_table(int size){
  HT_t* table;
  int i ;
  table =(HT_t*) malloc (sizeof(HT_t));
  table->size = size;
  table->count = 0;
  table->items = (HTB_t**)calloc(table->size, sizeof(HTB_t*));
  for( i = 0 ; i < table->size ; i++){
    table->items[i] = NULL;
  }
  return table;
}

HTB_t* create_item(char* key, char* value){
  HTB_t* item;
  item = (HTB_t*) malloc(sizeof(HTB_t));
  item->key = (char*) malloc(strlen(key) + 1);
  item->value = (char*) malloc(strlen(value) + 1);
  strcpy(item->key , key);
  strcpy(item->value, value);
  return item;
}


void free_item(HTB_t* item) {
    free(item->key);
    free(item->value);
    free(item);
}

void free_HT(HT_t* table) {
  int i ;
  HTB_t* item = table->items[0];
    for (i=0; i<table->size; i++) {
        item = table->items[i];
        if (item != NULL)
            free_item(item);
    }
    free(table);
}

int string_same(char* first, char* second){
  int i;
  if(strlen(first) != strlen(second)){
    return 1;
  }
  for(i = 0 ; i < strlen(first) ; i++){
    if(first[i] != second[i]){
      return -1;
    }
  }
  return 0;
}


void HT_insert(HT_t* table , char* key , char* value){
  HTB_t* item = create_item(key , value);
  unsigned int index = hash(key);
  if(table->items[index] == NULL){
    if(table->count == table->size){
      printf("Hash table is full ! \n");
      free(item);
      return;
    }
    table->items[index] = item;
    table->count++;
  }
  else{
    if(string_same(table->items[index]->key , key) == 0){
      strcpy(table->items[index]->value , value);
      return;
    }
    else{
      //handle_collision
      return;
    }
  }
}


char* HT_search(HT_t* table , char* key){
  int index = hash(key);
  if(table->items[index] != NULL){
    if(string_same(key , table->items[index]->key) == 0){
      return table->items[index]->value;
    }
  }
    return NULL;
}

void print_search(HT_t* table , char* key){
  char* value = HT_search(table , key);
  if(value == NULL){
    printf("No such key '%s'\n", key);
    return;
  }
  else{
    printf("Key:%s, Value:%s\n", key, value);
  }
}

void print_HT(HT_t* table){
  int i;
  printf("\nHash Table\n-------------------\n");
    for (i = 0; i<table->size; i++) {
        if (table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n");
}




int main(int argc , char *argv[]){
  unsigned int g[M] , i , j = 0, index;
  int norm = 0, empt = 0 , coll = 0 , n;
  int rnum;
  char s[N];
  char x[X];
  char tmp[N];
  HT_t* HashTable = create_table(M);
  HT_insert(HashTable, "Ryazanskiy" , "Vyacheslav");
  srand(time(NULL));
  for(i = 0; i < M ; i++){
    g[i] = 0;
  }

  while( j < M / 10){
    rnum = rand()%32;
    for( i = 0 ; i < rnum ; i++){
      s[i] = ((char)(65+rand()%52));
    }
    s[i] = '\0';
    index = hash(s);
    g[index]++;
    j++;
    for( i = 0 ; i < X-1 ; i++){
      if(i % 3 == 0){
        x[i] = ((char)(58+rand()%2));
      }
      else if(i % 3 == 1){
        x[i] = ((char)(40+rand()%2));
      }
      else{
        x[i] = (char)32;
       }
    }
    HT_insert(HashTable, s , x);
  }

  for(i = 0 ; i < M /10 ; i++)
    switch(g[i]){
      case 0 : empt++; break;
      case 1 : norm++; break;
      default: coll++;
    }

  
  for (i =( M / 10) - 10; i< M /10; i++) {
    if (HashTable->items[i]) {
        strcpy(tmp , HashTable->items[i]->key );
        break;
      }
    }

  
  print_HT(HashTable);

  print_search(HashTable, tmp);
  print_search(HashTable, "Ryazanskiy");
  print_search(HashTable, "MEPHI");

  free_HT(HashTable);

  printf("norm: %d\nempt: %d\ncoll: %d\n" , norm , empt , coll);

  return 0;

}
