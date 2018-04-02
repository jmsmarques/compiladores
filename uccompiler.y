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
%token ID
%token INTLIT
%token REALLIT
%token CHRLIT

%right ASSIGN NOT
%left BITWISEAND BITWISEOR BITWISEXOR
%left OR AND
%left EQ GE GT LE LT NE
%left PLUS MINUS
%left MUL DIV MOD
%left LPAR RPAR
%left COMMA
%nonassoc ELSE

%%
program: FunctionsAndDeclarations
    |
    ;

FunctionsAndDeclarations: FunctionDefinition 
    | FunctionDeclaration 
    | Declaration
    | FunctionDefinition FunctionsAndDeclarations
    | FunctionDeclaration FunctionsAndDeclarations
    | Declaration FunctionsAndDeclarations
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

DeclarationsAndStatements: error SEMI
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

MultStatement: Statement MultStatement
    | 
    ;

Statement: LBRACE MultStatement RBRACE
    ;

Statement: IF LPAR Expr RPAR Statement
    | IF LPAR Expr RPAR Statement ELSE Statement
    ;

Statement: WHILE LPAR Expr RPAR Statement
    ;

Statement: RETURN Expr SEMI
    | RETURN SEMI
    ;

Statement: LBRACE error RBRACE
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
    | Expr BITWISEOR Expr
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

CommaExpr: COMMA Expr CommaExpr
    | RPAR
    ;

Expr: ID LPAR RPAR
    | ID LPAR Expr CommaExpr 
    ;

Expr: ID
    | INTLIT
    | CHRLIT
    | REALLIT
    | LPAR Expr RPAR
    ;

Expr: ID LPAR error RPAR
    | LPAR error RPAR
    ;
%%