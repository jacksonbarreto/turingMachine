//
// Created by Jackson Junior on 25/06/2020.
//

#include "turingMachine.h"




void machineTuring(char *dataTape, const QUINTUPLE *programming, CONTROLINT programmingSize,const CONTROLINT *listFinalStates,
                   CONTROLINT listSize) {
    CONTROLINT i, IOHead=0, currentState=0;

    do
    {
        for(i=0; i<programmingSize; i++)
        {
            if (programming[i].currentState == currentState && programming[i].input == dataTape[IOHead])
            {
                dataTape[IOHead] = programming[i].output;
                currentState = programming[i].nextState;
                if (programming[i].movement == R)
                    IOHead++;
                else
                    IOHead--;
            }
        }
    }
    while (!isFinalStates(currentState,listFinalStates,listSize));

    printf("\nB%sBB",dataTape);
}


bool isFinalStates(CONTROLINT state,const CONTROLINT *listFinalStates, CONTROLINT listSize) {
    CONTROLINT i;

    for (i=0; i<listSize;i++)
    {
        if(state == listFinalStates[i])
            return true;
    }
    return false;
}
