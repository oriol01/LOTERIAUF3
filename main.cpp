// AQUI VA EL MAIN

#include "types.h" //Guardamos los tipos
#include "functions.h" //Cabeceras de las funtiones
#include "constants.h" //Constantes

#include<stdio.h>

int main()
{
    //TODO implementar las frases para collas
    //TODO separar push colla en las funciones correspondientes
    //TODO menu

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

    int masGente=1;
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
            scanf("%s", idiomaUser);
            
            if(cargarIdioma(idioma, idiomaUser) == false)
            {
                printf("Error al introducir el idioma, error al introduïr l'idioma / Error when inputting the lenguage\n"); //IDIOMA_ERR
                menu = IDIOMA;
                break;
            }
                
            menu = INPUT;
            break;

        case GUARDAR_COLLA:
            final=1;
            while(final){
                printf("Introdueix el nom de la colla: ");
                fgets(collaActual.nomcolla, LONG_NOM_COLLA, stdin);

                if(checkUnique(collaActual.nomcolla))
                {
                    printf("El nom introduït ja existeix, torna a intentar-ho.\n");
                    final=0;
                }
                else
                {
                    printf("A quin any esta participant aquesta colla? ");
                    scanf("%d" , &collaActual.ano);
                    getchar();
                    pushPersona(&collaActual);
                    printf("Vols introduïr una altra colla? S/N\n");
                    scanf("%c" , &sino);
                    switch (sino)
                    {
                    case 'n':
                        final=0;
                    case 'N':
                        final=0;  
                    default:
                        break;
                    }
                }
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


            printf("Introdueïx el nom de la colla que vols llegir: ");
            fgets(collaActual.nomcolla, LONG_NOM_COLLA, stdin);
			quitarSalto(collaActual.nomcolla);

            if(leerColla(&collaActual))
            {
                //MOSTRAR POR PANTALLA
                    //PREGUNTAR SI EXTRA GENTE
                        //Y
                            //INTRODUCIR EXTRA GENTE
            }
            else
            {
                //INTRODUCIR EXTRA GENTE
                    //GUARDAR
                    //MOSTRAR
                    //PREGUNTAR SI MAS

            }

            leerColla(&collaActual);
            menu=INPUT;
            break;
        /*
        case PUSH_PERSONA:
            printf("Introduce el nombre de la colla en el que quieres introducir una persona: ");
            fgets(collaActual.nomcolla, LONG_NOM_COLLA, stdin);
            pushPersona(&collaActual);
            menu=INPUT;
            break;
        */
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
                    // Premio vacío.
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
                    
                    // 2. Décimos.
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
            break;
        }
    } while (menu != EXIT);
    
    return 0;
}