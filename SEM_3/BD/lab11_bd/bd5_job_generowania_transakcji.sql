/*****************************************************
-- Automat czasowy do generowania transakcji
--
-- opr. Józef WoŸniak (2020)
******************************************************/

begin  
    -- Harmonogram "codziennie co godzinê"
    dbms_scheduler.create_schedule
   
    (schedule_name  => 'CO_GODZINE',    
     start_date    => trunc(sysdate)+21/24,    
     repeat_interval => 'freq=HOURLY;interval=1',    
     comments     => 'Uruchamiane codziennie co godzinê'
     ); 
end;
/
begin
    -- Program wywo³ywania pakietowej procedury  

    dbms_scheduler.create_program
	
    (program_name=> 'GENERUJ_TRANSAKCJE',  
     program_type=> 'STORED_PROCEDURE',  
     program_action=> 'bd5_pkg_generator_danych.pr_generuj_transakcje',
     enabled=>true,  
     comments=>'Generowanie transakcji z bie¿¹c¹ dat¹'  
     );       
end;
/
begin
     -- Zadanie ³¹cz¹ce harmonogram z programem
    
    dbms_scheduler.create_job  
    (job_name => 'GENEROWANIE_TRANSAKCJI',  
     program_name=> 'GENERUJ_TRANSAKCJE',  
     schedule_name=>'CO_GODZINE',  
     enabled=>true,  
     auto_drop=>false,  
     comments=>'Generowanie transakcji z bie¿¹c¹ dat¹'
     );       
end;
/
