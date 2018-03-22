%{
    #include <stdio.h>
    int yylex(void);
    void yyerror (char *s);
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
%token BITEWISEOR
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
%token ID
%token INTLIT
%token REALLIT
%token CHRLIT

%left COMMA

%%
FunctionsAndDeclarations: FunctionDefinition 
    | FunctionDeclaration 
    | Declaration
    | FunctionsAndDeclarations FunctionsAndDeclarations
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody
    ;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE
    | LBRACE RBRACE
    ;

DeclarationsAndStatements: Statement DeclarationsAndStatements
    | Declaration DeclarationsAndStatements
    | Statement
    | Declaration
    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI
    ;

FunctionDeclarator: ID LPAR ParameterList RPAR
    ;

ParameterList: ParameterDeclaration 
    | ParameterList COMMA ParameterDeclaration
    ;

ParameterDeclaration: TypeSpec ID
    | TypeSpec
    ;

CommaDeclarator: CommaDeclarator COMMA Declarator
    | COMMA Declarator
    ;

Declaration: TypeSpec Declarator SEMI
    | TypeSpec Declarator CommaDeclarator SEMI
    ;

TypeSpec: CHAR
    | INT
    | VOID
    | SHORT
    | DOUBLE
    ;

Declarator: ID 
    | ID ASSIGN Expr
    ;

Statement: SEMI
    | Expr SEMI
    ;

Statement: LBRACE Statement RBRACE
    |
    | Statement Statement
    ;

Statement: IF LPAR Expr RPAR Statement
    | IF LPAR Expr RPAR Statement ELSE Statement
    ;

Statement: WHILE LPAR Expr RPAR Statement
    ;

Statement: RETURN Expr SEMI
    | RETURN SEMI
    ;

Expr: Expr ASSIGN Expr
    | Expr COMMA Expr
    ;

Expr: Expr PLUS Expr
    | Expr MINUS Expr
    | Expr MUL Expr
    | Expr DIV Expr
    | Expr MOD Expr
    ;

Expr: Expr OR Expr
    | Expr AND Expr
    | Expr BITWISEAND Expr
    | Expr BITEWISEOR Expr
    | Expr BITWISEXOR Expr
    ;

Expr: Expr EQ Expr
    | Expr NE Expr 
    | Expr LE Expr
    | Expr GE Expr 
    | Expr LT Expr
    | Expr GT Expr
    ;

Expr: PLUS Expr
    | MINUS Expr
    | NOT Expr
    ;

CommaExpr: CommaExpr COMMA Expr
    | COMMA Expr
    ;

Expr: ID LPAR RPAR
    | ID LPAR Expr CommaExpr RPAR
    ;

Expr: ID
    | INTLIT
    | CHRLIT
    | REALLIT
    | LPAR Expr RPAR
    ;
%%