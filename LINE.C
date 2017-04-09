#include <dos.h>

void interrupt our();
void interrupt (*prev)();
char far *scr = (char far *) 0xb8000000l;
int ticks;

void main ()
{
	prev = getvect (8);
	setvect (8, our);
	keep (0,1000);
}
void interrupt our()
{
	int col, row;
	char far *v;
	ticks ++;

	if (ticks == 182)
	{
		for (col = 40; col <= 79; col ++)
		{
			for (row = 1; row <= 24; row ++)
			{
				v = scr + row * 160 + col * 2;
				*(v-160) = *v;
				*v = ' ';
				delay (200);
			}
		}
		ticks = 0;
	}
	(*prev) ();
}