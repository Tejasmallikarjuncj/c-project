#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
 

void win2_1 (int argc, char *argv[])
{
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
GtkWidget *win2 = GTK_WIDGET(gtk_builder_get_object (builder,"win2"));
gtk_builder_connect_signals(builder, NULL);
GtkWidget *box2 = GTK_WIDGET(gtk_builder_get_object (builder,"box2"));
GtkWidget *top = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_2"));
GtkWidget *r1 = GTK_WIDGET(gtk_builder_get_object (builder,"r1"));
GtkWidget *r2 = GTK_WIDGET(gtk_builder_get_object (builder,"r2"));
GtkWidget *r3 = GTK_WIDGET(gtk_builder_get_object (builder,"r3"));
GtkWidget *r4 = GTK_WIDGET(gtk_builder_get_object (builder,"r4"));
GtkWidget *ext = GTK_WIDGET(gtk_builder_get_object (builder,"ext_1"));
GtkWidget *sub = GTK_WIDGET(gtk_builder_get_object (builder,"submit_2"));
gtk_widget_show(win2);
gtk_main ();
}


void win3_a_1 (int argc, char *argv[])
{
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
GtkWidget *win3_a = GTK_WIDGET(gtk_builder_get_object (builder,"win3_a"));
g_signal_connect(win3_a, "destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_builder_connect_signals(builder, NULL);
GtkWidget *box3_a = GTK_WIDGET(gtk_builder_get_object (builder,"box3_a"));
GtkWidget *top = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_a"));
GtkWidget *name_1 = GTK_WIDGET(gtk_builder_get_object (builder,"name_1"));
GtkWidget *bal_1 = GTK_WIDGET(gtk_builder_get_object (builder,"bal_1"));
GtkWidget *Account_2 = GTK_WIDGET(gtk_builder_get_object (builder,"Account_2"));
GtkWidget *name  = GTK_WIDGET(gtk_builder_get_object (builder,"account"));
GtkWidget *bal = GTK_WIDGET(gtk_builder_get_object (builder,"bal"));
GtkWidget *Prev_1 = GTK_WIDGET(gtk_builder_get_object (builder,"Prev_1"));
GtkWidget *ext_2 = GTK_WIDGET(gtk_builder_get_object (builder,"ext_2"));
gtk_widget_show(win3_a);
gtk_main ();
}


void win3_b_1 (int argc, char *argv[])
{
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
GtkWidget *win3_b = GTK_WIDGET(gtk_builder_get_object (builder,"win3_b"));
gtk_builder_connect_signals(builder, NULL);
GtkWidget *box3_b = GTK_WIDGET(gtk_builder_get_object (builder,"box3_b"));
GtkWidget *top = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_b"));
GtkWidget *entry_money = GTK_WIDGET(gtk_builder_get_object (builder,"entry_money"));
GtkWidget *money_entry = GTK_WIDGET(gtk_builder_get_object (builder,"money_entry"));
GtkWidget *submit_3_a= GTK_WIDGET(gtk_builder_get_object (builder,"submit_3_a"));
gtk_widget_show(win3_b);
gtk_main ();
}


void win3_c_1 (int argc, char *argv[])
{
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
GtkWidget *win3_c = GTK_WIDGET(gtk_builder_get_object (builder,"win3_c"));
gtk_builder_connect_signals(builder, NULL);
GtkWidget *box3_c = GTK_WIDGET(gtk_builder_get_object (builder,"box3_c"));
GtkWidget *top = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_c"));
GtkWidget *new_pin = GTK_WIDGET(gtk_builder_get_object (builder,"new_pin"));
GtkWidget *entry_new_pin = GTK_WIDGET(gtk_builder_get_object (builder,"entry_new_pin"));
GtkWidget *confirm_pin = GTK_WIDGET(gtk_builder_get_object (builder,"confirm_pin"));
GtkWidget *entry_confirm_pin = GTK_WIDGET(gtk_builder_get_object (builder,"entry_confirm_pin"));
GtkWidget *submit_3_c = GTK_WIDGET(gtk_builder_get_object (builder,"submit_3_c"));
gtk_widget_show(win3_c);
gtk_main ();
}

void win3_d_1 (int argc, char *argv[])
{
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
GtkWidget *win3_d = GTK_WIDGET(gtk_builder_get_object (builder,"win3_d"));
g_signal_connect(win3_d, "destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_builder_connect_signals(builder, NULL);
GtkWidget *box3_d = GTK_WIDGET(gtk_builder_get_object (builder,"box3_d"));
GtkWidget *top = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_d"));
GtkWidget *entry_money_d = GTK_WIDGET(gtk_builder_get_object (builder,"entry_money_d"));
GtkWidget *entry_money_c = GTK_WIDGET(gtk_builder_get_object (builder,"entry_money_c"));
GtkWidget *submit_3_d = GTK_WIDGET(gtk_builder_get_object (builder,"submit_3_d"));
gtk_widget_show(win3_d);
gtk_main ();
}

void win1_1 (int argc, char *argv[])
{
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
GtkWidget *win = GTK_WIDGET(gtk_builder_get_object (builder,"win1"));
g_signal_connect(win,"destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_builder_connect_signals(builder, NULL);
GtkWidget *gid1 = GTK_WIDGET(gtk_builder_get_object (builder,"box1"));
GtkWidget *top = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_1"));
GtkWidget *pin = GTK_WIDGET(gtk_builder_get_object (builder,"pin_lb"));
GtkWidget *entry = GTK_WIDGET(gtk_builder_get_object (builder,"entry"));
GtkWidget *sub = GTK_WIDGET(gtk_builder_get_object (builder,"submit_1"));
gtk_widget_show(win);
gtk_main ();
}

int main(int argc, char *argv[])
{
char *dum[] = {"./atm"};
win1_1(1,dum);
//win2_1(argc, argv);
//win3_a(argc, argv);
//win3_b(argc, argv);
//win3_c(argc, argv);
//win3_d(argc, argv);
}
