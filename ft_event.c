/******************************************************************************* 
*
*   File : ft_event.c
*
*   Author : Adrien Chardon
*   Date :   2014-01-19 13:06:36
*
*   Last Modified by :   Adrien Chardon
*   Last Modified time : 2014-01-27 16:18:03
*
*******************************************************************************/

#include "portability.h" /* always last include */

#include "constantes.h"
#include "ft_event.h"

/* handle event : play/pause/quit + change direction */
void ft_update_event(int *quit, int *dir)
{
	if (kbhit())
	{
		char c = getchar();

		/* change dir */
		if (c == 'z' && *dir != DIR_DOWN)
			*dir = DIR_UP;
		if (c == 'q' && *dir != DIR_RIGHT)
			*dir = DIR_LEFT;
		if (c == 's' && *dir != DIR_UP)
			*dir = DIR_DOWN;
		if (c == 'd' && *dir != DIR_LEFT)
			*dir = DIR_RIGHT;

		/* pause */
		if (c == 'p')
		{
			if (*quit == STATE_PLAYING) /* playing -> pause */
				*quit = STATE_PAUSE;
			else
				*quit = STATE_PLAYING; /* pause -> playing */
		}

		/* menu */
		if (c == 'm')
			*quit = STATE_QUIT;
	}
}

/* update snake stuff : snake moving + handle death + respawn whe reach edge of map */
void ft_update_snake(t_snake *snake, char mapBlocks[MAP_HEIGHT][MAP_WIDTH])
{
	int i;

	/* update body */
	for (i = snake->len; i >= 1; --i)
	{
		snake->body[i].x = snake->body[i-1].x;
		snake->body[i].y = snake->body[i-1].y;
	}

	/* update head */
	if (snake->dir == DIR_RIGHT)
		snake->body[0].x++;
	if (snake->dir == DIR_LEFT)
		snake->body[0].x--;
	if (snake->dir == DIR_UP)
		snake->body[0].y--;
	if (snake->dir == DIR_DOWN)
		snake->body[0].y++;

	/* test death */
	if (mapBlocks[snake->body[0].y][snake->body[0].x] != ' ')
	{
		snake->alive = 0;
	}
	for (i = 1; i < snake->len; ++i)
	{
		if (snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y)
			snake->alive = 0;
	}

	/* respawn */
	if (snake->body[0].x == 0)
		snake->body[0].x = MAP_WIDTH-2;
	if (snake->body[0].x == MAP_WIDTH-1)
		snake->body[0].x = 1;
	if (snake->body[0].y == 0)
		snake->body[0].y = MAP_HEIGHT-2;
	if (snake->body[0].y == MAP_HEIGHT-1)
		snake->body[0].y = 1;
}

/* call the proper function ton gen new apple if the actual is eaten */
void ft_update_apple(t_snake *snake, t_vector *apple, char mapBlocks[MAP_HEIGHT][MAP_WIDTH])
{
	if (snake->body[0].x == apple->x && snake->body[0].y == apple->y)
	{
		snake->len++;
		ft_new_apple(snake, apple, mapBlocks);
	}
}

/* gen new apple */
void ft_new_apple(t_snake *snake, t_vector *apple, char mapBlocks[MAP_HEIGHT][MAP_WIDTH])
{
	int okApple = 0;
	int i;

	/* while new apple is on the snake */
	while (!okApple)
	{
		okApple = 1;

		/* random pos */
		apple->x = (rand() % (MAP_WIDTH-2)) + 1;
		apple->y = (rand() % (MAP_HEIGHT-2)) + 1;

		/* check snake */
		for (i = 0; i < snake->len; ++i)
		{
			if (snake->body[i].x == apple->x && snake->body[i].y == apple->y)
				okApple = 0;
		}
		/* check map */
		if (mapBlocks[apple->y][apple->x] != ' ')
			okApple = 0;
	}
}
