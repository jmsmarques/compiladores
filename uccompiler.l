/*Jorge Marques 2014199355*/
%{
char flag = 'N';
%}
/*aux*/
ENTER       \n
TAB         \\t
BAR         \\
ASPA        \"
ASPAS       \'
OCTO        \\[0-7]{1,3}
ESCAPE      {ENTER}|{TAB}|{BAR}|{ASPA}|{ASPAS}|{OCTO}
EXPO        ("+"|"-")?(e|E)[0-9]+
REALLITA    [0-9]+"."[0-9]*{EXPO}?
REALLITB    "."[0-9]+{EXPO}?
REALLITC    [0-9]+{EXPO}
/*end aux*/
CHAR        char
ELSE        else
WHILE       while
IF          if
INT         int
SHORT       short
DOUBLE      double
RETURN      return
VOID        void
BITWISEAND  "&"
BITWISEOR   "|"
BITWISEXOR  "^"
AND         "&&"
ASSIGN      "="
MUL         "*"
COMMA       ","
DIV         "/"
EQ          "=="
GE          ">="
GT          ">"
LBRACE      "{"
LE          "<="
LPAR        "("
LT          "<"
MINUS       "-"
MOD         "%"
NE          "!="
NOT         "!"
OR          "||"
PLUS        "+"
RBRACE      "}"
RPAR        ")"
SEMI        ";"
RESERVED    (\[|\]|"++"|"--")
ID          [A-Za-z\_][A-Za-z\_0-9]*
INTLIT      [0-9]+
CHRLIT      \'([^\n\']|{ESCAPE})\'
REALLIT     ({REALLITA}|{REALLITB}|{REALLITC})
%%
\/\/.*              ;
\/\*(.|\n)*\/       ;
{CHAR}              {if(flag == 'Y') printf("CHAR\n");}
{ELSE}              {if(flag == 'Y') printf("ELSE\n");}
{WHILE}             {if(flag == 'Y') printf("WHILE\n");}
{IF}                {if(flag == 'Y') printf("IF\n");}
{INT}               {if(flag == 'Y') printf("INT\n");}
{SHORT}             {if(flag == 'Y') printf("SHORT\n");}
{DOUBLE}            {if(flag == 'Y') printf("DOUBLE\n");}
{RETURN}            {if(flag == 'Y') printf("RETURN\n");}
{VOID}              {if(flag == 'Y') printf("VOID\n");}
{BITWISEAND}        {if(flag == 'Y') printf("BITWISEAND\n");}
{BITWISEOR}         {if(flag == 'Y') printf("BITWISEOR\n");}
{BITWISEXOR}        {if(flag == 'Y') printf("BITWISEXOR\n");}
{AND}               {if(flag == 'Y') printf("AND\n");}
{ASSIGN}            {if(flag == 'Y') printf("ASSIGN\n");}
{MUL}               {if(flag == 'Y') printf("MUL\n");}
{COMMA}             {if(flag == 'Y') printf("COMMA\n");}
{DIV}               {if(flag == 'Y') printf("DIV\n");}
{EQ}                {if(flag == 'Y') printf("EQ\n");}
{GE}                {if(flag == 'Y') printf("GE\n");}
{GT}                {if(flag == 'Y') printf("GT\n");}
{LBRACE}            {if(flag == 'Y') printf("LBRACE\n");}
{LE}                {if(flag == 'Y') printf("LE\n");}
{LPAR}              {if(flag == 'Y') printf("LPAR\n");}
{LT}                {if(flag == 'Y') printf("LT\n");}
{MINUS}             {if(flag == 'Y') printf("MINUS\n");}
{MOD}               {if(flag == 'Y') printf("MOD\n");}
{NE}                {if(flag == 'Y') printf("NE\n");}
{NOT}               {if(flag == 'Y') printf("NOT\n");}
{OR}                {if(flag == 'Y') printf("OR\n");}
{PLUS}              {if(flag == 'Y') printf("PLUS\n");}
{RBRACE}            {if(flag == 'Y') printf("RBRACE\n");}
{RPAR}              {if(flag == 'Y') printf("RPAR\n");}
{SEMI}              {if(flag == 'Y') printf("SEMI\n");}
{RESERVED}          {if(flag == 'Y') printf("RESERVED\n");}
{ID}                {if(flag == 'Y') printf("ID(%s)\n", yytext);}
{INTLIT}            {if(flag == 'Y') printf("INTLIT(%s)\n", yytext);}
{CHRLIT}            {if(flag == 'Y') printf("CHRLIT(%s)\n", yytext);}
{REALLIT}           {if(flag == 'Y') printf("REALLIT(%s)\n", yytext);}
.                   ;
\n                  ;
%%
int main(int argc, char** argv)
{
    if(argv[1][0] == '-' && argv[1][1] == 'l') {
        flag = 'Y';
    }
    
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
