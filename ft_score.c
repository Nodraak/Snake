/******************************************************************************* 
*
*   File : ft_score.c
*
*   Author : Adrien Chardon
*   Date :   2014-01-27 11:16:38
*
*   Last Modified by :   Adrien Chardon
*   Last Modified time : 2014-01-27 11:51:57
*
*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "ft_score.h"

/* load high score form file */
int ft_get_high_score(void)
{
	FILE *f = NULL;
	int n = 0;

	f = fopen("data.bin", "r");
	if (f == NULL)
	{
		printf("==> Erreur d'ouverture du ficher de scores.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(f, "%d", &n);

	fclose(f);
	
	return n;
}

/* save high score to file */
void ft_update_high_score(int n)
{
	FILE *f = NULL;

	f = fopen("data.bin", "r+");
	if (f == NULL)
	{
		printf("==> Erreur d'ouverture du ficher de scores.\n");
		exit(EXIT_FAILURE);
	}

	fprintf(f, "%d\n", n);

	fclose(f);
}
