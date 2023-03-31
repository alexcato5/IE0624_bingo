#include <pic14/pic12f675.h>

unsigned int lfsr_rnd(void);
void delay(unsigned int tiempo);
unsigned int lfsr = 0b0010;

void main(void)
{
	GPIO = 0x00; //Poner pines en bajo
    TRISIO =  0b00000000;
    TRISIO |= 0b00100000;
    /*	
    Entradas:
		- GPIO0
		- GPIO1
		- GPIO2
		- GPIO3
		- GPIO4

	Salidas:
		- GPIO5
	*/
	_Bool number_found = 0;
    unsigned int number;
	
	// Registros a utilizar para guardar los números:
	// (en codificación One-Hot)
	*(volatile unsigned int*)0x25 = 0b00000000;
	*(volatile unsigned int*)0x35 = 0b00000000;
	unsigned int history1;
	unsigned int history2;

    //Loop forever
    while ( 1 )
    {
    	if ( GPIO5 )
    	{
    		while ( !number_found )
    		{
	    		number = lfsr_rnd();
	    		number_found = 1;
	    		history1 = *(volatile unsigned int*)0x25;
	    		history2 = *(volatile unsigned int*)0x35;

	    		if (number == 0 && ((history1 >> 7) & 1) == 0) 
	    		{
	    			*(volatile unsigned int*)0x25 |= 0b10000000;
	    		}
	    		else if (number == 1 && ((history1 >> 6) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO0 = 1;
	    			/*GPIO1 = 0;
	    			GPIO2 = 0;
	    			GPIO3 = 0;
	    			GPIO4 = 0;*/	
	    			*(volatile unsigned int*)0x25 |= 0b01000000;
	    		}
	    		else if (number == 2 && ((history1 >> 5) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO1 = 1;
	    			/*GPIO0 = 0;
	    			GPIO2 = 0;
	    			GPIO3 = 0;
	    			GPIO4 = 0;*/
	    			*(volatile unsigned int*)0x25 |= 0b00100000;
	    		}
	    		else if (number == 3 && ((history1 >> 4) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO0 = 1;
	    			GPIO1 = 1;
	    			/*GPIO2 = 0;
	    			GPIO3 = 0;
	    			GPIO4 = 0;*/
	    			*(volatile unsigned int*)0x25 |= 0b00010000;
	    		}
	    		else if (number == 4 && ((history1 >> 3) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO2 = 1;
	    			/*GPIO0 = 0;
	    			GPIO1 = 0;
	    			GPIO3 = 0;
	    			GPIO4 = 0;*/	
	    			*(volatile unsigned int*)0x25 |= 0b00001000;
	    		}
	    		else if (number == 5 && ((history1 >> 2) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO0 = 1;
	    			GPIO2 = 1;
	    			/*GPIO1 = 0;
	    			GPIO3 = 0;
	    			GPIO4 = 0;*/
	    			*(volatile unsigned int*)0x25 |= 0b00000100;
	    		}
	    		else if (number == 6 && ((history1 >> 1) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO1 = 1;
	    			GPIO2 = 1;
	    			/*GPIO0 = 0;
	    			GPIO3 = 0;
	    			GPIO4 = 0;*/
	    			*(volatile unsigned int*)0x25 |= 0b00000010;
	    		}
	    		else if (number == 7 && ((history1 >> 0) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO0 = 1;
	    			GPIO1 = 1;
	    			GPIO2 = 1;
	    			/*GPIO3 = 0;
	    			GPIO4 = 0;*/
	    			*(volatile unsigned int*)0x25 |= 0b00000001;
	    		}
	    		else if (number == 8 && ((history2 >> 7) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO3 = 1;
	    			/*GPIO0 = 0;
	    			GPIO1 = 0;
	    			GPIO2 = 0;
	    			GPIO4 = 0;*/
	    			*(volatile unsigned int*)0x35 |= 0b10000000;
	    		}
	    		else if (number == 9 && ((history2 >> 6) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO0 = 1;
	    			GPIO3 = 1;
	    			/*GPIO1 = 0;
	    			GPIO2 = 0;
	    			GPIO4 = 0;*/
	    			*(volatile unsigned int*)0x35 |= 0b01000000;
	    		}
	    		else if (number == 10 && ((history2 >> 5) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			/*GPIO0 = 0;
	    			GPIO1 = 0;
	    			GPIO2 = 0;
	    			GPIO3 = 0;*/
	    			GPIO4 = 1;
	    			*(volatile unsigned int*)0x35 |= 0b00100000;
	    		}
	    		else if (number == 11 && ((history2 >> 4) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO0 = 1;
	    			/*GPIO1 = 0;
	    			GPIO2 = 0;
	    			GPIO3 = 0;*/
	    			GPIO4 = 1;
	    			*(volatile unsigned int*)0x35 |= 0b00010000;
	    		}
	    		else if (number == 12 && ((history2 >> 3) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO1 = 1;
	    			GPIO4 = 1;
	    			/*GPIO0 = 0;
	    			GPIO2 = 0;
	    			GPIO3 = 0;*/
	    			*(volatile unsigned int*)0x35 |= 0b00001000;
	    		}
	    		else if (number == 13 && ((history2 >> 2) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO0 = 1;
	    			GPIO1 = 1;
	    			/*GPIO2 = 0;
	    			GPIO3 = 0;
	    			GPIO4 = 1;*/
	    			*(volatile unsigned int*)0x35 |= 0b00000100;
	    		}
	    		else if (number == 14 && ((history2 >> 1) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO2 = 1;
	    			GPIO4 = 1;
	    			/*GPIO0 = 0;
	    			GPIO1 = 0;
	    			GPIO3 = 0;*/
	    			*(volatile unsigned int*)0x35 |= 0b00000010;
	    		}
	    		else if (number == 15 && ((history2 >> 0) & 1) == 0)
	    		{
	    		//	number_found = 1;
	    			GPIO0 = 1;
	    			GPIO2 = 1;
	    			GPIO4 = 1;
	    			/*GPIO1 = 0;
	    			GPIO3 = 0;*/
	    			*(volatile unsigned int*)0x35 |= 0b00000001;
	    		}
	    		else
	    		{
	    			number_found = 0;
	    		}
	    		/*
	    		*/
    		}
    	}
    	else
    	{
    		number_found = 0;
    		GPIO0 = 0;
	    	GPIO1 = 0;
	    	GPIO2 = 0;
	    	GPIO3 = 0;
	    	GPIO4 = 0;
	   	}
    }
}

unsigned int lfsr_rnd(void)
{
	
    unsigned int bit;

    for (int i = 0; i < 16; ++i)
    {
		bit = ( (lfsr >> 0) ^ (lfsr >> 1) ^ (lfsr >> 4) ) & 1;
		lfsr = (lfsr >> 1) | (bit << 3);
	}

	return lfsr;
}