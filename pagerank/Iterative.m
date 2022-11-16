function R = Iterative(nume, d, eps)
	% Functia care calculeaza matricea R folosind algoritmul iterativ.
	% Intrari:
	%	-> nume: numele fisierului din care se citeste;
	%	-> d: coeficentul d, adica probabilitatea ca un anumit navigator sa continue navigarea (0.85 in cele mai multe cazuri)
	%	-> eps: eroarea care apare in algoritm.
	% Iesiri:
	%	-> R: vectorul de PageRank-uri acordat pentru fiecare pagina.
fid = fopen (nume,'r'); % deschide fisierul
N = fscanf(fid,'%d',1); % citeste numarul de noduri
A = zeros(N,N); % initializez pe A cu 0
O = ones(N,1); % initializez pe O cu 1; O de la ones, adica 1-uri
K = zeros(N,N); 
% initializez ce se poate cu 0 sau cu 1, depinde de situatie
R = ones(N,1);
RU = zeros(N,1); % R calculat la urmatorul pas
% mai sus sa zicem ca mi-am declarat deja o parte din variabilele folosite
% citesc linie cu linie
for i = 1 : N % sunt N noduri, deci N, linii cu informatii
    nod = fscanf(fid,'%d',1); % primul element din "linie" este nodul
    nrnoduri = fscanf(fid,'%d',1); % al doilea de pe "linie" este numarul de noduri
    for j = 1 : nrnoduri % acum iau fiecare nod din "linia" citita
        nod2 = fscanf(fid,'%d',1);
        if nod ~= nod2
        A(nod, nod2) = 1; % si fac matricea de adiacenta
        end
    end
end
fclose(fid); % nu uit sa inchid fisierul
% acum ca am citit datele din fisier, calculez matricea stocastica M
    for i = 1 : N 
    nr = 0;
    for j = 1 : N 
        if A(i,j) ~= 0
            nr = nr + 1;
        end
            K(i,i) = nr; % K este matricea de grade
    end
    end
M = (PR_Inv(K) * A)'; % asa am aflat matricea stocastica, conform algoritmului de pe wiki
% acum calculez in continuare conform algoritmului de pe wiki
% R si RC sunt vectori =>
R = R .* (1 / N); % asa e in algoritm; presupunem ca la inceput se distribuie exact la cele N pagini
while abs(R - RU) >= eps 
   RU = R;
   R = d * M * R + ((1 - d) / N) * O;
end
end