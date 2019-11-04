
void print_library(struct song_node * library[27]);
void print_artist(struct song_node * library[27], char artist_name[100]);
void print_letter(struct song_node * library[27], char x);
struct song_node * find_song_lib(struct song_node * library[27],char song_name[100], char artist_name[100]);
struct song_node * find_artist_lib(struct song_node * library[27],char artist_name[100]);
struct song_node * add_song_lib(struct song_node * library[27], char song_name[100], char artist_name[100]);
struct song_node * remove_song (struct song_node * library[27], char song_name[100], char artist_name[100]);
struct song_node * free_library(struct song_node * library[27]);
struct song_node * random_song(struct song_node * library[27], int random);
