#include <stdio.h>
#include <math.h>
#include <ctype.h>

int getlength(unsigned long int num) {
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

int same_digit(int array[], int size){
   int i = array[0];
   int check = 1;
   for(int j = 0; j < size; j++){
      if(array[j] != i){
         check = 0;
      }
   }
   return check;
}

int extract_digit(int array[], int k, int pos){
   //so k will the number of digits starting from l to be extracted
   int digit = 0;
   for(int i = pos; k > 0; k--){
      digit = digit * 10;
      digit = digit + array[i];
      i++; 
   }
   
   return digit;
}

int digitcheck(unsigned long int digit){
   int length = getlength(digit);
   int arr[length];
   
   int k = length - 1;
   for(unsigned long int j = digit; j != 0; k--){
      arr[k] = j % 10;
      j /= 10;
   }//assign each digt to its corresponding index in the array

   for(int i = 1; i <= length / 2; i++){
      if(length % i == 0){//i.e if i is a factor of the length because any repeating subsequence can only have a length which is a actor of the full length
         int test = 0;
	 int check = 1;
	 for(int pos = 0; pos < length;){
	    if(pos == 0){
	       test = extract_digit(arr, i, 0);
	    }
	    if(test != extract_digit(arr, i, pos)){
	       check = 0;
	    }
	    pos = pos + i;
	 }
	 if(check == 1){
	    return 1;
	 }
      }
   }
   
   return 0;
}

int main(void){
   FILE *file = fopen("input.txt", "r");
   if(file == NULL){
      printf("Failed to open file\n");
      return 1;
   }
   
   unsigned long int digit1, digit2;
   unsigned long long int sum = 0;

   while(1){
      digit1 = digitget(file);
      if(digit1 == EOF){
         break;
      }
      digit2 = digitget(file);
      
      for(unsigned long int i = digit1; i <= digit2; i++){
         if(digitcheck(i)){
	    sum += i;
	 }
      }
   }

   printf("%lld\n", sum);
   fclose(file);
   return 0;
}
