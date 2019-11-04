#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "helperFunctionsHeader.h"
#include "musicalLibraryHeader.h"

int main() {
  char songs[8][100] = {"in my life","don't stop me now","tiny dancer","everybody talks","all night","1950","chasing fire","netflix trip"};
  char artists[8][100] = {"beatles","queen","elton john","neon trees","the vamps","king princess","lauv","ajr"};
  struct song_node *list = NULL;
  struct song_node * library[27];
  struct song_node *finder = NULL;
  struct song_node *random = NULL;
  int i;
  char fakesong[100] = "i want sleep";
  char fakeartist[100] = "amanda";

  printf("\n\n====================================\nLINKED LIST TESTS\n====================================\n\n");
  printf(" -- Testing adding nodes by alphabet and printing list-- \n");
  printf("\nInitial list <empty>\n");
  print_list(list);

  for (i = 0;i < 8; i++){
    printf("\nInserting: <%s>, <%s>\n",songs[i],artists[i]);
    list = add_node_alphabet(list,songs[i],artists[i]);
    print_list(list);
  }
  printf("_____________________________\n");

  printf("\n -- Testing returning random nodes -- \n");
  srand(time(0));
  for (i = 0;i < 3; i++){
    random = random_node(list, rand());
    printf("\nReturn random song: %s, %s\n",random->name, random->artist);
  }

  printf("_____________________________\n");

  printf("\n -- Testing find_node -- \n");
  for (i = 0;i < 2; i++){
    printf("\nFinding: <%s>, <%s>\n",songs[i],artists[i]);
    finder = find_node(list,songs[i],artists[i]);
    if(finder !=NULL){
      printf("FOUND IT: %s, %s\n",finder->artist, finder->name);
    }else{
      printf("Unable to find: <%s>, <%s>\n", songs[i],artists[i]);
    }
  }
  printf("\nFinding: <%s>, <%s>\n",artists[4],fakesong);
  finder = find_node(list,fakesong,artists[4]);
  if(finder !=NULL){
    printf("FOUND IT: <%s>, <%s>\n",artists[4],fakesong);
  }else{
    printf("Unable to find: <%s>, <%s>\n",artists[4],fakesong);
  }

    printf("\n_____________________________\n");

  printf("\n -- Testing finding the first node of an artist -- \n");
  for (i = 0;i < 3; i++){
    printf("\n\nFinding FIRST SONG OF: <%s>\n",artists[i]);
    finder=find_artist_song(list,artists[i]);
    if (finder !=NULL){
      printf("WOO! %s found, their first song is: %s\n", artists[i], finder->name);
    }else{
      printf("Awww : %s not found\n", artists[i]);
    }
  }
  printf("\n\nFinding FIRST SONG OF: <%s>\n",fakeartist);
  finder=find_artist_song(list,fakeartist);
  if (finder !=NULL){
    printf("WOO! %s found, their first song is: %s\n", fakeartist, finder->name);
  }else{
    printf("Awww : %s not found\n", fakeartist);
  }

    printf("\n_____________________________\n");

    printf("\n -- Testing removing nodes -- \n");
  for(i = 3; i < 7; i++){
    list = remove_node(list, songs[i],artists[i]);
    printf("\nRemoving: <%s>, <%s>\n",songs[i],artists[i]);
    list = remove_node(list, songs[i],artists[i]);
    print_list(list);
  }
    printf("\n_____________________________\n");

  printf("\n -- Testing freeing list -- \n");
  printf("Emptying list ... Printing Emptied list: \n");
  list = free_list(list);
  print_list(list);

  printf("\n\n====================================\nMUSICAL LIBRARY TESTS\n====================================\n\n");

  printf(" -- Testing adding songs by alphabet -- \n");
  printf("\nInitial library <empty>\n");
  print_library(library);

  for (i = 0;i < 8; i++){
    printf("\nInserting: <%s>, <%s>\n",songs[i],artists[i]);
    library[0] = add_song_lib(library,songs[i],artists[i]);
    print_library(library);
  }
  printf("_____________________________\n");

  printf("\n -- Testing returning random songs -- \n");
  srand(time(0));
  for (i = 0;i < 3; i++){
    random = random_song(library, rand());
    printf("\nReturn random song: %s, %s\n",random->name, random->artist);
  }

  printf("_____________________________\n");

  printf("\n -- Testing find_song -- \n");
  for (i = 0;i < 2; i++){
    printf("\nFinding: <%s>, <%s>\n",songs[i],artists[i]);
    finder = find_song_lib(library,songs[i],artists[i]);
    if(finder !=NULL){
      printf("FOUND IT: %s, %s\n",finder->artist, finder->name);
    }else{
      printf("Unable to find: <%s>, <%s>\n", songs[i],artists[i]);
    }
  }
  printf("\nFinding: <%s>, <%s>\n",artists[4],fakesong);
  finder = find_song_lib(library,fakesong,artists[4]);
  if(finder !=NULL){
    printf("FOUND IT: <%s>, <%s>\n",artists[4],fakesong);
  }else{
    printf("Unable to find: <%s>, <%s>\n",artists[4],fakesong);
  }

    printf("\n_____________________________\n");

  printf("\n -- Testing finding the first song of an artist -- \n");
  for (i = 0;i < 3; i++){
    printf("\n\nFinding FIRST SONG OF: <%s>\n",artists[i]);
    finder=find_artist_lib(library,artists[i]);
    if (finder !=NULL){
      printf("WOO! %s found, their first song is: %s\n", artists[i], finder->name);
    }else{
      printf("Awww : %s not found\n", artists[i]);
    }
  }
  printf("\n\nFinding FIRST SONG OF: <%s>\n",fakeartist);
  finder=find_artist_lib(library,fakeartist);
  if (finder !=NULL){
    printf("WOO! %s found, their first song is: %s\n", fakeartist, finder->name);
  }else{
    printf("Awww : %s not found\n", fakeartist);
  }

  printf("\n_____________________________\n");

printf("\n -- Testing finding the songs with artists starting with a certain letter -- \n");
  printf("\n\nFinding songs of artists starting with the letter: <b>\n");
  print_letter(library,'b');
  printf("\n\nFinding songs of artists starting with the letter: <q>\n");
  print_letter(library,'q');
}

printf("\n_____________________________\n");

printf("\n -- Testing finding all songs by an artist -- \n");
for (i = 0;i < 3; i++){
  printf("\n\nFinding all songs of : <%s>\n",artists[i]);
  print_artist(library, artists[i]);
}
    printf("\n_____________________________\n");

    printf("\n -- Testing removing songs -- \n");
  for(i = 3; i < 7; i++){
    library[0] = remove_song(library, songs[i],artists[i]);
    printf("\nRemoving: <%s>, <%s>\n",songs[i],artists[i]);
    library[0] = remove_song(library, songs[i],artists[i]);
    print_library(library);
  }
    printf("\n_____________________________\n");

  printf("\n -- Testing freeing library -- \n");
  printf("Emptying library ... Printing Emptied library: \n");
  library[0] = free_library(library);
  print_library(library);

  return 0;
}
