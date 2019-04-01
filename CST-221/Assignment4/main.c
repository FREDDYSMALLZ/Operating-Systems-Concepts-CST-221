//
//  main.c
//  Memory Management
//
//  Created by Fredrick  Onduso Ondieki on 3/31/19.
//  Copyright © 2019 Fredrick  Onduso Ondieki. All rights reserved.
/*
 Course: CST - 221 Operating system
 University: GCU
 Description: This program takes a single user input, integer, between 0 and 4095 then proceeds
 to calculate the binary and hexadecimal of that number. After which it shifts the
 number 16 bits to the left, performs additional calculations, then prints the new
 number, binary, and hexadecimal to the console.
 
 */
#include <stdio.h>
#include <string.h>

//initialize functions
long long toBinary(long long myNumbur);
long long shift(long long myBinary);
long long convHex();

int main(){
    
    //variables
    long long myNumber;
    long long myBinary;
    long long shifted;
    long long binShift;
    long long decimal = convHex();
    long long added;
    long long addBinary;
    
    //Get input from the user
    printf("Please Enter a number between 0 and 4095: \n");
    scanf("%lld", &myNumber);
    
    //create binary from the user input
    myBinary = toBinary(myNumber);
    
    //shift input 16 bits to the left
    shifted = shift(myNumber);
    
    //convert the  shifted input to binary number
    binShift = toBinary(shifted);
    
    //add hexadecimal number as decimal to the shifted decimal
    added = (shifted + decimal);
    
    //convert the result numbers to binary
    addBinary = toBinary(added);
    
    //Display the outpout result to the console
    printf("The entered number is: %lld \n", myNumber);
    printf("The binary for %lld is: %lld \n", myNumber, myBinary);
    printf("The number in hexadecimal is: %llx \n", myNumber);
    printf("Shifted 16 bits to the left: %lld \n", shifted);
    printf("Binary after shift is: %lld \n", binShift);
    printf("0x07FF in decimal is: %lld \n", decimal);
    printf("Final result dec: %lld \n", added);
    printf("Final result bin: %lld \n", addBinary);
    printf("Final result hex: %llx \n", added);
    
    
    return 0;
}

//if input from the user is < 2 return 0 or 1
// else convert the number to binary
long long toBinary(long long myNumber){
    
    if(myNumber < 2){
        return myNumber;
    }
    else{
        return toBinary(myNumber /2) * 10 + myNumber % 2;
    }
}
//Shift the number 16 bits to the left and then mask out
//for i < 16, shift left 1 bit and print the shift.
//return shifted number after the shift

long long shift(long long myNumber){
    for(int i = 0; i < 16; i++){
        myNumber = myNumber << 1;
        
        printf("Shift to the left 1 bit: %lld \n",
               toBinary(myNumber));
    }
    return myNumber;
}

//convert hexadecimal number 0x07FF to decimal
long long convHex(){
    long long total;
    
    //Hexadecimal is base 16, 0-9, a-f
    //7 = 7, F = 15,
    //(16^2 * 7), (16^1 * 15), (16^0 * 15)
    total = (7 * 256) + (15 * 16) + (15 * 1);
    return total;
}
