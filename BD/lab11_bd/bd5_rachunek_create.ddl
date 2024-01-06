/************************************

Skrypt przygotowujący schemat bazodanowy
do nauki Oracle Application Express
i projektowania generatora danych

opr.: Józef Woźniak (2021)
*************************************/


CREATE SEQUENCE seq_bd5_klient START WITH 10 INCREMENT BY 1 NOCACHE;

CREATE SEQUENCE seq_bd5_produkt START WITH 20 INCREMENT BY 1 NOCACHE;

CREATE SEQUENCE seq_bd5_rachunek START WITH 100 INCREMENT BY 1 NOCACHE;


CREATE TABLE bd5_klient (
    nr_klienta            NUMBER(4),
    klient_nazwisko       VARCHAR2(30) NOT NULL,
    klient_imie           VARCHAR2(15),
    klient_adres          VARCHAR2(50),
    klient_miasto         VARCHAR2(20) NOT NULL,
    klient_kod_adresowy   VARCHAR2(6) NOT NULL
);

ALTER TABLE bd5_klient ADD CONSTRAINT bd5_klient_pk PRIMARY KEY ( nr_klienta );

CREATE TABLE bd5_produkt (
    nr_produktu      NUMBER(5),
    nazwa_produktu   VARCHAR2(20) NOT NULL,
    cena_produktu    NUMBER(8, 2) NOT NULL,
    rok_produkcji    NUMBER(4),
    ranking          NUMBER(2)
);

COMMENT ON COLUMN bd5_produkt.ranking IS
    '1 – produkt bardzo zły,
	 10 - produkt bardzo dobry';

ALTER TABLE bd5_produkt ADD CONSTRAINT bd5_produkt_pk PRIMARY KEY ( nr_produktu );

CREATE TABLE bd5_rachunek (
    nr_rachunku      NUMBER(5),
    data_sprzedazy   DATE NOT NULL,
    ilosc_produktu   NUMBER(3) NOT NULL,
    nr_produktu      NUMBER(5) NOT NULL,
    nr_klienta       NUMBER(4) NOT NULL,
	cena_zakupu 	 NUMBER(8,2) NOT NULL,
	wartosc 		 NUMBER(8,2) NOT NULL
);

ALTER TABLE bd5_rachunek ADD CONSTRAINT bd5_rachunek_pk PRIMARY KEY ( nr_rachunku );

ALTER TABLE bd5_rachunek
    ADD CONSTRAINT bd5_klient_fk FOREIGN KEY ( nr_klienta )
        REFERENCES bd5_klient ( nr_klienta );

ALTER TABLE bd5_rachunek
    ADD CONSTRAINT bd5_produkt_fk FOREIGN KEY ( nr_produktu )
        REFERENCES bd5_produkt ( nr_produktu )
            ON DELETE CASCADE;
---------------------------------------
