//240
#ifndef funkcijos_H_INCLUDED
#define funkcijos_H_INCLUDED
#define Tipas2 " %d"
typedef int Tipas;
typedef struct node
{
    Tipas data;
    struct node* next;

}Node;
typedef struct node2
{
    Node* head;
    struct node2* next;
    int sk;
}Stekas;
int Sukurti(Stekas**);//Jeigu nebeina mallocinti grazina 0, jei pavyko sukurti grazina 1
int Pop(Stekas*, Tipas*);//Jeigu nera sukurta steku grazina 0, jeigu pasirinktas netinkamas steko numeris grazina 2, Jeigu pasirinktas stekas yra tuscias grazina 3
int Push(Stekas*);// Jeigu nera sukurta steko grazina 0, jeigu pasirinktas neegzistuojantis stekas grazina 2, Jeigu stekas pilnas grazina 3, jeigu nebegalima isskirti atminties grazina 4
int Sunaikinti(Stekas**);//Jeigu nera ka naikinti grazina 0, jeigu pasirinktas neegzistuojantis stekas grazina 2
int ArTuscias(Stekas*);//Jeigu nera sukurtu steku grazina 0, jeigu pasirinktas neegzistuojantis stekas grazina 2, jeigu stekas ne tuscias  grazina 3, jei tuscias grazina 1
int ArPilnas(Stekas*);//Jeigu nera sukurtu steku grazina 0, jeigu pasirinktas neegzistuojantis stekas grazina 2, jeigu stekas ne pilnas  grazina 3, jei pilnas grazina 1
int SpausdintiSteka(Stekas*);//Jeigu nera sukurtu steku grazina 0, jeigu pasirinktas neegzistuojantis stekas grazina 2
int ElementuSkaicius(Stekas*);
#endif
