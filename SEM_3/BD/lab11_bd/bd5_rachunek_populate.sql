
----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli BD5_KLIENT
----------------------------------------------------------------------

Insert into BD5_KLIENT(NR_KLIENTA,KLIENT_NAZWISKO,KLIENT_IMIE,KLIENT_ADRES,KLIENT_MIASTO,KLIENT_KOD_ADRESOWY) values (1,'Kowalski','Jan','ul. Strumykowa 15 / 60','Warszawa','01-578');

Insert into BD5_KLIENT(NR_KLIENTA,KLIENT_NAZWISKO,KLIENT_IMIE,KLIENT_ADRES,KLIENT_MIASTO,KLIENT_KOD_ADRESOWY) values (2,'Nowak','Adam','ul. Kwiatowa 12 / 5','Krak�w','31-879');

Insert into BD5_KLIENT(NR_KLIENTA,KLIENT_NAZWISKO,KLIENT_IMIE,KLIENT_ADRES,KLIENT_MIASTO,KLIENT_KOD_ADRESOWY) values (3,'Boczy�ski','Edward','ul. Spokojna 56','Warszawa','01-237');

Insert into BD5_KLIENT(NR_KLIENTA,KLIENT_NAZWISKO,KLIENT_IMIE,KLIENT_ADRES,KLIENT_MIASTO,KLIENT_KOD_ADRESOWY) values (4,'Walecki','Franciszek','ul. S�oneczna 4 / 6','Krak�w','31-769');

Insert into BD5_KLIENT(NR_KLIENTA,KLIENT_NAZWISKO,KLIENT_IMIE,KLIENT_ADRES,KLIENT_MIASTO,KLIENT_KOD_ADRESOWY) values (5,'Misiowiec','Jacek','pl. Miejski 14','��d�','90-019');

Insert into BD5_KLIENT(NR_KLIENTA,KLIENT_NAZWISKO,KLIENT_IMIE,KLIENT_ADRES,KLIENT_MIASTO,KLIENT_KOD_ADRESOWY) values (6,'Konieczny','Albert','ul. Conrada 20 / 43','Warszawa','01-911');

Insert into BD5_KLIENT(NR_KLIENTA,KLIENT_NAZWISKO,KLIENT_IMIE,KLIENT_ADRES,KLIENT_MIASTO,KLIENT_KOD_ADRESOWY) values (7,'Polewski','Zbigniew','ul. Zgody 17 / 16','��d�','90-019');

----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli BD5_PRODUKT
----------------------------------------------------------------------

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (1,'Koszulka polo',150,2019,3);

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (2,'Spodnie',180,2019,2);

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (3,'�akiet',150,2019,1);

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (4,'Bluzka',60,2019,3);

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (5,'Sp�dnica',80,2019,3);

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (6,'Buty damskie',120,2019,5);

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (7,'Pasek do spodni',30,2019,6);

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (8,'Torebka',125,2019,2);

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (9,'Buty m�skie',110,2019,4);

Insert into BD5_PRODUKT(NR_PRODUKTU,NAZWA_PRODUKTU,CENA_PRODUKTU,ROK_PRODUKCJI,RANKING) values (10,'Portfel',50,2019,2);

