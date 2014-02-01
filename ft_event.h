/******************************************************************************* 
*
*   File : ft_event.H
*
*   Author : Adrien Chardon
*   Date :   2014-01-19 13:09:33
*
*   Last Modified by :   Adrien Chardon
*   Last Modified time : 2014-01-24 09:00:02
*
*******************************************************************************/

#ifndef FT_EVENT_H
#define FT_EVENT_H

void ft_update_event(int *quit, int *dir);
void ft_update_snake(t_snake *snake, char mapBlocks[MAP_HEIGHT][MAP_WIDTH]);
void ft_update_apple(t_snake *snake, t_vector *apple, char mapBlocks[MAP_HEIGHT][MAP_WIDTH]);
void ft_new_apple(t_snake *snake, t_vector *apple, char mapBlocks[MAP_HEIGHT][MAP_WIDTH]);

#endif
