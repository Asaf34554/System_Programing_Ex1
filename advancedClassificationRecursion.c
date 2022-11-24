

#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int numdigits(int num){
    int x = num;
    int counter = 0;
    while(x > 0){
        x = x/10 ;
        counter+=1 ;
    }
    return counter;
}
int isPalindrome1(int num,int temp){
    if(num == 0){
        return temp;
    }
    temp = (temp*10)+(num %10);
    return isPalindrome1(num/10,temp);
}
int isPalindrome(int num){
    int temp = 0;
    int num1 = isPalindrome1(num,temp);
    return num1 == num;
}


int isArmstrong1(int num,int power){
    if(num == 0){
        return 0;
    }

    return pow((int)num%10,power) + isArmstrong1(num/10 ,power);
}

int isArmstrong(int num){
    int x = numdigits(num);
    return isArmstrong1(num,x) == num;
}