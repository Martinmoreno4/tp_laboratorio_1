#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "biblioteca.h"

/** \brief funcion que presenta una serie de opciones para elegir
 *
 * \return int devuelve el numero de opcion seleccionado
 *
 */
int menu();


int main()
{
    int operandoA = 0;
    int operandoB = 0;

    char seguir='s';
    char confirma ='s';

    int resultadoSuma=0;
    int resultadoResta=0;
    float resultadoDivision=0;
    int resultadoMultiplicacion=0;
    int resultadoFactorialA=0;
    int resultadoFactorialB=0;

    int statusA=0;
    int statusB=0;
    int ingresadoA=0;
    int ingresadoB=0;
    int statusDivision=0;
    int statusCuentas=0;

    do
    {
        switch(menu())
        {
        case 1:
            fflush(stdin);
            printf("introdusca el operando A\n");
            statusA=scanf("%d", &operandoA);
            while(statusA!=1)
            {
                fflush(stdin);
                printf("valor invalido, introdusca el operando A\n");
                statusA=scanf("%d", &operandoA);
            }
            ingresadoA=1;
            break;

        case 2:
            fflush(stdin);
            printf("introdusca el operando B\n");
            statusB=scanf("%d", &operandoB);
            while(statusB!=1)
            {
                fflush(stdin);
                printf("valor invalido, introdusca el operando B\n");
                statusB=scanf("%d", &operandoB);
            }

            ingresadoB=1;
            break;

        case 3:

            if(ingresadoA==1 && ingresadoB==1)
            {
                if(operandoB==0)
                {
                    statusDivision=0;
                }
                else
                {
                    resultadoDivision = division(operandoA,operandoB);
                    statusDivision=1;
                }
                fflush(stdin);
                resultadoSuma=sumar(operandoA,operandoB);
                resultadoResta=resta(operandoA,operandoB);
                resultadoMultiplicacion=multiplicacion(operandoA,operandoB);
                resultadoFactorialA=factorial(operandoA);
                resultadoFactorialB=factorial(operandoB);
                statusDivision=0;
                printf("\n Se han realizado correctamente las formulas\n");
                statusCuentas=1;
            }
            else
            {
                printf("no se an ingresado uno o dos de los operandos A y B\n");
            }

            break;

        case 4:
            if(statusCuentas==1)
            {
                printf("El resultado de %d+%d es: %d\n", operandoA, operandoB, resultadoSuma);
                printf("El resultado de %d-%d es: %d\n", operandoA, operandoB, resultadoResta);
                if(statusDivision==0)
                {
                    printf("No es posible dividir por cero");
                }
                else
                {

                    printf("El resultado de %d/%d es: %.2f\n", operandoA, operandoB, resultadoDivision);
                }
                printf("El resultado de %d*%d es: %d\n", operandoA, operandoB, resultadoMultiplicacion);
                printf("El factorial de %d es: %d y El factorial de %d es: %d\n", operandoA, resultadoFactorialA, operandoB, resultadoFactorialB);
            }
            else
            {
                printf("\n Error, las formulas no han sido realizadas,\n o a ocurrido un error con las mismas");
            }

            break;

        case 5:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("opcion invalida\n");
            break;
        }

        system("pause");
    }while(seguir=='s');

    return 0;

}

int menu()
{
    int opcion;
    system("cls");

    printf("1. Ingresar 1er operando (A=x)\n");
    printf("2. Ingresar 2do operando (B=y)\n");
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
