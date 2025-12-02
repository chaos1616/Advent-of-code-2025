#include <stdio.h>

typedef struct{      //type to represent the dial
   int ind;          //this holds the current index being pointed towards by the dial
} Dial;  



int rotatedial(char dir, int rotate, Dial *dialptr){
   int count = 0;

   if(dir == 'L'){
      for(; rotate != 0; rotate--){
         if(dialptr->ind == 0){
	    count++;
	 }
	 if(dialptr->ind == 0){
	    dialptr->ind = 99;
	    continue;
	 }
	 else{
	    dialptr->ind -= 1;
	 }
      }
   }
   else if(dir == 'R'){
      for(; rotate != 0; rotate--){
         if(dialptr->ind == 0){
	    count++;
	 }
	 if(dialptr->ind == 99){
	    dialptr->ind = 0;
	    continue;
	 }
	 else{
	    dialptr->ind += 1;
	 }
      }
   }
   return count;
}


int main(void){
   Dial dial = {50}; 
   Dial *dialptr = &dial;
   int count = 0;

   FILE *file = fopen("input.txt", "r");
   
   if(file == NULL){
      printf("%s\n", "Error in opening file");
      return 1;
   }

   int rotate;
   char dir;

   while(fscanf(file, " %c %d", &dir, &rotate) != EOF){
      count = count + rotatedial(dir, rotate, dialptr);
   }  
   
   printf("%d", count);
   return 0;
}
