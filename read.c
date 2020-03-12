#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <xlsxio_read.h>

extern atm client_pr;
atm p[20];

void load()
{
xlsxioreader xlsxioread;
xlsxioread = xlsxioread_open("atm.xlsx");
char* var;
int row = 0;
xlsxioreadersheet sheet;
sheet = xlsxioread_sheet_open(xlsxioread,NULL, XLSXIOREAD_SKIP_EMPTY_ROWS);
while (xlsxioread_sheet_next_row(sheet)) 
{
int cell = 0;
while ((var = xlsxioread_sheet_next_cell(sheet)) != NULL) 
{
switch(cell){

case 0:
	p[row].pin  = atoi(var);
	break;
case 1:
	p[row].acc_no = atoi(var);
	break;
case 2:
	strcpy(p[row].name,var);
	break;
case 3:
	strcpy(p[row].acc_type,var);
	break;
case 4:
	p[row].balance = (float)atoi(var);
	break;
case 5:
	strcpy(p[row].bank_name,var);
	break;	
}
cell ++;
}
row ++;
}
xlsxioread_sheet_close(sheet);
xlsxioread_close(xlsxioread);
}

int search(int d, atm* c)
{
int flag = 0;
for(int i =0;i < 20;i++)
{
if(p[i].pin == d)
{
flag = 1;
p[i].retrn = 1;
*(c) = *(p + i);
}
} 
if(flag == 0)
{
return 0;
}
else
{
return 1;
}
}
