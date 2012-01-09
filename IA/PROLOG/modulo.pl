modulo(0,X,X).
modulo(_X,1,0).
modulo(X,X,0).

modulo(M,N,X) :-
   N > 0,
   M > N,
   A is M-N,
   modulo(A,N,X).

modulo(M,N,X) :-
   M < N,
   X is M.
