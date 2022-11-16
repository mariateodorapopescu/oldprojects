function y = Apartenenta(x, val1, val2)
	% Functia care primeste ca parametrii x, val1, val2 si care calculeaza valoarea functiei membru in punctul x.
	% Stim ca 0 <= x <= 1
    % u(x)={0, x=0:val1; a*x+b, x=val1:val2; 1, x=val2:1; u continua
    % ca u sa fie continua, am trecut la limita =>
    % => lim(x->val1)(a*x+b)=0&&lim(x->val2)(a*x+b)=1=>
    a = 1 / (val2 - val1);
    b = val1 / (val1 - val2);
    if x >= 0 && x < val1
        y = 0;
    end
    if x >= val1 && x <= val2
        y = a * x + b;
    end
    if x > val2 && x <= 1
        y = 1;
    end
end
