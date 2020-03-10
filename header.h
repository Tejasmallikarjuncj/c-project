typedef struct client {
long int pin;
long long int acc_no;
char name[15];
char acc_type[15];
float balance;
char bank_name[15];
long long int card;
}atm;

typedef struct gui {
GtkWidget *win;
GtkWidget *box;
Gtkwidget *label[10];
GtkWidget *button[3];
GtkWidget *entry;
GtkWidget *radio_button[4];
GtkWidget *dailog_box[4];
}gui;

atm* load(void);

atm* search(atm *);






