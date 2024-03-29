-- Generated by Oracle SQL Developer Data Modeler 21.4.2.059.0838
--   at:        2022-08-25 17:33:00 CEST
--   site:      Oracle Database 12cR2
--   type:      Oracle Database 12cR2



-- predefined type, no DDL - SDO_GEOMETRY

-- predefined type, no DDL - XMLTYPE

CREATE SEQUENCE seq_klient START WITH 10 INCREMENT BY 1 NOCACHE;

CREATE SEQUENCE seq_produkt START WITH 20 INCREMENT BY 1 NOCACHE;

CREATE SEQUENCE seq_rachunek START WITH 1 INCREMENT BY 1 NOCACHE;

CREATE OR REPLACE PROCEDURE pr_insert_produkt 
                 (v_nr_produktu number,
                  v_nazwa_produktu varchar2,
                  v_cena_produktu number,
                  v_rok_produkcji number default null,
                  v_ranking number default 5) AS 
BEGIN
NULL;
        /* 
          Procedura wstawia nowy produkt do tabeli BD4_PRODUKT.
          Nale�y sprawdza�, czy podany numer produktu ju� istnieje.
          Rok produkcji i ranking nie musz� by� wype�nione.
        */   
END;

/

CREATE TABLE bd4_klient (
    nr_klienta          NUMBER(4) NOT NULL,
    klient_nazwisko     VARCHAR2(30) NOT NULL,
    klient_imie         VARCHAR2(15),
    klient_adres        VARCHAR2(50),
    klient_miasto       VARCHAR2(20) NOT NULL,
    klient_kod_adresowy VARCHAR2(6) NOT NULL
);

ALTER TABLE bd4_klient ADD CONSTRAINT bd4_klient_pk PRIMARY KEY ( nr_klienta );

CREATE TABLE bd4_produkt (
    nr_produktu    NUMBER(5) NOT NULL,
    nazwa_produktu VARCHAR2(20) NOT NULL,
    cena_produktu  NUMBER(8, 2) NOT NULL,
    rok_produkcji  NUMBER(4),
    ranking        NUMBER(2)
);

COMMENT ON COLUMN bd4_produkt.ranking IS
    '1 � produkt bardzo z�y,
10 - produkt bardzo dobry';

ALTER TABLE bd4_produkt ADD CONSTRAINT bd4_produkt_pk PRIMARY KEY ( nr_produktu );

CREATE TABLE bd4_rachunek (
    nr_rachunku    NUMBER(4) NOT NULL,
    data_sprzedazy DATE NOT NULL,
    ilosc_produktu NUMBER(3) NOT NULL,
    cena_zakupu    NUMBER(8, 2) NOT NULL,
    wartosc        NUMBER(8, 2) NOT NULL,
    nr_produktu    NUMBER(5) NOT NULL,
    nr_klienta     NUMBER(4) NOT NULL
);

ALTER TABLE bd4_rachunek ADD CONSTRAINT bd4_rachunek_pk PRIMARY KEY ( nr_rachunku );

ALTER TABLE bd4_rachunek
    ADD CONSTRAINT bd4_klient_fk FOREIGN KEY ( nr_klienta )
        REFERENCES bd4_klient ( nr_klienta )
    NOT DEFERRABLE;

ALTER TABLE bd4_rachunek
    ADD CONSTRAINT bd4_produkt_fk FOREIGN KEY ( nr_produktu )
        REFERENCES bd4_produkt ( nr_produktu )
            ON DELETE CASCADE
    NOT DEFERRABLE;



-- Oracle SQL Developer Data Modeler Summary Report: 
-- 
-- CREATE TABLE                             3
-- CREATE INDEX                             0
-- ALTER TABLE                              5
-- CREATE VIEW                              0
-- ALTER VIEW                               0
-- CREATE PACKAGE                           0
-- CREATE PACKAGE BODY                      0
-- CREATE PROCEDURE                         1
-- CREATE FUNCTION                          0
-- CREATE TRIGGER                           0
-- ALTER TRIGGER                            0
-- CREATE COLLECTION TYPE                   0
-- CREATE STRUCTURED TYPE                   0
-- CREATE STRUCTURED TYPE BODY              0
-- CREATE CLUSTER                           0
-- CREATE CONTEXT                           0
-- CREATE DATABASE                          0
-- CREATE DIMENSION                         0
-- CREATE DIRECTORY                         0
-- CREATE DISK GROUP                        0
-- CREATE ROLE                              0
-- CREATE ROLLBACK SEGMENT                  0
-- CREATE SEQUENCE                          3
-- CREATE MATERIALIZED VIEW                 0
-- CREATE MATERIALIZED VIEW LOG             0
-- CREATE SYNONYM                           0
-- CREATE TABLESPACE                        0
-- CREATE USER                              0
-- 
-- DROP TABLESPACE                          0
-- DROP DATABASE                            0
-- 
-- REDACTION POLICY                         0
-- 
-- ORDS DROP SCHEMA                         0
-- ORDS ENABLE SCHEMA                       0
-- ORDS ENABLE OBJECT                       0
-- 
-- ERRORS                                   0
-- WARNINGS                                 0