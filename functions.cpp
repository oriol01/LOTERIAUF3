﻿// AQUI VAN LAS DECLARACIONES DE LAS FUNCIONES
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include "constants.h"
#include "types.h"
#include "functions.h"



void fisherYates(int *arr)
{
    srand(time(NULL));

    for (int i = 0; i<NUMERO_BILLETES; i++)
        arr[i]=i;
    int num, tmp;

    for (int i = NUMERO_BILLETES-1; i >0; i--)
    {
        num= rand()%i;
        tmp = arr[num];
        arr[num] = arr[i];
        arr[i] = tmp;
    }
}

void randomizarPremios (int *arr)
{	
	int num_premios = TOTAL_PREMIOS;
	int numero_premio_m = TOTAL_M;
	int numero_premio_5 = TOTAL_60;
	int numero_premio_4 = TOTAL_200;
	int numero_premio_3 = TOTAL_3;
    int numero_premio_2 = TOTAL_2;
	int numero_premio_1 = TOTAL_1;

	
	srand(time (NULL));
					
			
	for (int i= num_premios;i>0;i--){
		int numero= rand()%i;
		
		if (numero<numero_premio_1){
			numero_premio_1--;
			arr[i-1] = PREMIO_1;
		}

		else if (numero<(numero_premio_1 + numero_premio_2)){
			numero_premio_2--;
	        arr[i-1] = PREMIO_2;
    	}

		else if (numero < (numero_premio_1 + numero_premio_2 + numero_premio_3))
		{
			numero_premio_3--;
	        arr[i-1] = PREMIO_3;
		}

		else if (numero<(numero_premio_1 + numero_premio_2 + numero_premio_m)){
			numero_premio_m--;
	        arr[i-1] = PREMIO_M;
		}
				
		else if (numero >= numero_premio_1 && numero<(numero_premio_2+numero_premio_1+numero_premio_m+numero_premio_5)){
			numero_premio_5--;
	        arr[i-1] = PREMIO_5;
		}

		else if(numero >= numero_premio_1+numero_premio_2+numero_premio_m+numero_premio_5 && numero <=  numero_premio_1+numero_premio_2+numero_premio_m+numero_premio_5+numero_premio_4){
			numero_premio_4--;
	        arr[i-1] = PREMIO_4;
		}
	}	
}

void aproximaciones(arrPremios* contenedor_premios,  arrPremios* premios_grandes)
{
	//Aproximaciones:
	premio Premio1 = premios_grandes->arr[0];
	premio Premio2 = premios_grandes->arr[1];
	premio Premio3 = premios_grandes->arr[2];

	pushPremio(contenedor_premios, Premio1.billete -1, APROXIMACION_1);
	pushPremio(contenedor_premios, Premio1.billete +1, APROXIMACION_1);

	pushPremio(contenedor_premios, Premio2.billete -1, APROXIMACION_2);
	pushPremio(contenedor_premios, Premio2.billete +1, APROXIMACION_2);

	pushPremio(contenedor_premios, Premio3.billete -1, APROXIMACION_3);
	pushPremio(contenedor_premios, Premio3.billete +1, APROXIMACION_3);
}

void reintegros(arrPremios* contenedor_premios, arrPremios* premios_grandes)
{
	int ultimosNumeros;
	int billete_a_crear;

	//DECENAS
	premio premiosGrandes[5];
	for (int i = 0; i < 5; i++)
	{
		premiosGrandes[i] = premios_grandes->arr[i];
	}

	//DOS ULTIMOS
	for(int i = 0; i<3; i++)
	{
		ultimosNumeros = premiosGrandes[i].billete % 100;
		for(int j= 0; j < 3333; j++)
		{
			billete_a_crear = j*100+ultimosNumeros;
			pushPremio(contenedor_premios, billete_a_crear, REINTEGRO_2_CIFRAS);
		}
	}

	//REINTEGRO
	ultimosNumeros = premiosGrandes[0].billete % 10;
	
	for(int i= 0; i < 2997; i++)
	{
		billete_a_crear = i*10+ultimosNumeros;
		pushPremio(contenedor_premios, billete_a_crear, REINTEGRO);
	}

	//CENTENAS
	for (int j = 0; j < 3; j++)
	{
		int primeros_numeros = premiosGrandes[j].billete/100;
		for (int i = 0; i < 99; i++)
		{
			billete_a_crear=primeros_numeros*100+i;
			pushPremio(contenedor_premios, billete_a_crear, CENTENAS);
		}
	}

	for (int j = 3; j < 5; j++)
	{
		int primeros_numeros = premiosGrandes[j].billete/100;
		for (int i = 0; i < 99; i++)
		{
			billete_a_crear=primeros_numeros*100+i;
			pushPremio(contenedor_premios, billete_a_crear, CENTENAS);
		}
	}
}

