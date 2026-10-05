%{
/* calc.l — Analizador LÉXICO (Flex) */
#include <stdlib.h>
#include <string.h>
#include "calc.tab.h"   /* tokens generados por Bison */
%}

%option noyywrap yylineno

DIGITO   [0-9]
LETRA    [a-zA-Z_]

%%
{DIGITO}+("."{DIGITO}+)?    { yylval.num = atof(yytext); return NUMERO; }
"print"                     { return PRINT; }
{LETRA}({LETRA}|{DIGITO})*  { yylval.id = strdup(yytext); return ID; }
"+"                         { return '+'; }
"-"                         { return '-'; }
"*"                         { return '*'; }
"/"                         { return '/'; }
"^"                         { return '^'; }
"("                         { return '('; }
")"                         { return ')'; }
"="                         { return '='; }
";"                         { return ';'; }
"#".*                       { /* comentario: se ignora */ }
[ \t\r\n]+                  { /* espacios: se ignoran */ }
.                           { fprintf(stderr, "Error léxico (línea %d): '%s'\n", yylineno, yytext); }
%%
