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
    char idiomaUser[100];
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
            printf("1: SORTEO\n"); //MENU_SORTEO
            printf("2: COLLES\n"); //MENU_COLLES 
            printf("3: IDIOMA\n"); //MENU_IDIOMA
            printf("4: EXIT\n");   //MENU_EXIT
            printf("Elige un modo:\n"); //MENU_CHOOSE
            scanf("%d", &menu);
            break;
        
        case IDIOMA:
            //selector idioma
            printf("Seleccione el idioma: \n"); //IDIOMA_SELECT
            printf("\tEspañol\n");
            scanf("%s", idiomaUser);
            
            if(cargarIdioma(idioma, idiomaUser) == false)
            {
                printf("idioma elegido inexistente, selecciome idioma de nuevo\n"); //IDIOMA_ERR
                menu = IDIOMA;
                break;
            }
                
            menu = INPUT;
            break;

        case COLLA:
            //menu colla
            break;
        
        case SORTEO:
            //loop pedir billete
            do
            {
                //pedir ano
                printf("introduzca el ano: "); //SORTEO_ANO
                anoPrevio = ano;
                scanf("%d", &ano);
                    //esta cargado ese ano
                        //Y -> nada
                        //N -> cargalo
                if(ano != anoPrevio)
                    cargarSorteo(&contenedor_premios, ano);
                
                printf("introduzca un billete: "); //SORTEO_BILLETE
                scanf("%d", &tu_billete);
                printf("introduzca los decimos: "); //SORTEO_DECIMOS
                scanf("%d", &decimos);

                imprimirPremio(buscar_premio(&contenedor_premios, tu_billete), decimos); //TODO OBSOLETO, IMPRIMIR EN MAIN
                
                printf("Introduzca 0 para salir: "); //SORTEO_EXIT
                scanf("%d", &menu);
                //pedir billete
                //imprimir premios
            }
            while (menu != INPUT);

            
            break;
        default:
            //mensaje de error
            printf("Error, opcion introducida inexistente, vuelva a introducir la opcion"); //ERROR
            break;
        }
    } while (menu != EXIT);
    
    return 0;
}