# Studenci stanowia zbior faktow
Studenci = {
    "Marek": {'srednia_ocen': 3.0, 'przychod_na_osobe': 1000, 'sukcesy_sportowe': True,
                        'sukcesy_artystyczne': False, 'obywatelstwo_polskie': True},
    "Mateusz": {'srednia_ocen': 4.5, 'przychod_na_osobe': 2500, 'sukcesy_sportowe': False,
                        'sukcesy_artystyczne': False, 'obywatelstwo_polskie': True},
    "Mozart": {'srednia_ocen': 3.45, 'przychod_na_osobe': 1754.47, 'sukcesy_sportowe': False,
                        'sukcesy_artystyczne': True, 'obywatelstwo_polskie': False},
    "Mariusz": {'srednia_ocen': 4.25, 'przychod_na_osobe': 1200.45, 'sukcesy_sportowe': True,
                        'sukcesy_artystyczne': True, 'obywatelstwo_polskie': True},
    "Mieczysław": {'srednia_ocen': 3.9, 'przychod_na_osobe': 1964.93, 'sukcesy_sportowe': False,
                        'sukcesy_artystyczne': False, 'obywatelstwo_polskie': True},
}

# Ponizej jest podane piec regul przyznawania roznych stypendiow
def stypendium_naukowe(fakty):
    if fakty.get('srednia_ocen', 0) >= 4.33: #Tylko studenci z srednia co najmniej 4.33 dostana stypendiun naukowe
        return "naukowe"
    return None


def stypendium_socjalne(fakty):
    if fakty.get('przychod_na_osobe', 0) < 1300:#Tylko studenci z przychodem mniejszym od 1300 na domownika dostana stypendiun socjalne
        return "socjalne"
    return None


def stypendium_sportowe(fakty):
    if fakty.get('sukcesy_sportowe', False):#Tylko studenci z sukcesami sportowymi stypendiun sportowe
        return "sportowe"
    return None


def stypendium_artystyczne(fakty):
    if fakty.get('sukcesy_artystyczne', False):#Tylko studenci z sukcesami artystycznymi stypendiun artystyczne
        return "artystyczne"
    return None


def stypendium_dla_cudzoziemcow(fakty):
    if fakty.get('obywatelstwo_polskie', False) == False:#Tylko studenci, ktorzy nie sa z Polski dostana stypendiun dla cudzoziemcow
        return "dla cudzoziemców"
    return None

#Spakowanie regul w jedna liste
reguly = [stypendium_naukowe, stypendium_socjalne, stypendium_sportowe, stypendium_artystyczne, stypendium_dla_cudzoziemcow]


#Implementacja mechanizmu wnioskujacego
def wnioskowanie(fakty, reguly):
    wnioski = []
    for regula in reguly:#sprawdzenie kazdej reguly
        wynik = regula(fakty)
        if wynik:
            wnioski.append(wynik)
    return wnioski

#wnioskowanie dla kazdego zbioru faktow
for imie, fakty_osoby in Studenci.items():
    wnioski = wnioskowanie(fakty_osoby, reguly)
    if wnioski:
        print(f"{imie} może dostać stypendium: {', '.join(wnioski)}.")
    else:
        print(f"{imie} nie kwalifikuje się na żadne stypendium.")