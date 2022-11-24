#include <stdio.h>
#include "NumClass.h"

int main (){
    int x,y;
    scanf (" %d",&x);
    scanf (" %d",&y);
    int i;
    printf("The Armstrong numbers are:");
    for( i = x; i <= y; i++){
      if(isArmstrong(i) == 1){
      printf(" %d",i);
      }
    }
    printf("\nThe Palindrome numbers are:");
    for(i=x;i<=y;i++){
      if(isPalindrome(i)==1){
      printf(" %d",i);
      }
    }
    printf("\nThe Prime numbers are:");
    for(i=x;i<=y;i++){
      if(isPrime(i)==1){
      printf(" %d",i);
      }
    }
    printf("\nThe Strong numbers are:");
    for(i=x;i<=y;i++){
      if(isStrong(i)==1){
      printf(" %d",i);
      }
    }
    printf("\n");
    return 0;  
 }

    


    
