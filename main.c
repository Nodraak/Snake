/*******************************************************************************
*
*   File : main.c
*
*   Author : Adrien Chardon
*   Date :   2014-01-14 11:30:26
*
*   Last Modified by :   Adrien Chardon
*   Last Modified time : 2014-01-28 13:12:38
*
*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h> /* time() for srand() */

#include "portability.h" /* always last include */

#include "constantes.h"
#include "ft_init.h"
#include "ft_event.h"
#include "ft_print.h"
#include "ft_score.h"

/* some prototypes */
int ft_menu(void);
void ft_play(int level);
void ft_sleep(int n, int dir);

/* guess what this function does */
int main(void)
{
	int choice;

	portability_init();
	srand(time(NULL));

	do {
		choice = ft_menu();

		if (choice != 0)
			ft_play(choice);
	} while (choice != 0);
	
	portability_shutdown();
	return 0;
}

int ft_gen_color(void)
{
	return 30+rand()%8;
}

///////////////////////////////////////////////////////////////////////////////////

/* get user's choice */
int ft_menu(void)
{
	char c;
	int ret;

	system("CLS");
	ft_print_title();
	ft_print_home();

	do {
		while (!kbhit())
			Sleep(1000/25); /* be nice with the CPU */
		c = getchar(); /* fflush(stdin) is not safe - google for more info */
		if (c == 'w')
			ret = 1;
		else if (c == 'x')
			ret = 2;
		else if (c == 'c')
			ret = 3;
		else if (c == 'q')
			ret = 0;
		else
			ret = -1;
	} while (ret == -1);

	return ret;
}

/* main loop */
void ft_play(int level)
{
	/* var */
	char screen[MAP_HEIGHT][MAP_WIDTH];
	char mapBlocks[MAP_HEIGHT][MAP_WIDTH];
	t_snake snake;
	t_vector apple;
	int state = STATE_PLAYING;
	int highScore;

	/* init */
	ft_load_blocks(level, mapBlocks);
	ft_init_snake(&snake);
	ft_new_apple(&snake, &apple, mapBlocks);
	highScore = ft_get_high_score();
	system("CLS");

	while (snake.alive && state != STATE_QUIT)
	{
		/* events */
		ft_update_event(&state, &snake.dir);
		
		/* pause or not */
		if (state == STATE_PLAYING)
		{
			ft_update_snake(&snake, mapBlocks);
			ft_update_apple(&snake, &apple, mapBlocks);
		}
		
		/* display */
		ft_update_screen(screen, mapBlocks, &snake, &apple);
		//portability_background_color_set(ft_gen_color()); /* !!! epileptique */
		portability_gotoligcol(0, 0);
		ft_print_title();
		ft_print_score(snake.len, highScore);
		ft_print_screen(screen);

		/* sleep - be nice with the cpu + change snake speed */
		ft_sleep(snake.len, snake.dir);
	}

	/* if the player die, sleep + update high score */
	if (!snake.alive)
	{
		printf("Vous etes mort !\n");

		if (snake.len-3 > highScore)
		{
			printf("Nouveau meilleur score : %d pt%s\n", snake.len-3, snake.len-3 < 5 ? "." : "s.");
			ft_update_high_score(snake.len-3);
		}

		Sleep(2000);
	}
}

void ft_sleep(int n, int dir)
{
	double delay;
	double fps;

	fps = 2+1.5*n;
	delay = 1000/fps;

	/* speed different because a printed char on the term because his high != width */
	if (dir == DIR_UP || dir == DIR_DOWN)
		delay *= 1.2;

	Sleep((int)delay);
}
