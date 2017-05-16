%{
#include<ctype.h>
char str[20];
int i=0;
%}
%token id
%left '+''/''*''-'
%%
E:S  {infix_postfix(str);}
S:S'+'T|S'-'T
|T
T:T'*'F|T'/'F
|F
F:id|'('S')'
;
%%

#include<stdio.h>
main()
{
printf("\n enter an identifier:");
yyparse();
}
yyerror()
{printf("invlaid");
}
yylex()
{char ch=' ';
while(ch!='\n')
{
ch=getchar();
str[i++]=ch;
if(isalpha(ch))
return id;
if(ch=='+'||ch=='*'||ch=='-'||ch=='/')
return ch;
}
str[--i]='\0';
return(0);
exit(0);
}
