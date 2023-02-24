#Cryptography in ASM
Full explanations about the implementation in Romanian --->

task-1:
- pun o litera din sursa, apoi adaug la litera aceea pasul. daca depaseste literele mari,
scad 26, ca sa ramana litera mare. apoi ma intorc in bucla for. daca nu, continua.
- verific daca litera continuta in al are valoarea in cod ascii mai mare decat Z
si verific si scad de fiecare data, cat e necesar, pana cand litera e mai mica decat Z
- daca totusi litera respectiva face parte din alfabet, nu scad si nu adaug, ci merg mai departe
- la final, pun cate un caracter in textul criptat, iar daca am terminat de iterat prin sir, inchid programul

task-2
1.
- initial ar fi fost: sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
- dar, cand e paralel cu ox => diferenta de y-uri e 0, deci rezultatul e x2 - x1
- cand e paralel cu oy => diferenta de x-uri e 0, deci rezultatul e y2 -y1
- verifica daca DOAR doua puncte au acelasi x
- iau registre mici, gen cl, dl pentru ca lucrez cu numere mici, asta din ce am observat din teste
- daca as fi folosit registre mai mari, ar fi fost in ele alte valori, fiind completat cu f-uri
- de mentionat faptul ca in cl si in dl se mentin, 
- dupa caz x-urile (sau y-urile) primului, respectiv celui de-al doilea punct. 
- iau mai intai x-urile a doua puncte. daca nu sunt egale x-urile, fac diferenta dintre ele
- daca sunt, trec mai departe si fac diferenta de y-uri.
de aceea muta in cl pe y al primului punct
- verific ordinea lor ca sa se faca diferenta in absoult. daca cel de-al doilea e mai mare,
fac diferenta direct; daca e invers, atunci scad din al doilea pe primul
- la final mut in destinatie diferenta si inchid programul

2.
- e asemanator ca la 1, doar ca iau cate 2 cate 2 de data asta nu random, ci dintr-un vector
- iau x-ul punctului de la indexul edx, care initial e 0, ca porneste de la inceput
apoi x-ul punctului urmatorul celui pe care l-am luat
- le compar, si daca nu-s egale fac difernta intre x-uri
- altfel, iau y-urile si fac diferenta intre ele
- verific care dintre ele e mai mare ca sa iau diferenta in absolut
- daca a doua e mai mare decat prima, scad din al doilea pe primul
- daca primul e mai mare, atunci face diferenta normal
- daca atat x-urile, cat si y-urile sunt egale, pun 0 in regsitrul in care se cere rezultatul
- pe urma adaug in registrul destinatie, apoi trec la urmatorul punct din vector
- compar adresa/indexul la care ma agflu sa stiu daca mai am elemente in vector
- daca mai am, atunci reiau. daca nu mai sunt elemente de verificat in vector, atunci inchid programul

3.
- in C ar veni cam asa:
 for (i = nr_elem_vector - 1; i >= 0; i--)
 for (j = 1; j <= elem_curr_vector; j++)
 if (j * j == elem_curent_din_vector)
 *atunci pune 1 in vectorul in care se cere rezultatul*
- dar e asm, deci: 
- iau elementul curent din vector
- mai intai presupun ca nu e patrat perfect, de aceea pun 0 im vectoruld destinatie
- intru intr-o bucla cu nume de for sugestiv cum am explicat mai sus cu un fel de j
- fac patratul j-ului si il compar cu elementul curent din vector
- daca e radacina lui, atunci ma duc la label-ul in care pune 1
- daca nu, trec mai departe
- si daca a trecut mai departe, trece la urmatorul factor, ca sa aflu radacina, 
in cazul in care e patrat perfect
- compara cu numarul ca sa stiu cand ies din for-ul sugestiv cu j
- si daca am terminat cu verificarea existentei radacinii (fie ca am gasit-o, fie ca nu), 
atunci trec mai departe in vector si vad daca mai am de verificat elemente din vector sau nu
- daca da, reia for-ul cu i sugestiv; daca nu, atunci ies din program

