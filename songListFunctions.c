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

void print_library(struct song_node *p){
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
  printf("]");
}
struct song_node * add_song_alphabet(struct song_node *p, char song_name[100], char artist_name[100]){
  struct song_node *pnew;
  struct song_node *looper=p;
  struct song_node *recorder=NULL;
  pnew=malloc(sizeof(struct song_node));
  strcpy(pnew->name,song_name);
  strcpy(pnew->artist,artist_name);
  while(looper !=NULL){
    if(strcmp(looper->artist,artist_name)==0){
      if(strcmp(looper->name,song_name)>0){
        connectNodes(recorder,pnew,looper);
        return p;
      }else{
        connectNodes(looper,pnew,looper->next);
        return p;
      }
    }else if(strcmp(looper->artist,artist_name)>0){
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
    recorder=looper;
    looper=looper->next;
  }
  return pnew;
}
void connectNodes(struct song_node *p,struct song_node *q,struct song_node *r){
  p->next=q;
  q->next=r;
}
struct song_node * add_song(struct song_node *p, char song_name[100], char artist_name[100]){
  struct song_node *pnew;
  pnew=malloc(sizeof(struct song_node));
  strcpy(pnew->name,song_name);
  strcpy(pnew->artist,artist_name);
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


struct song_node * remove_song (struct song_node *library, char song_name[100], char artist_name[100]){
  struct song_node * current_song = library;
  struct song_node * placeholder;
  if(strcmp(current_song->name,song_name) + strcmp(current_song->artist,artist_name) == 0){ //if I have to remove front node, it's a special case
    library = library->next;
    free(current_song);
    return library;
  }
  while(current_song->next != NULL){ //else, loop through, checking if my next node has to be removed
    if (strcmp(current_song->name,song_name) + strcmp(current_song->artist,artist_name) == 0){ //if it does have to be removed, relink neccesary nodes, and free node
      placeholder = current_song->next;
      current_song->next = current_song->next->next;
      current_song = current_song->next;
      free(placeholder);
      return library;
    } else{ //if not, move on to next node
      current_song = current_song->next;
    }
  }
  return library;
}

struct song_node * free_library(struct song_node* library){
  struct song_node* sub;
  while (library!=NULL) {
    sub=library;
    printf("Freeing: %s, %s\n", library->name, library->artist);
    library=library->next;
    free(sub);
  }
  return library;
}
