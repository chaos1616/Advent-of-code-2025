//gift shop
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int getLength(unsigned long int num) {
   int length = 0;

   // Handle 0 explicitly
   if (num == 0)
      return 1;

   // Handle negative numbers
   if (num < 0)
      num = -num;

   // Count digits
   while (num > 0) {
      num /= 10;
      length++;
   }

   return length;
}

unsigned long int digitget(FILE *stream){
   unsigned long int value = 0;
   char ch;

   while(ch = fgetc(stream)){
      if(ch == EOF){
         return EOF;
      }
      if(!isdigit(ch)){
        if(value == 0){
           continue;
	}
	else{
	   break;
	}
      }
      if(ch == 48){
         value = value * 10;
	 continue;
      }
      value = value * 10;
      value = value + (ch - 48);
   }

   return value;
}

int digitcheck(unsigned long int digit){
   //return 1 for valid, 0 for invalid
   int len = getLength(digit);
   if(len % 2 != 0){
      return 1;
   }

   int mult = pow(10, len / 2);
   int dig1 = digit / mult;
   int dig2 = digit % mult;

   if(dig1 == dig2){
      return 0;
   }
   else{
      return 1;
   }
}

int main(void){
   FILE *file = fopen("input.txt", "r");
   if(file == NULL){
      printf("Failed to open file\n");
      return 1;
   }
   
   unsigned long int digit1, digit2;
   unsigned long int sum = 0;

   while(1){
      digit1 = digitget(file);
      if(digit1 == EOF){
         break;
      }
      digit2 = digitget(file);
      
      for(unsigned long int i = digit1; i <= digit2; i++){
         if(!digitcheck(i)){
	    sum += i;
	 }
      }
   }

   printf("%ld\n", sum);
   fclose(file);
   return 0;
}
