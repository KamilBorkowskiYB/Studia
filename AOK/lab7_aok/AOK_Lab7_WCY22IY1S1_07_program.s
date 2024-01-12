;nr 7
.data
TA: .space 480
TB: .space 440
Suma: .double 0

.text
addi r7, r0, #0 ; suma
addi r1, r0, #107 ; pierwszy element TA
addi r20, r0, TA ; i dla TA
sw 0(r20), r1 ;przypisanie pierwszego elementu
addi r30, r0, #119 ; i dla petli1

petla1:
lw r2, 0(r20)
addi r15, r2, #1
subi r30, r30,#1
addi r20, r20, #4
sw 0(r20), r15
bnez r30,petla1

addi r30, r0, #110 ; nowe i dla petli2
addi r20, r0, TA ; i dla TA
addi r21, r0, TB ; i dla TB

petla2:
addi r22, r20, #16 ; i+4
lw r22, 0(r22) ; TA[i+4]
addi r23, r20, #36 ; i+9
lw r23, 0(r23) ; TA[i+9]
add r24, r22, r23 ;TA[i+4] +TA[i+9]
addi r25, r0, #32
multu r25, r25, r24
sw 0(r21), r25
addi r20, r20, #4 
addi r21, r21, #4
subi r30, r30, #1
bnez r30,petla2 

addi r30, r0, #110 ; nowe i dla petli2
addi r21, r0, TB ; i dla TB

petla3:
lw r2, 0(r21)
add r7, r7, r2
addi r21, r21, #4
subi r30, r30, #1
bnez r30, petla3

;movi2fp f7, r7
;cvti2d f10, f7
;sd Suma, f10

trap 0