----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli NAZWY_FIRM
----------------------------------------------------------------------
INSERT INTO nazwy_firm (id_nazwa_firmy, nazwa) VALUES (seq_naz_firm.nextval, 'JanuszPol');
INSERT INTO nazwy_firm (id_nazwa_firmy, nazwa) VALUES (seq_naz_firm.nextval, 'Adamex');
INSERT INTO nazwy_firm (id_nazwa_firmy, nazwa) VALUES (seq_naz_firm.nextval, 'ZbigTrans');
INSERT INTO nazwy_firm (id_nazwa_firmy, nazwa) VALUES (seq_naz_firm.nextval, 'McTrump');
INSERT INTO nazwy_firm (id_nazwa_firmy, nazwa) VALUES (seq_naz_firm.nextval, 'Cortez');

----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli NAZWY_LAPTOPOW
----------------------------------------------------------------------
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'Hp15s');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'Ideapad3');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'Inspiron14');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'MacBookAir');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'ThinkPadX1');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'SurfacePro7');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'EliteDragonfly');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'Aspire5');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'Latitude7400');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'YogaC940');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'Swift3');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'SurfaceLaptop3');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'Pavilion15');
INSERT INTO nazwy_laptopow (id_nazwa, nazwa) VALUES (seq_naz_lap.nextval, 'ROGStrixG15');

----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli PROCESOR
----------------------------------------------------------------------
INSERT INTO procesor (id_procesor, generacja, producent, liczba_rdzeni) VALUES (1, 9, 'Intel', 4);
INSERT INTO procesor (id_procesor, generacja, producent, liczba_rdzeni) VALUES (2, 5, 'AMD', 6);
INSERT INTO procesor (id_procesor, generacja, producent, liczba_rdzeni) VALUES (3, 3, 'Intel', 8);
INSERT INTO procesor (id_procesor, generacja, producent, liczba_rdzeni) VALUES (4, 7, 'AMD', 8);
INSERT INTO procesor (id_procesor, generacja, producent, liczba_rdzeni) VALUES (5, 5, 'Intel', 6);

----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli RAM
----------------------------------------------------------------------
INSERT INTO ram (id_ram, pamiec, rodzaj, taktowanie_mhz) VALUES (1, '8GB', 'DDR4', 2400);
INSERT INTO ram (id_ram, pamiec, rodzaj, taktowanie_mhz) VALUES (2, '16GB', 'DDR4', 3200);

----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli KARTA_GRAFICZNA
----------------------------------------------------------------------
INSERT INTO karta_graficzna (id_kartagraficzna, rtx, producent) VALUES (1, 'T', 'Nvidia');
INSERT INTO karta_graficzna (id_kartagraficzna, rtx, producent) VALUES (2, 'N', 'Nvidia');
INSERT INTO karta_graficzna (id_kartagraficzna, rtx, producent) VALUES (3, 'T', 'AMD');
INSERT INTO karta_graficzna (id_kartagraficzna, rtx, producent) VALUES (4, 'N', 'AMD');

----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli FIRMA_KLIENT
----------------------------------------------------------------------
INSERT INTO firma_klient (id_firmy, "e-mail", telefon, id_nazwa_firmy) VALUES (seq_firma.nextval, 'firmaA@example.com', 1234567890, 1);
INSERT INTO firma_klient (id_firmy, "e-mail", telefon, id_nazwa_firmy) VALUES (seq_firma.nextval, 'firmaB@example.com', 9876543210, 2);
INSERT INTO firma_klient (id_firmy, "e-mail", telefon, id_nazwa_firmy) VALUES (seq_firma.nextval, 'firmaC@example.com', 555111222, 3);
INSERT INTO firma_klient (id_firmy, "e-mail", telefon, id_nazwa_firmy) VALUES (seq_firma.nextval, 'firmaD@example.com', 999888777, 4);
INSERT INTO firma_klient (id_firmy, "e-mail", telefon, id_nazwa_firmy) VALUES (seq_firma.nextval, 'firmaE@example.com', 333444555, 5);

