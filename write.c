#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xlsxwriter.h"

extern atm client_pr;
extern atm p[20];

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
}

int wrt_pin(int d, atm *c)
{
for(int i = 0;i < 20; i++)
{
if(strcmp(c->name,p[i].name) == 0)
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
}
