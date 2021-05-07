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
	SORTEO_UN_PREMIO
};