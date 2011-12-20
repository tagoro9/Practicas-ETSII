suma(_X,[],[]).
suma(X,[Y|R],[Y|B]) :-
	suma_par(X,R,B).

suma_par(_X,[],[]).
suma_par(X,[Y|R],[A|B]) :-
	A is +(X,Y),
	suma(X,R,B).
