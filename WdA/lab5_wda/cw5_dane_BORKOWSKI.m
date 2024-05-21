% Kamil Borkowski WCY22IY1S1 16.05.2024
% Dane do zadania 5
% wariant 19
% m = 0.064
% a = 0.064
% h = 0.4
%dane do punktu 7:
%a=0.04
%a=0.064
%a=0.1
%a=0.45
m = 0.064
a = 0.04
h = 0.4

b0 = 1/m
a0 = h/m
a1 = a/m
A = [0 1;-a0 -a1]
B = [0;b0]
C = [1 0]
D = [0]
plot(tout, yout)
ylabel("Polozenie[m]")
xlabel("Czas[s]")

