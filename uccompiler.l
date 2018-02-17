/*Jorge Marques 2014199355*/
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
CHRLIT      \'([^\n\' ]|{ESCAPE})\'
REALLIT     ({REALLITA}|{REALLITB}|{REALLITC})
%%
\/\/.*              ;
\/\*(.|\n)*\/       ;
{CHAR}              {printf("CHAR\n");}
{ELSE}              {printf("ELSE\n");}
{WHILE}             {printf("WHILE\n");}
{IF}                {printf("IF\n");}
{INT}               {printf("INT\n");}
{SHORT}             {printf("SHORT\n");}
{DOUBLE}            {printf("DOUBLE\n");}
{RETURN}            {printf("RETURN\n");}
{VOID}              {printf("VOID\n");}
{BITWISEAND}        {printf("BITWISEAND\n");}
{BITWISEOR}         {printf("BITWISEOR\n");}
{BITWISEXOR}        {printf("BITWISEXOR\n");}
{AND}               {printf("AND\n");}
{ASSIGN}            {printf("ASSIGN\n");}
{MUL}               {printf("MUL\n");}
{COMMA}             {printf("COMMA\n");}
{DIV}               {printf("DIV\n");}
{EQ}                {printf("EQ\n");}
{GE}                {printf("GE\n");}
{GT}                {printf("GT\n");}
{LBRACE}            {printf("LBRACE\n");}
{LE}                {printf("LE\n");}
{LPAR}              {printf("LPAR\n");}
{LT}                {printf("LT\n");}
{MINUS}             {printf("MINUS\n");}
{MOD}               {printf("MOD\n");}
{NE}                {printf("NE\n");}
{NOT}               {printf("NOT\n");}
{OR}                {printf("OR\n");}
{PLUS}              {printf("PLUS\n");}
{RBRACE}            {printf("RBRACE\n");}
{RPAR}              {printf("RPAR\n");}
{SEMI}              {printf("SEMI\n");}
{RESERVED}          {printf("RESERVED\n");}
{ID}                {printf("ID(%s)\n", yytext);}
{INTLIT}            {printf("INTLIT(%s)\n", yytext);}
{CHRLIT}            {printf("CHRLIT(%s)\n", yytext);}
{REALLIT}           {printf("REALLIT(%s)\n", yytext);}
.                   ;
\n                  ;
%%
int main()
{
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
