//lobby
#include <stdio.h>
int digit(int x, int y){
   int value = 0;
   
   value *= 10;
   value += x;
   value *= 10;
   value += y;

   return value;
}

int main(void){
   FILE *file = fopen("input.txt", "r");
   if(file == NULL){
      printf("Unable to open file\n");
      return 1;
   }
   
   int char_count = 0;   
   while(fgetc(file) != '\n'){
      char_count++;
   }
   rewind(file);
   int bank[char_count];
   
   int sum = 0;
   
   fscanf(file, "%1d", &bank[0]);
   while(!feof(file)){
      int i = 1;
      while(i < char_count){
         fscanf(file,"%1d", &bank[i]);
	 i++;
      }
      
      int max = 0;
      
      for(int i = 0; i < char_count; i++){
         for(int j = 0; j < char_count; j++){
	    if(j == i){
	       continue;
	    }

	    if(digit(bank[i], bank[j]) > max && j > i){
	       max = digit(bank[i], bank[j]);
	    }
	 }
      }
   
      sum = sum + max;
      fscanf(file, "%1d", &bank[0]);      
   }
   
   printf("%d", sum);



   fclose(file);
   return 0;
}