----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli MODEL_LAPTOPA
----------------------------------------------------------------------
INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'HP', 2100.00, '24 miesiecy', 1, 1, 3, 2);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'Dell', 2500.00, '6 miesiecy', 2, 1, 2, 4);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'Lenovo', 3499.00, '12 miesiecy', 3, 2, 5, 3);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'Apple', 8000.00, '12 miesiecy', 4, 2, 4, 1);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'HP', 5499.00, '12 miesiecy', 5, 2, 1, 3);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'Microsoft', 3200.00, '24 miesiecy', 6, 1, 1, 2);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'HP', 8200.00, '24 miesiecy', 7, 2, 5, 1);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'Acer', 4999.00, '36 miesiecy', 8, 2, 2, 4);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'Dell', 5199.00, '36 miesiecy', 9, 2, 3, 2);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'HP', 2300.00, '24 miesiecy', 10, 1, 1, 4);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'Lenovo', 4200.00, '12 miesiecy', 11, 2, 4, 2);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'Acer', 3499.99, '12 miesiecy', 12, 2, 3, 4);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'Microsoft', 2200.00, '36 miesiecy', 13, 1, 1, 2);

INSERT INTO model_laptopa (id_laptopa, marka, cena, gwarancja, id_nazwa, id_ram, id_procesor, id_kartagraficzna) 
VALUES (seq_laptop.nextval, 'HP', 2400.00, '6 miesiecy', 14, 1, 2, 4);

----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli LEASING
----------------------------------------------------------------------
INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (1, 1, 20, TO_DATE('2023-01-01', 'YYYY-MM-DD'), TO_DATE('2024-01-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (2, 1, 10, TO_DATE('2023-01-01', 'YYYY-MM-DD'), TO_DATE('2024-01-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (8, 1, 30, TO_DATE('2023-01-01', 'YYYY-MM-DD'), TO_DATE('2024-01-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (10, 1, 30, TO_DATE('2024-01-01', 'YYYY-MM-DD'), TO_DATE('2026-01-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (4, 1, 40, TO_DATE('2024-01-01', 'YYYY-MM-DD'), TO_DATE('2026-01-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (14, 1, 5, TO_DATE('2025-06-01', 'YYYY-MM-DD'), TO_DATE('2026-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (6, 1, 10, TO_DATE('2025-06-01', 'YYYY-MM-DD'), TO_DATE('2026-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (3, 2, 50, TO_DATE('2023-01-01', 'YYYY-MM-DD'), TO_DATE('2026-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (5, 2, 100, TO_DATE('2023-01-01', 'YYYY-MM-DD'), TO_DATE('2026-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (7, 2, 30, TO_DATE('2025-01-01', 'YYYY-MM-DD'), TO_DATE('2027-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (9, 3, 30, TO_DATE('2023-06-01', 'YYYY-MM-DD'), TO_DATE('2025-01-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (12, 3, 10, TO_DATE('2023-06-01', 'YYYY-MM-DD'), TO_DATE('2025-01-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (13, 4, 5, TO_DATE('2023-01-01', 'YYYY-MM-DD'), TO_DATE('2028-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (11, 4, 25, TO_DATE('2023-01-01', 'YYYY-MM-DD'), TO_DATE('2028-01-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (1, 4, 30, TO_DATE('2025-03-01', 'YYYY-MM-DD'), TO_DATE('2027-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (4, 5, 5, TO_DATE('2023-02-01', 'YYYY-MM-DD'), TO_DATE('2024-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (7, 5, 50, TO_DATE('2023-06-01', 'YYYY-MM-DD'), TO_DATE('2025-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (6, 5, 25, TO_DATE('2024-01-01', 'YYYY-MM-DD'), TO_DATE('2025-06-01', 'YYYY-MM-DD'));

INSERT INTO leasing (id_laptopa, id_firmy, naklad, pocz_leasingu, kon_leasingu) 
VALUES (3, 5, 125, TO_DATE('2025-06-01', 'YYYY-MM-DD'), TO_DATE('2028-01-01', 'YYYY-MM-DD'));