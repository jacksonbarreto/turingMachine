//
// Created by Jackson Junior on 25/06/2020.
//
#include "turingMachine.h"


void machineTuring(const char * dataTape, const QUINTUPLE * programming)
{
    CONTROLINT i, IOHead, currentState;
    char * standardizedDataTape;
    const CONTROLINT programmingSize = defineListSize(programming);

    if (!isValidAlphabet(dataTape,programming,programmingSize))
    {
        printf("\nERRO: A palavra binária informada contém símbolos que não pertencem ao alfabeto definido.\n");
    }
    else
    {
        standardizedDataTape = normalizationOfDataTape(dataTape);
        currentState=0;
        IOHead=WHITE_STANDARDS;
        do
        {
            for (i=0; i < programmingSize; i++)
            {
                if (currentState == programming[i].currentState && standardizedDataTape[IOHead] == programming[i].input)
                {
                    standardizedDataTape[IOHead] = programming[i].output;
                    currentState = programming[i].nextState;
                    if (programming[i].movement == R)
                        IOHead++;
                    else
                        IOHead--;
                    break;
                }
            }
        }
        while ((!isFinalStates(currentState,programming,programmingSize)) && standardizedDataTape[IOHead] != '\0' && IOHead >= WHITE_STANDARDS);

        printf("\n%s",standardizedDataTape);
        free(standardizedDataTape);
    }

}

static bool isValidAlphabet(const char * dataTape, const QUINTUPLE * programming,const CONTROLINT programmingSize)
{
    CONTROLINT i, j, status;

    for (i=0, status=0; i < stringLength(dataTape); i++)
    {
        for (j=0; j < programmingSize; j++)
        {
            if (dataTape[i] == programming[j].input)
            {
                status++;
                break;
            }
        }
    }
    return (status == stringLength(dataTape));
}

static char * normalizationOfDataTape(const char * dataTape)
{
    CONTROLINT i;
    char * newDataTape = calloc(stringLength(dataTape)+(WHITE_STANDARDS*2),sizeof(char));
    char * whites = calloc(WHITE_STANDARDS,sizeof(char));
    for (i=0; i<WHITE_STANDARDS;i++)
        whites[i] = 'B';

    sprintf(newDataTape,"%s%s%s",whites, dataTape, whites);

    return newDataTape;
}

static CONTROLINT stringLength(const char * string)
{
    CONTROLINT size=0;
    while (string[size] != '\0')
       size++;
    return size;
}

static CONTROLINT defineListSize(const QUINTUPLE *programming)
{
    CONTROLINT size=0;
    do
    {
        size++;
    }
    while (programming[size].currentState != END_OF_PROGRAM);
    return size;
}

static bool isFinalStates(CONTROLINT state, const QUINTUPLE * programming, CONTROLINT programmingSize)
{
    CONTROLINT i;

    for (i=0; i<programmingSize;i++)
    {
        if(state == programming[i].currentState)
            return false;
    }
    return true;
}
