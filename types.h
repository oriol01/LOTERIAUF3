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
	EXIT,
	INPUT,
	IDIOMA,
	COLLA,
	SORTEO
};