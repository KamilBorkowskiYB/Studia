-- Generated by Oracle SQL Developer Data Modeler 23.1.0.087.0806
--   at:        2024-02-14 11:56:41 CET
--   site:      Oracle Database 12cR2
--   type:      Oracle Database 12cR2



-- predefined type, no DDL - MDSYS.SDO_GEOMETRY

-- predefined type, no DDL - XMLTYPE

CREATE TABLE autor (
    kod_autora      NUMBER NOT NULL,
    nazwisko        VARCHAR2(100),
    imiona          VARCHAR2(100),
    rok_urodzenia   VARCHAR2(4),
    poezja          NUMBER,
    proza           NUMBER,
    dramat          NUMBER,
    kod_narodowosci NUMBER NOT NULL
);

ALTER TABLE autor ADD CONSTRAINT autor_pk PRIMARY KEY ( kod_autora );

CREATE TABLE czytelnik (
    numer_karty       NUMBER NOT NULL,
    nazwisko          VARCHAR2(100) NOT NULL,
    imie              VARCHAR2(100) NOT NULL,
    data_urodzenia    DATE NOT NULL,
    miejsce_urodzenia VARCHAR2(100),
    kod_pocztowy      VARCHAR2(10),
    miasto            VARCHAR2(100),
    ulica             VARCHAR2(100)
);

ALTER TABLE czytelnik ADD CONSTRAINT czytelnik_pk PRIMARY KEY ( numer_karty );

CREATE TABLE gatunek (
    kod_gatunku   NUMBER NOT NULL,
    nazwa_gatunku VARCHAR2(100) NOT NULL
);

ALTER TABLE gatunek ADD CONSTRAINT gatunek_pk PRIMARY KEY ( kod_gatunku );

CREATE TABLE ksiazka (
    sygnatura       NUMBER NOT NULL,
    tytul           VARCHAR2(100) NOT NULL,
    wycofania       NUMBER NOT NULL,
    data_zakupu     DATE,
    uwagi           VARCHAR2(100),
    kod_wydawnictwa NUMBER NOT NULL,
    kod_gatunku     NUMBER NOT NULL,
    kod_autora      NUMBER NOT NULL
);

ALTER TABLE ksiazka ADD CONSTRAINT ksiazka_pk PRIMARY KEY ( sygnatura );

CREATE TABLE narodowosc (
    kod_narodowosci   NUMBER NOT NULL,
    nazwa_narodowosci VARCHAR2(100) NOT NULL
);

ALTER TABLE narodowosc ADD CONSTRAINT narodowosc_pk PRIMARY KEY ( kod_narodowosci );

CREATE TABLE wydawnictwo (
    kod_wydawnictwa   NUMBER NOT NULL,
    nazwa_wydawnictwa VARCHAR2(100),
    miasto            VARCHAR2(100) NOT NULL
);

ALTER TABLE wydawnictwo ADD CONSTRAINT wydawnictwo_pk PRIMARY KEY ( kod_wydawnictwa );

CREATE TABLE wypozyczenia (
    nr_wypozyczenia   NUMBER NOT NULL,
    data_wypozyczenia DATE NOT NULL,
    data_zwrotu       DATE,
    numer_karty       NUMBER NOT NULL,
    sygnatura         NUMBER NOT NULL
);

ALTER TABLE wypozyczenia ADD CONSTRAINT wypozyczenia_pk PRIMARY KEY ( nr_wypozyczenia );

ALTER TABLE autor
    ADD CONSTRAINT autor_narodowosc_fk FOREIGN KEY ( kod_narodowosci )
        REFERENCES narodowosc ( kod_narodowosci );

ALTER TABLE ksiazka
    ADD CONSTRAINT ksiazka_autor_fk FOREIGN KEY ( kod_autora )
        REFERENCES autor ( kod_autora );

ALTER TABLE ksiazka
    ADD CONSTRAINT ksiazka_gatunek_fk FOREIGN KEY ( kod_gatunku )
        REFERENCES gatunek ( kod_gatunku );

ALTER TABLE ksiazka
    ADD CONSTRAINT ksiazka_wydawnictwo_fk FOREIGN KEY ( kod_wydawnictwa )
        REFERENCES wydawnictwo ( kod_wydawnictwa );

ALTER TABLE wypozyczenia
    ADD CONSTRAINT wypozyczenia_czytelnik_fk FOREIGN KEY ( numer_karty )
        REFERENCES czytelnik ( numer_karty );

ALTER TABLE wypozyczenia
    ADD CONSTRAINT wypozyczenia_ksiazka_fk FOREIGN KEY ( sygnatura )
        REFERENCES ksiazka ( sygnatura );



-- Oracle SQL Developer Data Modeler Summary Report: 
-- 
-- CREATE TABLE                             7
-- CREATE INDEX                             0
-- ALTER TABLE                             13
-- CREATE VIEW                              0
-- ALTER VIEW                               0
-- CREATE PACKAGE                           0
-- CREATE PACKAGE BODY                      0
-- CREATE PROCEDURE                         0
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
-- CREATE SEQUENCE                          0
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