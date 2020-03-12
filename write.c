#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "xlsxwriter.h"
#include <gtk/gtk.h>

extern atm client_pr;
extern atm p[20];

long long int typ_lld(char *p)
{
long long int n = 0;
int l = strlen(p);
for(int i = l -1;i > l; i--)
{
char b;
char *a;
*a = *(p + i);
int s = atoi(a);
n += (long long int)s*pow(10,i);
}
return n;
}

void typ_int(int n, char *p)
{
char b[32];
sprintf(b,"%d",n);
strcpy(p,b);
}

void typ_flt(float f, char *p)
{
char b[32];
sprintf(b,"%.2f",f);
strcpy(p,b);
}

int wrt_bal(float f, atm *c)
{
for(int i =0;i < 20; i++)
{
if(c->pin == p[i].pin)
{
p[i].balance = f;
break;
}
}

lxw_workbook *workbook = workbook_new("atm.xlsx");
lxw_worksheet *worksheet = workbook_add_worksheet(workbook,NULL);

int row=0;
int col=0;

for(row=0;row<20;row++)
{
worksheet_write_number(worksheet, row, col, p[row].pin, NULL);
worksheet_write_number(worksheet, row, col+1, p[row].acc_no, NULL);
worksheet_write_string(worksheet, row, col+2, p[row].name, NULL);
worksheet_write_string(worksheet, row, col+3, p[row].acc_type, NULL);
worksheet_write_number(worksheet, row, col+4, p[row].balance, NULL);
worksheet_write_string(worksheet, row, col+5, p[row].bank_name, NULL);
}
return workbook_close(workbook);
load();
}

int wrt_pin(int d, atm *c)
{
for(int i = 0;i < 20; i++)
{
if(!(c->name,p[i].name))
{
p[i].pin = d;
break;
}
}

lxw_workbook *workbook = workbook_new("atm.xlsx");
lxw_worksheet *worksheet = workbook_add_worksheet(workbook,NULL);

int row=0;
int col=0;

for(row=0;row<20;row++)
{
worksheet_write_number(worksheet, row, col, p[row].pin, NULL);
worksheet_write_number(worksheet, row, col+1, p[row].acc_no, NULL);
worksheet_write_string(worksheet, row, col+2, p[row].name, NULL);
worksheet_write_string(worksheet, row, col+3, p[row].acc_type, NULL);
worksheet_write_number(worksheet, row, col+4, p[row].balance, NULL);
worksheet_write_string(worksheet, row, col+5, p[row].bank_name, NULL);
}
return workbook_close(workbook);
load();
}
