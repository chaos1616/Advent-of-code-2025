#include <stdio.h>
#include <stdlib.h>

typedef struct{//Attempt at a dynamic array
   unsigned long int *data;
   int size;//size represents the number of elements stored
   int capacity;//capacity should represent the number of elements that can be stored
} Vector;

Vector arr = {NULL, 0, 0};

void insertelement(Vector *arr, unsigned long int data){
   if(arr->data == NULL || arr->size == arr->capacity){
      if(arr->capacity == 0){
         arr->capacity = 8;
      }
      else{
         arr->capacity *= 2;
      }
      arr->data = realloc(arr->data, arr->capacity * sizeof(unsigned long int));
   }
   
   arr->data[arr->size] = data;
   arr->size++;
}

int arr_check(Vector *arrptr, unsigned long int check){
   int result = 0; // 0 means that check cannot be found in the array 
   
   if(arrptr->data == NULL){
      return result;
   }

   for(int i = 0; i < arrptr->size; i++){
      if(check == *(arrptr->data + i)){
         result = 1;
	 return result;
      }
   }

   return result;
}

void free_array(Vector *vecptr){
   free(vecptr->data);
   vecptr->size = 0;
   vecptr->capacity = 0;
}


int main(void){
   FILE *file = fopen("example.txt", "r");
   if(file == NULL){
      printf("File could not be opened\n");
      return 1;
   }

   char line[40];
   int count = 0;
   while(fgets(line, 40, file) != NULL){
      int dashcheck = 0;
      for(int i = 0; i < 40; i++){
         if(line[i] == '-'){
	    dashcheck = 1;
	    break;
	 }
	 if(line[i] == '\0'){
	    break;
	 }
      }
      
      if(dashcheck == 1){
         unsigned long int digit1;
	 unsigned long int digit2;
	 
	 sscanf(line,"%lu %lu", &digit1, &digit2);
         
         for(unsigned long int i = digit1; i <= digit2; i++){
	    if(!arr_check(&arr, i)){
	       insertelement(&arr, i);
	    }   
	 }	 
      }
      else{
         unsigned long int digit;
	 if(sscanf(line, "%lu", &digit) != EOF){
	    if(arr_check(&arr, digit)){
	       count = count + 1;
	    }
         }
      }
   }

   printf("%d \n", count);
  
   free_array(&arr);
   fclose(file);
   return 0;
}
