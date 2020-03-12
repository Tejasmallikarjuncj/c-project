#include "header.h"
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

static int count = 0; 
atm client_pr;
gui pg1;
gui pg2;
gui pg3a;
gui pg3b;
gui pg3c;
gui pg3d;
dail dail1;
dail dail2;
dail dail3;
dail dail4;
extern atm p[20];


void submit1(GtkWidget * wid,gpointer ptr)
{
char* a;
const char *b = gtk_entry_get_text(GTK_ENTRY(pg1.entry[0]));
sprintf(a,"%s",b);
int pin = atoi(a);
int s = search(pin, &client_pr);
if(s == 0)
{
count ++;
if(count > 5)
{
gtk_widget_hide(pg1.win);
gtk_widget_show(dail1.win);
}
else
{
gtk_widget_hide(pg1.win);
gtk_widget_show(dail2.win);
}
}
else
{
gtk_widget_hide(pg1.win);
gtk_widget_show(pg2.win);
}
}


int main(int argc, char *argv[])
{
load();
gtk_init(&argc, &argv);
GtkBuilder *builder;
builder = gtk_builder_new_from_file ("layout1.glade");

//building win1
pg1.win = GTK_WIDGET(gtk_builder_get_object (builder,"win1"));
g_signal_connect(pg1.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
pg1.box = GTK_WIDGET(gtk_builder_get_object (builder,"box1"));
pg1.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_1"));
pg1.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"pin_lb"));
pg1.entry[0] = GTK_WIDGET(gtk_builder_get_object (builder,"entry"));
pg1.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_1"));
g_signal_connect(pg1.button[0],"clicked",G_CALLBACK(submit1),NULL);

//building win2
pg2.win = GTK_WIDGET(gtk_builder_get_object(builder,"win2"));
g_signal_connect(pg2.win,"destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
pg2.box = GTK_WIDGET(gtk_builder_get_object (builder,"box2"));
pg2.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_2"));
pg2.radio_button[0] = (GtkToggleButton *)gtk_builder_get_object (builder,"r1");
//g_signal_connect(pg2.radio_button[0],"toggled",G_CALLBACK(next1),NULL);
pg2.radio_button[1] = (GtkToggleButton *)gtk_builder_get_object (builder,"r2");
//g_signal_connect(pg2.radio_button[1],"toggled",G_CALLBACK(next2),NULL);
pg2.radio_button[2] = (GtkToggleButton *)gtk_builder_get_object (builder,"r3");
//g_signal_connect(pg2.radio_button[2],"toggled",G_CALLBACK(next3),NULL);
pg2.radio_button[3]= (GtkToggleButton *)gtk_builder_get_object (builder,"r4");
//g_signal_connect(pg2.radio_button[3],"toggled",G_CALLBACK(next4),NULL);
pg2.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"ext_1"));
g_signal_connect(pg2.button[0], "clicked",G_CALLBACK(gtk_main_quit),NULL);
pg2.button[1] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_2"));
g_signal_connect(pg2.button[1], "clicked",G_CALLBACK(submit2),NULL);

//building win3_a
pg3a.win = GTK_WIDGET(gtk_builder_get_object (builder,"win3_a"));
g_signal_connect(pg3a.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
pg3a.box = GTK_WIDGET(gtk_builder_get_object (builder,"box3_a"));
pg3a.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_a"));
pg3a.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"name_1"));
pg3a.label[2] = GTK_WIDGET(gtk_builder_get_object (builder,"bal_1"));
pg3a.label[3] = GTK_WIDGET(gtk_builder_get_object (builder,"Account_2"));
pg3a.label[4] = GTK_WIDGET(gtk_builder_get_object (builder,"name"));
const char *temp3 = client_pr.name;
gtk_label_set_text(GTK_LABEL(pg3a.label[4]), temp3);
pg3a.label[5]  = GTK_WIDGET(gtk_builder_get_object (builder,"account no"));
char *c;
const char *temp1;
sprintf(c,"%d", client_pr.acc_no);
temp1 = c;  
gtk_label_set_text(GTK_LABEL(pg3a.label[5]), temp1);
pg3a.label[6] = GTK_WIDGET(gtk_builder_get_object (builder,"bal"));
char *b;
const char *temp2; 
sprintf(b,"%.2f",client_pr.balance);
temp2 = b;
gtk_label_set_text(GTK_LABEL(pg3a.label[6]), temp2);
pg3a.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"Prev_1"));
g_signal_connect(pg3a.button[0],"clicked",G_CALLBACK(prev),NULL);
pg3a.button[1] = GTK_WIDGET(gtk_builder_get_object (builder,"ext_2"));
g_signal_connect(pg3a.button[1], "clicked",G_CALLBACK(gtk_main_quit),NULL);

