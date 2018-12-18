//This is a fucking mancala board.

#include "mancala.h"

struct hole* newhole(int s,int h){
  struct hole* new=malloc(sizeof(struct hole));
  new->stones=s;
  new->home=h;
  return new;
}

struct mancala* newman(){
  struct mancala* m=malloc(sizeof(struct mancala));
  m->home1=newhole(0,1);
  m->home2=newhole(0,2);
  struct hole* c1=m->home1;
  struct hole* c2=m->home2;
  for(int i=0;i<6;i++){
    c1->next=newhole(4,0);
    c1->next->prev=c1;
    c2->next=newhole(4,0);
    c2->next->prev=c2;
    c1=c1->next;
    c2=c2->next;
  }
  c1->next=m->home2;
  m->home2->prev=c1;
  c2->next=m->home1;
  m->home1->prev=c2;
  return m;
}

void freeman(struct mancala* m){
  struct hole* cursor=m->home1->next->next;
  while(cursor!=m->home1){
    free(cursor->prev);
    cursor=cursor->next;
  }
  free(cursor->prev);
  free(cursor);
  free(m);
}

int turn(struct mancala* m,int space,int player){
  if(space<1||space>6){
    return -1;
  }
  if(player!=1 && player!=2){
    return -1;
  }
  struct hole* c;
  if(player==1){
    c=m->home2;
  }else{
    c=m->home1;
  }
  for(int i=0;i<space;i++){
    c=c->next;
  }
  if(c->stones>0){
    return pickup(c,player,m);
  }else{
    return -1;
  }
}

int hiddenturn(struct mancala* m,int space,int player){
  if(space<1||space>6){
    return -1;
  }
  if(player!=1 && player!=2){
    return -1;
  }
  struct hole* c;
  if(player==1){
    c=m->home2;
  }else{
    c=m->home1;
  }
  for(int i=0;i<space;i++){
    c=c->next;
  }
  if(c->stones>0){
    return hiddenpickup(c,player);
  }else{
    return -1;
  }
}

int pickup(struct hole* h,int player,struct mancala* m){
  int inhand=h->stones;
  h->stones=0;
  display(m);
  return drop(h->next,inhand,player,m);
}

int hiddenpickup(struct hole* h,int player){
  int inhand=h->stones;
  h->stones=0;
  return hiddendrop(h->next,inhand,player);
}

int drop(struct hole* h,int in,int player,struct mancala* m){
  int inhand= in;
  if(h->home!=0 && h->home!=player){
    return drop(h->next,in,player,m);
  }else{
    inhand--;
    h->stones++;
    if(inhand==0){
      if(h->home==player){
	return 1;
      }else if(h->stones==1){
	return 0;
      }else{
	return pickup(h,player,m);
      }
    }
    return drop(h->next,inhand,player,m);
  }
}

int hiddendrop(struct hole* h,int in,int player){
  int inhand= in;
  if(h->home!=0 && h->home!=player){
    return hiddendrop(h->next,in,player);
  }else{
    inhand--;
    h->stones++;
    if(inhand==0){
      if(h->home==player){
        return 1;
      }else if(h->stones==1){
        return 0;
      }else{
        return hiddenpickup(h,player);
      }
    }
    return hiddendrop(h->next,inhand,player);
  }
}


int gameover(struct mancala* m){
  int p1empty=1;
  int p2empty=1;
  struct hole* p1=m->home2->next;
  struct hole* p2=m->home1->next;
  for(int i=0;i<6;i++){
    if(p1->stones>0){
      p1empty=0;
    }
    if(p2->stones>0){
      p2empty=0;
    }
    p1=p1->next;
    p2=p2->next;
  }
  p1=p1->next;
  p2=p2->next;
  if(p1empty==1||p2empty==1){
    int s1=0;
    int s2=0;
    for(int i=0;i<6;i++){
      s1=s1+p2->stones;
      p2->stones=0;
      s2=s2+p1->stones;
      p1->stones=0;
      p1=p1->next;
      p2=p2->next;
    }
    m->home1->stones=m->home1->stones+s1;
    m->home2->stones=m->home2->stones+s2;
    return 1;
  }
  return 0;
}

struct mancala* newcopy(struct mancala* m){
  struct mancala* copy=newman();
  struct hole* c1=copy->home1;
  struct hole* c2=m->home1;
  for(int i=0;i<14;i++){
    c1->stones=c2->stones;
    c1=c1->next;
    c2=c2->next;
  }
  return copy;
}
