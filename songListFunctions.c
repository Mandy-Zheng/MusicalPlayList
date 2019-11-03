#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
//struct song_node{
//  char name[100];
//  char artist[100];
//  struct song_node *next;
//};

void print_list(struct song_node *p){
  printf("[");
  struct song_node *temp=p;
  while (temp!=NULL) {
    if (temp==p){
      printf("%s: %s ",temp->artist,temp->name);
    }
    else{
      printf("| %s: %s",temp->artist,temp->name);
    }
    temp=temp->next;
  }
  printf("]");
}
struct song_node * add_song_alphabet(struct song_node *p, char song_name[100], char artist_name[100]){
  struct song_node *pnew;
  struct song_node *looper=p;
  struct song_node *recorder;
  pnew=malloc(sizeof(struct song_node));
  pnew->name=song_name;
  pnew->artist=artist_name;
  boolean inserted=false;
  while(looper !=NULL && inserted){
    if(strcmp(looper->artist,artist_name)==0){
      if(strcmp(looper->name,song_name)>0){
        inserted=connectNodes(recorder,pnew,looper);
      }else{
        inserted=connectNodes(looper,pnew,looper->next);
      }
    }else if(strcmp(looper->artist,artist_name)>0){
      inserted=connectNodes(recorder,pnew,looper);
    }else{
      inserted=connectNodes(looper,pnew,looper->next);
    }
    recorder=looper;
    looper=loopoer->next
  }
  return p;
}
boolean connectNodes(struct song_node *p,struct song_node *q,struct song_node *r){
  p->next=q;
  q->next=r;
  return true;
}
struct song_node * add_song(struct song_node *p, char song_name[100], char artist_name[100]){
  struct song_node *pnew;
  pnew=malloc(sizeof(struct song_node));
  pnew->name=song_name;
  pnew->artist=artist_name;
  pnew->next=p;
  return pnew;
}
struct song_node * find_song(struct song_node *p,char song_name[100], char artist_name[100]){
  struct song_node *looper;
  while(looper !=NULL){
    if(strcmp(looper->artist,artist_name) == 0 && strcmp(looper->name,song_name) == 0){
      return looper;
    }
    looper=looper->next;
  }
  return looper;
}
struct song_node * find_first_song(struct song_node *p,char artist_name[100]){
  struct song_node *looper;
  while(looper !=NULL){
    if(strcmp(looper->artist,artist_name) == 0){
      return looper;
    }
    looper=looper->next;
  }
  return looper;
}
/*struct node * free_list(struct node* p){
  struct node* sub;
  while (p!=NULL) {
    sub=p;
    printf("Freeing: %d\n", sub->i);
    p=p->next;
    free(sub);
  }
  p=0;
  return p;
}*/
//JOSEPH DO WORK:
/*struct song_node * pop_song(struct song_node *p, char song_name[100], char artist_name[100]){
  struct node *delete=front;
  struct node *reconnect;
  if(delete==NULL){
    return front;
  }
  if(delete->i==data){
    front=front->next;
    free(delete);
    return front;
  }
  while (delete!=NULL && delete->i!=data) {
    reconnect=delete;
    delete=delete->next;
  }
  if(delete==NULL){
    return front;
  }else{
    reconnect->next=delete->next;
  }
  free(delete);
  return front;
}*/
