/******************************************************************************* 
*
*   File : constantes.h
*
*   Author : Adrien Chardon
*   Date :   2014-01-19 13:04:34
*
*   Last Modified by :   Adrien Chardon
*   Last Modified time : 2014-01-27 11:45:51
*
*******************************************************************************/

#ifndef CONSTANTES_H
#define CONSTANTES_H

#define MAP_WIDTH	    60
#define MAP_HEIGHT	    40

#define SNAKE_LEN	    50

#define SIZE_DOOR_1		5
#define SIZE_DOOR_2		10

enum
{
	STATE_PLAYING,
	STATE_PAUSE,
	STATE_QUIT
};

enum
{
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT
};

typedef struct  s_vector
{
	int         x;
	int         y;
}               t_vector;

typedef struct  s_snake
{
	t_vector    body[SNAKE_LEN];
	int         len;

	int			dir;
	int			alive;
}               t_snake;

#endif
