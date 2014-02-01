/******************************************************************************* 
*
*   File : ft_print.h
*
*   Author : Adrien Chardon
*   Date :   2014-01-19 16:14:57
*
*   Last Modified by :   Adrien Chardon
*   Last Modified time : 2014-01-27 11:27:34
*
*******************************************************************************/

#ifndef FT_PRINT_H
#define FT_PRINT_H

void ft_print_title(void);
void ft_print_home(void);
void ft_print_score(int len, int highScore);

void ft_update_screen(char screen[MAP_HEIGHT][MAP_WIDTH], char mapBlocks[MAP_HEIGHT][MAP_WIDTH], t_snake *snake, t_vector *apple);
void ft_print_screen(char map[MAP_HEIGHT][MAP_WIDTH]);

#endif
