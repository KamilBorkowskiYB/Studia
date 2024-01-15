;nr 7
.data
skladnik: .double 1770
ulamek: .double 0.77
rozmiar: .double 107
T: .space 1040
TB: .space 856
suma: .double 0
nr: .double 7.0
inkrement: .double 1
mnoznik: .double 7.7

.text 

ld f0, skladnik
ld f2, ulamek
addd f2, f0, f2
ld f0, nr
addd f2, f2, f0

addi r1,r0, T ;adres
addi r2,r0, #129 ;i  dla petli
sd 0(r1),f2
ld f0, inkrement

petla:
addi r1,r1,#8
addd f2,f2, f0
sd 0(r1),f2
subi r2,r2,#1
bnez r2,petla


addi r1,r0, T ;adres T
addi r2,r0, TB ;adres TB
addi r3,r0, #107 ;i  dla petli

petla2:
ld f0, 0(r1);T[i]
ld f2, 16(r1);T[i+2]
ld f4, 24(r1);T[i+3]
ld f6, 40(r1);T[i+5]
ld f8, 56(r1);T[i+7]
ld f10, 72(r1);T[i+9]

addd f12, f0, f4
addd f12, f12, f6;p1

addd f14, f8, f10;p2

subd f16, f2, f0;p3

ld f18, mnoznik
multd f20, f18, f12
multd f20, f20, f14
divd f20, f20, f16

sd 0(r2),f20
addi r1,r1,#8
addi r2,r2,#8
subi r3,r3,#1
addd f22, f22, f20
bnez r3, petla2
sd suma, f22
trap 0;
;Pierwszy element TB
;T[0]=1777,77	T[2]=1779,77	T[3] = 1780,77	T[5] = 1782,77	T[7] = 1784,77 T[9] = 1786,77
;TB[0]=(7.7*(1777,77+1780,77+1782,77)*(1784,77+1786,77))/(1779,77-1777,77)=(7.7*5341,31*3571,54)/2=146890607,8/2=73445303,92
;Ostatni element TB
;T[106]=1883,77	T[108]=1885,77	T[109] = 1886,77	T[111] = 1888,77	T[113] = 1890,77	T[115] = 1892,77
;TB[106]=(7.7*(1883,77+1886,77+1888,77)*(1890,77+1892,77))/(1885,77-1883,77)=(7.7*5659,31*3783,54)/2=164874138,3/2=82437069,17