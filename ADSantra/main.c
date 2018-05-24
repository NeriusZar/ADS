#include <stdio.h>
#include <stdlib.h>
#define DYDIS 8
#define DYDIS3 4
#define DYDIS2 16
void Padejimas(int Lenta[DYDIS][DYDIS], int x, int y);
void Koordinates(int sk, int* x, int* y, int M[DYDIS3][DYDIS3]);
void SimetriskasSudeliojimas(int Masyvas[DYDIS][DYDIS]);
void Spausdinti(int Lenta[DYDIS][DYDIS]);
void Isvalyti(int Lenta[DYDIS][DYDIS]);
int Tikrinimas(int Lenta[DYDIS][DYDIS]);
int ArkliuSudeliojimas(int Masyvas[DYDIS][DYDIS], int Lenta[DYDIS][DYDIS], int sk1, int sk2, int sk3);
int main()
{
    int count = 0;
    int M[DYDIS3][DYDIS3], i, j, k, n = 0, x,y,u,t;
    int Masyvas[DYDIS][DYDIS];
    int Lenta[DYDIS][DYDIS] = {0};
    int sk1, sk2, sk3;
	for(i = 0; i < DYDIS3; i++)
    {
        for(j = 0; j < DYDIS3; j++)
        {
            M[i][j] = n;
            n++;
        }
    }
    SimetriskasSudeliojimas(Masyvas);
    for(i = 0; i < DYDIS2; i++)
    {
        for(j = i+1; j < DYDIS2; j++)
        {
            for(k = j+1; k < DYDIS2; k++)
            {
                count++;
                sk1 = i;
                sk2 = j;
                sk3 = k;
                Koordinates(i, &x, &y, M);
                Padejimas(Lenta, x, y);
                Koordinates(j, &x, &y, M);
                Padejimas(Lenta, x, y);
                Koordinates(k, &x, &y, M);
                Padejimas(Lenta, x, y);
                for(t = 0; t < DYDIS; t++)
                {
                    for(u = 0; u < DYDIS; u++)
                    {
                        if(i == Masyvas[t][u])
                        {
                            Padejimas(Lenta, u, t);
                        }
                        if(j == Masyvas[t][u])
                        {
                            Padejimas(Lenta, u,t);
                        }
                        if(k == Masyvas[t][u])
                        {
                            Padejimas(Lenta,u,t);
                        }
                    }
                }
                if(Tikrinimas(Lenta) == 1)
                {
                    ArkliuSudeliojimas(Masyvas,Lenta,sk1,sk2,sk3);
                    Spausdinti(Lenta);
                    Isvalyti(Lenta);
                    printf("\n");
                }
                else {
                    Isvalyti(Lenta);
                }
            }

        }
    }
    printf("%d",count);
    return 0;
}
int Tikrinimas(int Lenta[DYDIS][DYDIS])
{
    int i, j, n = 0;
    for(i = 0; i < DYDIS; i++)
    {
        for(j = 0; j < DYDIS; j++)
        {
            if(Lenta[i][j] == 0)
                n++;
        }
    }
    if(n == 0)
        return 1;
    else return 0;
}

