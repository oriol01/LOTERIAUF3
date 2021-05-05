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
            printf("%s\n", idioma[MENU_SORTEO]); //MENU_SORTEO
            printf("%s\n", idioma[MENU_COLLES]); //MENU_COLLES 
            printf("%s\n", idioma[MENU_IDIOMA]); //MENU_IDIOMA
            printf("%s\n", idioma[MENU_EXIT]);   //MENU_EXIT
            printf("%s\n", idioma[MENU_CHOOSE]); //MENU_CHOOSE
            scanf("%d", &menu);
            break;
        
        case IDIOMA:
            //selector idioma
            printf("Seleccione el idioma: \n"); 
            printf("\tEspañol\n");
            scanf("%s", idiomaUser);
            
            if(cargarIdioma(idioma, idiomaUser) == false)
            {
                printf("%s\n", idioma[IDIOMA_ERR]); //IDIOMA_ERR
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
                printf("%s\n", idioma[SORTEO_ANO]); //SORTEO_ANO
                anoPrevio = ano;
                scanf("%d", &ano);
                    //esta cargado ese ano
                        //Y -> nada
                        //N -> cargalo
                if(ano != anoPrevio)
                    cargarSorteo(&contenedor_premios, ano);
                
                printf("%s\n", idioma[SORTEO_BILLETE]); //SORTEO_BILLETE
                scanf("%d", &tu_billete);
                printf("%s\n", idioma[SORTEO_DECIMOS]); //SORTEO_DECIMOS
                scanf("%d", &decimos);

                imprimirPremio(buscar_premio(&contenedor_premios, tu_billete), decimos); //TODO OBSOLETO, IMPRIMIR EN MAIN
                
                printf("%s\n", idioma[SORTEO_EXIT]); //SORTEO_EXIT
                scanf("%d", &menu);
                //pedir billete
                //imprimir premios
            }
            while (menu != INPUT);

            
            break;
        default:
            //mensaje de error
            printf("%s\n", idioma[ERROR]); //ERROR
            break;
        }
    } while (menu != EXIT);
    
    return 0;
}