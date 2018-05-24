#include <stdio.h>
#include <stdlib.h>
#include "funkcijos.h"

int Sukurti(Stekas** HEAD)
{
    if(*HEAD != NULL)
        return 0;
    else
    {
        Stekas* temp = (Stekas*)malloc(sizeof(Stekas));
        temp->head = NULL;
        temp->sk = 0;
        *HEAD = temp;
    }
}

int Pop(Stekas* HEAD, Tipas* data)
{
    Stekas* temp1 = HEAD;
    if(temp1->head == NULL)
        return 0;
    else
    {
        Node* temp = temp1->head;
        temp1->head = temp->next;
        *data = temp->data;
        free(temp);
        temp1->sk--;
        return 1;
    }
}
int Push(Stekas* HEAD)
{
    Stekas* temp1 = HEAD;
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL)
        return 4;
    else
    {
        Tipas duom;
        scanf(Tipas2, &duom);
        temp->data = duom;
        temp->next = temp1->head;
        temp1->head = temp;
        temp1->sk++;
        return 1;
    }
}
int Sunaikinti(Stekas** HEAD)
{
    Stekas* temp1 = *HEAD;
    Node* temp = temp1->head;
    while(temp->next != NULL)
    {
        temp1->head = temp->next;
        free(temp);
        temp = temp1->head;
    }
    free(temp);
    free(temp1);
    *HEAD = NULL;
}
int ArTuscias(Stekas* HEAD)
{
    if(HEAD == NULL)
        return 1;
    else
    {
        return 0;
    }

}
int ArPilnas(Stekas* HEAD)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL)
        return 1;
    else
    {
        free(temp);
        return 0;
    }
}
int SpausdintiSteka(Stekas* HEAD)
{
    if(HEAD == NULL)
        return 0;
    else
    {

        Stekas* temp1 = HEAD;
        Node* temp = temp1->head;
        while(temp != NULL)
        {
            printf(Tipas2, temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int ElementuSkaicius(Stekas* HEAD)
{
    if(HEAD == NULL)
        return 0;
    else
    {
        Stekas* temp1 = HEAD;
        return temp1->sk;
    }

}
