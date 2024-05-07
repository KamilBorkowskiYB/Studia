import matplotlib.pyplot as plt
import numpy as np

il_danych = 100

X = 4 * np.random.rand(il_danych, 1)#niezalezna
Y = 5 + 1.5 * X + np.random.randn(il_danych, 1)#zalezna od X

#Początkowe wartosci parametrow a i b
#Czym blizsze idealnej wartosci tym mniej powtorzen petli dla modelu potrzeba
a = 5
b = 5

#0.05 zdaje sie dawac srednio najnizsze MSE
wspolczynnik_uczenia = 0.05

#Trening modelu regresji liniowej
for i in range(il_danych*il_danych):#Im wiecej powtorzen tym lepsze wyniki
    Yprim = a * X + b #Y przewidywane
    roznica = Y - Yprim
    grad_a = (-2/il_danych) * np.sum(roznica * X)
    grad_b = (-2/il_danych) * np.sum(roznica)
    a = a - wspolczynnik_uczenia * grad_a
    b = b - wspolczynnik_uczenia * grad_b

#Obliczanie predykcji
Xmax = np.max(X)
X_pred = np.zeros(5)
X_pred[0] = Xmax + 0.1
for i in range(1, 5):
    X_pred[i] = X_pred[i-1] + 0.1
Y_nas = a * X_pred + b

#Obliczanie MSE
MSE = np.mean((Y - Yprim) ** 2)
print('MSE='+str(MSE))

#Wykres
plt.figure(figsize=(10, 6))
plt.plot(X, Y, 'bo', label='Dane')
plt.plot(X, Yprim, 'r-', label='Krzywa regresji')
plt.plot(X_pred, Y_nas, 'ko', label='Predykcje')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()

#Tabelka z wartościami MSE, a, b
table_data = [['MSE', MSE], ['a',a], ['b', b]]
plt.table(cellText=table_data, loc='lower right', edges='open',colWidths=[0.2, 0.2])
plt.show()