void pushPremio(arrPremios* contenedorPremios, int _billete, int _premio)
{
	int i = 0;
	bool checkPremio = false;

	while (!checkPremio && i < contenedorPremios->len)
	{
		if (contenedorPremios->arr[i].billete == _billete)
			checkPremio = true;
		else
			i++;
	}

	if (checkPremio) // si esta añadir el premio a ese billete
	{
		if(contenedorPremios->arr[i].premioGrande == false)
		{
			contenedorPremios->arr[i].premios_billete[contenedorPremios->arr[i].numPremios] = _premio;
			contenedorPremios->arr[i].numPremios++;
		}

	}

	else // si no añadir un premio nuevo a premios con el premio nuevo
	{
		premio tmp;
		tmp.billete = _billete;
		tmp.numPremios = 1;
		tmp.premios_billete[0] = _premio;
		
		contenedorPremios->arr[contenedorPremios->len] = tmp;
		contenedorPremios->len++;
	} 
}

void premios_emparejamientos(int* premios, int* billetes, arrPremios* contenedorPremios, arrPremios* premiosGrandes)
{
	for (int i = 0; i < TOTAL_PREMIOS; i++) 
	{
		int premios4 = 0;

		contenedorPremios->arr[i].billete = billetes[i];
		contenedorPremios->arr[i].premios_billete[0] = premios[i];
		contenedorPremios->arr[i].numPremios = 1;
		contenedorPremios->len++;
		contenedorPremios->arr[i].premioGrande = true;

		switch (premios[i])
		{
		case PREMIO_1:
			premiosGrandes->arr[0].billete = billetes[i];
			premiosGrandes->arr[0].premios_billete[0] = PREMIO_1;
			premiosGrandes->arr[0].numPremios = 1;

			break;
		
		case PREMIO_2:
			premiosGrandes->arr[1].billete = billetes[i];
			premiosGrandes->arr[1].premios_billete[0] = PREMIO_2;
			premiosGrandes->arr[1].numPremios = 1;

			break;

		case PREMIO_3:
			premiosGrandes->arr[2].billete = billetes[i];
			premiosGrandes->arr[2].premios_billete[0] = PREMIO_3;
			premiosGrandes->arr[2].numPremios = 1;

			break;

		case PREMIO_4:
			premiosGrandes->arr[2+premios4].billete = billetes[i];
			premiosGrandes->arr[2+premios4].premios_billete[0] = PREMIO_3;
			premiosGrandes->arr[2+premios4].numPremios = 1;
			premios4++;

			break;

		default:
			break;
		}
	}
}

premio buscar_premio (arrPremios* contenedorPremios, int tu_billete)
{
	int i = 0;
	bool encontrado = false;

	while (i < TOTAL_PREMIOS && !encontrado)
	{
		if (contenedorPremios->arr[i].billete == tu_billete)
			encontrado = true;
		
		else
			i++;	
	}		
	if (encontrado)
		return contenedorPremios->arr[i];

	else 
	{
		premio premio_vacio;
		premio_vacio.billete = tu_billete;

		return premio_vacio;
	}
}

void imprimirPremio (premio premio_a_imprimir, int decimos)
{
	if (premio_a_imprimir.numPremios == 0)
	{
		// Premio vacío.
		printf("Tu número no ha sido premiado ;( \n"); //NO_PREMIADO
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
			printf("La suma total de los decimos premiados es: %d", billete_decimos);//SORTEO_VARIOS_PREMIOS
		
		else
			printf("Tu premio es %d", billete_decimos); //SORTEO_UN_PREMIO
	}
}

bool cargarIdioma(char contenedorIdioma[NUM_FRASES][FRASES_MAX_LEN], char idioma[LONGITUD_IDIOMA]) //todo
{
	char direccion[LONGITUD_DIRECCION] = "docs/text_files/";
	strcat(direccion, idioma);
	strcat(direccion, ".txt");
	
	FILE *myTestFile;
	
    int j = 0;
    char tmp;
    bool eol;

    //bucle que ejecuta hasta EOF (facil con fgetc(returna EOF al llegar al EOF))
    //guardas en tmp el caracter y compruebas si es nuestra marca:
    //si es nuestra marca pasa a la siguiente frase
    //si no es nuestra marca escribe en el array de frase


	if(myTestFile = fopen(direccion, "r"))
	{
		for (int i = 0; i < NUM_FRASES; i++)
		{
			j = 0;
			eol = false;
			while (!eol)
			{
				tmp = fgetc(myTestFile);
				eol = tmp == '\n';

				if(!eol)
				{
					contenedorIdioma[i][j] = tmp;
					j++;
				}
			}
		}

		fclose(myTestFile);
		return true;
	}

		return false;
}

