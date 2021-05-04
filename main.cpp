// AQUI VA EL MAIN

#include "types.h" //Guardamos los tipos
#include "functions.h" //Cabeceras de las funtiones
#include "constants.h" //Constantes

#include<stdio.h>

int main()
{
    int menu;
    int ano;

    arrPremios contenedor_premios;
    char idioma[NUM_FRASES][FRASES_MAX_LEN];
    int tu_billete;
    int num_decimos;
    int decimos;


    cargarIdioma(idioma);

    // do
    // {
    //     printf("--------= LOTERIA DE NAVIDAD =--------");
    //     printf("\nIntroduzca el número del billete: "); 
    //     scanf("%d", &tu_billete);
        
    //     printf("Introduzca el número de decimos: ");
    //     scanf("%d", &num_decimos);

    //     printf("En que año tuvo lugar el sorteo?: ");
    //     scanf("%d", &ano);


    //     imprimirPremio (buscar_premio(tu_billete, num_decimos, &contenedor_premios), decimos);

    //     printf("Pulse 1 para Salir o cualquier otro numero para introducir otro billete: ");
    //     scanf("%d", &menu);

    // } while (menu != 1);
    
    cargarSorteo(&contenedor_premios, "test");

    return 0;
}