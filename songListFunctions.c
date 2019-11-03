#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
  struct song_node *looper
  pnew=malloc(sizeof(struct song_node));
  pnew->name=song_name;
  pnew->artist=artist_name;
  while()
}
struct song_node * add_song(struct song_node *p, char song_name[100], char artist_name[100]){
  struct song_node *pnew;
  pnew=malloc(sizeof(struct song_node));
  pnew->name=song_name;
  pnew->artist=artist_name;
  pnew->next=p;
  return pnew;
}

struct song_node * remove_song (struct node *libary, char song_name[100], char artist_name[100]){
  struct node * current_song = library;
  struct node * placeholder;
  if(strcmp(current_song->name,song_name) + strcmp(current_song->artist,artist_name) == 0){ //if I have to remove front node, it's a special case
    library = library->next;
    free(current_song);
    return library;
  }
  while(current_song->next != NULL){ //else, loop through, checking if my next node has to be removed
    if (strcmp(current_song->name,song_name) + strcmp(current_song->artist,artist_name) == 0){ //if it does have to be removed, relink neccesary nodes, and free node
      placeholder = p->next;
      current_song->next = current_song->next->next;
      current_song = current_song->next;
      free(placeholder);
      return libray;
    } else{ //if not, move on to next node
      current_song = current_song->next;
    }
  }
  return library;
}

struct song_node * free_list(struct node* library){
  struct node* sub;
  while (p!=NULL) {
    sub=libary;
    printf("Freeing: %d\n", libray->i);
    libary=libary->next;
    free(sub);
  }
  return p;
}
