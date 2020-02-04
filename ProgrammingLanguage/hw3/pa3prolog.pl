mother(X,Y):-female(X),parent(X,Y).
father(X,Y):-male(X),parent(X,Y).
child(X,Y):-parent(Y,X).

sibling(X,Y):-parent(Z,X),parent(Z,Y).
sister(X,Y):-female(X),sibling(X,Y).
brother(X,Y):-male(X),sibling(X,Y).

daughter(X,Y):-female(X),parent(Y,X).
son(X,Y):-male(X),parent(Y,X).

uncle(X,Y):-male(X),parent(Z,Y),sibling(X,Z).
aunt(X,Y):-female(X),parent(Z,Y),sibling(X,Z).

cousin(X,Y):-uncle(Z,Y),child(X,Z).
cousin(Y,X):-uncle(Z,Y),child(X,Z).
cousin(X,Y):-aunt(Z,Y),child(X,Z).
cousin(Y,X):-aunt(Z,Y),child(X,Z).


male(zues).
male(alan).
male(mark).
male(mel).
male(richard).

female(amy).
female(bitsy).
female(fran).
female(janny).
female(joan).
female(rosa).

parent(amy, janny).
parent(amy, richard).
parent(amy, joan).
parent(janny, bitsy).
parent(janny, alan).
parent(joan, fran).
parent(mark, janny).
parent(mark, richard).
parent(mel, joan).
parent(richard, zues).
parent(richard, rosa).