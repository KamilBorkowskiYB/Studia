%Kamil Borkowski WCY22IY1S1 22.05.2024
%wariant 14
%dane:
%C1 = 10
%C2 = 5
%R1 = 1
%R2 = 2
C1 = 10
C2 = 5
R1 = 1
R2 = 2

a0=1/(R1 *C1)
a1=1/(R1*C2)
a2=1/(R2*C2)

b1=1/C1


A=[-a0 a0; a1 -a1-a2]
B=[b1; 0]
C=[0 1]
D=[0]

plot(tout, yout)
legend('x1(t)[m]','y(t)[m]','q(t)[m^3/s]','x2(t)[m]');
ylabel("Poziom wody[m]")
xlabel("Czas[s]")