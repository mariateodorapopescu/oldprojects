Am facut tema in Matlab. Mi-a luat 2 zile. Nu am mai facut si alte functii
pe langa cele date.

la PR_Inv:
-am inceput prin a face factorizarea QR cu Gram-Schimdt. am luat fiecare
vector coloana al matricei A, iar pe urmatorii vectori coloana din matrice
ii "indrept" si ii normez pe cei de dupa cel pe care l-am luat; 
-am luat dimensiunile lui A pentru a sti cat sa aloc pentru Q si pentru R.
mai intai Q si R sunt matrice nule, dar si inversa lui A. fac o copie lui a, pe V
-am facut norma vectorului coloana a lui V, il normez, apoi indrept coloanele
ramse in functie de cea normata
-am rezolvat sistemul de n ori, afland cate o coloana pentru B, adica inversa
lui A, luand cate o coloana din Q transpus
-Q * R * B = IN,de unde il scot pe B; IN = eye(N) notez asa aici. il trec in
partea celalata si rezulta: R * B = Q'
-mai intai am calculat elementul de pe linia m (ultima), coloana i 
-B(:,i) este, de fapt, necunoscuta x din SST
-termenul liber al sistemului este vectorul coloana i al matricei QT (Q')
-se ia de jos in sus
-mereu e coloana i ca se ia pe coloane

la PageRank:
-dupa ce am citit datele din fisier (algoritmul se repeta si pentru Iterative,
Algebraic; o sa il detaliez numai pentru iterative) calculez vectorii
prin cele doua metode
-apoi am alipit continutul variabilei nume cu ".out" pentru a crea numele
fisierului de iesire. am deschis un alt fisier pentru scriere si am scris
mai intai numarul de noduri, apoi elementele celor doi vectori ceruti.
-am facut o copie celui de-al doilea vector si am sortat copia cu
algoritmul de sortare prin interschimbare; pe urma am luat doua foruri,
si am verificat pentru ce indici ale lui R2 si copiei sale sortate corespund
elementele, scriind, astfel, pozitia si pozitia relativa.
-apoi am calculat si F-ul din enunt, adica gradul de apartenenta pentru copia
sortata si am afisat.

la Iterative:
-am deschis mai intai fisierul. Am citit numarul de noduri. am initializat ce se
poate cu 0 sau cu 1, depinzand de situatie, de exemplu A, K sunt zerouri, O e unuri
-am initializat vectorii coloana R, si RU, RU fiind R calculat la pasul urmator
-am citit linie cu linie. sunt N noduri, deci N linii cu informatii. apoi, pe rand,
am citit primul nodul, numarul de noduri adiacente cu el si am luat fiecare nod adiacent
cu el intr-un for si am pus 1-uri unde nu se intalnea nodul adiacent cu el insusi,
facand, astfel, matricea de adiacenta.
-dupa citirem nu uit sa inchid fisierul
-acum ca am citit datele din fisier, calculez matricea stocastica M, cu ajutorul
matricei K, cea de grade, care este o matrice diagonala. am luat liniile si am numarat,
cate 1-uri sunt in matricea de adiacenta, adica cu cate noduri e adiacent nodul a carui
coloana din matrice corespune. Puteam sa fac asta si la citire, dar nu-mi am dat seama.
numarul calculat l-am pus pe diagonala principala a matricei K. I-am facut apoi inversa
cu ajutorul lui PR-Inv si am inmultit-o cu cea de adiacenta, afland, astfel, 
matricea stocastica, conform algoritmului de pe wiki.
-am calculat in continuare conform algoritmului de pe wiki pe R. R si RC sunt vectori,
deci inmultesc fiecare element din R cu 1/N, presupunand ca la inceput se distribuie
exact numarul de accesari la cele N pagini, apoi calculez iterativ pana cand diferenta
in modul dintre R si R calculat la pasul urmator este data de prag.

la Apartenenta:
-u(x)={0, x=0:val1; 
       a*x+b, x=val1:val2;   u continua
       1, x=val2:1; 
-ca u sa fie continua, am trecut la limita: lim(x->val1)(a*x+b)=0&&lim(x->val2)(a*x+b)=1
=> a=1/(val2-val1) si b=val1/(val1-val2) si am inlocuit pe a si b din definita functiei
si am luat pe cazuri

la Algebraic:
-dupa ce am citit datele din fisier (algoritmul se repeta si pentru Iterative,
si pentru PageRank; am detaliat numai pentru Iterative), am luat un vector coloana numai
cu unuri, numit O de la Ones. si am inmultit fiecare element al sau 
cu ((1-d) / N); asta va fi O=[(1-d)/N; (1-d)/N; ...; (1-d)/N] din algoritm
-R = [(1-d)/N; (1-d)/N; ...; (1-d)/N] + d * M * R, comform wiki
-B = eye(N) - d * M;  daca din algoritm trec ce e cu R intr-o parte si
restul in alta parte (initial: R = O + d * M * R => R - d * M * R = O)
=> (eye(N) (adica un fel de 1, ca am dat factor comun) - d*M)*R = O
iar coeficientul lui R l-am notat cu B (nu stiu ce nume sa le pun)
BINV e inversa lui B => B * R = O, calculata cu PR-Inv
