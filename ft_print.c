/******************************************************************************* 
*
*   File : ft_print.c
*
*   Author : Adrien Chardon
*   Date :   2014-01-19 16:12:21
*
*   Last Modified by :   Adrien Chardon
*   Last Modified time : 2014-01-27 11:51:42
*
*******************************************************************************/

#include <stdio.h>

#include "portability.h"

#include "constantes.h"
#include "ft_print.h"

void ft_print_title(void)
{
	printf( "+----------------------------------------------------------+\n"
			"|                                                          |\n"
			"|                        SUPER SNAKE                       |\n"
			"|                       -------------           by Nodraak |\n"
			"+-----------------------------+----------------------------+\n");
}

void ft_print_home(void)
{
	/*
		2 printf to disable warning due to ansi or pedantic option :
		maximum length of 509 that C90 compilers are required to support
	*/
	
	printf( "|  Vous etes un serpent.      |  Z : haut                  |\n"
			"|  Mangez le plus de pommes   |  S : bas                   |\n"
			"|  sans toucher les murs ou   |  Q : gauche                |\n"
			"|  votre queue (d'accord, en  |  D : droite                |\n"
			"|  vrai les serpents sont     |  P : pause                 |\n"
			"|  immunises contre leur      |  M : menu                  |\n"
			"|  venin, mais osef).         |                            |\n");
	printf( "+-----------------------------+----------------------------+\n"
			"|                                                          |\n"
			"|   W) Niveau 1                                            |\n"
			"|   X) Niveau 2                                            |\n"
			"|   C) Niveau 3                                            |\n"
			"|   Q) Quitter                                             |\n"
			"|                                                          |\n"
			"+----------------------------------------------------------+\n");
}

void ft_print_score(int len, int highScore)
{
	printf( "|                             |                            |\n"
			"|  SCORE : %2d pt%c             |  MEILLEUR SCORE : %2d pt%c   |\n"
			"|                             |                            |\n"
			"+-----------------------------+----------------------------+\n",
			len-3, len < 5 ? ' ' : 's',
			highScore, highScore < 2 ? ' ' : 's');
}

void ft_update_screen(char screen[MAP_HEIGHT][MAP_WIDTH], char mapBlocks[MAP_HEIGHT][MAP_WIDTH], t_snake *snake, t_vector *apple)
{
	int i, j;

	/* clear map + set edge (in french : bordure) */
	for (j = 0; j < MAP_HEIGHT; ++j)
	{
		for (i = 0; i < MAP_WIDTH; ++i)
		{
			screen[j][i] = ' ';
			
			if ((i == 0 || i == MAP_WIDTH-1) && j != 0 && j != MAP_HEIGHT-1)
				screen[j][i] = '|';
			else if ((j == 0 || j == MAP_HEIGHT-1) && i != 0 && i != MAP_WIDTH-1)
				screen[j][i] = '-';
			else if (i == 0 || i == MAP_WIDTH-1 || j == 0 || j == MAP_HEIGHT-1)
				screen[j][i] = '+';
		}
	}

	/* blit blocks */
	for (j = 0; j < MAP_HEIGHT; ++j)
	{
		for (i = 0; i < MAP_WIDTH; ++i)
		{
			if (mapBlocks[j][i] != ' ')
				screen[j][i] = mapBlocks[j][i];
		}
	}
	
	/* blit apple */
	screen[apple->y][apple->x] = 'o';

	/* blit snake */
	for (i = 0; i < snake->len; ++i)
	{
		if (snake->alive)
			screen[snake->body[i].y][snake->body[i].x] = 'O';
		else
			screen[snake->body[i].y][snake->body[i].x] = 'X';

	}
}

void ft_print_screen(char map[MAP_HEIGHT][MAP_WIDTH])
{
	int i, j;

	for (j = 1; j < MAP_HEIGHT; ++j) /* skip first line - already blitted */
	{
		for (i = 0; i < MAP_WIDTH; ++i)
		{
			if (map[j][i] == '#')
				portability_text_color_set(COLOR_RED);
			else if (map[j][i] == 'O')
				portability_text_color_set(COLOR_BLUE);
			else if (map[j][i] == 'o')
				portability_text_color_set(COLOR_GREEN);
			else
				portability_text_color_set(COLOR_DEFAULT);
			
			printf("%c", map[j][i]);
		}
		printf("\n");
	}

	/* for safety */
	portability_text_color_set(COLOR_DEFAULT);
}
