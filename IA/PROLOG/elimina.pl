
elimina(_X,[],[]).
elimina(X,[Y|W],[Y|Z]) :- X<Y, elimina(X,W,Z).
elimina(X,[_Y|W],Z):- elimina(X,W,Z).

%elimina(_,[],[]).
%elimina(N,[Y|W],[Y|Z]) :- write('Y vale: '), write(Y), nl, Y>=N, elimina(N,W,Z).
%elimina(N,[_|W],[Z]) :- elimina(N,W,Z).
