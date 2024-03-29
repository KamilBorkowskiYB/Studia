select 'BD4_KLIENT' as "Tabela", count(*) "Liczba wierszy" from bd4_klient
union
select 'BD4_PRODUKT', count(*) from bd4_produkt
union
select 'BD4_RACHUNEK', count(*) from bd4_rachunek;