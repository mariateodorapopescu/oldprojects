-pe langa structura data in cerinta am mai creat altele doua, 
si anume una de a stoca un pixel din imagine, apoi una cu arborele propiu zis,
pentru ca nu am stiut exact cum sa il parcurg fara sa-l vad ca pe o lista
1.read:
-aceasta functie face citirea unui fisier ppm. dupa declararea imaginii, drept matrice de pixeli,
-urmeaza o serie de un fel de buffere in care voi citi metadatele. 
-deschid fisierul de intrare; daca nu l-a putut deschide, inchide programul
-urmeaza citirea header-ului
-verific corectitudinea datelor
-dupa ce am citit headerul, citesc spatiile goale si apoi trec la  citirea imaginii binare,
alocand pe parcurs memorie pentru stocarea ei
2.compress:
-aici este rezolvarea primei cerinte cu compresia imaginii
-fac trei sume, care, la inceput, sunt toate 0, cate una pentru fiecare culoare, 
iar aceste trei sume le impart la dimesniunea (la patrat) imaginii, pentru a calcula 
culoarea medie per componenta de culoare, iar asta pentru ca un pixel e un patrat,
iar patratul are o arie; aria este produsul a doua laturi, egale;
-apoi calculez media/scorul cu ajutorul formulei date
-culorile medii se pun in arbore si se verifica formula cu scorul similaritatii
-daca scorul e mai mare ca pragul, se divide in continuare
-daca nu se mai poate divide, atunci e frunza, prin urmare toate legaturile sunt nule
3.ptr:
-fac un vector de legaturi ca sa stiu unde anume pun pixelii
-cat timp mai are de parcurs in arborele de compresie fac loc pentru o noua legatura,
-pun ce a ramas din arbore acolo, spun al catalea nod e si trec la urmatoarul nod
-parcurg conform cerintei, (in sensul acelor de ceasornic) recursiv, pana la frunze
4.createvector:
-se parcurge arborele de compresie
-al i-ulea nod din arbore primeste datele respective
-pun culorile care sa formeze ce e comprimat in si dimensiunea blocului
-daca nu e frunza -> se ia pe cazuri pentru toate cele 4 sectiuni, 
ii pun nr de ordine, altfel il marchez ca fiind frunza
5.createtree:
-aloc arborele de compresie si iau din vector culoarea potrivita ca sa o pun in arbore,
inclusiv dimensiunea pe care e
-daca nu e frunza, mai bine zis atata timp cat nu e frunza, merg mai departe, 
recursiv, nu neaparat in ordine
-daca s-a ajuns la frunza, adica acolo unde e -1 la zona/legatura,
atunci legaturile din nodul respectiv din arbore sunt nule, nemaiavnd altundeva unde sa se duca
6.decompress:
-atata timp cat nu e frunza (e marcata cu -1), reformeaza imaginea in binar,
in matricea in care tine imaginea
for-urile se deplaseaza cat e dimensiunea imaginii, (area din structura de arbore), 
mai ales ca de obicei x si y (de unde se porneste) se iau zero, la apel (stanga,sus)
-se ia pe cazuri, pe culori;
-se percurge recursiv vectorul de compresie, refacand imaginea progresiv, mai ales ca
tot asa, se ia pe patrimi, in ordinea specificata in enunt
-mereu se injumatateste si se aduna, ca imaginea e impartita
in patru, deci dimesniunea unei linii, cum ar veni, ar fi jumtate 
6.write:
-aceasta functie scrie imaginea noua in fisierul out
-scriu elementele duin imagine in ordine: formatul (stiu deja ca e P6); dimensiunile 
(in general, am vazut ca e o imagine-patrat), deci, nu conteaza care dintre 
lungime sau latime iau; numarul de pixeli rgb, de obicei 255
-scriu binar imaginea linie cu linie, iar ala final nu uit sa inchid fisierul
7.vertically:
daca nu e frunza, sau mai bine zis atata timp cat nu e frunza, pentru ca aceasta
este conditia de oprire la recursivitate
-se parcurge pana la frunze, in ordinea din enunt (ca un fel de ace de ceasornic),
se foloseste un nod ajutator care va fi folosit la interschombarea dintre nodurile arborelui,
mai exact la interschimbrea nodului stanga sus cu cel stanga-jos si dreapta-jos cu cel
drepta-sus pentru ca se face schimbare stanga dreapta,
fiind o rasucire verticala a imaginii, apoi se face schimbul, pe rand, dar se
revine din recursivitate de fiecare bloc.
8.horizontally:
-se procedeaza asemanator ca la horizontally, doar ca se schimba nodurile din
blocurile stanga sus cu cel drepta-sus si stanga jos cu cel drepta-jos 
9.deallocate:
-free recursiv la blocuri, incepand de jos-stanga si merge invers pana se elibereaza tot
10.main:
-daca se doreste compresie: dupa ce declar cam tot ce am nevoie, initilizez arborele de compresie. 
dupa ce citesc imaginea si factorul de compresie, date ca argumente, folosesc functia compress, 
apoi aloc vectorul de compresie si pun datele in el. apoi eliberez ce am alocat pana acum. 
-daca se doreste decompresie:
citesc nr de culori, nr noduri,vectorul de culori, initializez arborele si pun datele in el.
toate acestea le fac cu functiile createtree si decompress; eliberez vectorul;
iau dimensiunea imaginii din arbore, aloc memeorie pentru imagine si abia acum scriu imaginea.
-daca se doreste oglindirea imaginii: dupa ce se comprima imaginea, se verifica ce fel de
rasucire se doreste si, in functie de aceasta, se folosesc functiile horizontally si vertically.
decomprim si scriu imaginea noua, iar la final eliberez ce am alocat;
