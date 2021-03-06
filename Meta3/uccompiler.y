%{
    #include "structs.h"  

    node root;
    char printFlag = 'Y';
%}

%token CHAR
%token ELSE
%token WHILE
%token IF
%token INT
%token SHORT
%token DOUBLE
%token <info> RETURN
%token <info> VOID
%token <info> BITWISEAND
%token <info> BITWISEOR
%token <info> BITWISEXOR
%token <info> AND
%token <info> ASSIGN
%token <info> MUL
%token <info> COMMA
%token <info> DIV
%token <info> EQ
%token <info> GE
%token <info> GT
%token LBRACE
%token <info> LE
%token LPAR
%token <info> LT
%token <info> MINUS
%token <info> MOD
%token <info> NE
%token <info> NOT
%token <info> OR
%token <info> PLUS
%token RBRACE
%token RPAR
%token SEMI
%token <info> ID
%token <info> INTLIT
%token <info> REALLIT
%token <info> CHRLIT
%token RESERVED

%union {
    struct _info_node* info;
    struct _tree_node* no;
}

%type <no> program
%type <no> FunctionsAndDeclarations
%type <no> FunctionDefinition
%type <no> FunctionBody
%type <no> DeclarationsAndStatements
%type <no> FunctionDeclaration
%type <no> FunctionDeclarator
%type <no> ParameterList
%type <no> ParameterDeclaration
%type <no> CommaDeclarator
%type <no> Declaration
%type <no> TypeSpec
%type <no> Declarator
%type <no> MultStatement
%type <no> ErrorStatement
%type <no> Statement
%type <no> Expr
%type <no> Expr1

%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GE GT LE LT
%left PLUS MINUS
%left MUL DIV MOD
%left UNITARY
%right NOT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
program: FunctionsAndDeclarations                               {if(flag == 'T'){ root = createNode("Program"); addChild(root, $1); $$ = root; if(printFlag == 'Y') printTree(root, 0);};}
    ;

FunctionsAndDeclarations: FunctionDefinition                    {if(flag == 'T'){ $$ = $1;};}
    | FunctionDeclaration                                       {if(flag == 'T'){ $$ = $1;};}
    | Declaration                                               {if(flag == 'T'){ $$ = $1;};}
    | FunctionsAndDeclarations FunctionDefinition               {if(flag == 'T'){ addSibling($1, $2); $$ = $1;};}
    | FunctionsAndDeclarations FunctionDeclaration              {if(flag == 'T'){ addSibling($1, $2); $$ = $1;};}
    | FunctionsAndDeclarations Declaration                      {if(flag == 'T'){ addSibling($1, $2); $$ = $1;};}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody    {if(flag == 'T'){ $$ = createNode("FuncDefinition"); addChild($$, $1); addSibling($1, $2); addSibling($2, $3);};}
    ;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE           {if(flag == 'T'){ $$ = createNode("FuncBody"); addChild($$, $2);};}
    | LBRACE RBRACE                                             {if(flag == 'T'){ $$ = createNode("FuncBody");};}
    ;

DeclarationsAndStatements: DeclarationsAndStatements Statement  {if(flag == 'T'){ addSibling($1, $2); $$ = $1;};}
    | DeclarationsAndStatements Declaration                     {if(flag == 'T'){ addSibling($1, $2); $$ = $1;};}
    | Statement                                                 {if(flag == 'T'){ $$ = $1;};}
    | Declaration                                               {if(flag == 'T'){ $$ = $1;};}
    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI           {if(flag == 'T'){ $$ = createNode("FuncDeclaration"); addChild($$, $1); addSibling($1, $2);};}
    ;

FunctionDeclarator: ID LPAR ParameterList RPAR                  {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1); addSibling($$, $3);};}
    ;

ParameterList: ParameterDeclaration                             {if(flag == 'T'){ $$ = createNode("ParamList"); addChild($$, $1);};}
    | ParameterList COMMA ParameterDeclaration                  {if(flag == 'T'){ addSibling($1->child, $3); $$ = $1;};}
    ;

ParameterDeclaration: TypeSpec ID                               {if(flag == 'T'){ $$ = createNode("ParamDeclaration"); addChild($$, $1); addSibling($1, createNodeTerminal("Id", $2->id)); addLinesAndCols($$->child->sibling, $2->line, $2->col); free($2);};}
    | TypeSpec                                                  {if(flag == 'T'){ $$ = createNode("ParamDeclaration"); addChild($$, $1);};}
    ;

CommaDeclarator: COMMA Declarator CommaDeclarator               {if(flag == 'T'){ $$ = createNode("Declaration"); addChild($$, createNodeEmpty()); addSibling($$->child, $2); addSibling($$, $3);};}
    |                                                           {if(flag == 'T'){ $$ = NULL;};}
    ;

