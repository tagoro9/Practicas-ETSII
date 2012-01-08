suma(X, N) :- sumaAc(X, 0, N). 
prodEscalar(L1, L2, Resultado) :- prodEscalar(L1, L2, 0, 
Resultado). 
longitud(L, N) :- longitudAc(L, 0, N). 
piezas(X, L) :- piezas(X, [], L). 
