creare structura, lista, main:
-am creat o structura care contine legatura la nodul precedent, la nodul
urmator si doua campuri de date, unul cu timestamp-ul, si celalalt cu
valoarea.
-initialiazrea listei, in schimb, am facut-o in main, allocand primul nod,
apoi legand cele doua legaturi la NULL
-apoi am realizat o functie de adaugare valori in lista, care are transmise
ca parametri lista (capul de lista) si valorile pentru timestamp si valoare,
astfel: am luat un nod auxiliar, in care am pus valorile de adaugat si l-am
legat la NULL cu legatura next, apoi am verificat daca lista e vida, si daca
e, atunci acel nod devine primul; daca nu e vida, atunci se parcurge lista
pana la final (cu un alt nod auxiliar) si, astfel, primul nod auxiliar, cel
de adaugat, devine ultimul.
-urmeaza o functie de stergere a unui nod cu un anumit timestamp, aceasta
ajuta la rezolvarea de la 2.1 functia parcurge pana la final lista si daca
in aceasta parcurgere intalneste un nod care are in campul timestamp valoare
transmisa ca parametru, atunci, cu ajutorul unui nod auxiliar, nodul respectiv
este eliberat
-urmeaza o functie de eliberare a unei liste intregi. am luat un nod auxiliar q
pentru a atenua eliberarea brusca de memorie a primului nod din lista s, primul
devenind progresiv urmatorul pana se ajunge la un singur nod in lista.
-functia de afisare parcurge lista de la inceput la final si pe parcurs afiseaza
valorile din nodul aferent
-la toate punctele rezolvate, se presupune ca lista a fost deja initializata si
ca are valori in ea.

pentru 2.1: iau un nod care porneste de la primul nod propriu zis al listei
(s->next, caci s are o valoare random pentru ca s este capul de lista) si se
opreste la al cincilea nod de la sfarsit, caci q ajuta la luarea de subliste de
cate cinci elemente, caci de ficare data se ia nodul din mijloc in calcularea 
valorii sigma. calculez xmediu conform formula; acesta ramane neschimbat
indiferent de sublista de cinci elemente
-tot conform formulei calculez si sigma, scazand din fiecare element pe xmediu
si apoi fac media si scot radicalul
-unde se intampla ca conditia din cerinta sa nu fie indeplinita, marchez cumva
nodul de sters; cum timestampul e mereu pozitiv, m-am gandit sa-l fac -1
-apoi, iau fiecare sublista si sterg nodurile insemnmate

la 2.2.1: incerc sa sterg lista initiala, ca sa pun noile valori in ea, noile 
valori fiind cele mediane, conform cerintei
-tot asa iau subliste de cinci elemente, de data aceasta chiar creand o sublista
-sublista nou creata o ordonez cu metoda bulelor
-valoarea mediana rezultata in urma ordonarii se pune in lista mare
-dezaloc tot ce am alocat
la 2.2.2:
-aceasta functie merge pe principiul lui twoone (adoca 2.2.1), numai ca nu mai
face ordonarea elementelor, cu face media lor aritmetica si o introduce in lista mare
- incerc sa sterg lista initiala, ca sa pun noile valori in ea, noile valori fiind
cele mediane, conform cerintei
-tot asa iau subliste de cinci elemente, de data aceasta chiar creand o sublista
-valoarea rezultata in urma ordonarii se pune in lista mare
-timestampul ramane acelasi, dar l-am pus intr-o variabila toadd1, ca sa-mi fie
oarecum mai usor la functia de adaugare in lista 
-eliberez tot ce am alocat; incercat cu valgrind si merge, de aceea am eliberat asa

la 2.3: aici parcurg lista fara nod auxiliar si fac media intre valorile din
nodurile vecine, asa cum cere cerinta, cand apare o diferenta la timestampuri
de intre 100 si 1000

la 2.5:
-iau o functie de minim si una de maxim, care calculeaza valorile minima si maxima
din lista, in functie de campul value din structura; 
-delta1 si delta2 au la inceput valorile de valoarea minima si delta
-cele doua delta1 si delta2 cresc pe parcurs cu delta, pana se ajunge la valoarea maxima
-de fiecare data se numara cate valori din lista sunt intre delta1 si delta2
-si daca e macar unul, se afiseaza intervalul si numarul de elemente

in main:
-aloc lista, mai bine zis capul de lista si il leg la null
-citesc numarul de noduri si elementele de la tastatura si le inserez
-ficare functie one, twoone,twotwo,three,five (de four nu am reusit) corespund
unui argument
-ok=1 nu e statistica, deci se afiseaza lista mare =>nu e ok=1, deci nu se afiseza
lista, ci doar statistica
-iar la final se elibereaza elementele din lista mare



