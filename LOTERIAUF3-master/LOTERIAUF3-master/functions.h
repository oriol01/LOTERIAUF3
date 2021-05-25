// AQUI VAN LAS CABECERAS DE LAS FUNCIONES
#include"types.h"

void fisherYates(int * arr); //Esta funcion rellena arr de ints [0, NUMERO_BILLETES) y luego los baraja usando el Algoritmo Fisher-Yates (Durstenfeld). https://es.wikipedia.org/wiki/Algoritmo_de_Fisher-Yates#Tabla_paso_a_paso_(implementaci%C3%B3n_Durstenfeld)
void randomizarPremios(int *arr); //Esta funcion rellena un arr de ints de longitud TOTAL_PREMIOS con premios seleccionados de manera aleatoria
void aproximaciones(arrPremios* contenedor_premios,  arrPremios* premios_grandes);
void pushPremio(arrPremios* contenedorPremios, int _billete, int _premio);
void premios_emparejamientos(int* premios, int* billetes, arrPremios* contenedorPremios, arrPremios* premiosGrandes);
void reintegros(arrPremios* contenedor_premios, arrPremios* premios_grandes);
premio buscar_premio (arrPremios* contenedorPremios, int tu_billete);
void imprimirPremio (premio premio_a_imprimir, int decimos);

//cabeceras de las funciones del proyecto uf3
bool cargarIdioma(char contenedorIdioma[NUM_FRASES][FRASES_MAX_LEN], char idioma [100]);
void crearSorteo(arrPremios *contenedor_premios);
void cargarSorteo(arrPremios *contenedor_premios, int ano);
void guardarSorteo(arrPremios *contenedor_premios, const char *ano);
void guardarColla(colla *collaActual);
bool leerColla(colla *collaLectura);
void quitarSalto(char * nom);
void pushPersona(colla *collaActual, char _nombre[LONG_NOM_PERSONA], int _numlot, int _import);
int checkUnique(char nombre[LONG_NOM_COLLA]); //TODO haz que sea un bool
void pushPersona(colla *collaActual, char _nombre[LONG_NOM_PERSONA], int _numlot, int _import);
bool introducirPersonas(colla *collaActual);
void printResults(colla *collaActual, arrPremios *numsPremios);
int sumaPremios(arrPremios *contenedor_premios, int billete);