void crearSorteo(arrPremios *contenedor_premios)
{
	int billetes[NUMERO_BILLETES];
    int premios[TOTAL_PREMIOS];
    arrPremios premios_grandes;

	fisherYates(billetes);
    randomizarPremios(premios);
    premios_emparejamientos(premios, billetes, contenedor_premios, &premios_grandes);
    aproximaciones(contenedor_premios, &premios_grandes);
    reintegros(contenedor_premios, &premios_grandes);
}

void cargarSorteo(arrPremios *contenedor_premios, int ano)
{
	//comprobar si existe
	char direccion[LONGITUD_DIRECCION] = "docs/bin_files/sorteos";
	char anoToString[LONGITUD_DIRECCION];

	sprintf(anoToString, "%d", ano);

	strcat(direccion, anoToString);
	strcat(direccion, ".dat");

	FILE* sorteo;

	if(sorteo = fopen(direccion, "rb"))
	{
		//EL ARCHIVO EXISTE ASI QUE LEELO
		int tmp;
		int i = 0;
		int j = 0;
		bool primerNumero = true;

		while(fread(&tmp, sizeof(int), 1, sorteo))
		{
			fread(&tmp, sizeof(int), 1, sorteo);
			//numBillete=i, numPremio=j, flagBillete=priemerNumero
			
			//-1 nos avanza al siguiente billete
				//j=0, i++
			if(tmp == MARCA_SEPARACION)
			{
				j=0;
				i++;
				primerNumero = true;
			}
			//el primer dato es el billete
			else if(primerNumero)
			{
				contenedor_premios->arr[i].billete=tmp;
				contenedor_premios->len++;
				primerNumero = false;
			}
			else
			{	
				contenedor_premios->arr[i].premios_billete[j] = tmp;
				contenedor_premios->arr[i].numPremios++;
				j++;
			}
		}
		
		fclose(sorteo);
	}
	else
	{
		//EL ARCHIVO NO EXISTE CREA EL SORTEO, CARGALO EN MEMORIA, CREA EL ARCHIVO
		crearSorteo(contenedor_premios);
		
		//crearlo en memoria
		guardarSorteo(contenedor_premios, anoToString);
	}
}

void guardarSorteo(arrPremios *contenedor_premios, const char *ano)
{
	const int marcaSeparacion = MARCA_SEPARACION;

	char direccion[LONGITUD_DIRECCION] = "docs/bin_files/sorteos/";
	strcat(direccion, ano);
	strcat(direccion, ".dat");

	//CREAR ARCHIVO
	FILE* newFile = fopen(direccion, "wb");

	//LOOPEAR POR contenedor_premios imprimiendo en el archivo
	for (int i = 0; i < contenedor_premios->len; i++)
	{
		//push premio
		fwrite(&contenedor_premios->arr[i].billete, sizeof(int), 1, newFile);

		for(int j = 0; j < contenedor_premios->arr[i].numPremios; j++)
		{
			fwrite(&contenedor_premios->arr[i].premios_billete[j], sizeof(int), 1, newFile);
		}
		fwrite(&marcaSeparacion, sizeof(int), 1, newFile);
	}

	fclose(newFile);
}

void guardarColla(colla *collaActual)
{
    int len;
    char nomficher[LONG_NOM_COLLA];

    FILE *fp;

	quitarSalto(collaActual->nomcolla);
    
	strcpy(nomficher, collaActual->nomcolla);
    strcat(nomficher,".dat");

    fp=fopen(nomficher,"wb");

    fwrite(&collaActual->ano,sizeof(int),1,fp);
    fwrite(&collaActual->numpersones,sizeof(int),1,fp);
    fwrite(&collaActual->import_total,sizeof(int),1,fp);


    for(int i=0;i<collaActual->numpersones;i++)
    {
        /*
        len=strlen(collaActual->persones[i].nom);
        fwrite(&len,sizeof(int),1,fp);
        fwrite(collaActual->persones[i].nom,sizeof(char),len,fp);
        fwrite(&collaActual->persones[i].numlot,sizeof(int),1,fp);
        fwrite(&collaActual->persones[i].import,sizeof(int),1,fp);
        */
       fwrite(&collaActual->persones[i],sizeof(struct persona),1,fp);
    }
    fclose(fp);
}

