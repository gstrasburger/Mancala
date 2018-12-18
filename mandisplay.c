//It display mancala boards.

#include "mancala.h"

void display(struct mancala* m){
  printf("        6    5    4    3    2    1\n");
  printf("      /(");
  struct hole* c=m->home1->prev;
  for(int i=0;i<5;i++){
    printf("%d)<-(",c->stones);
    c=c->prev;
  }
  printf("%d)\\\n",c->stones);
  printf("P1 (%d)                             (%d)P2\n",m->home1->stones,m->home2->stones);
  c=m->home1->next;
  printf("      \\(");
  for(int i=0;i<5;i++){
    printf("%d)->(",c->stones);
    c=c->next;
  }
  printf("%d)/\n",c->stones);
  printf("        1    2    3    4    5    6\n");
}
