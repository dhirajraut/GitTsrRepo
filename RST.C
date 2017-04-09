/* PROGRAM TO RESTART THE COMPUTER */
#include <dos.h>
void main ()
{
	void far (*p)();
	p = 0xFFFF0000;
	(*p)();
}