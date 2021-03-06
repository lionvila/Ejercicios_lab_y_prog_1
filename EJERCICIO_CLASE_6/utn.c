#include <stdio.h>
#include <stdlib.h>

int isValidInt(int numero,int max,int min)
{
    if(numero<=max && numero>=min)
    {
        return 1;
    }
    return 0;
}

int getInt(char *mensaje,char *mensajeError,int minimo,
            int maximo,int reintentos,int *resultado)
{
    int buffer;
    int retorno=-1;
    if(mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%d",&buffer);
            if(isValidInt(buffer,maximo,minimo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    else
    {
        printf("%s",mensajeError);
    }
    return retorno;
}
int isValidFloat(float numero,float max,float min)
{
    if(numero<=max && numero>=min)
    {
        return 1;
    }
    return 0;
}

int getFloat(char *mensaje,char *mensajeError,float minimo,float maximo,int reintentos,float *resultado)
{
    int retorno=-1;
    float buffer;
    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer,maximo,minimo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char caracter,char min,char max)
{
    if(caracter<=max && caracter>=min)
    {
        return 1;
    }
    return 0;
}
int getChar(char *mensaje,char *mensajeError,char minimo,char maximo,int reintentos,char *resultado)
{
    int retorno=-1;
    char buffer;
    if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            //__fpurge(stdin);
            scanf("%c",&buffer);
            if(isValidChar(buffer,minimo,maximo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
void mostrarArrayInt(int *array,int limite)
{
    if(array!=NULL && limite>0)
    {
        for(int i=0;i<limite;i++)
        {
            printf("%d",array[i]);
        }
    }
}
void burbujeoArrayInt(int *array,int limite)
{
    int i;
    int buffer;
    for(int j=0;j<limite;j++)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i]>array[i+1])
            {
                buffer=array[i];
                array[i]=array[i+1];
                array[i+1]=buffer;
            }
        }
    }
}
/*int getNombre(char *mensaje,char *mensajeError,int size,char *nombreResultado)
{
    int charIngresados;
    char bufferNombre[size];
    if(mensaje!=NULL && mensajeError!=NULL && size<1000)
    {
        printf("\n%s",mensaje);
        fgets(bufferNombre,sizeof(bufferNombre),stdin);
        charIngresados=strlen(bufferNombre);
        if(isValidNombre(bufferNombre,charIngresados)==1)
        {
            strncpy(nombreResultado,bufferNombre,size);
            return 0;
        }
        else
        {
            printf("\n%s",mensajeError);
            return -1;
        }
    }
    return 0;
}
int isValidNombre(char *nombre,int size)
{
    for(int i=0;i<=size;i++)
    {
        if((nombre[i]>='a' && nombre[i]<='z')||
            (nombre[i]>='A' && nombre[i]<='Z'))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}*/
