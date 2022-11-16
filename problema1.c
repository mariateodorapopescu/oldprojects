#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pereche
{
    char cuv[102];
    double grad;
} mat[1001],aux; //aici se stocheaza cele doua cuvinte si gradul lor
void vector_litere(char *s,int v[])
{
    int i;
    for (i=0; i<strlen(s); i++)
        v[(int)s[i]]++;
        //ajuta la formarea unui vector caracteristic de litere
}
void zeros(int a[])
{
    int i;
    for (i=0; i<124; i++)
        a[i]=0;
        //initializare vector caracteristic cu 0
}
int compare(int a[],int b[])
{
    int i,nr;
    nr=0;
    for (i=97; i<=122; i++)
        if (a[i]==b[i])
            nr++;
    if (nr==26)
        return 1;
    return 0;
    //verifica daca doi vectori caracteristici de litere sunt identici
}
int is_anagram(char *s1,char *s2)
{
    int a[124],b[124],i,ok;
    zeros(a);
    zeros(b);
    vector_litere(s1,a);
    vector_litere(s2,b);
    for (i=97; i<=122; i++)
        ok=compare(a,b);
    if (ok==0)
        return 0;
    else
        return 1;
        //verifica daca doi vectori caracteristici de litere sunt identici
}
double compute_grade(char *s1, char *s2)
{
    int i,j;
    double gr,nre,nrd;
    nre=0;
    nrd=0;
    if (is_anagram(s1,s2)==0)
        gr=-1; //daca nu au aceleasi litere, nu sunt anagrame
    else
    {
        for (i=0; i<strlen(s1); i++)
            if (s1[i]==s2[i])
                nre++;
                //daca au aceleasi litere,verifica pe cate pozitii sunt egale
        if (nre==strlen(s1))
            gr=0; ////daca pe pozitii egale sunt litere egale atunci gradul e 0
        else
        {
            for (i=0; i<strlen(s1); i++)
                if (s1[i]!=s2[i])
                    nrd++; //daca pe pozitii identice sunt litere diferite,
                    //numara cate litere difera
            if (nrd==strlen(s1))
                gr=1; //daca toate sunt diferite, gradul e 1
            else
                gr=nrd/strlen(s1); //daca nu, aceasta este formula de calcul
        }
    }
    return gr;
}
int main()
{
    char s1[51],s2[51],*a,*b,fin[1001][102],cpy[102];
    int i,j,N,k;
    k=0;
    scanf("%d",&N);
    for (i=0; i<N; i++)
    {
        scanf("%s",&s1);
        scanf("%s",&s2);
        strcpy(mat[k].cuv,s1);
        strcat(mat[k].cuv," ");
        strcat(mat[k].cuv,s2);
        k++; //facem o matrice de cuvinte
    }
    for (i=0; i<N; i++)
    {
        strcpy(cpy,mat[i].cuv);
        a=strtok(cpy," ");
        b=strtok(NULL," ");
        mat[i].grad=compute_grade(a,b); //adaugam gradul la fiecare pereche de cuvinte
    }
    for (i=0; i<N-1; i++)
        for (j=i+1; j<N; j++)
        {
            //se compara gradul unei perechi cu gradelele urmatoare, nu 2 cate 2
            if (mat[i].grad<mat[j].grad)
                //daca gradul de pe pozitia urmatoare e mai mic
            {
                strcpy(aux.cuv,mat[i].cuv);
                aux.grad=mat[i].grad; //se face schimb intre ele
                strcpy(mat[i].cuv,mat[j].cuv);
                mat[i].grad=mat[j].grad;
                strcpy(mat[j].cuv,aux.cuv);
                mat[j].grad=aux.grad;
            }
            /*luam un sir pereche-grad auxiliar care ne ajuta sa ordonam
            perechile in functie de gradul lor, in ordine descrescatoare
        */
        }
        //dupa ce s-a facut ordonarea dupa grad, facem si ordonarea lexicografica
    for (i=0; i<N-1; i++)
        for (j=i+1; j<N; j++)
        {
            //se selecteaza o pereche cu fiecare dupa ea si se verifica
            if (strcmp(mat[i].cuv,mat[j].cuv)<0&&mat[i].grad==mat[j].grad)
                /*daca perechile selectate au acelasi grad dar cuvintele
                nu sunt in ordine alfabetica*/
            {
                strcpy(aux.cuv,mat[i].cuv);
                aux.grad=mat[i].grad;
                strcpy(mat[i].cuv,mat[j].cuv);
                mat[i].grad=mat[j].grad;
                strcpy(mat[j].cuv,aux.cuv);
                mat[j].grad=aux.grad;
            /*se schimba intre ele cu ajutorul unui sir auxiliar,
            conservandu-se ordinea gradelor (asta si cerea conditia, sa aiba acelasi grad)*/
            }
        }
    for (i=0; i<N; i++)
        puts(mat[i].cuv); //apoi afiseaza rezultatul
    return 0;
}
