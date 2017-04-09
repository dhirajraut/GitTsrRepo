#include <dos.h>
#include <conio.h>
#define INTR 0x24l
#ifdef __cplusplus
    #define __CPPARGS ...
#else
    #define __CPPARGS
#endif

//unsigned long interrupt our();
//unsigned long interrupt (*prev) ();
void interrupt our();
void interrupt (*prev) (__CPPARGS);
char far *scr = (char far*) 0xb8000000l;

void interrupt our()
{
	int i;
	for (i = 0; i<= 3999; i+=2)
	{
		if (*(scr+i)>='A' &&  *(scr+i)<='Z')
			*(scr+i) += 32;
		else
		if (*(scr+i)>='a' &&  *(scr+i)<='z')
			*(scr+i) -= 32;
	}
	(*prev)();
}

void main(void)
{
	unsigned long int far *p;
	prev = getvect(INTR);
//	prev = *p;
	setvect(0x24l,our);
	keep (0, 500);
//	while (!kbhit())
//		our();
}

