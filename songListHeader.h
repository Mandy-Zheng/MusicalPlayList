struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
void print_library(struct song_node *p);
struct song_node * add_song_alphabet(struct song_node *p, char song_name[100], char artist_name[100]);
void connectNodes(struct song_node *p,struct song_node *q,struct song_node *r);
struct song_node * add_song(struct song_node *p, char song_name[100], char artist_name[100]);
struct song_node * find_song(struct song_node *p,char song_name[100], char artist_name[100]);
struct song_node * find_first_song(struct song_node *p,char artist_name[100]);
struct song_node * remove_song (struct song_node *library, char song_name[100], char artist_name[100]);
struct song_node * free_library(struct song_node* library);
