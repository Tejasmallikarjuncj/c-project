#include<stdio.h>
#include "xlsxwriter.h"
#include<string.h>

struct atm
{
long int pin;
long long int acc_no;
char name[15];
char acc_type[15];
float balance;
char bank_name[15];
};

struct atm client[]={
{1234,7897879,"Liam","savings",80000,"ICICI"},
{2341,6786873,"Noah","savings",45000,"HDFC"},
{3452,1237823,"Trevor","FD",230000,"SBI"},
{2675,7638635,"William","DEMAT",320000,"ICICI"},
{2987,7897924,"James","FD",34000,"HDFC"},
{4523,5425689,"Oliver","savings",4500000,"SBI"},
{2980,7863871,"Lucas","savings",325000,"ICICI"},
{5423,9878621,"Mason","FD",67000,"SBI"},
{3429,9087979,"Harry","savings",76000,"HDFC"},
{2876,8098912,"Charles","DEMAT",56000,"ICICI"},
{4763,4227891,"Michael","FD",378000,"SBI"},
{2233,3355293,"Olivia","savings",456000,"HDFC"},
{1887,9933452,"Lily","DEMAT",77500,"ICICI"},
{3344,7823478,"Grace","FD",54000,"SBI"},
{3877,9884393,"Emily","savings",210000,"HDFC"},
{4444,6734527,"Anna","FD",45300,"SBI"},
{2501,7879292,"Sophia","savings",67900,"ICICI"},
{2340,7823798,"Jordan","FD",51600,"SBI"},
{4178,1278131,"Jessica","savings",500000,"HDFC"},
{6712,5671235,"Lucy","DEMAT",43000,"ICICI"},
};

void l_sort(struct atm *);

void change(struct atm *);

int main()
{
lxw_workbook *workbook = workbook_new("atm.xlsx");
lxw_worksheet *worksheet = workbook_add_worksheet(workbook,NULL);
l_sort(client);
change(client);
int row=0;
int col=0;

for(row=0;row<20;row++)
{
worksheet_write_number(worksheet, row, col, client[row].pin, NULL);
worksheet_write_number(worksheet, row, col+1, client[row].acc_no, NULL);
worksheet_write_string(worksheet, row, col+2, client[row].name, NULL);
worksheet_write_string(worksheet, row, col+3, client[row].acc_type, NULL);
worksheet_write_number(worksheet, row, col+4, client[row].balance, NULL);
worksheet_write_string(worksheet, row, col+5, client[row].bank_name, NULL);
}
return workbook_close(workbook);
}

void l_sort(struct atm *p)
{
struct atm temp;

for(int i = 1; i < 20; i++)
{
int j = i;
if((p + i)->pin < (p -1 + i)->pin)
{
do
{
temp = *(p + j);
*(p + j) = *(p + j - 1);
*(p + j -1) = temp;
if(j != 1)
j--;
}while((p+j)->pin < (p -1 +j)->pin);
}
}
}


void change(struct atm *p)
{
for(int i = 0; i < 20; i++)
{
if(strcmp(p[i].acc_type,"savings")) 
{
strcpy(p[i].acc_type,"savings");
}
}
}
