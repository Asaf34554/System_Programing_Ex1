

#include <stdio.h>
#include <math.h>
#include "NumClass.h"


int isPalindrome(int num){
    int x = num;
    int counter = 0;
    int x1=num;
    int i,y,z=0;
    while(x > 0){
        x = x/10 ;
        counter+=1 ;
    }
    for(i = counter; i > 0; i--){
        y= x1%10;
        x1 = (int) x1/10;
        z = z + (int) pow(10,i-1)*y;
    }
    return z == num;
}
int isArmstrong(int num){
    if(num == 0 || num ==1){
        return 1;
    }
    int x = num,y = num;
    int counter = 0,i=0,sum = 0;
    while(x>0){
        x = x/10;
        counter++;
    }
    while(i<counter){
        x = y%10;
        y = y/10;
        sum = sum + (int) pow( (double)x , (double)counter);
        i++;
    }
    return sum == num;
    }
