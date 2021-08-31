#include <stdio.h>
#include <string.h>

int main(void){
   char string[100] = "abcde";
   char string1[100] = "hello my friend";
   char string2[100] = "hello my friend";

   for(int i=0; string[i+1] != '\0'; i++){
      printf("%c",string[i]);
   }

   printf("\n");

   for(int i=1; string[i] != '\0'; i++){
      printf("%c",string[i]);
   }

   printf("\n");

   char *ptr = strtok(string1, " ");

   while (ptr != '\0')
   {
      for(int i=0; ptr[i+1] != '\0'; i++){
      printf("%c",ptr[i]);
      }
      printf(" ");
      ptr = strtok(NULL, " ");
   }

   printf("\n");

   char *ptr1 = strtok(string2, " ");

   while (ptr1 != '\0')
   {
      for(int i=1; ptr1[i] != '\0'; i++){
      printf("%c",ptr1[i]);
      }
      printf(" ");
      ptr1 = strtok(NULL, " ");
   }

   return 0;
}