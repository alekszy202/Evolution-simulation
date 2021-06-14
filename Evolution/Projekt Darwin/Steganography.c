#include <stdio.h>
#include "Header.h"

int main(int argc,char *argv[])
{
    int i;
    char *argv_2 = NULL, *argv_3 = NULL, *argv_4 = NULL;

    switch(argc)
    {
	case 8 :	if(!strcmp(argv[1],"-S"))
			{
			    for (i = 2; i < 8; i++)
			    {
				if (!strcmp(argv[i],"-i"))
				    argv_2 = argv[i+1];

				if (!strcmp(argv[i],"-t"))
				    argv_3 = argv[i+1];

				if (!strcmp(argv[i],"-o"))
				    argv_4 = argv[i+1];
			    }			    
			    szyfrowanie(argv_2, argv_3, argv_4);
			    break;
			}

	case 6 :	if(!strcmp(argv[1], "-O"))
			{
			    for (i = 2; i < 6; i++)
			    {
				if (!strcmp(argv[i],"-i"))
				    argv_2 = argv[i+1];
				if (!strcmp(argv[i],"-o"))
				    argv_4 = argv[i+1];
			    }			    

			    odczyt(argv_2, argv_4);
			    break;
			}

	default : 
		printf("\t*** !! Blad !! Blad !! Blad !!***\n\n");
		printf("\n\t\t*** Kodowanie *** ==> -S -i <input.bmp> -s <tekst.txt> -o <output.bmp>\n\n");
		printf("\t\t*** Odczyt *** ==> -O -i <input.bmp> -o <output_tekst.txt>\n\n");
    }	
    return 0;
}