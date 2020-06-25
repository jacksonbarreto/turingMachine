//
// Created by HP on 25/06/2020.
//

#ifndef TURINMACHINE_TURINGMACHINE_H
#define TURINMACHINE_TURINGMACHINE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define S0 0
#define S1 1
#define S2 2
#define S3 3

#define R 1
#define L 2

typedef unsigned short int CONTROLINT;

typedef struct _quintuple
{
    CONTROLINT currentState;
    char input;
    CONTROLINT nextState;
    char output;
    CONTROLINT movement;
}
QUINTUPLE
;

void machineTuring(char *dataTape, const QUINTUPLE *programming, CONTROLINT programmingSize,const CONTROLINT *listFinalStates, CONTROLINT listSize);
bool isFinalStates(CONTROLINT state,const CONTROLINT * listFinalStates, CONTROLINT listSize);
#endif //TURINMACHINE_TURINGMACHINE_H
