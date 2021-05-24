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
    char idiomaUser[LONGITUD_IDIOMA];
    premio premio_a_imprimir;
    int tu_billete;
    int num_decimos;
    int decimos;

    int menu = IDIOMA;

    int masGente;
    int personasIntroducidas;
    char sino;
    int final;
    int importeCorrecto=0;
    colla collaActual;

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
            getchar();
            break;
        
        case IDIOMA: 
            //selector idioma
            printf("Seleccione el idioma: \n"); 
            printf("\tEspañol\n");
            printf("\tCatala\n");
            printf("\tEnglish\n");
            scanf("%s", idiomaUser);
            
            if(cargarIdioma(idioma, idiomaUser) == false)
            {
                printf("Error al introducir el idioma, error al introduïr l'idioma / Error when inputting the lenguage\n");
                menu = IDIOMA;
                break;
            }
                
            menu = INPUT;
            break;

        case COLLA:

            //PREGUNTAR NOMBRE, CHECKEAR EXISTENCIA
                //Y
                    //CARGARLO EN MEMORIA, CARGAR EN MEMORIA EL SORTEO DE ESE AÑO
                    //MOSTRAR POR PANTALLA
                    //PREGUNTAR SI EXTRA GENTE
                        //Y
                            //INTRODUCIR EXTRA GENTE
                        //N -> EXIT
                //N
                    //INTRODUCIR EXTRA GENTE
                    //GUARDAR
                    //MOSTRAR
                    //PREGUNTAR SI MAS


            printf("%s", idioma[COLLES_INTRO_NOM]); //COLLAS_INTRO_NOM 
            fgets(collaActual.nomcolla, LONG_NOM_COLLA, stdin);
			quitarSalto(collaActual.nomcolla);

            

            if(leerColla(&collaActual))
            {
                //MOSTRAR POR PANTALLA
                    //PREGUNTAR SI EXTRA GENTE
                        //Y
                            //INTRODUCIR EXTRA GENTE

                cargarSorteo(&contenedor_premios, collaActual.ano);
                printResults(&collaActual, &contenedor_premios, idioma);
                printf("%s", idioma[INTRODUCIR_EXIT]); //FRASES::COLLAS_MAS_GENTE
                //getchar();
                scanf("%d", &masGente);

                if(masGente == 1)//TODO bug, no te deja salir
                    while (introducirPersonas(&collaActual, idioma));
            }

            else
            {
                //INTRODUCIR EXTRA GENTE
                    //GUARDAR
                    //MOSTRAR
                    //PREGUNTAR SI MAS
                masGente = 1;
                printf("%s", idioma[COLLES_INTRO_ANO]);
                scanf("%d", &collaActual.ano);

                do{
                    while(introducirPersonas(&collaActual, idioma));
                    getchar();
                    printResults(&collaActual, &contenedor_premios, idioma);
                    printf("%s", idioma[INTRODUCIR_EXIT]);//COLLES_MAS_GENTE
                    scanf("%d", &masGente);
                } while (masGente != 0);
                    
            }

            guardarColla(&collaActual);
            menu=INPUT;
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

                premio_a_imprimir = buscar_premio(&contenedor_premios, tu_billete);
                if (premio_a_imprimir.numPremios == 0)
                {
                    // Premio vacCOLLES_INTRO_NOMío.
                    printf("%s \n", idioma[NO_PREMIADO]); //NO_PREMIADO
                } else
                {
                    // Premio lleno.
                    // 1. Sumar premios.
                    int sum = 0;
                    int billete_decimos;

                    for (int i = 0; i< premio_a_imprimir.numPremios; i++)
                    {
                        sum += premio_a_imprimir.premios_billete [i];
                    }
                    billete_decimos = sum*(decimos/10);

                    // 3. Imprimir.	
                    if (billete_decimos =! 10 && decimos >= 0)
                        printf("%s%d", idioma[SORTEO_VARIOS_PREMIOS], billete_decimos);//SORTEO_VARIOS_PREMIOS
                    
                    else
                        printf("%s%d",idioma[SORTEO_UN_PREMIO], billete_decimos); //SORTEO_UN_PREMIO
                }                
                    
                    
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
            menu = INPUT;
            break;
        }
    } while (menu != EXIT);
    
    return 0;
}