#include<stdio.h>
#include <string.h>
main() 	
{
FILE *fp;
char hc,ch,mot[10],a[][6]={"MOVER","ADD","SUB"},b[][6]={"DC","DS"};
char save[10][10];
char  lit[20],sym[10],last_char;
int i=0,j=0,m=0,l=0,f=0,p=0,ch_cnt=0;
fp=fopen("asm.txt","r");


while(!feof(fp))
{
	ch = fgetc(fp);
	if((ch == ' ') || (ch == '\n'))
 	{
		mot[i++] = '\0';
		for(j=0 ;j<3;j++)
		{
			if(!strcmp(mot,a[j]))
			{
				strcpy(save[m++],mot);
			}
		
		}
		
		i=0;
	}
	else
		mot[i++] = ch;
}
rewind(fp);
while(!feof(fp))
{
	ch=fgetc(fp);
	if(isdigit(ch))
	{
		lit[l++]=ch;
        }
	else if((ch == '\n'))
	{
		lit[l++] = 32;
	}
}
rewind(fp);
while(!feof(fp))
{
	ch=fgetc(fp);
	if(isalpha(ch))
 	{
		ch_cnt++;
	}
	else if((ch_cnt==1) && (ch==32) )
	{
   		sym[p++]=last_char;
		printf("%c",ch);
		ch_cnt = 0;
	}	
	if(ch == '\n')
		ch_cnt=0;

	last_char = ch;
}	
printf("literal table is\n");
for(j=0;j<l;j++)
{
printf("%c",lit[j]);
}

printf("mnemonics table is\n");
for(j=0;j<m;j++)
{       
	printf("%s\n ",save[j]);
}
printf("symbol table is\n");
for(j=0;j<p;j++)
{
printf("\n%c ",sym[j]);
}
}

