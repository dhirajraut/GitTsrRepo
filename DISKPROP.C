#include <dos.h>

void main()
{
	union REGS i,o;
	struct SREGS s;

	unsigned char far * media_id;
	int num_of_clusters, sec_per_clusters, bytes_per_clusters;
	unsigned long capacity;

	i.h.ah = 0x1c;
	i.h.dl = 0;
	intdosx (&i, &o, &s);

	media_id = MK_FP (s.ds, o.x.bx);
	num_of_clusters = o.x.dx;
	sec_per_clusters = o.h.al;
	bytes_per_clusters = o.x.cx;

	clrscr();
	printf("\nMedia ID is %x ", *media_id);

	switch (*media_id)
	{
		case 0xF8:
			printf("HDD");
			break;
		case 0xF0:
			printf("3.5 INCH, 2 SIDED, 18 SECTORS");
			break;
		case 0xF9:
			printf("5.25 INCH, 2 SIDED, 15 SECTORS");
			printf("\n3.5 INCH, 2 SIDED, 9 SECTORS");
			break;
		case 0xFC:
			printf("5.25 INCH, 1 SIDED, 9 SECTORS");
			break;
		case 0xFD:
			printf("5.25 INCH, 2 SIDED, 9 SECTORS");
			break;
		case 0xFE:
			printf("5.25 INCH, 1 SIDED, 8 SECTORS");
			break;
		case 0xFF:
			printf("5.25 INCH, 2 SIDED, 8 SECTORS");
			break;
	};
	capacity = (long) sec_per_clusters * num_of_clusters * bytes_per_clusters / 1024;
	printf("\n Total data space         : %lu KB", capacity);
	printf("\n Total clusters are       : %lu", num_of_clusters);
	printf("\n No of sectors / clusters : %d", sec_per_clusters);
	printf("\n No. of bytes / sectors   : %d", bytes_per_clusters);

}