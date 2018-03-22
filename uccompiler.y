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
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody
    ;

FunctionBody: LBRACE[DeclarationsAndStatements] RBRACE
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

ParameterList: ParameterDeclaration {COMMA ParameterDeclaration}
    ;

ParameterDeclaration: TypeSpec [ID]
    ;

Declaration: TypeSpec Declarator {COMMA Declarator} SEMI
    ;

TypeSpec: CHAR
    | INT
    | VOID
    | SHORT
    | DOUBLE
    ;

Declarator: ID [ASSIGN Expr]
    ;

Statement: [Expr] SEMI
    ;

Statement: LBRACE {Statement} RBRACE
    ;

Statement: IF LPAR Expr RPAR Statement [ELSE Statement]
    ;

Statement: WHILE LPAR Expr RPAR Statement
    ;

Statement: RETURN [Expr] SEMI
    ;

Expr: Expr (ASSIGN | COMMA) Expr
    ;

Expr: Expr (PLUS | MINUS | MUL | DIV | MOD) Expr
    ;

Expr: Expr (OR | AND | BITWISEAND | BITEWISEOR | BITWISEXOR) Expr
    ;

Expr: Expr (EQ | NE | LE | GE | LT | GT) Expr
    ;

Expr: (PLUS | MINUS | NOT) Expr
    ;

Expr: ID LPAR [Expr {COMMA Expr}] RPAR
    ;

Expr: ID
    | INTLIT
    | CHRLIT
    | REALLIT
    | LPAR Expr RPAR
    ;
%%

int main() {
    yyparse();
    return 0;
}