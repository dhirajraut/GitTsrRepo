# include <stdio.h>
void main ()
{
	unsigned int far *mem;
	mem = (unsigned int far *) 0x413;
	printf("\n Base memory size = %u KB", *mem);
}