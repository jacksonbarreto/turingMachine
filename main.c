#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "turingMachine.h"

const QUINTUPLE adderProgramming[] = {
        {S0,'1',S1,BLANK_SYMBOL,R},
        {S1,'1',S2,BLANK_SYMBOL,R},
        {S2,'1',S2,'1',R},
        {S2,'+',S3,'1',R},
        {S1,'+',S3,BLANK_SYMBOL,R},
        {END_OF_PROGRAM}
};

const QUINTUPLE programming[] = {
        {S0,'0',S0,'0',R},
        {S0,'1',S1,'1',R},
        {S0,BLANK_SYMBOL,S3,BLANK_SYMBOL,R},
        {S1,'0',S0,'0',R},
        {S1,'1',S2,'0',L},
        {S1,BLANK_SYMBOL,S3,BLANK_SYMBOL,R},
        {S2,'1',S3,'0',R},
        {END_OF_PROGRAM}
};

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

    machineTuring(argv[1],adderProgramming);
    //machineTuring(argv[1],programming);

    return EXIT_SUCCESS;
}
