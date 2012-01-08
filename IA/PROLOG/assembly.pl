
basicPart( spokes ).
basicPart( rim ).
basicPart( tire ).
basicPart( inner_tube ).
basicPart( handle_bar ).
basicPart( front_fork ).
basicPart( rear_fork ).

assembly( bike, [ wheel, wheel, frame ]  ).
assembly( wheel, [ spokes, rim, wheel_cushion ]  ).
assembly( wheel_cushion, [ inner_tube, tire ]  ).
assembly( frame, [ handle_bar, front_fork, rear_fork ]  ).

partsof( X , P )  :-  partsacc( X , [] , P ).
partsacc( X , A , [ X | A ] )  :-  basicPart( X ).
partsacc( X , A , P )  :-  assembly( X , Subparts ) ,
			    partsacclist( Subparts , A , P ).
partsacclist( [] , A , A ).
partsacclist( [ P | Tail ] , A , Total ) :-  partsacc( P , A , HeadParts ),
					      partsacclist( Tail , HeadParts , Total ).



