// AQUI VAN LAS DEFINICIONES DE LOS TIPOS
#pragma once
#include"constants.h"


struct premio
{
	int billete;
	int premios_billete[NUMERO_PREMIOS_POR_BILLETE];
	int numPremios = 0;
	bool premioGrande = false;
};

struct arrPremios
{
	premio arr[NUMERO_BILLETES];
	int len = 0;
};

enum menu{
	EXIT = 4,
	INPUT = 0,
	IDIOMA = 3,
	COLLA = 2,
	SORTEO = 1
};

enum frases{
	MENU_SORTEO,
	MENU_COLLES,
	MENU_IDIOMA,
	MENU_EXIT,
	MENU_CHOOSE,
	SORTEO_ANO,
	SORTEO_BILLETE,
	SORTEO_DECIMOS,
	SORTEO_EXIT,
	ERROR,
	NO_PREMIADO,
	SORTEO_VARIOS_PREMIOS,
	SORTEO_UN_PREMIO,
	INTRODUCIR_NONBRE,
	INTRODUCIR_LOTERIA,
	INTRODUCIR_IMPORTE,
	INTRODUCIR_EXIT,
	RESULTS_CABECERA_SORTEO,
	RESULTS_CABECERA_PERSONAS,
	COLLES_INTRO_NOM,
	COLLES_INTRO_ANO
};

struct persona
{
    char nom[LONG_NOM_PERSONA];
    int numlot;
    int import;
	int premio;
};

struct colla
{
    struct persona persones[LONG_COLLA];
    int ano;
    int numpersones=0;
	int import_total;
    char nomcolla[LONG_NOM_COLLA];
};