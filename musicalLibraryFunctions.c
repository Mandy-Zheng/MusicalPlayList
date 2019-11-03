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

void print_library(struct song_node *p){
}
struct song_node * add_song(struct song_node *p, char song_name[100], char artist_name[100]){
}

struct song_node * find_song(struct song_node *p,char song_name[100], char artist_name[100]){
}
struct song_node * find_first_song(struct song_node *p,char artist_name[100]){

}


struct song_node * remove_song (struct song_node * library[27], char song_name[100], char artist_name[100]){
  if(artist_name[0] - 97 < 0){
    remove_node(library[26], song_name, artist_name)
  }
  remove_node(library[artist[0] - 97], song_name, artist_name)
}

struct song_node * free_library(struct song_node * library[27]){
  int i = 0;
  for(i = 0; i < 27; i++){
    free_list(library[0]);
  }
}

struct song_node * random_song(struct song_node *library, int random){
  random = random%27;
  return random_song(library[random]);
}