----------------------------------------------------------------------
-- Wprowadzenie danych do tabeli BD5_RACHUNEK
----------------------------------------------------------------------
/*
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('1',to_date('20/08/02','RR/MM/DD'),'4','10','3','50','200');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('2',to_date('20/08/02','RR/MM/DD'),'2','1','5','50','100');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('3',to_date('20/08/02','RR/MM/DD'),'1','8','5','125','125');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('4',to_date('20/08/02','RR/MM/DD'),'9','3','6','150','1350');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('5',to_date('20/08/02','RR/MM/DD'),'9','4','6','60','540');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('6',to_date('20/08/02','RR/MM/DD'),'3','9','6','110','330');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('7',to_date('20/08/02','RR/MM/DD'),'6','4','3','60','360');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('8',to_date('20/08/02','RR/MM/DD'),'4','4','1','60','240');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('9',to_date('20/08/02','RR/MM/DD'),'5','8','1','125','625');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('10',to_date('20/08/02','RR/MM/DD'),'5','5','2','80','400');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('11',to_date('20/08/02','RR/MM/DD'),'4','5','3','80','320');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('12',to_date('20/08/02','RR/MM/DD'),'6','5','1','80','480');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('13',to_date('20/08/02','RR/MM/DD'),'8','1','4','50','400');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('14',to_date('20/08/02','RR/MM/DD'),'8','6','6','120','960');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('15',to_date('20/08/02','RR/MM/DD'),'9','7','4','30','270');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('16',to_date('20/08/03','RR/MM/DD'),'5','6','2','120','600');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('17',to_date('20/08/03','RR/MM/DD'),'2','6','4','120','240');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('18',to_date('20/08/03','RR/MM/DD'),'2','5','2','80','160');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('19',to_date('20/08/03','RR/MM/DD'),'3','1','7','50','150');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('20',to_date('20/08/03','RR/MM/DD'),'9','9','4','110','990');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('21',to_date('20/08/03','RR/MM/DD'),'4','8','3','125','500');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('22',to_date('20/08/03','RR/MM/DD'),'3','7','2','30','90');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('23',to_date('20/08/03','RR/MM/DD'),'9','7','3','30','270');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('24',to_date('20/08/03','RR/MM/DD'),'4','7','1','30','120');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('25',to_date('20/08/04','RR/MM/DD'),'7','9','4','110','770');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('26',to_date('20/08/04','RR/MM/DD'),'10','4','3','60','600');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('27',to_date('20/08/04','RR/MM/DD'),'1','7','5','30','30');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('28',to_date('20/08/04','RR/MM/DD'),'2','7','2','30','60');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('29',to_date('20/08/04','RR/MM/DD'),'5','8','5','125','625');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('30',to_date('20/08/04','RR/MM/DD'),'3','10','4','50','150');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('31',to_date('20/08/04','RR/MM/DD'),'5','4','1','60','300');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('32',to_date('20/08/04','RR/MM/DD'),'2','9','2','110','220');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('33',to_date('20/08/04','RR/MM/DD'),'9','10','6','50','450');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('34',to_date('20/08/04','RR/MM/DD'),'3','7','5','30','90');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('35',to_date('20/08/04','RR/MM/DD'),'3','10','7','50','150');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('36',to_date('20/08/04','RR/MM/DD'),'6','6','3','120','720');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('37',to_date('20/08/05','RR/MM/DD'),'5','1','6','50','250');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('38',to_date('20/08/05','RR/MM/DD'),'6','2','3','80','480');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('39',to_date('20/08/05','RR/MM/DD'),'1','3','6','150','150');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('40',to_date('20/08/05','RR/MM/DD'),'8','4','4','60','480');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('41',to_date('20/08/05','RR/MM/DD'),'2','5','4','80','160');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('42',to_date('20/08/05','RR/MM/DD'),'5','5','3','80','400');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('43',to_date('20/08/05','RR/MM/DD'),'8','5','5','80','640');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('44',to_date('20/08/05','RR/MM/DD'),'4','6','5','120','480');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('45',to_date('20/08/05','RR/MM/DD'),'9','6','5','120','1080');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('46',to_date('20/08/05','RR/MM/DD'),'10','7','3','30','300');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('47',to_date('20/08/05','RR/MM/DD'),'5','8','3','125','625');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('48',to_date('20/08/05','RR/MM/DD'),'3','8','4','125','375');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('49',to_date('20/08/05','RR/MM/DD'),'7','9','3','110','770');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('50',to_date('20/08/05','RR/MM/DD'),'10','9','4','110','1100');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('51',to_date('20/08/06','RR/MM/DD'),'2','1','3','50','100');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('52',to_date('20/08/06','RR/MM/DD'),'4','9','4','110','440');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('53',to_date('20/08/06','RR/MM/DD'),'4','2','6','80','320');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('54',to_date('20/08/06','RR/MM/DD'),'1','2','4','80','80');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('55',to_date('20/08/06','RR/MM/DD'),'4','3','1','150','600');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('56',to_date('20/08/06','RR/MM/DD'),'3','3','6','150','450');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('57',to_date('20/08/06','RR/MM/DD'),'7','4','7','60','420');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('58',to_date('20/08/06','RR/MM/DD'),'4','5','3','80','320');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('59',to_date('20/08/06','RR/MM/DD'),'9','6','7','120','1080');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('60',to_date('20/08/06','RR/MM/DD'),'10','10','4','50','500');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('61',to_date('20/08/06','RR/MM/DD'),'3','7','3','30','90');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('62',to_date('20/08/06','RR/MM/DD'),'2','7','4','30','60');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('63',to_date('20/08/06','RR/MM/DD'),'6','8','3','125','750');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('64',to_date('20/08/06','RR/MM/DD'),'9','8','6','125','1125');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('65',to_date('20/08/06','RR/MM/DD'),'5','8','7','125','625');
Insert into BD5_RACHUNEK (NR_RACHUNKU,DATA_SPRZEDAZY,ILOSC_PRODUKTU,NR_PRODUKTU,NR_KLIENTA,CENA_ZAKUPU,WARTOSC) values ('66',to_date('20/08/06','RR/MM/DD'),'9','1','2','50','450');
*/
COMMIT;
