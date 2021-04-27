// AQUI VAN LAS CABECERAS DE LAS FUNCIONES
#include"types.h"

void fisherYates(int * arr); //Esta funcion rellena arr de ints [0, NUMERO_BILLETES) y luego los baraja usando el Algoritmo Fisher-Yates (Durstenfeld). https://es.wikipedia.org/wiki/Algoritmo_de_Fisher-Yates#Tabla_paso_a_paso_(implementaci%C3%B3n_Durstenfeld)
void randomizarPremios(int *arr); //Esta funcion rellena un arr de ints de longitud TOTAL_PREMIOS con premios seleccionados de manera aleatoria
void aproximaciones(arrPremios* contenedor_premios,  arrPremios* premios_grandes);
void pushPremio(arrPremios* contenedorPremios, int _billete, int _premio);
void premios_emparejamientos(int* premios, int* billetes, arrPremios* contenedorPremios, arrPremios* premiosGrandes);
void reintegros(arrPremios* contenedor_premios, arrPremios* premios_grandes);
premio buscar_premio (int tu_billete, int num_decimos, arrPremios* contenedorPremios);
void imprimirPremio (premio premio_a_imprimir, int decimos);

//cabeceras de las funciones del proyecto uf3
void cargarIdioma(char nombreIdioma[IDIOMA_MAX_LEN], char contenedorIdioma[NUM_FRASES][FRASES_MAX_LEN]);
void cargarIdioma(char contenedorIdioma[NUM_FRASES][FRASES_MAX_LEN]);