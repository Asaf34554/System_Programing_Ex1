#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isStrong(int num){
    int x = num,y = num;
    int i,j,z,counter = 0;
    int sum =1;
    while(x>0){
        x=x/10;
        counter++;
    }
    for(i=0;i<counter;i++){
        x = y %10;
        for(j=0;j<x;j++){
            sum = sum*(j+1);
        }
        z = z+sum;
    }
    return z == num;
}
int isPrime(int num){
  if( num == 1 ) {
    return 1;
  }
 else if(num%2 == 0){
    return num == 2;
 }
 int i = 3;
 while(i*i <= num){
    if( num % i == 0){
        return 0;
    }
    i++;
 }
 return 1;
}