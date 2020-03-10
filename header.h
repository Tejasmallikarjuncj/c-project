#include <gtk/gtk.h>

typedef struct client {
int pin;
long long int acc_no;
char name[15];
char acc_type[15];
float balance;
char bank_name[15];
long long int card;
int retrn; 
}atm;

typedef struct gui {
GtkWidget *win;
GtkWidget *box;
GtkWidget *label[10];
GtkWidget *button[3];
GtkWidget *entry;
GtkWidget *radio_button[4];
GtkWidget *dailog_box[4];
}gui;

void win1(int, char* []);

void win2(int, char* []);

void win3_a(int, char* []);

void win3_b(int, char* []);

void win3_c(int, char* []);

void win3_d(int, char* []);

void next1(GtkWiget *,gpointer);

void next2(GtkWiget *,gpointer);

void next3(GtkWiget *,gpointer);

void next4(GtkWiget *,gpointer);

void prev(GtkWiget *,gpointer);

void submit3a(GtkWiget *,gpointer);

void submit3c(GtkWiget *,gpointer);

void submit3d(GtkWiget *,gpointer);

atm* load(void);

atm* search(atm *);

void wrt_bal(long long int);

char* typ_int(int);

char* typ_flt(float);






