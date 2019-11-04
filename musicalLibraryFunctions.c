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
    if(library[i] != NULL){
      printf("%c list:\n",(library[i]->artist)[0]);
      print_list(library[i]);
      printf("\n");
    }
  }
}

void print_artist(struct song_node * library[27], char artist_name[100]){
  int index;
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
  int i= x-97;
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
      library[0] =  add_node_alphabet(library[artist_name[0]-97], song_name, artist_name);
      return library[0];
    }else{
      library[artist_name[0]-97] = add_node_alphabet(library[artist_name[0]-97], song_name, artist_name);
      return library[0];
    }
  }

}

struct song_node * remove_song (struct song_node * library[27], char song_name[100], char artist_name[100]){
  if(artist_name[0]-97<0){
    library[26] = remove_node(library[26], song_name, artist_name);
    return library[0];
  }else{
    if(artist_name[0]-97 == 0 ){
      library[0] =  remove_node(library[artist_name[0]-97], song_name, artist_name);
      return library[0];
    }else{
      library[artist_name[0]-97] = remove_node(library[artist_name[0]-97], song_name, artist_name);
      return library[0];
    }
  }
}

struct song_node * free_library(struct song_node * library[27]){
  int i = 0;
  for(i = 0; i < 27; i++){
    library[i] = free_list(library[i]);
  }
  return library[0];
}

struct song_node * random_list(struct song_node * library[27], struct song_node * list,int randomseed){
  int size = 0;
  int i;
  for(i = 0;i < 27; i++){
    if(library[i] != NULL){
      size++;
    }
  }
  size = randomseed%size;
  struct song_node * randomsong;
  for(i = 0; i < size; i++){
    int random = randomseed%27;
    while (library[random] == NULL){
      //printf("%d\n",random);
      random = rand()%27;
    }
    randomsong = random_node(library[random],randomseed);
    list = add_node_front(list,randomsong->name,randomsong->artist);
  }
  return list;
}
