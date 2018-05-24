#include <stdio.h>
#include <stdlib.h>
#include "funkcijos.h"

int Sukurti(Stekas** HEAD);
int Pop(Stekas* HEAD, int* data);
int Push(Stekas* HEAD);
int Sunaikinti(Stekas** HEAD);
int ArTuscias(Stekas* HEAD);
int ArPilnas(Stekas* HEAD);
int SpausdintiSteka(Stekas* HEAD);
int ElementuSkaicius(Stekas* HEAD);
int main()
{
    Tipas data;
    Stekas* st1 = NULL;
    Stekas* st2 = NULL;
    Sukurti(&st1);
    Sukurti(&st2);

    printf("\t AR STEKAS TUSCIAS - %d\n", ArTuscias(st1));
    printf("\t AR STEKAS PILNAS - %d\n", ArPilnas(st2));
    Push(st1);
    Push(st1);
    Push(st2);
    Pop(st2, &data);
    printf("\t ELEMENTU SK - %d\n", ElementuSkaicius(st2));
    SpausdintiSteka(st1);
    SpausdintiSteka(st2);
    Sunaikinti(&st1);
    SpausdintiSteka(st2);
    printf("\t AR STEKAS TUSCIAS - %d\n", ArTuscias(st2));

    return 0;
}
