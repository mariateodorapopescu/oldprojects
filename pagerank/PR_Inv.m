function B = PR_Inv(A)
	% Functia care calculeaza inversa matricii A folosind factorizari Gram-Schmidt
    % am inceput prin a face factorizarea QR cu Gram-Schimdt
    % iau fiecare vector coloana al matricei A, iar pe urmatorii vectori
    % coloana din matrice ii "indrept" si il normez (adica il ortonormez) pe cei de 
    % dupa cel pe care l-am luat; 
[m, n] = size(A); % iau dimensiunile lui A pentru a sti cat sa aloc pentru Q si pentru R
V = A; % ii fac o copie
Q = zeros(m,n); % mai intai Q si R sunt matrice nule
R = zeros(n,n);
B = zeros(m,n); % fac si inversa lui A initial nula
for i = 1 : n
    R(i,i) = norm(V(:,i),2); 
    % fac norma vectorului coloana a lui A (sau mai bine zis al lui V, copia lui A)
    Q(:,i) = V(:,i)/R(i,i); % il normez
    % sa zicem ca asa am normat o coloana matricea A
    % apoi trebuie sa indrept coloanele ramse in functie de cea normata
    for j = (i + 1) : n
        R(i,j) = Q(:,i)' * V(:,j);
        V(:,j) = V(:,j) - R(:,i) * Q(i,j);
        % algoritmul acesta a fost preluat din lab3
    end
end
% acum rezolv sistemul de n ori, afland cate o coloana pentru B = AINV
% A = Q * R, A * AINV = IN adica Q * R * AINV = IN,DE UNDE IL SCOT PE AINV;
% Q^(-1) = QINV = Q' si il trec in partea celalata si rezulta: R * AINV = Q'
QT = Q';
for i = 1 : n % Q are n coloane si m linii
    % mai pe scurt, rezolv sistemul de n ori
% iau cate o coloana din Q', adica din QT (Q Transpus)
% elementul de pe linia m (ultima), coloana i 
B(m,i) = QT(m,i); % B(:,i) este, de fapt, necunoscuta x din SST
% termenul liber al sistemului este vectorul coloana i al matricei QT (Q')
% adica QT(:,i);
    for j = (m-1) : 1 % se ia de jos in sus
        sum = 0;
        for k = (j + 1) : m
            sum = sum + R(j,k)* B(k,i); % mereu e coloana i ca se ia pe coloane
        end
        B(j,i) = (QT(j,i) - sum) / R(j,j);
    end
end
end
