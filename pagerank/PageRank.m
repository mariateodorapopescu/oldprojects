function [R1, R2] = PageRank(nume, d, eps)
	% Calculeaza indicii PageRank pentru cele 3 cerinte
	% Scrie fisierul de iesire nume.out
    fid = fopen (nume,'r'); % deschide fisierul
N = fscanf(fid,'%d',1); % citeste numarul de noduri
A = zeros(N,N); % initializez pe A cu 0
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
val1 = fscanf(fid,'%f',1);
val2 = fscanf(fid,'%f',1);
fclose(fid); % nu uit sa inchid fisierul
% dupa ce am citit datele din fisier si am facut matricea de adiacenta
% calculez vectorii prin cele doua metode
R1 = Iterative(A,d,eps);
R2 = Algebraic(A,d);
str1 = nume;
str2 = '.out';
filename = strcat(str1, str2);
fileID = fopen(filename,'w');
fprintf(fileID,'%d\n',N);
fprintf(fileID,'\n');
fprintf(fileID,'%.6f\n',R1);
fprintf(fileID,'\n');
fprintf(fileID,'%.6f\n',R2);
fprintf(fileID,'\n');
CPY = R2;
for i = 1 : N
    for j = (i+1) : N
        if CPY(i) < CPY(j)
            aux = CPY(i);
            CPY(i) = CPY(j);
            CPY(j) = aux;
        end
    end
end
for i = 1 : N
    fprintf(fileID,'%d ',i);
    for j = 1 : N 
        if CPY(i) == R2(j)
            fprintf(fileID,'%d ',j);
        end
    end
    F = Apartenenta(CPY(i),val1,val2);
    fprintf(fileID,'%.6f\n',F);
end 
end
