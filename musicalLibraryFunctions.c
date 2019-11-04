#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <time.h>
#include <ctype.h>
#include "helperFunctionsHeader.h"

//struct song_node{
//  char name[100];
//  char artist[100];
//  struct song_node *next;
//};

void print_library(struct song_node * library[27]){
  int i;
  for (i = 0; i < 27; i++) {
    printf("%c list:\n",(library[i]->artist)[0]);
    print_list(library[i]);
    printf("\n");
  }
}

void print_artist(struct song_node * library[27], char artist_name[100]){
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
void print_letter(struct song_node * library[27], char x){
  int i= x;
  printf("%c list:\n",i);
  print_list(library[i]);
  printf("\n");
}


struct song_node * find_song_lib(struct song_node * library[27],char song_name[100], char artist_name[100]){
  if(artist_name[0]-97<0){
    return find_node(library[26],song_name,artist_name);
  }else{
    return find_node(library[artist_name[0]-97],song_name,artist_name);
  }
}
struct song_node * find_artist_lib(struct song_node * library[27],char artist_name[100]){
  if(artist_name[0]-97<0){
    return find_artist_song(library[26],artist_name);
  }else{
    return find_artist_song(library[artist_name[0]-97],artist_name);
  }
}

struct song_node * add_song_lib(struct song_node * library[27], char song_name[100], char artist_name[100]){
  if(artist_name[0]-97<0){
    library[26] = add_node_alphabet(library[26], song_name, artist_name);
    return library[0];
  }else{
    if(artist_name[0]-97 == 0 ){
      return add_node_alphabet(library[artist_name[0]-97], song_name, artist_name);
    }else{
      library[artist_name[0]-97] = add_node_alphabet(library[artist_name[0]-97], song_name, artist_name);
      return library[0];
    }
  }

}

struct song_node * remove_song (struct song_node * library[27], char song_name[100], char artist_name[100]){
  if(artist_name[0] - 97 < 0){
    remove_node(library[26], song_name, artist_name);
  }
  remove_node(library[artist_name[0] - 97], song_name, artist_name);
}

struct song_node * free_library(struct song_node * library[27]){
  int i = 0;
  for(i = 0; i < 27; i++){
    free_list(library[0]);
  }
}

struct song_node * random_song(struct song_node * library[27], int random){
  random = random%27;
  return random_song(library[random],random);
}
