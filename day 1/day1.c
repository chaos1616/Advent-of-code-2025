//secret entrance
//First try constructing a data structure and function to rotate the dial
#include <stdio.h>

typedef struct{      //type to represent the dial
   int arr[100];     //array where each index represents a number on the dial
   int ind;          //this holds the current index being pointed towards by the dial
} Dial;  



int rotatedial(char dir, int rotate, Dial *dialptr){
   if(dir == 'L'){
      for(; rotate != 0; rotate--){
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
         if(dialptr->ind == 99){
	    dialptr->ind = 0;
	    continue;
	 }
	 else{
	    dialptr->ind += 1;
	 }
      }
   }
   return dialptr->ind;
}


int main(void){
   Dial dial = {{0}, 50}; 
   Dial *dialptr = &dial;

   FILE *file = fopen("input.txt", "r");
   
   if(file == NULL){
      printf("%s\n", "Error in opening file");
      return 1;
   }

   int rotate;
   char dir;
   int password = 0;

   while(fscanf(file, " %c %d", &dir, &rotate) != EOF){
      if(rotatedial(dir, rotate, dialptr) == 0){
         password++;
      }
   }  
   
   printf("%d\n", password);
   return 0;
}
