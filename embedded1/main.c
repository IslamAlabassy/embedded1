
//Memory Mapping
#define	 PORTA  (*(volatile unsigned char*)0x3B)
#define	 DDRA   (*(volatile unsigned char*)0x3A)
#define	 PINA   (*(volatile unsigned char*)0x39)
#define  PORTC  (*(volatile unsigned char*)0x35)
#define  DDRC   (*(volatile unsigned char*)0x34)
#define  PINC   (*(volatile unsigned char*)0x33)
//Bit Masking 
#define  SET_BIT(reg,bit)    (reg=reg|(1<<bit))
#define  CLEAR_BIT(reg,bit)  (reg=reg&(~(1<<bit)))
#define  READ_BIT(reg,bit)   ((reg>>bit)&1)
#define  TOGGLE_BIT(reg,bit) (reg=reg^(1<<bit))

#define  F_CPU 8000000UL
#include <util/delay.h>

volatile long int x=1;

int main(void)
{
	DDRA = 0xff;
	DDRC = 0;
	PORTC = 0xfe;	
	//unsigned char flag = 1;
	
	//PORTA = 0xff;
    while (1) 
    {
/*		//push button project 1:
		if (READ_BIT(PINC,0)==1)
		{
			SET_BIT(PORTA,2);
		}
		if (!READ_BIT(PINC,1))
		{
			CLEAR_BIT(PORTA,2);
		}*/

		//push button project 2:  /* toggle led when press push button */
/*		if (!READ_BIT(PINC,1))
		{
			if (flag == 1)
			{
				CLEAR_BIT(PORTA,0);
				flag = 0;
			}
			else
			{
				SET_BIT(PORTA,0);
				flag = 1;
			}
			while(!READ_BIT(PINC,1));
		}      */


		//another solution :
/*		if (READ_BIT(PINC,1)==0)
		{
			TOGGLE_BIT(PORTA,0);
			while(READ_BIT(PINC,1)==0); //POLLING
		} */
		
		
		//push button project 3:
		if (READ_BIT(PINC,1)==0)
		{
			
			if (x==128)
			{
				x=1;
			}
			PORTA = x;
			x = x<<1;
			
			while(READ_BIT(PINC,1)==0); //POLLING
			
		}
    }
}

