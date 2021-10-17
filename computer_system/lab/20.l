/*** Definition Section all variable declaration ***/
%{
int total_char = 0;
int total_num = 0;
int even_num = 0;
int odd_num = 0;
%}

/***contains rules ***/
%%
[exit]       {return 0;}
[0 2 4 6 8]  {++even_num;++total_num;++total_char;printf("%sdetected even digit\n", yytext);}
[1 3 5 7 9]  {++odd_num;++total_num;++total_char;printf("%sdetected odd digit\n", yytext);}
.            {total_char++;printf("%s detected character\n", yytext);}
%%

/*** User code ***/
int yywrap(){}
int main(int argc, char **argv)
{

printf("enter char, type exit to exit program\n");
yylex();
printf("total char counts = %d\ntotal digit count = %d\ntotal even digit count = %d\ntotal odd digit count = %d\n",
	total_char, total_num,even_num,odd_num );

return 0;
}

