potencia(_,0,1).
potencia(X,N,Z) :- N > 0, M is N - 1, potencia(X,M,C), Z is C*X.
