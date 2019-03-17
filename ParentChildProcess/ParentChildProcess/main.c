//
//  main.c
//  ParentChildProcess
//
//  Created by Fredrick  Onduso Ondieki on 3/15/19.
//  Copyright © 2019 Fredrick  Onduso Ondieki. All rights reserved.
//
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample()
{
    int x = 1;
  
    if (fork() == 0)
        printf("Child has x = %d\n", ++x);
    else
        printf("Parent has x = %d\n", --x);
}
int main()
{
    forkexample();
    return 0;
}
