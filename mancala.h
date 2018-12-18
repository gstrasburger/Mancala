#include <stdio.h>
#include <stdlib.h>

struct hole{
  int stones;
  struct hole * next;
  struct hole * prev;
  //0: is not a home 1: p1 home 2: p2 home                                                      
  int home;
};

struct mancala{
  struct hole* home1;
  struct hole* home2;
};

#ifndef MANBOARD
#define MANBOARD

struct hole* newhole(int s,int h);
struct mancala* newman();
int turn(struct mancala* m,int space,int player);
int pickup(struct hole* h,int player,struct mancala* m);
int drop(struct hole* h,int in,int player,struct mancala* m);
int gameover(struct mancala* m);
void freeman(struct mancala* m);
int hiddenpickup(struct hole* h, int player);
int hiddenturn(struct mancala* m, int space, int player);
int hiddendrop(struct hole* h, int in, int player);
struct mancala* newcopy(struct mancala* m);

#endif

#ifndef DISPLAY
#define DISPLAY

void display(struct mancala* m);

#endif

#ifndef MINMAX
#define MINMAX

int Search(struct mancala* m,int depth);
int MinMax(struct mancala* m,int player,int depth);

#endif
