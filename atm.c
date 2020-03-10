#include "header.h"
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

atm client_pr;

void win2 (int argc, char *argv[])
{
gui pg2;
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
pg2.win = GTK_WIDGET(gtk_builder_get_object (builder,"win2"));
g_signal_connect(pg2.win,"destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_builder_connect_signals(builder, NULL);
pg2.box = GTK_WIDGET(gtk_builder_get_object (builder,"box2"));
pg2.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_2"));
pg2.radio_button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"r1"));
g_signal_connect(pg2.radio_button[0],"toggled",G_CALLBACK(next1),NULL);
pg2.radio_button[1] = GTK_WIDGET(gtk_builder_get_object (builder,"r2"));
g_signal_connect(pg2.radio_button[1],"toggled",G_CALLBACK(next2),NULL);
pg2.radio_button[2] = GTK_WIDGET(gtk_builder_get_object (builder,"r3"));
g_signal_connect(pg2.radio_button[2],"toggled",G_CALLBACK(next3),NULL);
pg2.radio_button[3]= GTK_WIDGET(gtk_builder_get_object (builder,"r4"));
g_signal_connect(pg2.radio_button[3],"toggled",G_CALLBACK(next4),NULL)
pg2.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"ext_1"));
pg2.button[2] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_2"));
gtk_widget_show(pg2.win);
gtk_main ();
}




void win3_a (int argc, char *argv[], atm *)
{
gui pg3a;
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
pg3a.win = GTK_WIDGET(gtk_builder_get_object (builder,"win3_a"));
g_signal_connect(pg3a.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_builder_connect_signals(builder, NULL);
pg3a.box = GTK_WIDGET(gtk_builder_get_object (builder,"box3_a"));
pg3a.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_a"));
pg3a.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"name_1"));
pg3a.label[2] = GTK_WIDGET(gtk_builder_get_object (builder,"bal_1"));
pg3a.label[3] = GTK_WIDGET(gtk_builder_get_object (builder,"Account_2"));
pg3a.label[4] = GTK_WIDGET(gtk_builder_get_object (builder,"name"));
gtk_label_set_text(GTK_LABEL(pg3a.label[4]), client_pr.name);
pg3a.label[5]  = GTK_WIDGET(gtk_builder_get_object (builder,"account no"));
gtk_label_set_text(GTK_LABEL(pg3a.label[5]), client_pr.acc_no);
pg3a.label[6] = GTK_WIDGET(gtk_builder_get_object (builder,"bal"));
gtk_label_set_text(GTK_LABEL(pg3a.label[6]), client_pr.balance);
pg3a.box[0] = GTK_WIDGET(gtk_builder_get_object (builder,"Prev_1"));
g_signal_connect(pg3a.box[0],"clicked",G_CALLBACK(prev),NULL);
pg3a.box[1] = GTK_WIDGET(gtk_builder_get_object (builder,"ext_2"));
g_signal_connect(pg3a.box[1], "clicked",G_CALLBACK(gtk_main_quit),NULL);
gtk_widget_show(pg3a.win);
gtk_main ();
}

void win3_b (int argc, char *argv[])
{
gui pg3b;
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
pg3b.win = GTK_WIDGET(gtk_builder_get_object (builder,"win3_b"));
g_signal_connect(pg3b.win, "destroy",G_CALLBACK(next),NULL);
gtk_builder_connect_signals(builder, NULL);
pg3b.box[0] = GTK_WIDGET(gtk_builder_get_object (builder,"box3_b"));
pg3b.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_b"));
pg3b.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_money"));
pg3b.entry[0] = GTK_WIDGET(gtk_builder_get_object (builder,"money_entry"));
pg3b.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_3_a"));
g_signal_connect(pg3.button[0], "clicked",G_CALLBACK(submit3a),pg3b.entry);
gtk_widget_show(pg3b.win);
gtk_main ();
}


void win3_c (int argc, char *argv[])
{
gui pg3c;
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
pg3c.win = GTK_WIDGET(gtk_builder_get_object (builder,"win3_c"));
g_signal_connect(pg3c.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_builder_connect_signals(builder, NULL);
pg3c.box = GTK_WIDGET(gtk_builder_get_object (builder,"box3_c"));
pg3c.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_c"));
pg3c.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"new_pin"));
pg3c.entry[0] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_new_pin"));
pg3c.label[2] = GTK_WIDGET(gtk_builder_get_object (builder,"confirm_pin"));
pg3c.entry[1] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_confirm_pin"));
pg3c.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_3_c"));
g_signal_connect(pg3c.button[0],"clicked",G_CALLBACK(submit3c),pg3c.entry[0]);
gtk_widget_show(pg3c);
gtk_main ();
}

void win3_d (int argc, char *argv[])
{
gui pg3d;
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
pg3d.win = GTK_WIDGET(gtk_builder_get_object (builder,"win3_d"));
g_signal_connect(pg3d.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_builder_connect_signals(builder, NULL);
pg3d.box = GTK_WIDGET(gtk_builder_get_object (builder,"box3_d"));
pg3d.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_d"));
pg3d.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_money_d"));
pg3d.entry[0] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_money_c"));
pg3d.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_3_d"));
g_signal_connect(pg3d.button[0],"clicked",G_CALLBACK(submit3d),pg3d.entry[0]);
gtk_widget_show(pg3d.win);
gtk_main ();
}

void win1(int argc, char *argv[])
{
gui pg1
gtk_init (&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");
pg1.win = GTK_WIDGET(gtk_builder_get_object (builder,"win1"));
g_signal_connect(pg1.win, "destroy",G_CALLBACK(next),NULL);
gtk_builder_connect_signals(builder, NULL);
pg1.box = GTK_WIDGET(gtk_builder_get_object (builder,"box1"));
pg1.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_1"));
pg1.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"pin_lb"));
pg1.entry[0] = GTK_WIDGET(gtk_builder_get_object (builder,"entry"));
pg1.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_1"));
g_signal_connect(pg1.button[0],"clicked",G_CALLBACK(next1),pg1.entry[0]);
gtk_widget_show(pg1.win);
gtk_main ();
}

int main(int argc, char *argv[])
{
//win1_1(argc, argv);
win2(argc, argv);
//win3_a(argc, argv);
//win3_b(argc, argv);
//win3_c(argc, argv);
//win3_d(argc, argv);
}
