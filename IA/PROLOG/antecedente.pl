antecedente([],_L).
antecedente([X|R],[X|F]) :-
   antecedente(R,F).
