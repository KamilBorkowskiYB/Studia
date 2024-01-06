
select nazwa_klubu klub, nazwa_kategorii kategoria, punkty_globalne pkt
    from bd3_zawodnicy z
        join bd3_kluby k on z.nr_klubu = k.nr_klubu
        join bd3_kategorie ka on z.nr_kategorii = ka.nr_kategorii
        join bd3_wyniki w on z.nr_zawodnika = w.nr_zawodnika
  
where plec = 'K' 
order by klub, kategoria 
;
  