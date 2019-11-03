#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songListHeader.h"

int main() {

  struct song_node *library = NULL;
  int i;

  printf("\nInitial library <empty>\n");
  printf("Value of library:");
  print_library(library);

  for (i = 9;i > -1; i--){
    library = add_song(library,i,i);
    printf("\nInserting at the front, Value: <%d>\n",i);
    printf("Value of library: ");
    print_library(library);
  }

  for(i = 0; i < 2; i++){
    library = remove_song(library, i,i);
    printf("\nRemoving from the front, Value: <%d>\n",i);
    printf("Value of library: ");
    print_library(library);
  }

  for(i = 3; i < 5; i++){
    library = remove_song(library, i,i);
    printf("\nRemoving from the middle, Value: <%d>\n",i);
    printf("Value of library: ");
    print_library(library);
  }

  for(i = 9; i > 7; i--){
    library = remove_song(library, i,i);
    printf("\nRemoving from the end, Value: <%d>\n",i);
    printf("Value of library: ");
    print_library(library);
  }
    library = free_library(library);
    printf("\nEmptying library ... Printing Emptied library: \n");
    print_library(library);
  return 0;
}
