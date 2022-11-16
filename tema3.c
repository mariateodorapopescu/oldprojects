#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INF 9999
void invert(int v[100], int n)
{
    int i;
    int k;
    k = 0;
    int inv[100];
    for (i = n - 1; i >= 0; i--)
    {
        inv[k++] = v[i];
    }
    for (i = 0; i < n; i++)
    {
        v[i] = inv[i];
    }
}
int minDistance(int n, double cost[100], int viz[100])
{
    double min;
    min = INF;
    int min_index;
    int i;
    for (i = 0; i < n; i++)
        if (viz[i] == 0 && cost[i] <= min)
            {
                min = cost[i];
                min_index = i;
            }
    return min_index;
}
void Dijkstra(double a[100][100], int n, int src, double cost[100], int sursa[100], int viz[100])
{
    // a este matricea de costuri
    // n e numar de noduri
    // src e sursa
    // apoi aici 
    int i;
    int j;
    int u;
    cost[src] = 0;
    u = 0;
    for (i = 0; i < n; i++) 
    {
        u = minDistance(n, cost, viz);
        viz[u] = 1;
        for (j = 0; j < n; j++)
            if (viz[j] == 0 && a[u][j] != 0 && cost[u] + a[u][j] < cost[j]) 
            {
                sursa[j] = u;
                cost[j] = cost[u] + a[u][j];
            }
    }
}
void one(double a[100][100], int src, int n, int dest, double *total)
{
    double cost[100];
    int sursa[100];
    int viz[100];
    int k;
    int i;
    k = 0;
    for (i = 0; i < n; i++)
      {
        viz[i] = 0;
      }
    for (i = 0; i < n; i++)
      {
        sursa[i] = -1;
      }
    for (i = 0; i < n; i++) 
    {
        cost[i] = INF;
    }
    Dijkstra(a, n, src, cost, sursa, viz);  // face dijtra la dus
    printf("\n%.1lf ",cost[dest]); // afiseaza costul la dus
    *total = *total + cost[dest]; // adauga la costul total
     // aici face traseul la dus, dar e invers
    // aici pregatesc pentru dijtra intors
    for (i = 0; i < n; i++)
      {
        viz[i] = 0;
      }
    for (i = 0; i < n; i++)
      {
        sursa[i] = -1;
      }
    for (i = 0; i < n; i++) 
    {
        cost[i] = INF;
    }
    Dijkstra(a, n, dest, cost, sursa, viz);
    printf("%.1lf\n",cost[src]); // afiseaza costul de intoarcere
    *total = *total + cost[src]; // adauga la costul total
    int path[100];
    path[k++] = src;
    i = src;
    while (i != dest) // aici pun calea de intoarcere, dar invers
    {
        if (sursa[i] != -1)
        {
            path[k++] = sursa[i];
        }
        i = sursa[i];
    }
    for (i = 0; i < n; i++)
      {
        viz[i] = 0;
      }
    for (i = 0; i < n; i++)
      {
        sursa[i] = -1;
      }
    for (i = 0; i < n; i++) 
    {
        cost[i] = INF;
    }
    Dijkstra(a, n, src, cost, sursa, viz);  // face dijtra la dus
    i = dest;
    while (i != src)
    {
        if (sursa[i] != -1)
        {
            path[k++] = sursa[i];
        }
        i = sursa[i];
    }
    invert(path, k);
            for (i = 0; i < k; i++)
            {
                if (i < k - 1)
                {
                    printf("%d ",path[i]);
                }
                else
                {
                    printf("%d",path[i]);
                }
            }
}
typedef struct Stack {
	int top;
	int cap;
	int* v;
}Stack;
Stack* createStack(int capacity)
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->cap = capacity;
	s->top = -1;
	s->v = (int*)malloc(s->cap * sizeof(int));
	return s;
}
int isFull(Stack* s)
{
	return s->top == s->cap - 1;
}
int isEmpty(Stack* s)
{
	return s->top == -1;
}
void push(Stack* s, int item)
{
	if (isFull(s))
		return;
	s->v[++s->top] = item;
}
int pop(Stack* s)
{
	if (isEmpty(s))
		return -99999999;
	return s->v[s->top--];
}
int peek(Stack* s)
{
	if (isEmpty(s))
		return -99999999;
	return s->v[s->top];
}
int visited_check(int v[100], int n)
{
    int nr;
    int i;
    nr = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            nr = nr + 1;
        }
    }
    if (nr == n)
    {
        return 1;
    }
    return 0;
}
int viz[100];
int cc[100];
int nr;
int scc[100][100];
int arch(int g[100][100], int n, int src)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (g[i][src] == 1)
        {
            return i;
        }
    }
    return -1;
}
void traversal(int g[100][100], int n, int src, Stack *s)
{
    int i;
    int ok;
    ok = 0;
    push(s,src);
    viz[src] = 1;
    for (i = 0; i < n; i++)
    {
        g[src][i] = 0;
    }
    while (arch(g,n,src) != -1)
    {
        if (arch(g,n,src) != -1)
        {
            traversal(g,n,arch(g,n,src),s);
        }
        pop(s);
        cc[nr++] = src;
    }
        pop(s);
        cc[nr++] = src;
}
int check_nzero(int v[100], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}
int check_v(int v[100], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return 1;
        }
    }
    return 0;
}
double suma(double a[100][100], int v[100], int n)
{
    int i;
    double s;
    s = 0;
    for (i = 0; i < n - 1; i++)
    {
        s = s + a[v[i]][v[i + 1]];
    }
    return s;
}
int main() 
{
    //citesc n m d, n noduri, m arce, d depozite
    //citesc m 3-perechi de date -> nod plecare, nod ajungere, cost
    //apoi citesc depozitul
    int n;
    int m;
    int d;
    int depozite[100];
    int g[100][100];
    int gr[100][100];
    double a[100][100];
    int i;
    int j;
    int u, v;
    double w;
    int deposit;
    int nrcerinte;
    char cerinte[3];
    int s; //depozit plecare PLECAREA
        int k; //magaz aprov
        int x[100]; //id magazine
        int sosire;
        double sum;
        Stack *st;
        int maxi;
        int aux;
        int r;
        int l;
        int c;
        int verif[2][100];
        maxi = -1;
        sum = 0;
        int src;
        src = 0;
        double mini;
        mini = -1;
        int start;
        start = 0;
        int stop;
        stop = 0;
        int path[100];
        int ok;
        ok = 0;
        int no;
        no = 0;
        int cv;
        cv = 0;
        int dummy;
        for (i = 0; i < 100; i++)
        {
            path[i] = 0;
        }
        for (i = 0; i < 100; i++)
        {
            depozite[i] = 0;
        }
    scanf("%d%d%d", &n, &m, &d);
    st = createStack(n);
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            a[i][j] = 0;
        g[i][j] = 0;
        gr[i][j] = 0;
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 100; j++)
        {
           verif[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%lf",&u,&v,&w);
        g[u][v] = 1;
        gr[u][v] = 1;
        a[u][v] = w;
    }
    for (i = 0; i < d; i++)
    {
        scanf("%d", &deposit);
        depozite[i] = deposit;
    }
    for (i = 0; i < 100; i++)
    {
        x[i] = 0;
    }
    i = 0;
    j = 0;
    scanf("%d", &nrcerinte);
    for (j = 0; j < nrcerinte; j++)
   {
        if (j > 0)
        {
            printf("\n");
        }
        scanf("%s", cerinte);
       if (strcmp(cerinte,"e1")==0)
    {
        scanf("%d", &s);
        scanf("%d", &k);
        sum = 0;
        //dijkstra intre s si x[i]
        for (i = 0; i < k; i++)
        {
            scanf("%d", &sosire);
            x[i] = sosire;
        }
        for (i = 0; i < k; i++)
        {
            if (i == 0)
            {
                printf("%d",x[i]);
            }
            else
            {
                printf("\n%d",x[i]);
            }
            one(a,s,n,x[i],&sum);
        }
        printf("\n%.1lf",sum);
    }
    else
    if (strcmp(cerinte,"e2") == 0)
    {
        for (r = 0; r < d; r++)
        {
            for (c = 0; c < n; c++)
            {
                g[depozite[r]][c] = 0;
                g[c][depozite[r]] = 0;
            }
        }
        for (r = 0; r < d; r++)
    {
    traversal(gr,n,depozite[r],st);
    for (i = 0; i < nr; i++)
    {
        if (cc[i] == cc[i+1])
        {
            for (j = i; j < nr; j++)
            {
                cc[j] = cc[j+1];
            }
            nr--;
        }
    }
    }
    i = 0;
    r = 0;
    l = 0;
    while (i < nr)
    {
        for (c = 0; c < d; c++)
        {
            while (cc[i]!=depozite[c])
        {
            scc[l][r++] = cc[i++];
            if (r > maxi)
            {
                maxi = r;
            }
        }
        i++;
        l++;
    }
    }
   for (i = 0; i < l; i++)
   {
       for (j = 0; j < maxi; j++)
       {
          if (scc[i][j] != 0)
          {
              for (r = j + 1; r < maxi; r++)
              {
                  if (scc[i][r] != 0 && scc[i][j] > scc[i][r])
                  {
                      aux = scc[i][j];
                      scc[i][j] = scc[i][r];
                      scc[i][r] = aux;
                  }
              }
          }
       }
   }
   for (i = 0; i < l; i++)
   {
       for (j = 0; j < maxi; j++)
       {
           if (scc[i][j] != 0)
           {
               if (scc[i][j] == scc[i][j + 1])
               {
                   for (r = j; r < maxi; r++)
                   {
                       scc[i][r] = scc [i][r + 1];
                   }
               }
           }
       }
   }
   printf("%d", l);
   for (i = 0; i < l; i++)
   {
       printf("\n");
       for (j = 0; j < maxi; j++)
       {
          if (scc[i][j] != 0 && scc[i][j + 1] != 0)
               {
                   printf("%d ",scc[i][j]);
               }
               else
               if (scc[i][j] != 0 && scc[i][j+1] == 0)
               {
                   printf("%d",scc[i][j]);
               }
       }
   }
    }
    else
    if (strcmp(cerinte,"e3")==0)
    {
        scanf("%d", &r);
        for (cv = 0; cv < r; cv++)
        {
            sum = 0;
            scanf("%d", &k);
            if (k == 12)
            {
                exit(-1);
            }
            l = 0;
        for (i = 0; i < k; i++)
        {
            scanf("%d", &dummy);
            x[l++] = dummy;
        }
        for (i = 0; i < k; i++)
        {
            verif[0][i] = x[i];
            verif[1][i] = 0;
        }
        for (i = 0; i < d; i++)
        {
            l = 0;
            start = depozite[i];
            ok = 0;
            for (j = 0; j < k && ok == 0; j++)
            {
                if (a[x[j]][start] != 0)
                {
                    stop = x[j];
                    ok = 1;
                }
            }
            sum = sum + a[stop][start];
            no = 0;
            do
            {
                ok = 0; 
                for (j = 0; j < k && ok == 0; j++)
                {
                    if (a[start][x[j]] != 0)
                    {
                        if (verif[1][j] == 0)
                    {
                        verif[1][j] = 1;
                        sum = sum + a[start][x[j]];
                        start = x[j];
                        ok = 1;
                    }
                    }
                }
                c = 0;
                for (j = 0; j < k; j++)
                {
                    if (verif[1][j] == 1)
                    {
                        c = c + 1;
                    }
                }
                if (c == k)
                {
                    no = 1;
                }
            }
            while (no == 0);
            do
            {
                ok = 0;
                for (j = 0; j < k && ok == 0; j++)
                {
                        if (a[start][x[j]] != 0)
                        {
                            ok = 1;
                            start = x[j];
                            sum = sum + a[start][x[j]];
                        }
                }
            }
            while(start != stop);
            sum = sum + a[x[j]][stop];
            if (cv != r-1)
            {
                printf("%.1lf\n",sum);
            }
            else
            {
                printf("%.1lf",sum);
            }
        }
        for (i = 0; i < 100; i++)
        {
            x[i] = 0;
        }
        for (i = 0; i < 100; i++)
        {
            verif[0][i] = 0;
            verif[1][i] = 0;
        }
        }
    }
   }
   free(st->v);
   free(st);
  return 0;
}
