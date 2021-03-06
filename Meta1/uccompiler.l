/*Jorge Marques 2014199355*/
/*Fábio Antunes 2014206491*/
/*Grupo Mooshak: jms*/
%{
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
{CHAR}                      {if(flag == 'Y') printf("CHAR\n"); col += yyleng;}
{ELSE}                      {if(flag == 'Y') printf("ELSE\n"); col += yyleng;}
{WHILE}                     {if(flag == 'Y') printf("WHILE\n"); col += yyleng;}
{IF}                        {if(flag == 'Y') printf("IF\n"); col += yyleng;}
{INT}                       {if(flag == 'Y') printf("INT\n"); col += yyleng;}
{SHORT}                     {if(flag == 'Y') printf("SHORT\n"); col += yyleng;}
{DOUBLE}                    {if(flag == 'Y') printf("DOUBLE\n"); col += yyleng;}
{RETURN}                    {if(flag == 'Y') printf("RETURN\n"); col += yyleng;}
{VOID}                      {if(flag == 'Y') printf("VOID\n"); col += yyleng;}
{BITWISEAND}                {if(flag == 'Y') printf("BITWISEAND\n"); col += yyleng;}
{BITWISEOR}                 {if(flag == 'Y') printf("BITWISEOR\n"); col += yyleng;}
{BITWISEXOR}                {if(flag == 'Y') printf("BITWISEXOR\n"); col += yyleng;}
{AND}                       {if(flag == 'Y') printf("AND\n"); col += yyleng;}
{ASSIGN}                    {if(flag == 'Y') printf("ASSIGN\n"); col += yyleng;}
{MUL}                       {if(flag == 'Y') printf("MUL\n"); col += yyleng;}
{COMMA}                     {if(flag == 'Y') printf("COMMA\n"); col += yyleng;}
{DIV}                       {if(flag == 'Y') printf("DIV\n"); col += yyleng;}
{EQ}                        {if(flag == 'Y') printf("EQ\n"); col += yyleng;}
{GE}                        {if(flag == 'Y') printf("GE\n"); col += yyleng;}
{GT}                        {if(flag == 'Y') printf("GT\n"); col += yyleng;}
{LBRACE}                    {if(flag == 'Y') printf("LBRACE\n"); col += yyleng;}
{LE}                        {if(flag == 'Y') printf("LE\n"); col += yyleng;}
{LPAR}                      {if(flag == 'Y') printf("LPAR\n"); col += yyleng;}
{LT}                        {if(flag == 'Y') printf("LT\n"); col += yyleng;}
{MINUS}                     {if(flag == 'Y') printf("MINUS\n"); col += yyleng;}
{MOD}                       {if(flag == 'Y') printf("MOD\n"); col += yyleng;}
{NE}                        {if(flag == 'Y') printf("NE\n"); col += yyleng;}
{NOT}                       {if(flag == 'Y') printf("NOT\n"); col += yyleng;}
{OR}                        {if(flag == 'Y') printf("OR\n"); col += yyleng;}
{PLUS}                      {if(flag == 'Y') printf("PLUS\n"); col += yyleng;}
{RBRACE}                    {if(flag == 'Y') printf("RBRACE\n"); col += yyleng;}
{RPAR}                      {if(flag == 'Y') printf("RPAR\n"); col += yyleng;}
{SEMI}                      {if(flag == 'Y') printf("SEMI\n"); col += yyleng;}
{RESERVED}                  {if(flag == 'Y') printf("RESERVED(%s)\n", yytext); col += yyleng;}
{ID}                        {if(flag == 'Y') printf("ID(%s)\n", yytext); col += yyleng;}
{INTLIT}                    {if(flag == 'Y') printf("INTLIT(%s)\n", yytext); col += yyleng;}
{REALLIT}                   {if(flag == 'Y') printf("REALLIT(%s)\n", yytext); col += yyleng;}
\'{CHRLIT}\' 	            {if(flag == 'Y') printf("CHRLIT(%s)\n", yytext); col += yyleng;}
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
        }
    }
    
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

void yyerror (char *s) {
    printf("Line %d, col %d: %s: %s\n", line, col, s, yytext);
}