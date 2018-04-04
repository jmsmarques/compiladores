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
%token RETURN
%token VOID
%token BITWISEAND
%token BITWISEOR
%token BITWISEXOR
%token AND
%token ASSIGN
%token MUL
%token COMMA
%token DIV
%token EQ
%token GE
%token GT
%token LBRACE
%token LE
%token LPAR
%token LT
%token MINUS
%token MOD
%token NE
%token NOT
%token OR
%token PLUS
%token RBRACE
%token RPAR
%token SEMI
%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> CHRLIT
%token RESERVED

%union {
    char* id;
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

%right ASSIGN
%left COMMA
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GE GT LE LT
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
program: FunctionsAndDeclarations                               {if(flag == 'T'){ root = createNode("Program"); addChild(root, $1); $$ = root;}; if(printFlag == 'Y'){ printTree(root, 0);} else { freeTree(root);};}
    ;

FunctionsAndDeclarations: FunctionDefinition                    {if(flag == 'T'){ $$ = $1;}}
    | FunctionDeclaration                                       {if(flag == 'T'){ $$ = $1;}}
    | Declaration                                               {if(flag == 'T'){ $$ = $1;};}
    | FunctionsAndDeclarations FunctionDefinition               {if(flag == 'T'){ addSibling($1, $2); $$ = $1;}}
    | FunctionsAndDeclarations FunctionDeclaration              {if(flag == 'T'){ addSibling($1, $2); $$ = $1;}}
    | FunctionsAndDeclarations Declaration                      {if(flag == 'T'){ addSibling($1, $2); $$ = $1;}}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody    {if(flag == 'T'){ $$ = createNode("FuncDefinition"); addChild($$, $1); addSibling($1, $2); addSibling($2, $3);};}
    ;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE           {if(flag == 'T'){ $$ = createNode("FuncBody"); addChild($$, $2);};}
    | LBRACE RBRACE                                             {if(flag == 'T') $$ = createNode("FuncBody");}
    ;

DeclarationsAndStatements: DeclarationsAndStatements Statement  {if(flag == 'T'){ addSibling($1, $2); $$ = $1;};}
    | DeclarationsAndStatements Declaration                     {if(flag == 'T'){ addSibling($1, $2); $$ = $1;};}
    | Statement                                                 {if(flag == 'T'){ $$ = $1;};}
    | Declaration                                               {if(flag == 'T'){ $$ = $1;};}
    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI           {if(flag == 'T'){ $$ = createNode("FuncDeclaration"); addChild($$, $1); addSibling($1, $2);};}
    ;

FunctionDeclarator: ID LPAR ParameterList RPAR                  {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1); addSibling($$, $3);};}
    ;

ParameterList: ParameterDeclaration                             {if(flag == 'T'){ $$ = createNode("ParamList"); addChild($$, $1);};}
    | ParameterList COMMA ParameterDeclaration                  {if(flag == 'T'){ addSibling($1, $3); $$ = createNode("Comma"); addChild($$, $1);};}
    ;

ParameterDeclaration: TypeSpec ID                               {if(flag == 'T'){ $$ = createNode("ParamDeclaration"); addChild($$, $1); addChild($$, createNodeTerminal("Id", $2));};}
    | TypeSpec                                                  {if(flag == 'T'){ $$ = createNode("ParamDeclaration"); addChild($$, $1);};}
    ;

CommaDeclarator: CommaDeclarator COMMA Declarator               {if(flag == 'T'){ addSibling($1, $3); $$ = $1;};}
    | COMMA Declarator                                          {if(flag == 'T') $$ = $2;}
    ;

Declaration: TypeSpec Declarator SEMI                           {if(flag == 'T'){ addSibling($1, $2); $$ = $1;};}
    | TypeSpec Declarator CommaDeclarator SEMI                  {if(flag == 'T'){ addSibling($1, $2); addSibling($2, $3); $$ = $1;};}
    | error SEMI                                                {printFlag = 'N';}
    ;

TypeSpec: CHAR                                                  {if(flag == 'T'){ $$ = createNode("Char");};}
    | INT                                                       {if(flag == 'T'){ $$ = createNode("Int");};}
    | VOID                                                      {if(flag == 'T'){ $$ = createNode("Void");};}
    | SHORT                                                     {if(flag == 'T'){ $$ = createNode("Short");};}
    | DOUBLE                                                    {if(flag == 'T'){ $$ = createNode("Double");};}
    ;

Declarator: ID                                                  {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1);};}
    | ID ASSIGN Expr                                            {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1); addSibling($$, $3);};}
    ;

MultStatement: ErrorStatement MultStatement                     {}
    | ErrorStatement                                            {}
    ;

ErrorStatement: Statement                                       {}
    | error SEMI                                                {printFlag = 'N';}
    ;

Statement: SEMI                                                 {}
    | Expr SEMI                                                 {}
    | LBRACE RBRACE                                             {}
    | LBRACE MultStatement RBRACE                               {}
    | IF LPAR Expr RPAR ErrorStatement %prec LOWER_THAN_ELSE    {}
    | IF LPAR Expr RPAR ErrorStatement ELSE ErrorStatement      {}
    | WHILE LPAR Expr RPAR ErrorStatement                       {}
    | RETURN Expr SEMI                                          {if(flag == 'T'){ $$ = createNode("Return"); addChild($$, $2);};}
    | RETURN SEMI                                               {if(flag == 'T'){ $$ = createNode("Return"); addNullChild($$);};}
    | LBRACE error RBRACE                                       {printFlag = 'N';}
    ;

Expr: Expr ASSIGN Expr                                          {}
    | Expr COMMA Expr                                           {}
    | Expr PLUS Expr                                            {}
    | Expr MINUS Expr                                           {}
    | Expr MUL Expr                                             {}
    | Expr DIV Expr                                             {}
    | Expr MOD Expr                                             {}
    | Expr OR Expr                                              {}
    | Expr AND Expr                                             {}
    | Expr BITWISEAND Expr                                      {}
    | Expr BITWISEOR Expr                                       {}
    | Expr BITWISEXOR Expr                                      {}
    | Expr EQ Expr                                              {}
    | Expr NE Expr                                              {}
    | Expr LE Expr                                              {}
    | Expr GE Expr                                              {}
    | Expr LT Expr                                              {}
    | Expr GT Expr                                              {}
    | PLUS Expr                                                 {}
    | MINUS Expr                                                {}
    | NOT Expr                                                  {}
    | ID LPAR RPAR                                              {}
    | ID LPAR Expr RPAR                                         {}
    | ID                                                        {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1);};}
    | INTLIT                                                    {if(flag == 'T'){ $$ = createNodeTerminal("IntLit", $1);};}
    | CHRLIT                                                    {if(flag == 'T'){ $$ = createNodeTerminal("ChrLit", $1);};}
    | REALLIT                                                   {if(flag == 'T'){ $$ = createNodeTerminal("RealLit", $1);};}
    | LPAR Expr RPAR                                            {}
    | ID LPAR error RPAR                                        {printFlag = 'N';}
    | LPAR error RPAR                                           {printFlag = 'N';}
    ;
%%