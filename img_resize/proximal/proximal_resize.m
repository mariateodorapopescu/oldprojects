function R = proximal_resize(I, p, q)
    % =========================================================================
    % Se scaleaza imaginea folosind algoritmul de Interpolare Proximala.
    % Transforma imaginea I din dimensiune m x n �n dimensiune p x q.
    % =========================================================================
    [m n nr_colors] = size(I);

    % Se converteste imaginea de intrare la alb-negru, daca este cazul.
    if nr_colors > 1
        R = -1;
        return
    endif

     % TODO: Initializeaza matricea finala drept o matrice nula.
    
    R = size(p, q);
    for i = 1 : p
      for j = 1 : q
        R(i, j) = 0;
      endfor
    endfor

    % Obs:
    % Atunci c�nd se aplica o scalare, punctul (0, 0) al imaginii nu se va deplasa.
    % �n Octave, pixelii imaginilor sunt indexati de la 1 la n.
    % Daca se lucreaza cu indici de la 1 la n si se �nmultesc x si y cu s_x respectiv s_y,
    % atunci originea imaginii se va deplasa de la (1, 1) la (sx, sy)!
    % De aceea, trebuie lucrat cu indici �n intervalul [0, n - 1].

    % TODO: Calculeaza factorii de scalare.
    % Obs: Daca se lucreaza cu indici din intervalul [0, n - 1], ultimul pixel
    % al imaginii se va deplasa de la (m - 1, n - 1) la (p, q).
    % s_x nu va fi q ./ n
    
    s_x = (q-1) ./ (n-1);
    s_y = (p-1) ./ (m-1);

    % TODO: Defineste matricea de transformare pentru redimensionare.
    
    T = [s_x, 0; 0 s_y];

    % TODO: Inverseaza matricea de transformare, FARA a folosi functii predefinite!
    
    Tinv = invert(T);
    
    % Se parcurge fiecare pixel din imagine.
    
    pixel = 0;
    for y = 0 : p - 1
        for x = 0 : q - 1
          
            % TODO: Aplica transformarea inversa asupra (x, y) si calculeaza x_p si y_p
            % din spatiul imaginii initiale.
            
            v = [x, y];
            v = v * Tinv;
            x_p = v(1);
            y_p = v(2);
            
            % TODO: Trece (xp, yp) din sistemul de coordonate [0, n - 1] in
            % sistemul de coordonate [1, n] pentru a aplica interpolarea.
            
            x_p = x_p + 1;
            y_p = y_p + 1;
            
            % TODO: Calculeaza cel mai apropiat pixel.
            
            x_p = round(x_p);
            y_p = round(y_p);
            
            % TODO: Calculeaza valoarea pixelului din imaginea finala.
            
            pixel = I(y_p, x_p);
            R(y + 1, x + 1) = pixel;
        endfor
    endfor

    % TODO: Transforma matricea rezultata �n uint8 pentru a fi o imagine valida.
    
    R = uint8(R);

endfunction
