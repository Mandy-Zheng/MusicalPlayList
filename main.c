#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songListHeader.h"

int main() {
  char songs[10][100] = {"in my life","don't stop me now","tiny dancer","everybody talks","new house","all night","1950","chasing fire","build","netflix trip"};
  char artists[10][100] = {"beatles","queen","elton john","neon trees","rex orange country","the vamps","king princess","lauv","healy","ajr"};
  struct song_node *library = NULL;
  int i;

  printf("\n\nInitial library <empty>\n");
  print_library(library);

  for (i = 0;i < 10; i++){
    library = add_song(library,songs[i],artists[i]);
    printf("\n\nInserting: <%s>, <%s>\n",songs[i],artists[i]);
    print_library(library);
  }

  for(i = 3; i < 7; i++){
    library = remove_song(library, songs[i],artists[i]);
    printf("\n\nRemoving: <%s>, <%s>\n",songs[i],artists[i]);
    print_library(library);
  }
    library = free_library(library);
    printf("\n\nEmptying library ... Printing Emptied library: \n");
    print_library(library);
  return 0;
}
