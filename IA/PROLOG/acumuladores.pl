
basica(llanta).
basica(radio).
basica(manillar).
basica(engranaje).
basica(tornillo).
basica(trasero).
basica(tuercas).
basica(horquilla).

ensamblada(bici,[rueda,rueda,marco]).
ensamblada(rueda,[radio,llanta,centro]).
ensamblada(marco,[trasero,delantero]).
ensamblada(centro,[engranaje,eje]).
ensamblada(eje,[tornillo,tuercas]).
ensamblada(delantero,[horquilla,manillar]).

piezas(X, Ac, [X|Ac]) :- basica(X). 
piezas(X, Ac, L) :- ensamblada(X, ListPiezas), 
		    piezaslistaAc(ListPiezas, Ac, L). 

piezaslistaAc([], Ac, Ac). 
piezaslistaAc([X|T], Ac, L) :- piezas(X, Ac, PiezasCabeza), 
			       piezaslistaAc(T, PiezasCabeza, L).


piezasNew(X, [X]) :- basica(X). 
piezasNew(X, L) :- ensamblada(X, ListPiezas), 
		   piezaslista(ListPiezas, L).

piezaslista([], []). 
piezaslista([X|T], L) :- piezasNew(X, PiezasCabeza), 
			 piezaslista(T,PiezasCola),
			 append(PiezasCabeza, PiezasCola, L).
