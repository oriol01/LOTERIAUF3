// AQUI VAN LAS DECLARACIONES DE LAS FUNCIONES
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
    char nomficher[LONGNOMCOLLA];

    FILE *fp;

    strcpy(nomficher, collaActual->nomcolla);
    strcat(nomficher,".dat");

    fp=fopen(nomficher,"wb");

    fwrite(&collaActual->ano,sizeof(int),1,fp);
    fwrite(&collaActual->numpersones,sizeof(int),1,fp);

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
    char nomficher[LONGNOMCOLLA];
  
    strcpy(nomficher, collaLectura->nomcolla);
    strcat(nomficher,".dat");

    fp=fopen(nomficher,"rb");

    fread(&collaLectura->ano, sizeof(int), 1, fp);
    fread(&collaLectura->numpersones,sizeof(int), 1, fp);

    for(int i=0;i<collaLectura->numpersones;i++)
    {
        /*
        fread(&len, sizeof(int), 1, fp);
        fread(&collaLectura->persones[i].nom,sizeof(char),len,fp);
        fread(&collaLectura->persones[i].numlot,sizeof(int),1,fp);
        fread(&collaLectura->persones[i].import,sizeof(int),1,fp);
        */
       fread(&collaLectura->persones[i],sizeof(struct persona),1,fp);
    }

    //La parte que viene a continuacion es para comprovar si lee correctamente la informacion.
    
    printf("Nom: %s\nAny: %d\nNumPers: %d\n", collaLectura->nomcolla, collaLectura->ano, collaLectura->numpersones);
   
    for(int i=0;i<collaLectura->numpersones;i++)
    {
        printf("Nom: [%s],NumLot: [%d],Import: [%d].\n", collaLectura->persones[i].nom, collaLectura->persones[i].numlot, collaLectura->persones[i].import);
    }

    

    fclose(fp);
    
};

void quitar_salto_de_linea(char * nombre){
    int len;
    int i;
    int final=0;

    for(i=0;nombre[i]!='\0'&&final!=0;i++){
        if(nombre[i]=='\n'){
            nombre[i]='\0';
            final++;
        }
    }
}