suma_lista(X,[],[]).
suma_lista(X,[Y|R],[Y|B]) :-
	suma_par(X,R,B).

suma_par(X,[],[]).
suma_par(X,[Y|R],[A|B]) :-
	A is +(X,Y),
	suma_lista(X,R,B).
