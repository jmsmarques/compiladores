/*Jorge Marques 2014199355*/
/*Fábio Antunes 2014206491*/
/*Grupo Mooshak: jms*/
%{
#include "y.tab.h"

char flag = 'N';
int col = 1;
int line = 1;
int aux_line = 1;
int aux_col = 1;
%}
/*states*/
%X COMMENT
/*end states*/
/*aux*/
ENTER       \\n
TAB         \\t
BAR         \\\\
ASPA        \\\"
ASPAS       \\\'
OCTO        \\[0-7]{1,3}
ESCAPE      {ENTER}|{TAB}|{BAR}|{ASPA}|{ASPAS}|{OCTO}
EXPO        (e|E)("+"|"-")?[0-9]+
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
RESERVED    (\[|\]|"++"|"--"|"auto"|"struct"|"break"|"long"|"switch"|"case"|"enum"|"register"|"typedef"|"extern"|"union"|"const"|"float"|"short"|"unsigned"|"continue"|"for"|"signed"|"default"|"goto"|"sizeof"|"volatile"|"do"|"static"|"_Bool"|"_Imaginary"|"restrict"|"_Complex"|"inline")
INTLIT      [0-9]+
ID          [A-Za-z\_][A-Za-z\_0-9]*
CHRLIT      ([^\n\'\\]|{ESCAPE})
REALLIT     ({REALLITA}|{REALLITB}|{REALLITC})
%%
\/\/.*                      {col += yyleng;}
\/\*                        {BEGIN COMMENT; aux_col = col; col += yyleng; aux_line = line;}
<COMMENT>\*\/               {BEGIN 0; col += yyleng;}
<COMMENT>.                  {col += yyleng;}
<COMMENT>\n                 {col = 1; line++;}
<COMMENT><<EOF>>            {printf("Line %d, col %d: unterminated comment\n", aux_line, aux_col); BEGIN 0;}
{CHAR}                      {if(flag == 'Y') printf("CHAR\n"); col += yyleng; if(flag != 'Y') return CHAR;}
{ELSE}                      {if(flag == 'Y') printf("ELSE\n");  col += yyleng; if(flag != 'Y') return ELSE;}
{WHILE}                     {if(flag == 'Y') printf("WHILE\n");  col += yyleng; if(flag != 'Y') return WHILE;}
{IF}                        {if(flag == 'Y') printf("IF\n");  col += yyleng; if(flag != 'Y') return IF;}
{INT}                       {if(flag == 'Y') printf("INT\n");  col += yyleng; if(flag != 'Y') return INT;}
{SHORT}                     {if(flag == 'Y') printf("SHORT\n");  col += yyleng; if(flag != 'Y') return SHORT;}
{DOUBLE}                    {if(flag == 'Y') printf("DOUBLE\n");  col += yyleng; if(flag != 'Y') return DOUBLE;}
{RETURN}                    {if(flag == 'Y') printf("RETURN\n");  col += yyleng; if(flag != 'Y') return RETURN;}
{VOID}                      {if(flag == 'Y') printf("VOID\n");  col += yyleng; if(flag != 'Y') return VOID;}
{BITWISEAND}                {if(flag == 'Y') printf("BITWISEAND\n");  col += yyleng; if(flag != 'Y') return BITWISEAND;}
{BITWISEOR}                 {if(flag == 'Y') printf("BITWISEOR\n");  col += yyleng; if(flag != 'Y') return BITWISEOR; col += yyleng;}
{BITWISEXOR}                {if(flag == 'Y') printf("BITWISEXOR\n");  col += yyleng; if(flag != 'Y') return BITWISEXOR;}
{AND}                       {if(flag == 'Y') printf("AND\n");  col += yyleng; if(flag != 'Y') return AND;}
{ASSIGN}                    {if(flag == 'Y') printf("ASSIGN\n");  col += yyleng; if(flag != 'Y') return ASSIGN;}
{MUL}                       {if(flag == 'Y') printf("MUL\n");  col += yyleng; if(flag != 'Y') return MUL;}
{COMMA}                     {if(flag == 'Y') printf("COMMA\n");  col += yyleng; if(flag != 'Y') return COMMA;}
{DIV}                       {if(flag == 'Y') printf("DIV\n");  col += yyleng; if(flag != 'Y') return DIV;}
{EQ}                        {if(flag == 'Y') printf("EQ\n");  col += yyleng; if(flag != 'Y') return EQ;}
{GE}                        {if(flag == 'Y') printf("GE\n");  col += yyleng; if(flag != 'Y') return GE;}
{GT}                        {if(flag == 'Y') printf("GT\n");  col += yyleng; if(flag != 'Y') return GT;}
{LBRACE}                    {if(flag == 'Y') printf("LBRACE\n");  col += yyleng; if(flag != 'Y') return LBRACE;}
{LE}                        {if(flag == 'Y') printf("LE\n");  col += yyleng; if(flag != 'Y') return LE;}
{LPAR}                      {if(flag == 'Y') printf("LPAR\n");  col += yyleng; if(flag != 'Y') return LPAR;}
{LT}                        {if(flag == 'Y') printf("LT\n");  col += yyleng; if(flag != 'Y') return LT;}
{MINUS}                     {if(flag == 'Y') printf("MINUS\n");  col += yyleng; if(flag != 'Y') return MINUS;}
{MOD}                       {if(flag == 'Y') printf("MOD\n");  col += yyleng; if(flag != 'Y') return MOD;}
{NE}                        {if(flag == 'Y') printf("NE\n");  col += yyleng; if(flag != 'Y') return NE;}
{NOT}                       {if(flag == 'Y') printf("NOT\n");  col += yyleng; if(flag != 'Y') return NOT;}
{OR}                        {if(flag == 'Y') printf("OR\n");  col += yyleng; if(flag != 'Y') return OR;}
{PLUS}                      {if(flag == 'Y') printf("PLUS\n"); col += yyleng; if(flag != 'Y') return PLUS;}
{RBRACE}                    {if(flag == 'Y') printf("RBRACE\n");  col += yyleng; if(flag != 'Y') return RBRACE;}
{RPAR}                      {if(flag == 'Y') printf("RPAR\n");  col += yyleng; if(flag != 'Y') return RPAR;}
{SEMI}                      {if(flag == 'Y') printf("SEMI\n");  col += yyleng; if(flag != 'Y') return SEMI;}
{RESERVED}                  {if(flag == 'Y') printf("RESERVED(%s)\n", yytext); col += yyleng; return RESERVED;}
{ID}                        {if(flag == 'Y') printf("ID(%s)\n", yytext);  col += yyleng; if(flag != 'Y') yylval.id = (char*)strdup(yytext); if(flag != 'Y') return ID;}
{INTLIT}                    {if(flag == 'Y') printf("INTLIT(%s)\n", yytext);  col += yyleng; if(flag != 'Y') yylval.id = (char*)strdup(yytext); if(flag != 'Y') return INTLIT;}
{REALLIT}                   {if(flag == 'Y') printf("REALLIT(%s)\n", yytext);  col += yyleng; if(flag != 'Y') yylval.id = (char*)strdup(yytext); if(flag != 'Y') return REALLIT;}
\'{CHRLIT}\' 	            {if(flag == 'Y') printf("CHRLIT(%s)\n", yytext);  col += yyleng; if(flag != 'Y') yylval.id = (char*)strdup(yytext); if(flag != 'Y') return CHRLIT;}
\'([^\n\'\\]|\\.)*\'        {printf("Line %d, col %d: invalid char constant (%s)\n", line, col, yytext); col += yyleng;}
\'([^\n\'\\]|\\.)*(\\)?     {printf("Line %d, col %d: unterminated char constant\n", line, col); col += yyleng;}
[ ]|"\t"                    {col += yyleng;}
\n|"\r\n"|"\r"              {col = 1; line++;}
.                           {printf("Line %d, col %d: illegal character (%c)\n", line, col, *yytext); col += yyleng;}
%%
int main(int argc, char** argv)
{
    if(argc > 1) {
        if(argv[1][0] == '-' && argv[1][1] == 'l') {
            flag = 'Y';
            yylex();
            return 0;
        }
        else if(argv[1][0] == '-' && argv[1][1] == 't') {
            flag = 'T';
        }
    }
    
    yyparse();
    return 0;
}

int yywrap() {
    return 1;
}

void yyerror (char *s) {
    printf("Line %d, col %d: %s: %s\n", line, col - (int)strlen(yytext), s, yytext);
}
