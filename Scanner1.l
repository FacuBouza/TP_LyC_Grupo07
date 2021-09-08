%{
#include <unistd.h>
%}

%%
"username"	printf("%s\n", getlogin());
%%

main()
{
  yylex();
}
