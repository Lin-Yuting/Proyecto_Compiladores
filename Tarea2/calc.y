%{
/* calc.y — Analizador SINTÁCTICO (Bison) */
#include <stdio.h>
#include <string.h>
#include <math.h>

int  yylex(void);
void yyerror(const char *s);
extern int yylineno;

/* Tabla de símbolos muy simple */
#define MAX 100
char  *nombres[MAX];
double valores[MAX];
int    nsim = 0;

int buscar(const char *n) {
    for (int i = 0; i < nsim; i++) if (strcmp(nombres[i], n) == 0) return i;
    nombres[nsim] = strdup(n); valores[nsim] = 0; return nsim++;
}
%}

%union {
    double num;
    char  *id;
}

%token <num> NUMERO
%token <id>  ID
%token PRINT
%type  <num> expr

/* Precedencia: de menor a mayor */
%right '='
%left  '+' '-'
%left  '*' '/'
%right '^'
%precedence NEG        /* menos unario */

%%
programa  : /* vacío */
          | programa sentencia
          ;

sentencia : ID '=' expr ';'      { valores[buscar($1)] = $3; free($1); }
          | PRINT expr ';'       { printf("= %g\n", $2); }
          | error ';'            { yyerrok; }   /* recuperación de errores */
          ;

expr : NUMERO                    { $$ = $1; }
     | ID                        { $$ = valores[buscar($1)]; free($1); }
     | expr '+' expr             { $$ = $1 + $3; }
     | expr '-' expr             { $$ = $1 - $3; }
     | expr '*' expr             { $$ = $1 * $3; }
     | expr '/' expr             { if ($3 == 0) { yyerror("división entre cero"); $$ = 0; }
                                   else $$ = $1 / $3; }
     | expr '^' expr             { $$ = pow($1, $3); }
     | '-' expr %prec NEG        { $$ = -$2; }
     | '(' expr ')'              { $$ = $2; }
     ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error sintáctico (línea %d): %s\n", yylineno, s);
}

int main(void) {
    return yyparse();
}