void Koordinates(int sk, int* x, int* y, int M[DYDIS3][DYDIS3])
{
    int i, j;
    for(i = 0; i < DYDIS3; i++)
    {
        for(j = 0; j < DYDIS3; j++)
        {
            if(M[i][j] == sk)
            {
                *x = j;
                *y = i;
            }
        }
    }
}
void Padejimas(int Lenta[DYDIS][DYDIS],int x, int y)
{
    if(y >=2 && y <= 5 && x >= 1 && x <= 6)
    {
        Lenta[y+2][x+1] = 1;
        Lenta[y+2][x-1] = 1;
        Lenta[y-2][x+1] = 1;
        Lenta[y-2][x-1] = 1;
    }
    if(x >= 2 && x <= 5 && y >= 1 && y <= 6)
    {
        Lenta[y+1][x+2] = 1;
        Lenta[y-1][x+2] = 1;
        Lenta[y+1][x-2] = 1;
        Lenta[y-1][x-2] = 1;
    }
    if((x == 1)&&(y >= 2 && y <= 5))
    {
        Lenta[y+1][x+2] = 1;
        Lenta[y-1][x+2] = 1;
    }
    if((x == 6)&&(y >= 2 && y <= 5))
    {
        Lenta[y+1][x-2] = 1;
        Lenta[y-1][x-2] = 1;
    }
    if((y == 1)&&(x >= 2 && x <= 5))
    {
        Lenta[y+2][x+1] = 1;
        Lenta[y+2][x-1] = 1;
    }
    if((y == 6)&&(x >= 2 && x <= 5))
    {
        Lenta[y-2][x+1] = 1;
        Lenta[y-2][x-1] = 1;
    }
    if((x == 0)&&(y >= 2 && y <= 5))
    {
        Lenta[y+2][x+1] = 1;
        Lenta[y-2][x+1] = 1;
        Lenta[y+1][x+2] = 1;
        Lenta[y-1][x+2] = 1;
    }
    if((x == 7)&&(y >= 2 && y <= 5))
    {
        Lenta[y+1][x-2] = 1;
        Lenta[y-1][x-2] = 1;
        Lenta[y+2][x-1] = 1;
        Lenta[y-2][x-1] = 1;
    }
    if((y == 0)&&(x >= 2 && x <= 5))
    {
        Lenta[y+2][x+1] = 1;
        Lenta[y+2][x-1] = 1;
        Lenta[y+1][x+2] = 1;
        Lenta[y+1][x-2] = 1;
    }
    if((y == 7)&&(x >= 2 && x <= 5))
    {
        Lenta[y-2][x+1] = 1;
        Lenta[y-2][x-1] = 1;
        Lenta[y-1][x+2] = 1;
        Lenta[y-1][x-2] = 1;

    }
    //sudini variantai
    if(y == 0 && x == 0)
    {
        Lenta[y+1][x+2] = 1;
        Lenta[y+2][x+1] = 1;
    }
    if(y == 0 && x == 7)
    {
        Lenta[y+1][x-2] = 1;
        Lenta[y+2][x-1] = 1;

    }
    if(y == 7 && x == 0)
    {
        Lenta[y-2][x+1] = 1;
        Lenta[y-1][x+2] = 1;

    }
    if(y == 7 && x == 7)
    {
        Lenta[y-2][x-1] = 1;
        Lenta[y-1][x-2] = 1;
    }
    if(y == 0 && x == 1)
    {
        Lenta[y+1][x+2] = 1;
        Lenta[y+2][x+1] = 1;
        Lenta[y+2][x-1] = 1;
    }
    if(y == 0 && x == 6)
    {
        Lenta[y+1][x-2] = 1;
        Lenta[y+2][x+1] = 1;
        Lenta[y+2][x-1] = 1;
    }
    if(y == 7 && x == 1)
    {
        Lenta[y-2][x+1] = 1;
        Lenta[y-2][x-1] = 1;
        Lenta[y-1][x+2] = 1;
    }
    if(y == 7 && x == 6)
    {
        Lenta[y-2][x+1] = 1;
        Lenta[y-2][x-1] = 1;
        Lenta[y-1][x-2] = 1;
    }
    if(y == 1 && x == 0)
    {
        Lenta[y+1][x+2] = 1;
        Lenta[y-1][x+2] = 1;
        Lenta[y+2][x+1] = 1;
    }
    if(y == 6 && x == 0)
    {
        Lenta[y+1][x+2] = 1;
        Lenta[y-1][x+2] = 1;
        Lenta[y-2][x+1] = 1;
    }
    if(y == 1 && x == 7)
    {
        Lenta[y+1][x-2] = 1;
        Lenta[y-1][x-2] = 1;
        Lenta[y+2][x-1] = 1;
    }
    if(y == 6 && x == 7)
    {
        Lenta[y+1][x-2] = 1;
        Lenta[y-1][x-2] = 1;
        Lenta[y-2][x-1] = 1;
    }
    if(y == 1 && x == 1)
    {
        Lenta[y+1][x+2] = 1;
        Lenta[y-1][x+2] = 1;
        Lenta[y+2][x+1] = 1;
        Lenta[y+2][x-1] = 1;
    }
    if(y == 6 && x == 1)
    {
        Lenta[y+1][x+2] = 1;
        Lenta[y-1][x+2] = 1;
        Lenta[y-2][x+1] = 1;
        Lenta[y-2][x-1] = 1;
    }
    if(y == 1 && x == 6)
    {
        Lenta[y+1][x-2] = 1;
        Lenta[y-1][x-2] = 1;
        Lenta[y+2][x+1] = 1;
        Lenta[y+2][x-1] = 1;

    }
    if(y == 6 && x == 6)
    {
        Lenta[y+1][x-2] = 1;
        Lenta[y-1][x-2] = 1;
        Lenta[y-2][x+1] = 1;
        Lenta[y-2][x-1] = 1;
    }
    Lenta[y][x] = 2;
}
void SimetriskasSudeliojimas(int Masyvas[DYDIS][DYDIS])
{
    int i,j, n = 0;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            Masyvas[i][j] = n;
            n++;
        }
    }
    n = 0;
    for(i = 7; i > 3; i--)
    {
        for(j = 0; j < 4; j++)
        {
            Masyvas[j][i] = n;
            n++;
        }
    }
    n = 0;
    for(i = 0; i < 4; i++)
    {
        for(j = 7; j > 3; j--)
        {
            Masyvas[j][i] = n;
            n++;
        }
    }
    n = 0;
    for(i = 7; i > 3; i--)
    {
        for(j = 7; j > 3; j--)
        {
            Masyvas[i][j] = n;
            n++;
        }
    }
}
void Spausdinti(int Lenta[DYDIS][DYDIS])
{
    int i, j;
    for(i = 0; i < DYDIS; i++)
    {
        for(j = 0; j < DYDIS; j++)
        {
            printf("%d ", Lenta[i][j]);
        }
        printf("\n");
    }
}
void Isvalyti(int Lenta[DYDIS][DYDIS])
{
    int i, j;
    for(i = 0; i < DYDIS; i++)
    {
        for(j = 0; j < DYDIS; j++)
        {
            Lenta[i][j] = 0;
        }
    }
}
int ArkliuSudeliojimas(int Masyvas[DYDIS][DYDIS], int Lenta[DYDIS][DYDIS], int sk1, int sk2, int sk3)
{
    int t, u;
    for(t = 0; t < DYDIS; t++)
    {
        for(u = 0; u < DYDIS; u++)
        {
            if(sk1 == Masyvas[t][u])
            {
                Lenta[t][u] = 2;
            }
            if(sk2 == Masyvas[t][u])
            {
               Lenta[t][u] = 2;
            }
            if(sk3 == Masyvas[t][u])
            {
                Lenta[t][u] = 2;
            }
        }
    }
}