//building win3_b
pg3b.win = GTK_WIDGET(gtk_builder_get_object (builder,"win3_b"));
g_signal_connect(pg3b.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
pg3b.box = GTK_WIDGET(gtk_builder_get_object (builder,"box3_b"));
pg3b.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_b"));
pg3b.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_money"));
pg3b.entry[0] = GTK_WIDGET(gtk_builder_get_object (builder,"money_entry"));
pg3b.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_3_a"));
g_signal_connect(pg3b.button[0], "clicked",G_CALLBACK(submit3b),NULL);

//building win3_c
pg3c.win = GTK_WIDGET(gtk_builder_get_object (builder,"win3_c"));
g_signal_connect(pg3c.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
pg3c.box = GTK_WIDGET(gtk_builder_get_object (builder,"box3_c"));
pg3c.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_c"));
pg3c.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"new_pin"));
pg3c.entry[0] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_new_pin"));
pg3c.label[2] = GTK_WIDGET(gtk_builder_get_object (builder,"confirm_pin"));
pg3c.entry[1] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_confirm_pin"));
pg3c.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_3_c"));
g_signal_connect(pg3c.button[0],"clicked",G_CALLBACK(submit3c),NULL);

//building win3_d
pg3d.win = GTK_WIDGET(gtk_builder_get_object (builder,"win3_d"));
g_signal_connect(pg3d.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
pg3d.box = GTK_WIDGET(gtk_builder_get_object (builder,"box3_d"));
pg3d.label[0] = GTK_WIDGET(gtk_builder_get_object (builder,"top_lb_3_d"));
pg3d.label[1] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_money_d"));
pg3d.entry[0] = GTK_WIDGET(gtk_builder_get_object (builder,"entry_money_c"));
pg3d.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"submit_3_d"));
g_signal_connect(pg3d.button[0],"clicked",G_CALLBACK(submit3d),NULL);

//buliding dial1
dail1.win = GTK_WIDGET(gtk_builder_get_object (builder,"wind1"));
g_signal_connect(dail1.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
dail1.box = GTK_WIDGET(gtk_builder_get_object (builder,"boxd1"));
dail1.grid = GTK_WIDGET(gtk_builder_get_object (builder,"gd1"));
dail1.b_grid = GTK_WIDGET(gtk_builder_get_object (builder,"bgd1"));
dail1.label = GTK_WIDGET(gtk_builder_get_object (builder,"dl1"));
dail1.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"Retry1"));
g_signal_connect(dail1.button[0],"clicked",G_CALLBACK(dail1f),NULL);
dail1.button[1] = GTK_WIDGET(gtk_builder_get_object (builder,"Exit1"));
g_signal_connect(dail1.button[1],"clicked",G_CALLBACK(gtk_main_quit),NULL);

//buliding dial2
dail2.win = GTK_WIDGET(gtk_builder_get_object (builder,"wind2"));
g_signal_connect(dail2.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
dail2.box = GTK_WIDGET(gtk_builder_get_object (builder,"boxd2"));
dail2.grid = GTK_WIDGET(gtk_builder_get_object (builder,"gd2"));
dail2.b_grid = GTK_WIDGET(gtk_builder_get_object (builder,"bgd2"));
dail2.label = GTK_WIDGET(gtk_builder_get_object (builder,"dl2"));
dail2.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"Ok2"));
g_signal_connect(dail2.button[0],"clicked",G_CALLBACK(gtk_main_quit),NULL);



//buliding dial3
dail3.win = GTK_WIDGET(gtk_builder_get_object (builder,"wind3"));
g_signal_connect(dail3.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
dail3.box = GTK_WIDGET(gtk_builder_get_object (builder,"boxd3"));
dail3.grid = GTK_WIDGET(gtk_builder_get_object (builder,"gd3"));
dail3.b_grid = GTK_WIDGET(gtk_builder_get_object (builder,"bgd3"));
dail3.label = GTK_WIDGET(gtk_builder_get_object (builder,"dl3"));
dail3.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"Ok3"));
g_signal_connect(dail3.button[0],"clicked",G_CALLBACK(dail3f),NULL);
dail3.button[1] = GTK_WIDGET(gtk_builder_get_object (builder,"Exit3"));
g_signal_connect(dail3.button[1],"clicked",G_CALLBACK(gtk_main_quit),NULL);

//buliding dial4
dail4.win = GTK_WIDGET(gtk_builder_get_object (builder,"wind4"));
g_signal_connect(dail4.win, "destroy",G_CALLBACK(gtk_main_quit),NULL);
//gtk_builder_connect_signals(builder, NULL);
dail4.box = GTK_WIDGET(gtk_builder_get_object (builder,"boxd4"));
dail4.grid = GTK_WIDGET(gtk_builder_get_object (builder,"gd4"));
dail4.b_grid = GTK_WIDGET(gtk_builder_get_object (builder,"bgd4"));
dail4.label = GTK_WIDGET(gtk_builder_get_object (builder,"dl4"));
dail4.button[0] = GTK_WIDGET(gtk_builder_get_object (builder,"Retry4"));
g_signal_connect(dail4.button[0],"clicked",G_CALLBACK(dail4f),NULL);
dail4.button[1] = GTK_WIDGET(gtk_builder_get_object (builder,"Exit3"));
g_signal_connect(dail4.button[1],"clicked",G_CALLBACK(gtk_main_quit),NULL);

gtk_widget_show(pg1.win);
gtk_main ();
}


