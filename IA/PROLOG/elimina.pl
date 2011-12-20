
elimina(_N,[],[]).
elimina(N,[Y|R],[Y|W]) :-
   Y >= N,
   elimina(N,R,W).

elimina(N,[Y|R],W) :-
   Y < N,
   elimina(N,R,W).
