#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songListHeader.h"

int main() {
  char songs[10][100] = {"in my life","don't stop me now","tiny dancer","everybody talks","new house","all night","1950","chasing fire","build","netflix trip"};
  char artists[10][100] = {"beatles","queen","elton john","neon trees","elton john","the vamps","beatles","lauv","healy","ajr"};
  struct song_node *library = NULL;
  struct song_node *finder = NULL;
    struct song_node *random = NULL;
  int i;
  char fakesong[100] = "i want sleep";
  char fakeartist[100] = "amanda";
  printf("\n\nInitial library <empty>\n");
  print_list(library);

  for (i = 0;i < 10; i++){
    printf("\n\nInserting: <%s>, <%s>, This is element %d\n",songs[i],artists[i],i);
    library = add_node_alphabet(library,songs[i],artists[i]);
    print_list(library);
  }

  srand(time(0));
  for (i = 0;i < 3; i++){
    random = random_node(library, rand());
    printf("\n\nReturn random song: %s, %s\n",random->name, random->artist);
  }

  for (i = 0;i < 10; i++){
    printf("\n\nFinding: <%s>, <%s>, This is element %d\n",songs[i],artists[i],i);
    if( find_node(library,songs[i],artists[i]) !=NULL){
      printf("FOUND IT\n");
    }else{
      printf("YOU SUCK\n" );
    }
  }
  if( find_node(library,fakesong,fakeartist) !=NULL){
    printf("FOUND IT\n");
  }else{
    printf("YOU SUCK\n" );
  }
  for (i = 0;i < 10; i++){
    printf("\n\nFinding FIRST SONG OF: <%s>, This is element %d\n",artists[i],i);
    finder=find_first_node(library,artists[i]);
    if( finder !=NULL){
      printf("YASSS QUEEN, %s\n", finder->name);
    }else{
      printf("DUMMY\n" );
    }
  }
  if( find_first_node(library,fakeartist) !=NULL){
    printf("YASSS QUEEN, %s\n", finder->name);
  }else{
    printf("Dummy" );
  }
/*
  for(i = 3; i < 7; i++){
    library = remove_song(library, songs[i],artists[i]);

    printf("\n\nRemoving: <%s>, <%s>\n",songs[i],artists[i]);
    library = remove_song(library, songs[i],artists[i]);
    print_list(library);
  }*/
    library = free_list(library);
    printf("\n\nEmptying library ... Printing Emptied library: \n");
    library = free_list(library);
    print_list(library);

  return 0;
}
