%{
    #include "structs.h"  

    node root;
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
program: FunctionsAndDeclarations                               {if(flag == 'T'){ root = createNode("Program"); addChild(root, $1); $$ = root; printTree(root, 0);}}
    ;

FunctionsAndDeclarations: FunctionDefinition                    {if(flag == 'T'){ $$ = $1;}}
    | FunctionDeclaration                                       {if(flag == 'T'){ $$ = $1;}}
    | Declaration                                               {if(flag == 'T'){ $$ = $1;}}
    | FunctionsAndDeclarations FunctionDefinition               {if(flag == 'T'){ addSibling($1, $2); $$ = $1;}}
    | FunctionsAndDeclarations FunctionDeclaration              {if(flag == 'T'){ addSibling($1, $2); $$ = $1;}}
    | FunctionsAndDeclarations Declaration                      {if(flag == 'T'){ addSibling($1, $2); $$ = $1;}}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody    {if(flag == 'T'){ $$ = createNode("FuncDefinition"); addChild($$, $1); addSibling($1, $2); addSibling($2, $3);};printf("ola: %s\n", $2->sibling->tag);}
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

FunctionDeclarator: ID LPAR ParameterList RPAR                  {if(flag == 'T'){ $$ = createNodeTerminal("Id", $1); addSibling($$, $3);};printf("oi: %s\n", $3->tag);}
    ;

ParameterList: ParameterDeclaration                             {if(flag == 'T'){ $$ = createNode("ParamList"); addChild($$, $1);};printf("%s %s\n", $1->tag, $$->tag);}
    | ParameterList COMMA ParameterDeclaration                  {if(flag == 'T'){ addSibling($1, $3); $$ = $1;};}
    ;

ParameterDeclaration: TypeSpec ID                               {if(flag == 'T'){ $$ = createNode("ParamDeclaration"); addChild($$, $1); addChild($$, createNodeTerminal("Id", $2));};}
    | TypeSpec                                                  {if(flag == 'T'){ $$ = createNode("ParamDeclaration"); addChild($$, $1);};}
    ;

CommaDeclarator: CommaDeclarator COMMA Declarator               {}
    | COMMA Declarator                                          {}
    ;

Declaration: TypeSpec Declarator SEMI                           {}
    | TypeSpec Declarator CommaDeclarator SEMI                  {}
    | error SEMI                                                {flag = 'N'; freeTree($$);}
    ;

TypeSpec: CHAR                                                  {if(flag = 'T'){ $$ = createNode("Char");};}
    | INT                                                       {if(flag = 'T'){ $$ = createNode("Int");};}
    | VOID                                                      {if(flag = 'T'){ $$ = createNode("Void");};}
    | SHORT                                                     {if(flag = 'T'){ $$ = createNode("Short");};}
    | DOUBLE                                                    {if(flag = 'T'){ $$ = createNode("Double");};}
    ;

Declarator: ID                                                  {}
    | ID ASSIGN Expr                                            {}
    ;

MultStatement: ErrorStatement MultStatement                     {}
    | ErrorStatement                                            {}
    ;

ErrorStatement: Statement                                       {}
    | error SEMI                                                {flag = 'N'; freeTree($$);}
    ;

Statement: SEMI                                                 {}
    | Expr SEMI                                                 {}
    | LBRACE RBRACE                                             {}
    | LBRACE MultStatement RBRACE                               {}
    | IF LPAR Expr RPAR ErrorStatement %prec LOWER_THAN_ELSE    {}
    | IF LPAR Expr RPAR ErrorStatement ELSE ErrorStatement      {}
    | WHILE LPAR Expr RPAR ErrorStatement                       {}
    | RETURN Expr SEMI                                          {}
    | RETURN SEMI                                               {}
    | LBRACE error RBRACE                                       {}
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
    | ID                                                        {}
    | INTLIT                                                    {}
    | CHRLIT                                                    {}
    | REALLIT                                                   {}
    | LPAR Expr RPAR                                            {}
    | ID LPAR error RPAR                                        {flag = 'N'; freeTree($$);}
    | LPAR error RPAR                                           {flag = 'N'; freeTree($$);}
    ;
%%