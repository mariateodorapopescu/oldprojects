function R = Algebraic(nume, d)
	% Functia care calculeaza vectorul PageRank folosind varianta algebrica de calcul.
	% Intrari: 
	%	-> nume: numele fisierului in care se scrie;
	%	-> d: probabilitatea ca un anumit utilizator sa continue navigarea la o pagina urmatoare.
	% Iesiri:
	%	-> R: vectorul de PageRank-uri acordat pentru fiecare pagina.
fid = fopen (nume,'r'); % deschide fisierul
N = fscanf(fid,'%d',1); % citeste numarul de noduri
A = zeros(N,N); % initializez pe A cu 0
O = ones(N,1); % initializez pe O cu 1; O de la ones, adica 1-uri
K = zeros(N,N); 
% initializez ce se poate cu 0 sau cu 1, depinde de situatie
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
O = O .* ((1-d) / N); % asta va fi [(1-d)/N; (1-d)/N; ...; (1-d)/N] din algoritm
% R = [(1-d)/N; (1-d)/N; ...; (1-d)/N] + d * M * R; M este stocastica
% unde [(1-d)/N;(1-d)/N; ...; (1-d)/N] = O (asa l-am notat eu)
B = eye(N) - d * M; % daca din algoritm trec ce e cu R intr-o parte si
% restul in alta parte (initial: R = O + d * M * R => R - d * M * R = O)
% => (eye(N) (adica un fel de 1, ca am dat factor comun) - d*M)*R = O
% iar coeficientul lui R l-am notat cu B (nu stiu ce nume sa le pun)
% BINV e inversa lui B => B * R = O
BINV = PR_Inv(B);
R = BINV * O;
end