Declaration: TypeSpec Declarator CommaDeclarator SEMI           {if(flag == 'T'){ $$ = createNode("Declaration"); addSibling($1, $2); addSibling($$, $3); addChild($$, $1); typeSpecDef($$->sibling, $$->child);};}
    | error SEMI                                                {printFlag = 'N'; if(flag == 'T') $$ = NULL;}
    ;

TypeSpec: CHAR                                                  {if(flag == 'T'){ $$ = createNode("Char");};}
    | INT                                                       {if(flag == 'T'){ $$ = createNode("Int");};}
    | VOID                                                      {if(flag == 'T'){ $$ = createNode("Void"); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | SHORT                                                     {if(flag == 'T'){ $$ = createNode("Short");};}
    | DOUBLE                                                    {if(flag == 'T'){ $$ = createNode("Double");};}
    ;

Declarator: ID                                                  {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | ID ASSIGN Expr                                            {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1); addSibling($$, $3);};}
    ;

MultStatement: ErrorStatement MultStatement                     {if(flag == 'T'){ addSibling($1, $2); if($1 != NULL){ $$ = $1;} else{ $$ = $2;};};}
    | ErrorStatement                                            {if(flag == 'T'){ $$ = $1;};}
    ;

ErrorStatement: Statement                                       {if(flag == 'T'){ $$ = $1;};}
    | error SEMI                                                {printFlag = 'N'; if(flag == 'T') $$ = NULL;}
    ;

Statement: SEMI                                                 {if(flag == 'T'){ $$ = NULL;};}
    | Expr SEMI                                                 {if(flag == 'T'){ $$ = $1;};}
    | LBRACE RBRACE                                             {if(flag == 'T'){ $$ = NULL;};}
    | LBRACE MultStatement RBRACE                               {if(flag == 'T'){ if($2 != NULL && $2->sibling != NULL){ $$ = createNode("StatList"); addChild($$, $2);}else{ $$ = $2;}};}
    | IF LPAR Expr RPAR ErrorStatement %prec LOWER_THAN_ELSE    {if(flag == 'T'){ $$ = createNode("If"); addChild($$, checkNull($3)); addSibling($$->child, checkNull($5)); addSibling($$->child->sibling, createNode("Null"));};}
    | IF LPAR Expr RPAR ErrorStatement ELSE ErrorStatement      {if(flag == 'T'){ $$ = createNode("If"); addChild($$, checkNull($3)); addSibling($$->child, checkNull($5)); addSibling($$->child->sibling, checkNull($7));};}
    | WHILE LPAR Expr RPAR ErrorStatement                       {if(flag == 'T'){ $$ = createNode("While"); addChild($$, checkNull($3)); addSibling($$->child, checkNull($5));};}
    | RETURN Expr SEMI                                          {if(flag == 'T'){ $$ = createNode("Return"); addChild($$, $2); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | RETURN SEMI                                               {if(flag == 'T'){ $$ = createNode("Return"); addNullChild($$); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | LBRACE error RBRACE                                       {printFlag = 'N'; if(flag == 'T') $$ = NULL;}
    ;

Expr: Expr ASSIGN Expr                                          {if(flag == 'T'){ $$ = createNode("Store"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr COMMA Expr                                           {if(flag == 'T'){ $$ = createNode("Comma"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr PLUS Expr                                            {if(flag == 'T'){ $$ = createNode("Add"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr MINUS Expr                                           {if(flag == 'T'){ $$ = createNode("Sub"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr MUL Expr                                             {if(flag == 'T'){ $$ = createNode("Mul"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr DIV Expr                                             {if(flag == 'T'){ $$ = createNode("Div"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr MOD Expr                                             {if(flag == 'T'){ $$ = createNode("Mod"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr OR Expr                                              {if(flag == 'T'){ $$ = createNode("Or"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr AND Expr                                             {if(flag == 'T'){ $$ = createNode("And"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr BITWISEAND Expr                                      {if(flag == 'T'){ $$ = createNode("BitWiseAnd"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr BITWISEOR Expr                                       {if(flag == 'T'){ $$ = createNode("BitWiseOr"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr BITWISEXOR Expr                                      {if(flag == 'T'){ $$ = createNode("BitWiseXor"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr EQ Expr                                              {if(flag == 'T'){ $$ = createNode("Eq"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr NE Expr                                              {if(flag == 'T'){ $$ = createNode("Ne"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr LE Expr                                              {if(flag == 'T'){ $$ = createNode("Le"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr GE Expr                                              {if(flag == 'T'){ $$ = createNode("Ge"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr LT Expr                                              {if(flag == 'T'){ $$ = createNode("Lt"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr GT Expr                                              {if(flag == 'T'){ $$ = createNode("Gt"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | PLUS Expr     %prec UNITARY                               {if(flag == 'T'){ $$ = createNode("Plus"); addChild($$, $2); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | MINUS Expr    %prec UNITARY                               {if(flag == 'T'){ $$ = createNode("Minus"); addChild($$, $2); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | NOT Expr      %prec UNITARY                               {if(flag == 'T'){ $$ = createNode("Not"); addChild($$, $2); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | ID LPAR RPAR                                              {if(flag == 'T'){ $$ = createNode("Call"); addChild($$, createNodeTerminal("Id", $1->id)); addLinesAndCols($$->child, $1->line, $1->col); free($1->id); free($1);};}
    | ID LPAR Expr1 RPAR                                        {if(flag == 'T'){ $$ = createNode("Call"); addChild($$, createNodeTerminal("Id", $1->id)); addLinesAndCols($$->child, $1->line, $1->col); free($1->id); free($1); addSibling($$->child, $3);};}
    | ID                                                        {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | INTLIT                                                    {if(flag == 'T'){ $$ = createNodeTerminal("IntLit", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | CHRLIT                                                    {if(flag == 'T'){ $$ = createNodeTerminal("ChrLit", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | REALLIT                                                   {if(flag == 'T'){ $$ = createNodeTerminal("RealLit", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | LPAR Expr RPAR                                            {if(flag == 'T'){ $$ = $2;};}
    | ID LPAR error RPAR                                        {printFlag = 'N'; if(flag == 'T') $$ = NULL;}
    | LPAR error RPAR                                           {printFlag = 'N'; if(flag == 'T') $$ = NULL;}
    ;

Expr1: Expr1 ASSIGN Expr1                                       {if(flag == 'T'){ $$ = createNode("Store"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 COMMA Expr1                                         {if(flag == 'T'){ addSibling($1, $3); $$ = $1;};}
    | Expr1 PLUS Expr1                                          {if(flag == 'T'){ $$ = createNode("Add"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 MINUS Expr1                                         {if(flag == 'T'){ $$ = createNode("Sub"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 MUL Expr1                                           {if(flag == 'T'){ $$ = createNode("Mul"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 DIV Expr1                                           {if(flag == 'T'){ $$ = createNode("Div"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 MOD Expr1                                           {if(flag == 'T'){ $$ = createNode("Mod"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 OR Expr1                                            {if(flag == 'T'){ $$ = createNode("Or"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 AND Expr1                                           {if(flag == 'T'){ $$ = createNode("And"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 BITWISEAND Expr1                                    {if(flag == 'T'){ $$ = createNode("BitWiseAnd"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 BITWISEOR Expr1                                     {if(flag == 'T'){ $$ = createNode("BitWiseOr"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 BITWISEXOR Expr1                                    {if(flag == 'T'){ $$ = createNode("BitWiseXor"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 EQ Expr1                                            {if(flag == 'T'){ $$ = createNode("Eq"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 NE Expr1                                            {if(flag == 'T'){ $$ = createNode("Ne"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 LE Expr1                                            {if(flag == 'T'){ $$ = createNode("Le"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 GE Expr1                                            {if(flag == 'T'){ $$ = createNode("Ge"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 LT Expr1                                            {if(flag == 'T'){ $$ = createNode("Lt"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | Expr1 GT Expr1                                            {if(flag == 'T'){ $$ = createNode("Gt"); addChild($$, $1); addSibling($1, $3); addLinesAndCols($$, $2->line, $2->col); free($2);};}
    | PLUS Expr1        %prec UNITARY                           {if(flag == 'T'){ $$ = createNode("Plus"); addChild($$, $2); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | MINUS Expr1       %prec UNITARY                           {if(flag == 'T'){ $$ = createNode("Minus"); addChild($$, $2); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | NOT Expr1         %prec UNITARY                           {if(flag == 'T'){ $$ = createNode("Not"); addChild($$, $2); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | ID LPAR RPAR                                              {if(flag == 'T'){ $$ = createNode("Call"); addChild($$, createNodeTerminal("Id", $1->id)); addLinesAndCols($$->child, $1->line, $1->col); free($1->id); free($1);};}
    | ID LPAR Expr1 RPAR                                        {if(flag == 'T'){ $$ = createNode("Call"); addChild($$, createNodeTerminal("Id", $1->id)); addLinesAndCols($$->child, $1->line, $1->col); free($1->id); free($1); addSibling($$->child, $3);};}
    | ID                                                        {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | INTLIT                                                    {if(flag == 'T'){ $$ = createNodeTerminal("IntLit", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | CHRLIT                                                    {if(flag == 'T'){ $$ = createNodeTerminal("ChrLit", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | REALLIT                                                   {if(flag == 'T'){ $$ = createNodeTerminal("RealLit", $1->id); addLinesAndCols($$, $1->line, $1->col); free($1->id); free($1);};}
    | LPAR Expr RPAR                                            {if(flag == 'T'){ $$ = $2;};}
    | ID LPAR error RPAR                                        {printFlag = 'N'; if(flag == 'T') $$ = NULL;}
    | LPAR error RPAR                                           {printFlag = 'N'; if(flag == 'T') $$ = NULL;}
    ;
%%
