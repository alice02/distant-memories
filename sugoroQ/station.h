void init_station_server(struct board *board);
void init_station_client(struct board *board,char st_name[MAP_SIZE][BUF_SIZE], int value[MAP_SIZE], int have[MAP_SIZE]);
void free_station(struct board *board);
void convert_CSV(struct station *dat,char string[BUF_SIZE]);
struct station *insert_station(struct station *p);
struct station *s_access_station(struct station *p,int n);
struct station *r_access_station(struct station *p,int id);
