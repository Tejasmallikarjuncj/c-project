#include<gtk/gtk.h>

typedef struct client {
int pin;
long long int account_no;
char* name;
char* acount_type;
float balance;
char* bank_name;
long long int card;
}client;

typedef struct gui {
GtkWidget *win;
GtkWidget *box;
GtkWidget *label[5];
GtkWidget *button[2];
GtkWidget *entry;
GtkWidget *radio_button[4];
GtkWidget *dailog_box;
}gui;

client* load(void);

client* search(client []);





