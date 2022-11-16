#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x,y;
} nebun; //definire nebun ca o colectie de x,y, x=linie, y=coloana
int dp(nebun v[],int i,int m)
{
    int k;
    for (k=0; k<m-1; k++)
    {
        if (v[i].x==v[i].y+k)
            return k; //daca e deasupra diagonalei principale
        if (v[i].x==v[i].y-k)
            return -k; //daca e dedesubtul diagonalei principale
    }
    //verifica daca doi nebuni sunt pe aceeasi diagonala stanga-dreapta
}
int ds(nebun v[],int i,int m)
{
    int k;
    for (k=0; k<m-1; k++)
    {
        if (v[i].x+v[i].y==m-1+k)
            return k; //daca e deasupra diagonalei secundare
        if (v[i].x+v[i].y==m-1-k)
            return -k; //daca e dedesubtul diagonalei secundare
    }
    //verifica daca doi nebuni sunt pe aceeasi diagonala dreapta-stanga
}
int atac(nebun v[],int m,int i,int j)
{
    if ((dp(v,i,m)==dp(v,j,m))||(ds(v,i,m)==ds(v,j,m)))
        return 1; //daca sunt pe aceeasi diagonala=se ataca
    return 0;
}
int nr_atac(nebun v[],int m,int n)
{
    int i,j,nr;
    nr=0;
    for (i=0; i<n-1; i++)
        for (j=i+1; j<n; j++)
            if (atac(v,m,i,j)==1)
                nr++; //numara cate perechi se ataca
    return nr;
}
int det_per(nebun v[],int m,int n)
{
    int i,j,nr;
    nr=0;
    for (i=0; i<n-1; i++)
        for (j=i+1; j<n; j++)
            if (atac(v,m,i,j)==1)
            {
                return i; //determina primul element din perechea care se ataca
            }
}
int main()
{
    int i,j,n,m,nr,p,a[101][101],ok,xx,yy,b,c;
    nebun v[101],aux;
    ok=0;
    scanf("%d%d",&m,&n);
    for (i=0; i<m; i++)
        for (j=1; j<m; j++)
            a[i][j]=0; //formez tabla de sah, initial nula, fara piese
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&b,&c);
        a[b][c]=1; //marchez locul ca fiind ocupat pe tabla
        v[i].x=b;
        v[i].y=c; //pun piesele pe linia si coloana corespunzatoare
        //ii pun pe nebuni intr-un vector/sir
    }
    nr=nr_atac(v,m,n); //numar cati se ataca si afisez
    printf("%d\n",nr);
    if (nr!=1) //daca nu s-au atacat numai o pereche
        printf("NU\n");
    else
    {
        //daca s-a atacat numai o pereche
        //caut un alt loc pentru ca primul sa nu se atace cu niciunul
        for(i=0; i<n-1; i++)
            p=det_per(v,m,n); //iau locatia primului din pereche care se ataca
            //mai precis rangul lui in vectorul de nebuni
            //asa il selectez
        for (xx=0; xx<m; xx++)
            for(yy=0; yy<m; yy++)
                if (a[xx][yy]==0) //daca am gasit spatiu liber
                {
                    a[xx][yy]=1; //se marcheaza ca ocupat
                    v[p].x=xx;
                    v[p].y=yy; //pun pionul selectat in acel loc
                    for(i=0; i<n; i++)
                        if (atac(v,m,i,p)==0)//daca de acolo nu ataca pe nimeni
                            ok=1; //atunci am gassit alternativa
                }
        if (ok==0) //daca nu am gasit alternativa
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}
