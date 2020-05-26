#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define ctoi(a) (a - 48)

#include "C:\Users\54112\Desktop\Ejercicios en C\dinamica\pila.h"

int main()
{
    tPila pila1, pila2, pila3;
    char num[31];
    int n;
    printf("Ingresar numero de maximo 30 caracteres: \n");
    gets(num);

    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&pila3);
    for(int i = 0; i < strlen(num); i++)
    {
        n = (int)ctoi(num[i]);
        ponerEnPila(&pila1, &n, sizeof(n));
    }

    printf("Ingresar otro numero de maximo 30 caracteres: \n");
    gets(num);

    for(int j = 0; j< strlen(num);j++)
    {
        n = (int)ctoi(num[j]);
        ponerEnPila(&pila2, &n, sizeof(n));
    }

    sumarPilas(&pila1, &pila2, &pila3);
    mostrarPila(&pila3);
    return 0;
}

/*Funciones de Main*************************************************/
void mostrarPila(tPila *p)
{
    int n;
    if(pilaVacia(p))
        puts("\nVACIO\n");
    puts("\nMostrando Pila...\n");
    while(sacarDePila(p, &n, sizeof(n)))
    {
        printf("%d", n);
    }

}

void sumarPilas(tPila *p1, tPila *p2, tPila* p3)
{
    int n, m, r;
    if(!pilaVacia(p3))
        vaciarPila(p3);
    while(!pilaVacia(p1))
    {
        sacarDePila(p1, &n, sizeof(int));
        sacarDePila(p2, &m, sizeof(int));

        r = n + m;
        ponerEnPila(p3, &r, sizeof(int));
    }
}
