problema 1
-mi-a luat doua ore
-cu ajutorul unei structuri de date am imagazinat intr-un vector de cuvinte
perechea de cuvinte si gradul acesteia
-dupa calculul gradului cu ajutorul unui fel de vector caracteristic de litere,
am sortat mai intai cuvintele din vectorul acela de cuvinte descrescator in
functie de grad, apoi in ordine descrescrescator lexicogrfica, tinand cont
de ordinea gradelor

problema 2
-mi-a trebuit pentru rezolvare o zi
-tot cu ajutorul unei structuri de date, am stocat intr-un vector coordonatele
fiecarui nebun (x-ul si y-ul sau), tabla de sah fiind vazuta ca un plan 2D, 
dar si ca o matrice de 1 si de 0
-tot la citire, atunci cand formam vectorul de mai sus, am format si o matrice
patratica de mXm cu 1 pe pozitiile unde era un nebun. matricea aceasta ajuta
la verificarea daca se poate muta un nebun asa incat sa nu se atace cu niciunul
-la prima parte a problemei, se numara perechile de pioni de pe aceeasi
diagonala (diagonala principala sau paralela cu cea principala a tablei, adica
de la stanga spre dreapta, sau secundara si cele paralele cu ea, adica
diagonalele de la dreapta spre stanga) si se afiseaza acest numar.
-daca numarul calculat anterior nu este egal cu 1, atunci se afiseaza "NU"
-verificarea pozitiilor optime de mutare (partea a doua a problemei) se face
cautand in matricea de pozitii/matricea de nebuni/matricea-tabla pozitii cu 0.
-daca s-a gasit una libera, adica cu 0, atunci se verifica daca, un nebun ce 
s-ar afla pe acea pozitie s-ar ataca cu fiecare celalt pion de pe tabla
-daca nu se ataca, atunci de marcheaza ok=1, o variabila de verificare a
gasirii unei posibilitati de mutare si se afiseaza "DA".
-daca se ataca, se cauta alta pozitie.
-daca nu s-a gasit o pozitie potrivita, adica daca dupa ce am cautat pe toata
tabla avem ok=0, atunci se afiseaza "NU".

problema 3
-nu am inteles ce anume cere mai exact

problema 4
-se stie ca se citesc opt numere, deci la citire facem un vector cu opt numere
-fiecare numar este transformat in baza doi, dar cu opt biti/opt cifre
-apoi fiecare numar din acela in baza doi se pune intr-o matrice de siruri 
-acea matrice se transfoma intr-una de tip int
-se face transpusa
-se face inmultirea cu transpusa si cu ea insasi si aceste produse se
inmagazineaza in doua matrice int diferite 
-se calculeaza scorul fiecarei matrice
-se fac trei scoruri: scor matrice normala, scor a*a(transpus) si scor a^2
-se calculeaza maxim scoruri
-se face o copie a matricii cu scorul maxim
-se transforma matricea cu scorul maxim (care e de tip int) in matrice de siruri
-fiecare linie/sir din matricea noua de siruri se transforma in zecimal
si se afiseaza fiecare
