#include "string.h"
#include "boolean.h"

void strcrear (String &s)
{
    s = new char[1];
    s[0] = '\0';
}

void strdestruir (String &s)
{
    delete [] s;
    s = NULL;
}

void scan (String &s)
{
    String vAux = new char[MAX];
    int i=0;
    char c;
    fflush(stdin);
    scanf ("%c", &c);
    while (c!= '\n' && i < MAX-1)
    {
        vAux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    vAux[i] = '\0';
    strcop (s,vAux);
    strdestruir (vAux);
}

void print (String s)
{
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

boolean streq(String s1,String s2)
{
    int i = 0;
    boolean vIguales = TRUE;
    while (vIguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            vIguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        vIguales = FALSE;

    return vIguales;
}

void strcop (String &s1,String s2)
{
    int i = 0;
    int vLargo = strlar(s2) + 1;
    delete [] s1;
    s1 = new char[vLargo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

int strlar (String s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void agregarStringAArchivo(String s, FILE * f)
{
    int i = 0;
    while(s[i] != '\0')
    {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, f);
}

void leerStringDeArchivo (String &s, FILE * f)
{
    int i=0;
    String vAux;
    vAux = new char[MAX];
    fread(&vAux[i], sizeof(char), 1, f);
    while(!feof(f) && (vAux[i] != '\0'))
    {
        i++;
        fread(&vAux[i], sizeof(char), 1, f);
    }
    strcop (s, vAux);
    delete [] vAux;
}
