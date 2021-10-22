identifier [a-zA-Z_][a-zA-Z0-9_]*
number [0-9]+
keyword auto|break|case|char|const|continue|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|goto


%{
int total_iden = 0;
int total_num = 0;
int total_key = 0;
%}

%%

{keyword} {
	total_key++;
	printf("%sidentifier\n", yytext);
}

{identifier} {
	total_iden++;
	printf("%sidentifier\n", yytext);
}

{number} {
	total_num++;
	printf("%sidentifier\n", yytext);
}

%%

int main(){
	FILE *fp = fopen("input.txt","r");
	yyin = fp;
	yylex();

  printf("total keywords counts = %d\ntotal number count = %d\ntotal identifier count = %d\n",
	total_key, total_num,total_iden );
	return 0;
}

int yywrap(){
	return 1;
}