void leerColla(colla *collaLectura)
{
    FILE *fp;
    int len;
    char nomficher[LONG_NOM_COLLA];
	
    strcpy(nomficher, collaLectura->nomcolla);
    strcat(nomficher,".dat");
	

	if(fp=fopen(nomficher,"rb"))
	{

		fread(&collaLectura->ano, sizeof(int), 1, fp);
		fread(&collaLectura->numpersones,sizeof(int), 1, fp);
		fread(&collaLectura->import_total,sizeof(int),1,fp);

		for(int i=0;i<collaLectura->numpersones;i++)
		{
			/*
			fread(&len, sizeof(int), 1, fp);
			fread(&collaLectura->persones[i].nom,sizeof(char),len,fp);
			fread(&collaLectura->persones[i].numlot,sizeof(int),1,fp);
			fread(&collaLectura->persones[i].import,sizeof(int),1,fp);
			*/
			fread(&collaLectura->persones[i],sizeof(struct persona),1,fp);
			quitarSalto(collaLectura->persones[i].nom);

		}

		//La parte que viene a continuacion es para comprovar si lee correctamente la informacion.

		printf("Nom: %s\nAny: %d\nNumPers:%d \nImportTot:%d \n", collaLectura->nomcolla, collaLectura->ano, collaLectura->numpersones, collaLectura->import_total);
	
		for(int i=0;i<collaLectura->numpersones;i++)
		{
		//	quitar_Salto(collaLectura->persones[i].nom);
			printf("Nom: [%s],NumLot: [%d],Import: [%d].\n", collaLectura->persones[i].nom, collaLectura->persones[i].numlot, collaLectura->persones[i].import);
		}

		fclose(fp);
	}
	else
	{
		printf("No s'ha trobat la colla introduïda, si us plau torna a intentar-ho.\n");	
	}
	

};

void quitarSalto(char * nom){
	int i;
	int len=(strlen(nom));
	for(i=0;nom[i]!='\0'&&i<=len;i++){
		if(nom[i]=='\n'){
			nom[i]='\0';
			i=len;
		}
	}

}

void pushPersona(colla *collaActual)
{
	int correcto;
	int importeCorrecto;
	int masGente=1;
	char sino;
	char nomficher[LONG_NOM_COLLA];
    
	strcpy(nomficher, collaActual->nomcolla);
    strcat(nomficher,".dat");
	
	if(fopen(nomficher,"rb")){
	leerColla(collaActual);}

	while(masGente){
		correcto=0;
		importeCorrecto=0;
		printf("Introduce el nombre de la persona que quieres introducir: ");
		fgets(collaActual->persones[collaActual->numpersones].nom, LONG_NOM_PERSONA, stdin);
		printf("Introdueix el seu nº de loteria: ");
		scanf("%d" , &collaActual->persones[collaActual->numpersones].numlot);
		printf("Introdueix el seu import: ");
		scanf("%d" , &collaActual->persones[collaActual->numpersones].import);
			while(!importeCorrecto)
			{
				if(collaActual->persones[collaActual->numpersones].import%5!=0)
				{
					printf("Si us plau introdueix un import multiple de 5: ");
					scanf("%d" , &collaActual->persones[collaActual->numpersones].import);
				}
				else if((collaActual->persones[collaActual->numpersones].import>60)||(collaActual->persones[collaActual->numpersones].import<5))           // Checkeamos que el importe sea multiple de 5 como pide el enunciado
				{
					printf("Si us plau introdueix un import minim de 5 o maxim de 60: ");   //Checkeamos maximo y minimo del importe.
					scanf("%d" , &collaActual->persones[collaActual->numpersones].import);
				}
				else
				{
					collaActual->import_total+=collaActual->persones[collaActual->numpersones].import;
					importeCorrecto=1;
				}
			}
		getchar();
		printf("Vols introduïr una altra persona a aquesta colla? S/N\n");
		scanf("%c" , &sino);
		getchar();
		collaActual->numpersones++;
		if(sino=='n'||sino=='N')
		{
			masGente=0;
		}
	}
	guardarColla(collaActual);
}

int checkUnique(char nombre[LONG_NOM_COLLA])
{	FILE *fp;
	char nombrefichero[LONG_NOM_COLLA];
	strcpy(nombrefichero,nombre);
	quitarSalto(nombrefichero);
	strcat(nombrefichero,".dat");

	if(fp=fopen(nombrefichero,"rb"))
	{
		fclose(fp);
		return 1;
	}
	else
	{
		return 0;
	}	
}