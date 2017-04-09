# include <dos.h>
void interrupt (*prevtimer) ();
void interrupt mytimer ();
int running = 0;
unsigned long far *time = (unsigned long far *)0x46c;
char far *scr;
char far *mode;

void main()
{
	if ((*mode & 0x30) == 0x30)
		scr = (char far *)0xb0000000;
	else scr = (char far *)0xb8000000;
	prevtimer = getvect (8);
	setvect (8, mytimer);
	keep (0,1000);
}

void interrupt mytimer()
{
	unsigned char hr, sec, min;
	if (running == 0)
	{
		running = 1;
		hr = (*time/65520);
		min = (*time - hr * 65520) / 1092;
		sec = (*time - hr * 65520 - min * 1092) * 10 / 182;
		if (sec >= 60)
		{
			sec -= 60;
			min++;
			if (min == 60)
			{
				min = 0;
				hr ++;
				if (hr == 24)
					hr = 0;
			}
		}
		writechar (48+hr/10 , 0, 72, 112);
		writechar (48+hr%10 , 0, 73, 112);
		writechar (':'	    , 0, 74, 112);
		writechar (48+min/10, 0, 75, 112);
		writechar (48+hr%10 , 0, 76, 112);
		writechar (':'	    , 0, 77, 112);
		writechar (48+sec/10, 0, 78, 112);
		writechar (48+sec%10, 0, 79, 112);
		running = 0;
	}
	(*prevtimer) ();
}

writechar (char ch, int row, int col, int att)
{
	*(scr + row * 160 + col * 2) = ch;
	*(scr + row * 160 + col * 2 + 1) = att;
}