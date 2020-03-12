#include <gtk/gtk.h>

typedef struct client {
int pin;
int acc_no;
char name[15];
char acc_type[15];
float balance;
char bank_name[15];
int card;
int retrn; 
}atm;

typedef struct dailog {
GtkWidget *win;
GtkWidget *box;
GtkWidget *grid;
GtkWidget *b_grid;
GtkWidget *label;
GtkWidget *button[2];
}dail;

typedef struct gui {
GtkWidget *win;
GtkWidget *box;
GtkWidget *label[10];
GtkWidget *button[3];
GtkWidget *entry[2];
GtkToggleButton *radio_button[4];
}gui;

/*void next(GtkWidget *,gpointer);

void next1(GtkWidget *,gpointer);

void next2(GtkWidget *,gpointer);

void next3(GtkWidget *,gpointer);

void next4(GtkWidget *,gpointer);*/

void prev(GtkWidget *,gpointer);

void submit2(GtkWidget *,gpointer);

void submit3b(GtkWidget *,gpointer);

void submit3c(GtkWidget *,gpointer);

void submit3d(GtkWidget *,gpointer);

void submit1(GtkWidget *,gpointer);

void dail1f(GtkWidget *,gpointer);

//void dail2f(GtkWidget *,gpointer);

void dail3f(GtkWidget *,gpointer);

void dail4f(GtkWidget *,gpointer);

void load(void);

int search(int, atm *);

int wrt_bal(float, atm *);

int wrt_pin(int, atm *);

void typ_int(int, char *);

void  typ_flt(float, char *);

long long int typ_lld(char *);
