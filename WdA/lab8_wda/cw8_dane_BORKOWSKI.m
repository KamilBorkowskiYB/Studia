%Kamil Borkowski WCY22IY1S1 22.05.2024
%cwiczenie 8
%Modelowanie ukladu regulacji z regulatorem PID.
%wariant: 2
%dane
%C1 = 10
%C2 = 5
%C3 = 2
%R1 = 0.5
%R2 = 2
%R3 = 3

C1 = 10
C2 = 5
C3 = 2
R1 = 0.5
R2 = 2
R3 = 3

q0 = 1

x30 = 3
p0 = x30

kg=31.69
kp=0.5*kg
kpi=0.45*kg
kpid=0.6*kg

tg=11.76
ti_pi=tg/1.2
ti_pid=tg/2
td=tg/8

a11 = -(1/(R1*C1))
a12 = (1/(R1*C1))
a13 = 0

a21 = (1/(R1*C2))
a22 = -(1/(R1*C2)) -(1/(R2*C2))
a23 = (1/(R2*C2))

a31 = 0
a32 = (1/(R2*C3))
a33 = -(1/(R2*C3)) -(1/(R3*C3))

A = [a11, a12, a13; a21, a22, a23; a31, a32, a33]

b11 = (1/C1)
b21 = 0
b31 = 0

B = [b11; b21; b31]

C = [0, 0, 1]
D = 0

plot(out.tout,out.yout); grid on;
title('Wykres zaleznosci poziomu wody w zbiorniku 3 od czasu');
xlabel('czas [s]'); ylabel('poziom wody w zbiorniku 3 [m]');
legend('p0','y_P(t)','y_P_I(t)','y_P_I_D(t)');