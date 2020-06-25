//
// Created by Jackson Junior on 25/06/2020.
//

#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define R 1
#define L 2
#define END_OF_PROGRAM 99
#define WHITE_STANDARDS 3

typedef unsigned short int CONTROLINT;

typedef struct _quintuple
{
    CONTROLINT currentState;
    char input;
    CONTROLINT nextState;
    char output;
    CONTROLINT movement;
}
QUINTUPLE;

void machineTuring(const char * dataTape, const QUINTUPLE * programming);
static bool isFinalStates(CONTROLINT state, const QUINTUPLE * programming, CONTROLINT programmingSize);
static CONTROLINT defineListSize(const QUINTUPLE *programming);
static CONTROLINT stringLength(const char * string);
static char * normalizationOfDataTape(const char * dataTape);
static bool isValidAlphabet(const char * dataTape, const QUINTUPLE * programming, const CONTROLINT programmingSize);

#endif
