# include <stdio.h>
# include <dos.h>
void main ()
{
	struct WORDREGS
	{
		unsigned int ax, bx, cx, dx, si, di, cflag, flags;
	};
	struct BYTEREGS
	{
		unsigned char al, ah, bl, bh, cl, ch, dl, dh;
	};
	union REGS
	{
		struct WORDREGS x;
		struct BYTEREGS h;
	};
	union REGS inregs, outregs;
	int memsize;

	int86 (18,&inregs,&outregs);
	memsize = outregs.x.ax;
	printf("\n Total memory size = %d", memsize);
}