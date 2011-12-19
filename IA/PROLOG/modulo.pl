modulo(0,X,X).
modulo(_X,1,0).

modulo(M,N,X) :-
   N > 0,
   M > N,
   A is M div N,
   B is N*A,
   X is M - B.

modulo(M,N,X) :-
   not(M < N),
   M1 is M - N,
   modulo(M1,N,X).
