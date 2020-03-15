#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include <gtk/gtk.h>


extern atm client_pr;
extern gui pg1;
extern gui pg2;
extern gui pg3a;
extern gui pg3b;
extern gui pg3c;
extern gui pg3d;
extern dail dail1;
extern dail dail2;
extern dail dail3;
extern dail dail4;

static int count = 0;

void dail1f(GtkWidget * wid,gpointer ptr)
{
gtk_widget_hide(dail1.win);
gtk_widget_show(pg1.win);
}

void dail3f(GtkWidget * wid,gpointer ptr)
{
gtk_widget_hide(dail3.win);
}

void dail4f(GtkWidget * wid,gpointer ptr)
{
gtk_widget_hide(dail4.win);
}


void submit2(GtkWidget * wid,gpointer ptr)
{
if(gtk_toggle_button_get_active(pg2.radio_button[0]))
{
gtk_widget_hide(pg2.win);
gtk_widget_show(pg3b.win);
}
else if(gtk_toggle_button_get_active (pg2.radio_button[1]))
{
gtk_widget_hide(pg2.win);
const char *temp3 = client_pr.name;
gtk_label_set_text(GTK_LABEL(pg3a.label[4]), temp3);
char c[15];
const char *temp1;
sprintf(c,"%d", client_pr.acc_no);
temp1 = c;  
gtk_label_set_text(GTK_LABEL(pg3a.label[5]), temp1);
char b[15];
const char *temp2; 
sprintf(b,"%f",client_pr.balance);
temp2 = b;
gtk_label_set_text(GTK_LABEL(pg3a.label[6]), temp2);
gtk_widget_show(pg3a.win);
}
else if(gtk_toggle_button_get_active (pg2.radio_button[2]))
{
gtk_widget_hide(pg2.win);
gtk_widget_show(pg3c.win);
}
else if(gtk_toggle_button_get_active (pg2.radio_button[3]))
{
gtk_widget_hide(pg2.win);
gtk_widget_show(pg3d.win);
}
}

void prev(GtkWidget * wid,gpointer ptr)
{
gtk_widget_hide(pg3a.win);
gtk_widget_show(pg2.win);
}

void submit3b(GtkWidget * wid,gpointer ptr)
{
char temp1[15];
const char* temp2; 
temp2 = gtk_entry_get_text(GTK_ENTRY(pg3b.entry[0]));
sprintf(temp1,"%s", temp2);
if(atoi(temp1) > (int)client_pr.balance)
{
gtk_widget_show(dail4.win);
}
else
{
float b = (float)atoi(temp1);
client_pr.balance -= b;
atm *pot;
pot = &client_pr;
wrt_bal(b, pot);
load(); 
gtk_widget_hide(pg3b.win);
gtk_widget_show(pg2.win);
}
}

void submit3c(GtkWidget * wid,gpointer ptr)
{
int pin1,pin2;
char temp1[15];
const char* temp2; 
temp2 = gtk_entry_get_text(GTK_ENTRY(pg3c.entry[0]));
sprintf(temp1,"%s", temp2);
pin1 = atoi(temp1);
if(pin1 == 0)
{
gtk_widget_show(dail3.win);
}

char temp3[15];
const char* temp4; 
temp4 = gtk_entry_get_text(GTK_ENTRY(pg3c.entry[1]));
sprintf(temp3,"%s", temp4);
pin2 = atoi(temp3);

if(pin2 == 0)
{
gtk_widget_show(dail3.win);
}


if(pin1 != pin2)
{
count ++;
if(count > 5)
{
gtk_widget_hide(pg3c.win);
gtk_widget_show(dail2.win);
}
else
{
gtk_widget_show(dail3.win);
}
}
else
{
client_pr.pin = pin1;
atm *d;
d = &client_pr;
wrt_pin(pin1,d);
load();
gtk_widget_hide(pg3c.win);
gtk_widget_show(pg2.win);
}
}

void submit3d(GtkWidget * wid,gpointer ptr)
{
char temp1[15];
const char* temp2; 
temp2 = gtk_entry_get_text(GTK_ENTRY(pg3d.entry[0]));
sprintf(temp1,"%s", temp2);
float b = (float)atoi(temp1);
client_pr.balance += b;
atm *y;
y = &client_pr;
wrt_bal(b,y);
load(); 
gtk_widget_hide(pg3d.win);
gtk_widget_show(pg2.win);
}
