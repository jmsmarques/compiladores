%{
    int numints = 0; 
%}

%%
	                
%%
int main()
{
    yylex();
    
    return 0;
}

int yywrap() {
    return 1;
}
