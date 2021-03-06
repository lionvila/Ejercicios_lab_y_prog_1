#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "utn.h"

Persona* Per_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* Per_newStr(char *id,char *nombre,char *apellido,char *estado)
{
	Persona* retorno=NULL;
	Persona* pAuxPersona;
	if(id!=NULL &&
	   nombre!=NULL &&
	   apellido!=NULL &&
	   estado!=NULL)
	{
		pAuxPersona=Per_new();
		if(pAuxPersona!=NULL)
		{
			if(	!Per_setNombre(pAuxPersona,nombre)&&
				!Per_setApellido(pAuxPersona,apellido)&&
				!Per_setIdStr(pAuxPersona,id)&&
				!Per_setEstadoStr(pAuxPersona,estado))
			{
				retorno=pAuxPersona;
			}
			else
			{
				Per_delete(pAuxPersona);
			}
		}
	}
	return retorno;
}

int Per_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}
int Per_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && !isValidInt(id,sizeof(id),0))
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int Per_setIdStr(Persona* this, char* id)
{
    int retorno = -1;
    if(this != NULL && !isValidNumber(id))
    {
        retorno = Per_setId(this,atoi(id));
    }
    return retorno;
}
int Per_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}
int Per_getIdStr(Persona* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        Per_getId(this,&bufferInt);
        sprintf(resultado,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}
int Per_setNombre(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidName(nombre)==0)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int Per_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int Per_setApellido(Persona* this,char* apellido)
{
	int retorno = -1;
    if(this != NULL && isValidName(apellido)==0)
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}
int Per_getApellido(Persona* this, char* resultado)
{
	int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}
int Per_setEstado(Persona* this, int estado)
{
    int retorno = -1;
    if(this != NULL && !isValidInt(estado,sizeof(estado),0))
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}
int Per_setEstadoStr(Persona* this, char* estado)
{
    int retorno = -1;
    if(this != NULL && estado!=NULL && !isValidNumber(estado))
    {
        retorno=Per_setEstado(this,atoi(estado));
    }
    return retorno;
}
int Per_getEstado(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}

int Per_parserPersonas(char* fileName,Persona* array,int size)
{
    int r;
    int qtyLineas=0;
    char aux[512];
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferEstado[4096];

    FILE* pFile=fopen(fileName,"r");
    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^\n]\n",aux);  //salteo la primer linea
        //fgets(aux,512,pFile);  //salteo la primer linea
        do
        {
            r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                        bufferNombre,
                                                        bufferApellido,
                                                        bufferEstado);
            if(r==4)
            {
                printf("%s,%s,%s,%s\n", bufferId,
                                    bufferNombre,
                                    bufferApellido,
                                    bufferEstado);
                qtyLineas++;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return qtyLineas;
}
int Per_initArray(Persona* arrayPer[],int lenPer)
{
    int i;
    int retorno=-1;
    if(arrayPer!=NULL&&lenPer>0)
    {
        for(i=0; i<lenPer; i++)
        {
            arrayPer[i]=NULL;
        }
        retorno=0;

    }
    return retorno;
}
/*int Per_sortName(Persona *this,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
		if(strncmp((this=i)->nombre,(this=i+1)->nombre,50)>0)
		{
			return 1;
		}
		else if(strncmp((this=i)->nombre,(this=i+1)->nombre,50)<0)
		{
			return 0;
		}
    }
}*/


