struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
void print_list(struct song_node *p);
struct song_node * add_node_alphabet(struct song_node *p, char node_name[100], char artist_name[100]);
void connectNodes(struct song_node *p,struct song_node *q,struct song_node *r);
struct song_node * add_node_front(struct song_node *p, char node_name[100], char artist_name[100]);
struct song_node * find_node(struct song_node *p,char node_name[100], char artist_name[100]);
struct song_node * find_artist_song(struct song_node *p,char artist_name[100]);
struct song_node * remove_node (struct song_node *list, char node_name[100], char artist_name[100]);
struct song_node * free_list(struct song_node* list);
struct song_node * random_node(struct song_node *list,int random);
struct song_node * free_list_nonprint(struct song_node* list);
