

Am decis sa fac tema in mare parte static pentru ca asa imi era mai usor, mai ales
ca nu am observat constrangeri spre a aloca datele exculsiv dinamic.


Pana la rezolvarea propriu-zisa a task-urilor, am pregatit datele pentru a fi prelucrate,
astfel: am citit pe rand numarul de noduri, numarul de muchii si apoi numarul de dpozite,
apoi am citit cele m randuri cu nodul de pornire (u), cel de sosire (v) si costul (w).
Pentru fiecare data citita am construit astfel matricile de adiacenta si de costuri (g
fiind matricea de adiacenta a grafului, gr fiind o copie a sa si a fiind matricea de
costuri, nu inainte de a fi initializate pe toate pozitiile cu 0): pentru g si gr: pe
linia u si coloana v am pus 1 si in a pe linia u si pe coloana v am pus w. Dupa aceea, am
citit fiecare depozit si le-am pus intr-un vector de depozite, apoi numarul de cerinte si
pentru fiecare cerinta, am citit cerinta si am verificat ce fel de tip de cerinta e. 


La e1: am folosit o varianta modificata a algoritmului Dijsktra, dar de doua ori: o data
pentru traseul de dus, ca sa ma exprim astfel, iar altul pentru traseul de intors. 
in urma aceastei functii dijkstra am pus intr-un vector nodurile vizitate, dar in ordine
inversa. a trebuit sa inversez acel vector ca sa il prelucrez si sa il afisez. apoi am
facut un vector de costuri/ distante pentru fiecare nod de la sursa (src) in care am
adunat pe pozitia specifica nodului costul respectiv si am aflat minimul. 
Programul mai intai afiseaza nodul pentru care a facut dijtra dus-intors, apoi costurile
de la dus si de la intors, apoi foloseste iar un fel de dijsktra pentru a afisa nodurile
prin care a trecut ca sa calculeze acele costuri afisate anterior, dar aceasta dupa ce le
pune intr-un vector. La final am afisat vectorul. 


La e2: nu am facut cu kosarakju sau tarjan cum a facut majoritatea, ci am incercat o
varianta proprie. Am luat fiecare depozit din vectorul de depozite si am incercat sa
elimin din graf tot ce avea legatura cu acel nod, apoi am folosit functia traversal
(explin imediat ce face) pentru fiecare depozit, apoi am sters duplicatele din vectorul
cc in care au fost puse nodurile parcurse din "traversal". Apoi din vectorul cc in
functie de cum gaseam un nod ce reprezenta un depozit, am pus elementele din vector pe
linii, intr-o matrice. apoi fiecare linie am sortat-o crescator. daca mai erau duplicate,
le-am eliminat, iar la final am afisat liniile din matricea, numai dupa ce am afisat
numarul liniilor, care e, de fapt, numarul de componente conexe din graf. Functia
"traversal" pune pe stiva cate un nod (depozit), il marcheaza ca vizitat, si cat timp
gaseste un arc (o muchie) (functia "arch" de graf, numar de noduri si nodul respectiv) de acel nod, cauta recursiv. cand nu a mai gasit muchie, iese din recursivitate, scoate
nodul de pe stiva si il adauga la vectorul de noduri din componenta conexa. iar la final
mai face inca o data acest lucru. 


La e3: chiar daca nu da pe checker, am incercat o rezolvare proprie: am citit, in plus, r
care e  numarul de rute (adica componente conexe de pelucrat), iar pentru fiecare am citit
cate un k, ce e numarul de noduri din componenta, si nodurile propriu-zise, pe care le-am
pus intr-un vector x. Am facut apoi o matrice de dimensiune 2 X k in care pe prima linie
am pus valorile stocate in vectorul x si pe a doua linie am initializat-o cu zero pentru
ca sa o folosesc pe post de un vector de vizitzati. am luat apoi fiecare depozit, l-am
marcat ca fiind un start (punct de plecare) si apoi am cautat punctul de sosire 
(da, intr-adevar trebuie sa se intoarca la acelasi depozit, dar stop-ul este, de fapt,
nodul din componenta data care are acces la acel depozit. am adaugat la suma si costul de
la nodul de start la nodul de stop. apoi pentru fiecare nod din vectorul x am cautat care
e primul nod din vector nevizitat si am adaugat costul la o suma. dupa ce toate din vector
au fost vizitate (linia doi din matricea creata la acest punct este plina cu 1) atunci
cauta un nod care face parte din vectorul x si care are legatura cu nodul de stop. pe
parcurs ce cauta si gaseste noduri din x care sa se apropie de stop, adauga la suma
costul. suma finala este afisata, per depozit. deci: mai clar: ia linia start si coloana
x[i] (0<=i<k) si verifica daca acolo e element diferit de zero. daca da, marcheaza ca
vizitat elementuk x[i], se opreste din cautat, start-ul devine x[i], si se aduna la suma
costul, asta pana cand toti x[i]-ii au fost vizitati. daca au fost vizitati dar nu s-a
ajuns la nodul de stop, la fel se cauta pe linia start o coloana x[i] ce reprezinta nodul
de stop, la fel, adunandu-se pe parcurs, costul.


