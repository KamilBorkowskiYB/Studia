import numpy as np
import random

def losuj_cechy(i):
    if i == 0:#x0
        return random.randint(0, 10)
    if i == 1:#x1 mod 10 = od 1 do 7
        return random.choice([i for i in range(1, 26) if i % 10 in range(1, 8)])
    if i == 2:#x2
        return random.randint(1, 25)
    if i == 3:#x3
        return random.randint(0, 20)
    if i == 4:#x4
        return random.randint(6, 25)


def zrob_dziecko():
    return np.array([
        losuj_cechy(0),
        losuj_cechy(1),
        losuj_cechy(2),
        losuj_cechy(3),
        losuj_cechy(4)
    ])


def punkty_sily(x):
    return 2*x[0]*x[0] + x[1]*x[1]*x[1] - x[2]*x[2] + 7*x[3]*x[3] - 2*x[4]*x[4]*x[4]*x[4]*x[4]


def selekcja_rankingowa(populacja, pkt):
    polulacja_sort = [x for _, x in sorted(zip(pkt, populacja))]
    rank_probs = [i / sum(range(1, len(populacja) + 1)) for i in range(1, len(populacja) + 1)]
    return random.choices(polulacja_sort, rank_probs)[0]


def krzyzowanie(parent1, parent2):
    p1 = np.array(parent1)
    p2 = np.array(parent2)
    child = np.empty(p1.shape, dtype=p1.dtype)
    for i in range(p1.size):
        if random.random() < 0.5:
            child[i] = p1[i]
        else:
            child[i] = p2[i]
    return child


def mutuj_dzicko(child):
    ktory_x = random.randint(0,4)
    child[ktory_x] = losuj_cechy(ktory_x)
    return child


liczba_pokolen = 50
rozmiar_populacji = 20
populacja = []
np_populacja = []
elita = []
np_elita = []
ranking = []
np_ranking = []
nowe_pokolenie = []
np_nowe_pokolenie = []

for i in range(rozmiar_populacji):
    populacja.append(zrob_dziecko())
np_populacja = np.array(populacja)
print("Pierwsze pokolenie")
print(np_populacja)

for i in range(liczba_pokolen):

    #ranking populacji
    ranking= []
    for i in populacja:
        ranking.append(punkty_sily(i))
    np_ranking = np.array(ranking)
    print("Ranking rozwiazan")
    print(np_ranking)

    #wybor rodzicow nastepnej generacji
    print("Rodzic 1")
    parent1 = selekcja_rankingowa(populacja, ranking)
    print(parent1)
    print("Rodzic 2")#zakladam mozliwe rozmnazanie przez paczkowanie
    parent2 = selekcja_rankingowa(populacja, ranking)
    print(parent2)

    #wybor elity, ktora bezwarunkowo przechodzi do kolejnej generacji
    elita = []
    for i in range(int(rozmiar_populacji * 0.1)):
        max_index = ranking.index(max(ranking))
        elita.append(populacja[max_index])
        ranking.remove(max(ranking))
    np_elita = np.array(elita)
    print("Elita")
    print(np_elita)
    liczba_elit = np_elita.size/5

    #tworzenie nowego pokolenia
    nowe_pokolenie = []
    for i in range(int(rozmiar_populacji-liczba_elit)):
        nowe_pokolenie.append(krzyzowanie(parent1,parent2))
    np_nowe_pokolenie = np.array(nowe_pokolenie)
    print("Nowe pokolenie przed mutacja")
    print(np_nowe_pokolenie)


    #mutowanie nowego pokolenia
    for i in range(int(np_nowe_pokolenie.size/5)):
        mutuj_dzicko(np_nowe_pokolenie[i])
    print("Nowe pokolenie po mutacji")
    print(np_nowe_pokolenie)

    #dodanie elity do nowego pokolenia
    np_nowe_pokolenie = np.concatenate((np_nowe_pokolenie, np_elita), axis=0)
    print("Nowe pokolenie")
    print(np_nowe_pokolenie)

    np_populacja = np_nowe_pokolenie
    populacja = np_populacja.tolist()


#ranking populacji
ranking = []
for i in populacja:
    ranking.append(punkty_sily(i))
np_ranking = np.array(ranking)


najwyzszy_element = max(populacja, key=punkty_sily)
print("Optymalny potomek:", najwyzszy_element," o rankingu: ", max(ranking))