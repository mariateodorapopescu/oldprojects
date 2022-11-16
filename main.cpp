#include<iostream>
#include<math.h>
using namespace std;
float f[100][100];
void eliml(float a[100][100], int &n, int m, int k)
{
	int i, j;
	for (i = k + 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			a[i - 1][j] = a[i][j];
	}
	n--;
}
void elimc(float a[100][100], int n, int &m, int k)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = k + 1; j <= m; j++)
			a[i][j - 1] = a[i][j];
	}
	m--;
}

void citire(float a[100][100],int &n,int &m)
{
    int i,j;
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        cin>>a[i][j];
}
void transpusa(float a[100][100],float t[100][100],int n,int m)
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        t[i][j]=a[j][i];
}
void afis(float a[100][100],int n,int m)
{
        int i,j;
    for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
                cout<<a[i][j]<<' ';
            cout<<endl;
        }
}
float determinant(int n,float a[100][100],int i,int j)
{
    float det=0;
    int ok,jj;
    if ((i+j)%2==1)
        ok=-1;
    else
        ok=1;
    if (n>3)
    {
        for (jj=j+1;jj<=n;jj++)
        det=det+ok*determinant(n-1,a,i+1,jj);
    }
    else

        if (n==3)
    {
det=(a[i][j]*a[i+1][j+1]*a[i+2][j+2])+(a[i][j+2]*a[i+1][j]*a[i+2][j+1])+(a[i][j+1]*a[i+1][j+2]*a[i+2][j])-
            (a[i][j+2]*a[i+1][j+1]*a[i+2][j])-(a[i][j]*a[i+1][j+2]*a[i+2][j+1])-(a[i][j+1]*a[i+1][j]*a[i+2][j+2]);
    }
    else
        if (n==2)
    {
 det=(a[i][j]*a[i+1][j+1])-(a[i][j+1]*a[i+1][j]);
    }
    return det;
}
void cofactor(float t[100][100],float c[100][100],int n,int m,int l,int k)
{
    int i,j,okl,okc;
    okl=0;okc=0;
    if (n!=m)
        cout<<"Imposibl";
    else
        if (n>2)
    {
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            c[i][j]=t[i][j];
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            {
                if (i==l&&okl==0)
                {
                    eliml(c,n,m,l);
                    okl=1;
                    //afis(c,n,m);
                   // cout<<endl;
                }
                if(j==k&&okc==0)
                    {
                        elimc(c,n,m,k);
                        okc=1;
                        //afis(c,n,m);
                        //cout<<endl;
                    }
    }
    }
    else
        if(n==2)
    {
        if (l==1)
            if (k==1)
            c[1][1]=t[2][2];
        else
            c[1][1]=t[2][1];
        else
        if(k==1)
            c[1][1]=t[1][2];
        else
            c[1][1]=t[1][1];
    }
}
void adjuncta(float t[100][100],float ad[100][100],int n,int m)
{
    int i,j,k,l,x;
    float c[100][100];
    if (n!=m)
    cout<<"Imposibil";
    else
    {
        if (n>2)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
        {
            x=n;
            cofactor(t,c,n,m,i,j);
            x--;
            ad[i][j]=pow(-1,i+j)*determinant(x,c,1,1);
        }
            else
            for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
        {
            cofactor(t,c,n,m,i,j);
            ad[i][j]=pow(-1,i+j)*c[1][1];
        }

    }
}
void inversa(float a[100][100],float ad[100][100],float inv[100][100],int n,int m)
{
    float d;
    int i,j;
    if (n!=m)
        cout<<"Imposibil";
    else
    {
        d=determinant(n,a,1,1);
        if (d==0)
            cout<<"Imposibil";
        else
        {
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++)
                inv[i][j]=ad[i][j]/d;
        }
    }
}
void cv2(float a[100][100],float b[100][100],int n,int m,float p[100][100])
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
for(j=1;j<=m;j++)
{
p[i][j]=0;
for(k=1;k<=m;k++)
p[i][j]=p[i][j]+a[i][k]*b[k][j];
}
}
}
void sum(float a[100][100],float b[100][100],int n,int m,float s[100][100])
{
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        s[i][j]=a[i][j]+b[i][j];
}
void dif(float a[100][100],float b[100][100],int n,int m,float d[100][100])
{
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        d[i][j]=a[i][j]-b[i][j];
}
void cv(float a[100][100],float b[100][100],int n,float p[100][100])
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
for(j=1;j<=n;j++)
{
p[i][j]=0;
for(k=1;k<=n;k++)
p[i][j]=p[i][j]+a[i][k]*b[k][j];
}
}
}
void egl(float d[100][100],float a[100][100],int n)
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        d[i][j]=a[i][j];
}
int main()
{
  cout<<"Bun venit la Matrix Ex!"<<endl;
  cout<<"Cu cate matrice doriti sa lucrati?(Cu una sau cu doua?)"<<endl;
  int x;
  cout<<"Cu ";
  cin>>x;
  cout<<"Se va lucra cu "<<x<<" matrice"<<endl;
  cout<<"Va rugam sa asteptati..."<<endl;
  if (x==1)
  {
      int n,m,i,j,gr,put,b,c;
      float inm,a[100][100],s,s1,s2,t[100][100],det,coef[11],p[100][100],d[100][100];
      det=0; s1=0; s2=0; s=0;
      cout<<"A se citi mai intai dimensiunile matricii, apoi elementele ei pe linie si coloana";
      cout<<endl;
      cout<<"Cu cate linii si cu cate coloane sa fie matricea?"<<endl;
      cout<<"Cu ";
      cin>>n;
      cout<<"linii si ";
      cin>>m;
      cout<<"coloane";
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
cin>>a[i][j];
int op1;
do
             {
      cout<<"Ce doriti sa faceti cu matricea?"<<endl;
      cout<<"1=Sa aflati suma elementelor."<<endl;
      cout<<"2=Sa aflati urma matricei."<<endl;
      cout<<"3=Sa aflati suma elementelor de pe diagonala secundara."<<endl;
      cout<<"4=Sa aflati transpusa matricei."<<endl;
      cout<<"5=Sa aflati matricea la o anumita putere."<<endl;
      cout<<"6=Sa aflati determinantul acelei matrici."<<endl;
      cout<<"7=Sa o afisati."<<endl;
      cout<<"8=Sa o inmultiti cu un numar real."<<endl;
      cout<<"9=Sa aflati rezultatul unei functii cu matricea respectiva."<<endl;
      cout<<"10=Sa eliminati o linie."<<endl;
      cout<<"11=Sa eliminati o coloana."<<endl;
      cout<<"12=Sa eliminati o linie si o coloana."<<endl;
      cout<<"13=Sa aflati inversa acesteia."<<endl;
      cout<<"14=Iesire"<<endl;
      cin>>op1;
       switch (op1)
    {
        case 1:
      {
for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    s=s+a[i][j];
    cout<<"Suma elementelor matricei este "<<s<<'.'<<endl;
      break;}
case 2:
{
    if (n!=m)
        cout<<"Nu se poate calcula urma matricei."<<endl;
    else
        {
        for (i=1;i<=n;i++)
        s1=s1+a[i][i];
    cout<<"Urma matricii este "<<s1<<'.'<<endl;
        }
break;}
case 3:
{
    if (n!=m)
        cout<<"Nu se poate calcula suma de pe diagonala secundara!"<<endl;
    else
    {
    for (i=1;i<=n;i++)
        s2=s2+a[i][n-i+1];
    cout<<"Suma elementelor de pe diagonala secundara este "<<s2<<endl;
}
break;}
case 4:
{
  transpusa(a,t,n,m);
  cout<<"Matricea transpusa este "<<endl;
  afis(t,n,m);
break;}
case 5:{
if (n!=m)
    cout<<"Nu se poate ridica matricea la orice putere."<<endl;
else
{
egl(d,a,n);
cout<<"La ce putere sa se ridice matricea?"<<endl;
cin>>c;
for (b=1;b<=c-1;b++)
{
cv(a,d,n,p);
egl(d,p,n);
}
for(i=1;i<=n;i++)
    {
for(j=1;j<=n;j++)
cout<<d[i][j]<<" ";
cout<<endl;
}
}
break;}
case 6:
    {
        if (n!=m)
            cout<<"Nu se poate calcula determinantul.";
        else
            {
                cout<<determinant(n,a,i,j);
    }
            break;
    }
    case 7:{
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        cout<<a[i][j]<<' ';
        cout<<endl;
    }
    break;
    }
    case 8:{
        cout<<"Cu ce numar doriti sa o inmultiti?"<<endl;
        cout<<"Cu ";
        cin>>inm;
        cout<<"Va rugam sa asteptati..."<<endl;
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
            a[i][j]=a[i][j]*inm;
        cout<<"Matricea modificata este"<<endl;
for (i=1;i<=n;i++)
            {
                for (j=1;j<=m;j++)
                    cout<<a[i][j]<<' ';
                cout<<endl;}
    break;}
    case 9:{

        cout<<"De ce grad sa fie functia?(De gradul 1,2 sau 3?)"<<endl;
        cout<<"De gradul ";
        cin>>gr;
        cout<<"Care sunt coeficientii?"<<endl;
        for (i=1;i<=gr;i++)
        cin>>coef[i];
        cout<<"Va rugam sa asteptati..."<<endl;
        put=gr;
        for (i=1;i<=gr;i++)
        {
egl(d,a,n);
for (b=1;b<=put-1;b++)
{
cv(a,d,n,p);
egl(d,p,n);
}
    for (b=1;b<=n;b++)
            {
                for (j=1;j<=n;j++)
            cout<<f[b][j]<<' ';
        cout<<endl;
            }
    for(b=1;b<=n;b++)
for(j=1;j<=n;j++)
    f[b][j]=f[b][j]+coef[i]*d[b][j];
            put--;
        }
        cout<<"Rezultatul functiei este"<<endl;
        for (i=1;i<=n;i++)
            {
                for (j=1;j<=n;j++)
            cout<<f[i][j]<<' ';
        cout<<endl;
            }
            for(b=1;b<=n;b++)
for(j=1;j<=n;j++)
    a[b][j]=f[b][j];
    break;
    }
    case 10:{
        int lini;
        cout<<"Ce linie doriti sa eliminati?"<<endl;
        cout<<"Linia ";
        cin>>lini;
        cout<<"Va rugam sa asteptati..."<<endl;
        eliml(a,n,m,lini);
        cout<<"Matricea modificata este"<<endl;
for (i=1;i<=n;i++)
            {
                for (j=1;j<=m;j++)
                    cout<<a[i][j]<<' ';
                cout<<endl;}
    break;}
    case 11:{
        int coli;
        cout<<"Ce coloana doriti sa eliminati?"<<endl;
        cout<<"Coloana ";
        cin>>coli;
        cout<<"Va rugam sa asteptati..."<<endl;
        elimc(a,n,m,coli);
        cout<<"Matricea modificata este"<<endl;
for (i=1;i<=n;i++)
            {
                for (j=1;j<=m;j++)
                    cout<<a[i][j]<<' ';
                cout<<endl;}
    break;}
    case 12:{
        int lini1,coli1;
        cout<<"Ce linie si ce coloana doriti sa eliminati?"<<endl;
        cout<<"Linia ";
        cin>>lini1;
        cout<<"si coloana ";
        cin>>coli1;
        cout<<"Va rugam sa asteptati..."<<endl;
        eliml(a,n,m,lini1);
        elimc(a,n,m,coli1);
        cout<<"Matricea modificata este"<<endl;
for (i=1;i<=n;i++)
            {
                for (j=1;j<=m;j++)
                    cout<<a[i][j]<<' ';
                cout<<endl;}
    break;}
    case 13:{
        cout<<"Va rugam sa asteptati...";
        float inv[100][100],ad[100][100],d;
    d=determinant(n,a,1,1);
    transpusa(a,t,n,m);
    adjuncta(t,ad,n,m);
inversa(a,ad,inv,n,m);
        cout<<"Matricea inversa este:"<<endl;
        afis(inv,n,m);
    break;}
case 14: {cout<<"La revedere!"<<endl;break;}
    {default: cout<<"Optiune gresita"; break;
    }
        }
             }
        while (op1<14);
}
  if (x==2)
  {
float p1[100][100],e[100][100],p2[100][100],a[100][100],ss[100][100],dd[100][100];
int n1,n2,m1,m2,k=0,ok1=0,ok2=0,i,j;
cout<<"A se citi de la tastatura mai intai dimensiunea si elementele primei matrici, apoi a celei de a doua."<<endl;
cout<<"Cu cate linii si cu cate coloane sa fie prima matrice?"<<endl;
cout<<"Cu "<<endl;
cin>>n1;
cout<<" linii si ";
cin>>m1;
cout<<"coloane"<<endl;
cout<<"Elementele primei matrice sunt"<<endl;
for(i=1;i<=n1;i++)
for(j=1;j<=m1;j++)
cin>>a[i][j];
cout<<"Cu cate linii si cu cate coloane sa fie a doua matrice?"<<endl;
cout<<"Cu "<<endl;
cin>>n2;
cout<<" linii si ";
cin>>m2;
cout<<"coloane"<<endl;
cout<<"Elementele celei de-a doua matrice sunt"<<endl;
for(i=1;i<=n2;i++)
for(j=1;j<=m2;j++)
cin>>e[i][j];
int op2;
do
{
    cout<<"Ce doriti sa faceti cu matricele?"<<endl;
    cout<<"Nota: Prima matrice = A; a doua matrice = B"<<endl;
      cout<<"1=A+B=?"<<endl;
      cout<<"2=A-B=?"<<endl;
      cout<<"3=A*B=?"<<endl;
      cout<<"4=B*A=?"<<endl;
      cout<<"5=A*B=B*A?"<<endl;
      cout<<"6*=X=?, unde A*X=B."<<endl;
      cout<<"7*=X=?, unde X*A=B."<<endl;
      cout<<"8*=X=?, unde A*X*A=B."<<endl;
      cout<<"9=Sa se afiseze matricele."<<endl;
      cout<<"10=Iesire"<<endl;
       cout<<"Nota: *Numai pentru matricele A,B patratice de acelasi ordin."<<endl;
      cin>>op2;
      switch (op2){
      case 1:
      {
if (n1!=n2||m1!=m2)
       cout<<"Nu se poate calcula diferenta de matrici."<<endl;
else
    {sum(a,e,n1,m1,ss);
cout<<"Matricea suma este:"<<endl;
for(i=1;i<=n1;i++)
    {
for(j=1;j<=m1;j++)
cout<<ss[i][j]<<" ";
cout<<endl;
}
cout<<endl;
}
      break;}
      case 2:
      {
if (n1!=n2||m1!=m2)
       cout<<"Nu se poate calcula diferenta de matrici."<<endl;
else
{
    dif(a,e,n1,m1,dd);
cout<<"Matricea difernta este:"<<endl;
for(i=1;i<=n1;i++)
    {
for(j=1;j<=m1;j++)
cout<<dd[i][j]<<" ";
cout<<endl;
}
}
      break;}
case 3:
{
if (m1==n2)
{
    cv2(a,e,n1,m2,p1);
    ok1=1;
    for (i=1;i<=n1;i++)
{
    for (j=1;j<=m2;j++)
        cout<<p1[i][j]<<' ';
            cout<<endl;
}
cout<<endl;
}
else
    cout<<"Nu se poate calcula produsul A*B."<<endl;
break;}
case 4:
{
if (m2==n1)
{
    cv2(a,e,n2,m1,p2);
    ok2=1;
        for (i=1;i<=n1;i++)
{
    for (j=1;j<=m2;j++)
        cout<<p1[i][j]<<' ';
            cout<<endl;
}
cout<<endl;
}
else
    cout<<"Nu se poate calcula produsul B*A."<<endl;
break;}
case 5:
{
if (m1==n2)
{
    cv2(a,e,n1,m2,p1);
    ok1=1;
}
if (m2==n1)
{
    cv2(a,e,n2,m1,p2);
    ok2=1;
}
    if (ok1==1&&ok2==1)
        if (m1!=m2&&n1!=n2)
            cout<<"Matricile nu comuta."<<endl;
        else
        {
            for (i=1;i<=n1;i++)
        for (j=1;j<=m1;j++)
        if (p1[i][j]==p2[i][j])
            k++;
        if (k==(n1*m1))
            cout<<"Matricile comuta."<<endl;
        else
            cout<<"Matricile nu comuta."<<endl;
        }
        else
            cout<<"Imposibil."<<endl;
break;}
case 6:{
 cout<<"Va rugam sa asteptati...";
        float inv[100][100],ad[100][100],d,x[100][100],t[100][100];
        if(n1==m1&&n2==m2&&n1==n2)
    {
        d=determinant(n1,a,1,1);
    transpusa(a,t,n1,m1);
    adjuncta(t,ad,n1,m1);
inversa(a,ad,inv,n1,m1);
    cv2(inv,e,n1,m2,x);
    for (i=1;i<=n1;i++)
{
    for (j=1;j<=m2;j++)
        cout<<x[i][j]<<' ';
            cout<<endl;
}
    }
else
    cout<<"Nu se poate calcula X din ecuatie."<<endl;
break;
}
case 7:{
 cout<<"Va rugam sa asteptati...";
        float inv[100][100],ad[100][100],d,y[100][100],t[100][100];
        if(n1==m1&&n2==m2&&n1==n2)
    {
        d=determinant(n1,a,1,1);
    transpusa(a,t,n1,m1);
    adjuncta(t,ad,n1,m1);
inversa(a,ad,inv,n1,m1);
    cv2(inv,e,n2,m1,y);
        for (i=1;i<=n1;i++)
{
    for (j=1;j<=m2;j++)
        cout<<y[i][j]<<' ';
            cout<<endl;
}
    }
else
    cout<<"Nu se poate calcula X din ecuatie."<<endl;
break;
}
case 8:{
 cout<<"Va rugam sa asteptati...";
        float inv[100][100],ad[100][100],d,z[100][100],zz[100][100],t[100][100];
        if(n1==m1&&n2==m2&&n1==n2)
    {
        d=determinant(n1,a,1,1);
    transpusa(a,t,n1,m1);
    adjuncta(t,ad,n1,m1);
inversa(a,ad,inv,n1,m1);
cv2(inv,e,n1,m2,z);
    cv2(inv,z,n2,m1,zz);
        for (i=1;i<=n1;i++)
{
    for (j=1;j<=m2;j++)
        cout<<zz[i][j]<<' ';
            cout<<endl;
}
    }
else
    cout<<"Nu se poate calcula X din ecuatie."<<endl;
break;
}
case 9:{

for(i=1;i<=n1;i++)
{
    for(j=1;j<=m1;j++)
cout<<a[i][j]<<' ';
cout<<endl;
}
for(i=1;i<=n2;i++)
{
    for(j=1;j<=m2;j++)
cout<<e[i][j]<<' ';
cout<<endl;
}
break;
}
case 10:
    {cout<<"La revedere!"<<endl;break;}
 {default: cout<<"Optiune gresita"; break;
    }
        }
             }
        while (op2<10);
  }
return 0;}
