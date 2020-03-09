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
Gtkwidget *label[];
GtkWidget *button[];
GtkWidget *entry;
GtkWidget *radio_button[];
GtkWidget *dailog_box;
}gui;

client[]* load(void);

client* search(client []);





