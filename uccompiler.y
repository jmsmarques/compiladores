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
program: FunctionsAndDeclarations                               {if(flag == 'T') root = createNode("Program"); if(flag == 'T') addChild(root, $1); if(flag == 'T') $$ = root; if(flag == 'T') printTree(root, 0);}
    ;

FunctionsAndDeclarations: FunctionDefinition                    {if(flag == 'T')}
    | FunctionDeclaration                                       {}
    | Declaration                                               {}
    | FunctionDefinition FunctionsAndDeclarations               {}
    | FunctionDeclaration FunctionsAndDeclarations              {}
    | Declaration FunctionsAndDeclarations                      {}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody    {}
    ;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE           {}
    | LBRACE RBRACE                                             {}
    ;

DeclarationsAndStatements: Statement DeclarationsAndStatements  {}
    | Declaration DeclarationsAndStatements                     {}
    | Statement                                                 {}
    | Declaration                                               {}
    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI           {}
    ;

FunctionDeclarator: ID LPAR ParameterList RPAR                  {}
    ;

ParameterList: ParameterDeclaration                             {}
    | ParameterList COMMA ParameterDeclaration                  {}
    ;

ParameterDeclaration: TypeSpec ID                               {}
    | TypeSpec                                                  {}
    ;

CommaDeclarator: CommaDeclarator COMMA Declarator               {}
    | COMMA Declarator                                          {}
    ;

Declaration: TypeSpec Declarator SEMI                           {}
    | TypeSpec Declarator CommaDeclarator SEMI                  {}
    | error SEMI                                                {}
    ;

TypeSpec: CHAR                                                  {}
    | INT                                                       {}
    | VOID                                                      {}
    | SHORT                                                     {}
    | DOUBLE                                                    {}
    ;

Declarator: ID                                                  {}
    | ID ASSIGN Expr                                            {}
    ;

MultStatement: ErrorStatement MultStatement                     {}
    | ErrorStatement                                            {}
    ;

ErrorStatement: Statement                                       {}
    | error SEMI                                                {}
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
    | ID LPAR error RPAR                                        {}
    | LPAR error RPAR                                           {}
    ;
%%