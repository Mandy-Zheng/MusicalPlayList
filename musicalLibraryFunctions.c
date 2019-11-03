#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <time.h>
#include <ctype.h>
#include "songListHeader.h"
#include "songListFunctions.c"
//struct song_node{
//  char name[100];
//  char artist[100];
//  struct song_node *next;
//};

void print_library(struct song_node library[27]){
  int i;
  for (i = 0; i < 27; i++) {
    printf("%c list:\n",(library[i]->artist)[0]);
    print_list(library[i]);
    printf("\n");
  }
}

void print_artist(struct song_node library[27], char artist_name[100]){
  int index;
  printf("%s list:\n",artist_name);
  if(artist_name[0]-97<0){
    index=26;
  }else{
    index=artist_name[0]-97;
  }
  struct song_node * looper=library[index];
  printf("[");
  while(looper != NULL && strcmp(looper->artist,artist_name)==0){
    if (looper==library[index]){
      printf("%s: %s",looper->artist,looper->name);
    }
    else{
      printf(" | %s: %s",looper->artist,looper->name);
    }
    looper=looper->next;
  }
  printf("]");
}
void print_letter(struct song_node library[27], char x){
  int i= x;
  printf("%c list:\n",i);
  print_list(library[i]);
  printf("\n");
}


struct song_node * find_song_lib(struct song_node library[27],char song_name[100], char artist_name[100]){
  if(artist_name[0]-97<0){
    return find_song(library[26],song_name,artist_name);
  }else{
    return find_song(library[artist_name[0]-97],song_name,artist_name);
  }
}
struct song_node * find_artist_lib(struct song_node library[27],char artist_name[100]){
  if(artist_name[0]-97<0){
    return find_artist_song(library[26],artist_name);
  }else{
    return find_artist_song(library[artist_name[0]-97],artist_name);
  }
}

struct song_node * add_song_lib(struct song_node library[27], char song_name[100], char artist_name[100]){
  if(artist_name[0]-97<0){
    add_node_alphabet(library[26], song_name, artist_name);
    return library;
  }else{
    if(artist_name[0]-97 == 0 ){
      return add_node_alphabet(library[artist_name[0]-97], song_name, artist_name);
    }else{
      add_node_alphabet(library[artist_name[0]-97], song_name, artist_name);
      return library;
    }
  }

}

struct song_node * remove_song (struct song_node *library, char song_name[100], char artist_name[100]){
  struct song_node * current_song = library;
  struct song_node * placeholder;
  if(strcmp(current_song->name,song_name) == 0 && strcmp(current_song->artist,artist_name) == 0){ //if I have to remove front node, it's a special case
    library = library->next;
    free(current_song);
    return library;
  }
  while(current_song->next != NULL){ //else, loop through, checking if my next node has to be removed
    if (strcmp(current_song->next->name,song_name) == 0 && strcmp(current_song->next->artist,artist_name) == 0){ //if it does have to be removed, relink neccesary nodes, and free node
      placeholder = current_song->next;
      current_song->next = current_song->next->next;
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

struct song_node * random_song(struct song_node *library, int random){
  struct song_node *looper=library;
  int size=0;
  while(looper != NULL){
      size++;
      looper = looper->next;
    }
  random = random%size;
  int count;
  looper=library;
  for(count = 0;looper != NULL;count++){
    if(count == random){
      return looper;
    }
    looper=looper->next;
  }
  return library;
}