task-3:
- in edi mut dimensiunea textului in clar
- iterez prin sirul in clar
- pun cate un caracter din cheie aici pentru ca sa completez, sa repet cheia 
cat sa aiba cate caractere are clarul
- incerc sa iau un fel de for (j = strlen(cheie)-1; j >= 0; j--)
fiind o modalitate buna de a ma ajuta sa trec prin cheie
- iterez prin cheie pana cand ajung la final, ca sa o pun intr-un sir in care sa o repet
- iau adresa cheii, iau adresa textului in clar, fac diferenta dintre adrese, ca sa stiu cat sa completez
- ideea principala e sa completez cheia cu ea insasi cat sa ajunga de lungimea textului in clar ca sa trec prin
amandoua in acelasi timp
- mut noua dimensiune ramasa ca sa stiu cat iterez, cat prelungesc
- merg la inceputul cheii prelungite ca sa ma pregatesc sa parcurg simultan in cheie si in textul in clar
- iau un caracter din cheia prelungita, il compar cu un caracter din textul in clar, fac diferenta
dintre cheie si clar, conform formulei descoperite cu ajutorul uneia de pe wiki
- formula suna cam asa: carac_cheie - carac_clar + litera_A (adica 65 in ascii); daca e mai mic, adaug 26 sa ma intorc in alfabetul cu litere mari. daca depaseste, scad
- mut in destinatie ce am modificat. merg mai departe in cheia prelungita, dar si cu textul in clar.

task-4:
- matricea o impart intr-un fel de patrate concentrice/unul in celalalt, pe care le parcurg astfel:
- mai intai latura de sus, apoi latura din dreapta, apoi latura de jos si la urma latura din stanga
- ca sa fie mai interativ: impart matricea in k patrate, in functie de paritatea lui N
- o sa fac discutie dupa paritatea lui N mai incolo
- iau linia k, apoi coloana N-k, apoi linia N-K apoi coloana k. 
- iau lungimea unei linii din matrice, dar si a unei coloane din matrice (sunt la fel),
mai ales ca este matrice patratica
- iau adresa primului element din matrice si pun intr-un registru separat dimensiunea unui int
- acea dimensiune pe care am luat-o mai devrem o fac 16 pentru ca am 4 pentru linie, 4 pentru coloana.
- practic, asta ma ajuta sa ma deplasez de pe o linie pe alta. 
- iau un fel de for ( k = N; k >= 0; k--) dar e cu label-ul fork (for k)
- fiecare patrat are dimensuiune k si dimensiunea lor creste succesiv
- verific daca am ajuns la elementul 0
- fac verificarea pe caz a lui k si N. aici verific sa vad daca N e impar sau nu
- resetez contorul cum ar veni
- iau linia k, pun caracterul (in ascii) din cheie, adica din matrice si il adaug la 
caracterul din textul in clar, conform formulei
- adaug 1 ca sa trec la urmatorul element din textul in clar
- adaug 4 ca sa trec la elementul urmator din linie
- continui iterarea prin linie. daca nu mai am elemente prin linie, mut inapoi in contor dimensiunea, 
pentru cand voi lua coloana n-k
- se va repeta logica aceasta, doar ca atunci cand se merge pe coloane se adauga 16 (pentru ca ma mut de pe o
linie pe alta).
se adauga 4, respectiv 16 cand merg de la dreapta spre stanga pe linia de sus, pe coloana din dreapta, apoi
merg de la final catre inceput (deci se scade 4 respectiv 16)
pe linia de jos si pe coloana din stanga a patratului.
- aici se intampla asemanator ca la parcurgerea liniei k (lk), doar ca nu mai adaug patru ci 16, ca ma duc pe o linie mai in jos
- dupa ce a facut un patrat, merg mai departe, adaug adresa la care am ajuns si inca 1 
ca sa trec in patratul din interior
- scad din dimensiunea unui patrat 1 ca se micsoreaza patratele in mod progresiv
- dupa ce ies din fork (for k) care ia patratele, mut inapoi ce era la inceput 
in registre ca sa ma ajute la pus caracterele prelucrate in sirul criptat
- iau textul in clar, care a fost modificat si pun in destinatie. 
- trec la urmatorul caracter din clarul modificat, la fel si in ceea ce pun ce am modificat, asta doar daca mai am elemente in clarul modificat








