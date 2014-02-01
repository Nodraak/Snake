/******************************************************************************* 
*
*   File : ft_init.c
*
*   Author : Adrien Chardon
*   Date :   2014-01-19 12:58:38
*
*   Last Modified by :   Adrien Chardon
*   Last Modified time : 2014-01-27 11:56:39
*
*******************************************************************************/

#include "portability.h" /* always last include */

#include "constantes.h"
#include "ft_init.h"

int ft_abs(int nb)
{
	return nb < 0 ? -nb : nb;
}

void ft_init_snake(t_snake *snake)
{
	snake->body[0].x = MAP_WIDTH/2;
	snake->body[0].y = 6;
	snake->body[1].x = MAP_WIDTH/2;
	snake->body[1].y = 5;
	snake->body[2].x = MAP_WIDTH/2;
	snake->body[2].y = 4;

	snake->len = 3;
	snake->alive = 1;
	snake->dir = DIR_DOWN;
}

void ft_load_blocks(int level, char mapBlocks[MAP_HEIGHT][MAP_WIDTH])
{
	int i, j;

	/* clean map */
	for (j = 0; j < MAP_HEIGHT; ++j)
	{
		for (i = 0; i < MAP_WIDTH; ++i)
		{
			mapBlocks[j][i] = ' ';
		}
	}

	if (level == 2)
	{
		for (j = 1; j < MAP_HEIGHT-1; ++j)
		{
			if (ft_abs(MAP_HEIGHT/2 - j) > SIZE_DOOR_1)
			{
				mapBlocks[j][1] = '#';
				mapBlocks[j][MAP_WIDTH-2] = '#';
			}
		}
		for (i = 1; i < MAP_WIDTH-1; ++i)
		{
			if (ft_abs(MAP_WIDTH/2 - i) > SIZE_DOOR_1)
			{
				mapBlocks[1][i] = '#';
				mapBlocks[MAP_HEIGHT-2][i] = '#';
			}
		}
	}

	if (level == 3)
	{
		for (i = 10; i < MAP_WIDTH-11; ++i)
		{
			mapBlocks[MAP_HEIGHT/2-1][i] = '#';
			mapBlocks[MAP_HEIGHT/2][i] = '#';
			mapBlocks[MAP_HEIGHT/2+1][i] = '#';
		}
		/* vert */
		for (j = 1; j < MAP_HEIGHT-1; ++j)
		{
			if (ft_abs(MAP_HEIGHT/2 - j) > SIZE_DOOR_2)
			{
				mapBlocks[j][1] = '#';
				mapBlocks[j][MAP_WIDTH-2] = '#';
			}
		}
		/* top / bottom horiz */
		for (i = 1; i < MAP_WIDTH-1; ++i)
		{
			mapBlocks[1][i] = '#';
			mapBlocks[MAP_HEIGHT-2][i] = '#';
		}
	}
}
