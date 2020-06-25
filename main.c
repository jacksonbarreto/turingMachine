#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "turingMachine.h"

const QUINTUPLE programming[] = {
        {S0,'1',S1,'B',R},
        {S1,'1',S2,'B',R},
        {S2,'1',S2,'1',R},
        {S2,'+',S3,'1',R},
        {S1,'+',S3,'B',R}
};
const CONTROLINT finalStates[] = {S3};

int main(int argc, char * argv[]) {

    setlocale(LC_ALL,"");

    if(argc<2)
    {
        printf("ERRO: Não foi enviada a fita com a palavra binária.\n");
        return EXIT_FAILURE;
    }
    else if(argc>2)
    {
        printf("ERRO: Deve ser passada apenas uma palavra binária.\n");
        return EXIT_FAILURE;
    }

    machineTuring(argv[1],programming,5,finalStates,1);

    return EXIT_SUCCESS;
}
