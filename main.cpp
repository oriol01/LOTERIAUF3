// AQUI VA EL MAIN

#include "types.h" //Guardamos los tipos
#include "functions.h" //Cabeceras de las funtiones
#include "constants.h" //Constantes

#include<stdio.h>

int main()
{
    int ano = -1;
    int anoPrevio;

    arrPremios contenedor_premios;
    char idioma[NUM_FRASES][FRASES_MAX_LEN];
    int tu_billete;
    int num_decimos;
    int decimos;

    int menu = IDIOMA;

    do
    {
        switch (menu)
        {
        case INPUT:
            //seleccion de opcion del menu
            break;
        
        case IDIOMA:
            //selector idioma
            menu = SORTEO;
            break;

        case COLLA:
            //menu colla
            break;
        
        case SORTEO:
            //loop pedir billete
            do
            {
                //pedir ano
                printf("introduzca el ano: ");
                anoPrevio = ano;
                scanf("%d", &ano);
                    //esta cargado ese ano
                        //Y -> nada
                        //N -> cargalo
                if(ano != anoPrevio)
                    cargarSorteo(&contenedor_premios, ano);
                
                printf("introduzca un billete: ");
                scanf("%d", &tu_billete);
                printf("introduzca los decimos: ");
                scanf("%d", &decimos);

                imprimirPremio(buscar_premio(&contenedor_premios, tu_billete), decimos);
                
                printf("Introduzca 1 para salir: ");
                scanf("%d", &menu);
                //pedir billete
                //imprimir premios
            }
            while (menu != INPUT);

            
            break;
        default:
            //mensaje de error
            printf("Error, opcion introducida inexistente, vuelva a introducir la opcion");
            break;
        }
    } while (menu != EXIT);
    
    return 0;
}