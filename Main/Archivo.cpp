#include "Archivo.h"

/*void agregarExpediente(String nomArch, Expediente pExp)
{
    FILE * f = fopen(nomArch, "ab");
    fwrite(&entero, sizeof(int), 1, f);
    fclose(f);
}

boolean existe(String nomArch)
{
    boolean resultado = FALSE;

    FILE * f = fopen(nomArch, "rb");

    if(f==NULL)
        resultado =  FALSE;
    else
       {
         resultado =  TRUE;
         fclose(f);
       }

    return resultado;
}

boolean Vacio (String nomArch)
//El archivo debe existir
{
    boolean resultado = FALSE;
    FILE * f = fopen(nomArch, "rb");
    int entero;

    fread(&entero, sizeof(int), 1, f);
    if(feof(f))
       resultado = TRUE;

    fclose(f);

    return resultado;
}

boolean Pertenece (String nomArch, int entero)
{
    boolean encontrado = FALSE;
    int aux;

    FILE * f = fopen (nomArch, "rb");
    fread(&aux, sizeof(int), 1, f);

    while(!feof(f) && !encontrado)
    {
        if(aux==entero)
            encontrado = TRUE;
        else
        {
            fread(&aux, sizeof(int), 1, f);
        }
    }
    fclose(f);
    return encontrado;
}


/*int Largo (String nomArch)
{
    int contador = 0;
    int entero;

    FILE * f = fopen(nomArch, "rb");
    fread(&entero, sizeof(int), 1, f);

    while(!feof(f))
    {
        contador ++;
        fread(&entero, sizeof(int), 1, f);
    }

    fclose(f);
    return contador;
}


int Largo (String nomArch)
{
    FILE * f = fopen(nomArch, "rb");
    fseek(f, 0, SEEK_END);
    long tam = ftell (f);


    fclose(f);
    return (tam/sizeof(int));
}


int Kesimo (String nomArch, int k)
{
    int entero;

    FILE * f = fopen(nomArch, "rb");
    fseek(f, (k-1)*sizeof(int), SEEK_SET);
    fread(&entero, sizeof(int), 1, f);

    fclose(f);

    return entero;

}
*/
