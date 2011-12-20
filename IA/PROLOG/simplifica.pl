simplifica([],[]).
simplifica([X|R],NR) :-
   member(X,R),
   simplifica(R,NR).

simplifica([X|R],[X|NR]) :-
   not(member(X,R)),
   simplifica(R,NR).
