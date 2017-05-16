%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 100
int getreindex(const char *);
signed char productions[max][max];
int count=0,i,j;
char temp[max+max],temp2[max+max];
%}
%token ALPHABET
%left '|'
%left '.'
%nonassoc '*''+'
%%
S :re'\n' {

for(i=count-1;i>=0;--i)
{
if(i==count-1)
{
printf("\nre-->");
strcpy(temp,productions[i]);
printf("%s",productions[i]);
}
else
{
printf("\n-->");

j=getreindex(temp);
temp[j]='\0';
sprintf(temp2,"%s%s%s",temp,productions[i],(temp+j+2));
printf("%s",temp2);
strcpy(temp,temp2);
}
}
printf("\n");
exit(0);
}
re: ALPHABET {
temp[0]=yylval;temp[1]='\0';
strcpy(productions[count++],temp);
}
|'('re')' {strcpy(productions[count++],"(re)");}
|re'*' {strcpy(productions[count++],"re*");}
|re'+'re {strcpy(productions[count++],"re+re" );}
|re'|'re {strcpy(productions[count++],"re|re");}
|re'.'re {strcpy(productions[count++],"re.re");}
;
%%
int main(int argc,char **argv)
{
yyparse();
return 0;
}
yylex()
{
signed char ch=getchar();
yylval=ch;
if(isalpha(ch))
return ALPHABET;
return ch;
}
yyerror()
{
fprintf(stderr,"invalid regular expression!\n");
exit(1);
}
int getreindex(const char *str)
{
int i=strlen(str)-1;
for(;i>=0;i--)
if(str[i]=='e' && str[i-1]=='r')
return i-1;
}

