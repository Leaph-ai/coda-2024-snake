#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 320

typedef struct s_nake snake;

struct s_nake
{
    int pos_x;
    int pos_y;
    int direction;
    snake *next;
};

typedef struct s_fruit fruit;

struct s_fruit
{
    int pos_x;
    int pos_y;
    int pos_bonus_x;
    int pos_bonus_y;
};

// snake.c
void move(snake **list, int direction);
snake *create_list();
int wincondition(snake **list);

// fruits.c
fruit *create_list_fruit();
void eat_fruit(snake **list, fruit *fruit, char **tab);
void pos_fruit(char **tab, fruit *list);

//fonction.c
void refresh_map(char **tab, snake *list, fruit *fruit);
void add_to_end(snake **list);
char * get_file(FILE * fp);
int count_lines(char *str);
void display_tab(char **tab, int lines);


#endif