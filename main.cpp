// AQUI VA EL MAIN

#include "types.h" //Guardamos los tipos
#include "functions.h" //Cabeceras de las funtiones
#include "constants.h" //Constantes

#include<stdio.h>

int main()
{
    int billetes[NUMERO_BILLETES];
    int premios[TOTAL_PREMIOS];
    int tu_billete;
    int num_decimos;
    int decimos;
    int numero;
    arrPremios contenedor_premios;
    arrPremios premios_grandes;

    fisherYates(billetes);
    randomizarPremios(premios);
    premios_emparejamientos(premios, billetes, &contenedor_premios, &premios_grandes);
    aproximaciones(&contenedor_premios, &premios_grandes);
    reintegros(&contenedor_premios, &premios_grandes);

    do
    {
        printf("--------= LOTERIA DE NAVIDAD =--------");
        printf("\nIntroduzca el número del billete: "); 
        scanf("%d", &tu_billete);
        
        printf("Introduzca el número de decimos: "); 
        scanf("%d", &num_decimos);

        imprimirPremio (buscar_premio(tu_billete, num_decimos, &contenedor_premios), decimos);

        printf("Pulse 1 para Salir o cualquier otro numero para introducir otro billete: ");
        scanf("%d", &numero);

    } while (numero != 1);
    
       

    

    return 0;
}