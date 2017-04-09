void main ()
{
	int i;
	char far *vidmem = (char far *) 0xb8000000l;

	for (i = 0; i <= 3999; i = i + 2)
		if (*(vidmem + i) >= 65 && *(vidmem + i) <= 91)
		{
			*(vidmem + i) = (*(vidmem + i)) + 32;
			*(vidmem + i + 1) = 64;
		}
		else if (*(vidmem + i) >= 97 && *(vidmem + i) <= 122)
		{
			*(vidmem + i) = (*(vidmem + i)) - 32;
			*(vidmem + i + 1) = 77;
		}
}