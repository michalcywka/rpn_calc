typedef struct stos{
        int wartosc;
        struct stos *poprz;
        } T_stos;

int pop(T_stos **);
int czydwa(T_stos **);

void push (T_stos **, int);
void print(T_stos *);
void zamien(T_stos **);
void duplikuj(T_stos **);
