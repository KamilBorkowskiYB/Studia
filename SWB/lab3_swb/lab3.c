#include <REGX52.H>

unsigned char Licznik_Dzies=0;
unsigned char Licznik_Jed=0;
unsigned char tab[10]={2,159,37,13,153,73,65,31,1,9};

void ISR_INT0 (void) interrupt 0
{
	Licznik_Jed++;
	if(Licznik_Jed==10)
	{
		Licznik_Jed=0;
		Licznik_Dzies++;
			if(Licznik_Dzies==10)
			{
				Licznik_Jed=0;
				Licznik_Dzies=0;
			}
	}
	//P2 = tab[Licznik_Jed];
}
void ISR_INT1 (void) interrupt 2
{
	Licznik_Jed--;
	if(Licznik_Jed==-1)
	{
		Licznik_Jed=9;
		Licznik_Dzies--;
			if(Licznik_Dzies==-1)
			{
				Licznik_Jed=9;
				Licznik_Dzies=9;
			}
	}
	//P2 =tab[Licznik_Jed];	
}
void IRS_T1(void) interrupt 3
{
    if(P3_0==0) 
    {
        P3_0=1;
        P2=tab[Licznik_Dzies];
        P3_1=0;
    }
    else 
    {
        P3_1=1;
        P2=tab[Licznik_Jed];
        P3_0=0; 
    }
}

void main(void)
{
   
    IT0 = 1;
    IT1 = 1;
    EX0 = 1;
    EX1 = 1;
		TL1 = 250;
		TH1 = 250;
		TMOD = 0x19;
    ET1 = 1;
    
    EA = 1;
    TR1 = 1;
    
    for(;;){
				;
		}
}