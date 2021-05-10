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
	EXIT = 5,
	INPUT = 0,
	IDIOMA = 4,
	COLLA = 3,
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
	SORTEO_UN_PREMIO
};

struct persona
{
    char nom[LONG_NOM_PERSONA];
    int numlot;
    int import;
};

struct colla
{
    struct persona persones[LONG_COLLA];
    int ano;
    int numpersones=0;
	int import_total;
    char nomcolla[LONG_NOM_COLLA];
};