#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <time.h>
#include <ctype.h>
#include "songListHeader.h"
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
      printf("%s: %s",temp->artist,temp->name);
    }
    else{
      printf(" | %s: %s",temp->artist,temp->name);
    }
    temp=temp->next;
  }
  printf("]\n");
}
struct song_node * add_node_alphabet(struct song_node *p, char song_name[100], char artist_name[100]){
  struct song_node *pnew;
  struct song_node *looper=p;
  struct song_node *recorder=NULL;
  pnew=malloc(sizeof(struct song_node));
  strcpy(pnew->name,song_name);
  strcpy(pnew->artist,artist_name);
  while(looper !=NULL){
    //printf("%d\n",strcmp(looper->artist,artist_name) );
    if(strcmp(looper->artist,artist_name)>0){
      if(recorder==NULL){
        pnew->next=looper;
        //printf("%s\n",pnew->next->artist);
        p=pnew;
        return pnew;
      }else{
        connectNodes(recorder,pnew,looper);
        return p;
      }
    }
    if(strcmp(looper->artist,artist_name)==0){
      if(strcmp(looper->name,song_name)>0){
        if(recorder==NULL){
          pnew->next=looper;
          return pnew;
        }else{
          connectNodes(recorder,pnew,looper);
          return p;
        }
      }else{
        connectNodes(looper,pnew,looper->next);
        return p;
      }
    }
    recorder=looper;
    looper=looper->next;
  }
  if(recorder!=NULL){
    //printf("whats");
    recorder->next=pnew;
    return p;
  }
  return pnew;
}
void connectNodes(struct song_node *p,struct song_node *q,struct song_node *r){
  p->next=q;
  q->next=r;
}
struct song_node * add_node_front(struct song_node *p, char song_name[100], char artist_name[100]){
  struct song_node *pnew;
  pnew=malloc(sizeof(struct song_node));
  strcpy(pnew->name,song_name);
  strcpy(pnew->artist,artist_name);
  pnew->next=p;
  return pnew;
}

struct song_node * find_node(struct song_node *p,char song_name[100], char artist_name[100]){
  struct song_node *looper=p;
  while(looper !=NULL){
    if(strcmp(looper->artist,artist_name) == 0 && strcmp(looper->name,song_name) == 0){
      return looper;
    }
    looper=looper->next;
  }
  return looper;
}
struct song_node * find_first_node(struct song_node *p,char artist_name[100]){
  struct song_node *looper=p;
  while(looper !=NULL){
    if(strcmp(looper->artist,artist_name) == 0){
      return looper;
    }
    looper=looper->next;
  }
  return looper;
}


struct song_node * remove_node (struct song_node *list, char song_name[100], char artist_name[100]){
  struct song_node * current_song = list;
  struct song_node * placeholder;
  if(strcmp(current_song->name,song_name) == 0 && strcmp(current_song->artist,artist_name) == 0){ //if I have to remove front node, it's a special case
    list = list->next;
    free(current_song);
    return list;
  }
  while(current_song->next != NULL){ //else, loop through, checking if my next node has to be removed
    if (strcmp(current_song->next->name,song_name) == 0 && strcmp(current_song->next->artist,artist_name) == 0){ //if it does have to be removed, relink neccesary nodes, and free node
      placeholder = current_song->next;
      current_song->next = current_song->next->next;
      free(placeholder);
      return list;
    } else{ //if not, move on to next node
      current_song = current_song->next;
    }
  }
  return list;
}

struct song_node * free_list(struct song_node* list){
  struct song_node* sub;
  while (list!=NULL) {
    sub=list;
    printf("Freeing: %s, %s\n", list->name, list->artist);
    list=list->next;
    free(sub);
  }
  return list;
}

struct song_node * random_node(struct song_node *list, int random){
  struct song_node *looper=list;
  int size=0;
  while(looper != NULL){
      size++;
      looper = looper->next;
    }
  random = random%size;
  int count;
  looper=list;
  for(count = 0;looper != NULL;count++){
    if(count == random){
      return looper;
    }
    looper=looper->next;
  }
  return list;
}
