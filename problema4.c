#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void dec_to_bin(int n,char *s)
{
    int k,c,i,nr;
    char cv[8],nou[8];
    k=0; //cu for imi dadea eroare, asa ca, tinand cont ca sunt 8 valori
    //am scris manual
    s[0]=n%2+48;
    n=n/2;//deci, pentru un sir de caractere de dimensiune opt,impartim repetat
    //numarul n la 2, ca sa fie transformat in baza 2, opt biti
    //acesti biti se pun pe cate o pozitie din sirul de caractere
    s[1]=n%2+48;
    n=n/2;
    s[2]=n%2+48;
    n=n/2;
    s[3]=n%2+48;
    n=n/2;
    s[4]=n%2+48;
    n=n/2;
    s[5]=n%2+48;
    n=n/2;
    s[6]=n%2+48;
    n=n/2;
    s[7]=n%2+48;
    n=n/2;
    char ch[8];
    //totusi, transformarea in baza 2 se face incepand cu ultimul rest,
    //adica de la sfarsitul la inceputul algoritmului de impartire se
    //citesc cifrele din baza doi, asa ca trebuie sa inversez sirul creat
    //ca sa fie o transformare directa
    //din nou, aceasta se va face element cu element, pentru ca versiunea
    //cu for dadea eroare la executie
    //plus, nu sunt multe valori de inlocuit
    ch[0]=s[7];
    ch[1]=s[6];
    ch[2]=s[5];
    ch[3]=s[4];
    ch[4]=s[3];
    ch[5]=s[2];
    ch[6]=s[1];
    ch[7]=s[0];
    ch[8]='\0';
    strcpy(s,ch);
}
int bin_to_dec(char *s)
{
    int i,v[8],k,p,nr;
    k=0;
    p=1;
    nr=0;
    for (i=0; i<strlen(s); i++) /*aici ia sirul de caractere care are codificarea
        in binar a unui numar zecimal si, de la sfarsit la inceput fiecare*/
    {
        if(s[i]=='0')
            v[k++]=0;
        else if(s[i]=='1') //cifra care din caracter este transformata in int
            v[k++]=1; //se pune intr-un vector care contine cifrele din baza 2

    }
    for (i=k-1; i>=0; i--)
    {
        nr=nr+p*v[i]; /*se inmulteste fiecare cifra a numarului binar
        cu o putere de 2, si se aduna la o valoare initial nula;
        iar suma este numarul zecimal */
        p=p*2;
    }
    return nr;
}
void vect(char *s,int a[])
{
    int i,k,p;
    k=0;
    for (i=0; i<strlen(s); i++)
    {
        a[i]=s[i]-48; /*aici vectorul cu cifrele binare se trasforma in sir
        de caractere cu cifrele din baza 2 a numarului */
    }
}
void mat_string(int v[],char mat[][8])
{
    char s[8],nou[8];
    dec_to_bin(v[0],s); //rezolv pas cu pas pentru ca for-ul imi calcula gresit
    strcpy(mat[0],s); /*fiecare element din vectorul v citit de la tastatura
    se transforma in binar si se adauga succesiv la o matrice de siruri
    de caractere, ce contin numerele in binar, fiecare numar pe cate o linie*/
    dec_to_bin(v[1],s);
    strcpy(mat[1],s);
    mat[1][8]='\0';
    dec_to_bin(v[2],s);
    strcpy(mat[2],s);
    mat[2][8]='\0';
    dec_to_bin(v[3],s);
    strcpy(mat[3],s);
    mat[3][8]='\0';
    dec_to_bin(v[4],s);
    strcpy(mat[4],s);
    dec_to_bin(v[5],s);
    strcpy(mat[5],s);
    dec_to_bin(v[6],s);
    strcpy(mat[6],s);
    dec_to_bin(v[7],s);
    strcpy(mat[7],s);
}
void mat_create(char m[][8],int mat[][8])
{
    int i,j;
    for (i=0; i<8; i++)
        for(j=0; j<8; j++)
        {
            mat[i][j]=m[i][j]-48;//aici, din matrice char cu '0' si '1'
            /*transform in matrice int pentru a realiza operatii cu matrici
            aproximativ ca in liceu*/
        }
}
void transpose(int a[][8],int t[][8])
{
    int i,j;
    for (i=0; i<8; i++) //calcularea matricei transpuse
    {
        for (j=0; j<8; j++)
        {
            t[i][j]=a[j][i]; // fiecare coloana devine linie
        }
    }
}
void multiplication(int a[][8],int b[][8],int p[][8])
{
    int i,j,k,ceva;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            p[i][j]=0; //initial, matricea produs trebuie sa fie nula
            //pentru a putea calcula corect
            for(k=0; k<8; k++) /*se ia fiecare valoare pentru produsul
            elementul i1j1 de pe linie cu elementul i2j2 de pe coloana
            celilalte matrice*/
            {
                if (a[i][k]==1&&b[k][j]==1)
                {
                    ceva=1; // se ia fiecare posibilitate a produsului boolean
                }
                else
                {
                    ceva=0;
                }
                if (ceva==0&&p[i][j]==0)//dupa calcularea produselor se insumeaza
                {
                    p[i][j]=0; //tinand cont de regulile lui sau(+) boolean
                }
                else
                {
                    p[i][j]=1;
                }
            }
        }
    }
}
void apatrat(int a[][8],int p[][8])
{
    multiplication(a,a,p); //calculeaza matricea a^2
}
void ata(int a[][8],int p[][8])
{
    int t[8][8];
    transpose(a,t);
    multiplication(a,t,p); //calculeaza produsul matricelor a si a transpus
}
int verifc(int a[][8],int j,int zone)
{
    int i,nr,p,u;
    nr=0; //ajuta la calcularea valorilor de 1 de pe o coloana
    if (zone==1||zone==2) //se ia pe zone, conform cerintei din pdf
        //zona1=patrat rosu, zona2=patrat albastru
        //zona3=patrat galben, zona4=patrat verde
    {
        p=0; //primul indice, de unde porneste calcului scorului pe zona
        u=3; //ultimul indice, unde se opreste calcului scorului pe zona
    }
    else if (zone==3||zone==4)
    {
        p=4;
        u=7;
    }
    for (i=p; i<=u; i++)
    {
        if (a[i][j]==1)
            nr++; //se numara valorile din fiecare zona
    }
    if (nr==4)
        return 1; //daca toate valorile sunt 1, atunci scorul e 1
    return 0;
}
int verifl(int a[][8],int i,int zone)
{
    int j,nr,p,u;
    nr=0; //ajuta la calcularea valorilor de 1 de pe o linie
    if (zone==1||zone==4) //analong ca mai sus, la cautarea pe coloane
    {
        p=0;
        u=3;
    }
    else if (zone==2||zone==3)
    {
        p=4;
        u=7;
    }
    for (j=p; j<=u; j++)
    {
        if (a[i][j]==1)
            nr++;
    }
    if (nr==4)
        return 1;
    return 0;
}
int verifdp(int a[][8],int zone)
{
    int i,nr;
    nr=0; //ajuta la calcularea valorilor de 1 de pe diagonala principala
    if (zone==1)
    {
        for (i=0; i<=3; i++)
        {
            if (a[i][i]==1) //diagonala principala a fiecarei zone
                nr++; //analog ca mai sus
        }
    }
    else if (zone==2)
    {
        for (i=0; i<=3; i++)
        {
            if (a[i][4+i]==1)
                nr++;
        }
    }
    else if (zone==4)
    {
        for (i=4; i<=7; i++)
        {
            if (a[i][i-4]==1)
                nr++;
        }
    }
    else
    {
        for (i=4; i<=7; i++)
        {
            if (a[i][i]==1)
                nr++;
        }
    }
    if (nr==4)
        return 1;
    return 0;
}
int verifds(int a[][8],int zone)
{
    int i,nr;
    nr=0; /*analog ca la diagonala principala, dar pentru fiecare diagonala
    secundara a fiecarei zone*/
    if (zone==1)
    {
        for (i=0; i<=3; i++)
        {
            if (a[i][4-i-1]==1)
                nr++;
        }
    }
    else
    {
        if (zone==2)
        {
            for (i=0; i<=3; i++)
            {
                if (a[i][8-i-1]==1)
                    nr++;
            }
        }
        else
        {
            if (zone==3)
            {
                for (i=4; i<=7; i++)
                {
                    if (a[i][11-i]==1)
                        nr++;
                }
            }
            else
            {
                for (i=4; i<=7; i++)
                    if (a[i][7-i]==1)
                        nr++;
            }
        }
    }
    if (nr==4)
        return 1;
    else
        return 0;
}
int sum_X_0(int m[][8])
{
    int zone,c,s,i;
    s=0; //suma scoruri zone
    for (zone=1; zone<=4; zone++)
    {
        c=0; /*calculeaza scorul numarand cate linii, coloane, diagonale din
    fiecare zona au toate 1*/
        if (verifdp(m,zone)==1)
            c++;
        if (verifds(m,zone)==1)
            c++;
        if (zone==1)
            for (i=0; i<=3; i++)
            {
                if(verifc(m,i,zone)==1)
                    c++;
                if (verifl(m,i,zone)==1)
                    c++;
            }
        else
        {
            if (zone==2)
            {
                for (i=0; i<=3; i++)
                {
                    if(verifl(m,i,zone)==1)
                        c++;
                }
                for (i=4; i<=7; i++)
                {
                    if (verifc(m,i,zone)==1)
                        c++;
                }
            }
            else
            {
                if (zone==4)
                {
                    for (i=0; i<=3; i++)
                        if(verifc(m,i,zone)==1)
                            c++;
                    for (i=4; i<=7; i++)
                        if (verifl(m,i,zone)==1)
                            c++;
                }
                else
                {
                    for (i=4; i<=7; i++)
                    {
                        if (verifc(m,i,zone)==1)
                            c++;
                        if (verifl(m,i,zone)==1)
                            c++;
                    }
                }
            }
        }
        s=s+c;
    }
    return s;
}
int max(int a,int b,int c)
{
    int maxi;
    if (a>b&&b>c)
        maxi=a;
    if (a>c&&c>b)
        maxi=a;
    if (b>a&&a>c)
        maxi=b;
    if (b>c&&c>a)
        maxi=b;
    if (c>b&&b>a)
        maxi=c;
    if (c>a&&a>b)
        maxi=c;
    return maxi;
    //face maximul dintre scoruri
}
int verifegal(int a,int b,int c)
{
    if (a==b==c)
        return 3;
    if (a==b||b==c||a==c)
        return 2;
    return 0;
    //verifica cate scoruri sunt egale intre ele
}
void egl(int a[][8],int b[][8])
{
    int i,j;
    for (i=0; i<8; i++)
    {
        for (j=0; j<8; j++)
        {
            b[i][j]=a[i][j];
        }
    }
    //egaleaza doua matrice
}
void stringl(int v[],char *m)
{
    int i,k;
    k=0;
    for(i=0; i<8; i++)
    {
        m[k++]=v[i]+48;
    }
    m[k]='\0';
    //face din matrice int o matrice char
    //fiecare linie din matricea int fiind un sir binar
}
void final(int v[])
{
    int mat[8][8],t[8][8],a[8][8],i,j,a2[8][8],c1,c2,c3,maxi,nr,matrix[8][8],p;
    char m[8][8],cv[8][8];
    mat_string(v,m); /*dupa ce a facut din vectorul cu numerele
    zecimale citite de la tastatura o matrice char care contine pe fiecare
    linie transformarea in binar a numarului citit*/
    mat_create(m,mat); //o transforma intr-o matrice normala, int
    transpose(mat,t); //face transpusa
    ata(mat,a); //face produsul dintre matrice si transpusa sa
    apatrat(mat,a2); //ridica matricea la patrat
    c1=sum_X_0(mat); //calculeza scorul matricii normale
    c2=sum_X_0(a); //calculeza scorul produsului a*a transpus
    c3=sum_X_0(a2); //calculeaza scorului matricei la patrat
    maxi=max(c1,c2,c3);
    if (verifegal(c1,c2,c3)==0) //daca toate cele trei scoruri sunt diferite
    {
        if(c1==maxi) //daca prima are scorul maxim
            egl(mat,matrix); //prima se selecteaza pentru a calcula rezultatul
            /*rezultatul este calcularea numarului din cifrele binare
            in zecimal a fiecarei linii din aceasta matrice*/
        {
            if (c2==maxi)
                egl(a,matrix); //daca a*a transpus are scor maxim, ea e aleasa
            else
                egl(a2,matrix); //analog daca a^2 are maxim
                //a=mat=matricea de siruri in binar
        }
        if (verifegal(c1,c2,c3)==3) //daca toate cele trei scoruri sunt egale
            egl(mat,matrix); //se alege normala,(int) ea fiind prima calculata
        else
        {
            //daca scorurile sunt doua cate doua egale,
            if (c1==c2)
                egl(mat,matrix); //atunci se ia prima calculata
            else
                if (c1==c3)
                egl(a,matrix);
        }
        for(i=0; i<8; i++) //pentru matricea selectata, se face transformarea
        {
            nr=0;
            p=1;
            for(j=7; j>=0; j--)
            /*transformare directa, cu fiecare element(=cifra binara) inmultita
            cu o putere de 2 si adunata pentru a forma numarul zecimal*/
            {
                nr=nr+p*matrix[i][j];
                p=p*2;
            }
            printf("%d\n",nr);
        }
    }
    }
    int main()
    {
        int i,v[8];
        char mat[8][8];
        for (i=0; i<8; i++)
            scanf("%d",&v[i]); //citire fiecare numar si introducerea in vector
       final(v);
        return 0;
    }
