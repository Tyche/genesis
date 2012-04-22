echo Generating parser source...
yacc -d -l ..\src\grammar.y
move y.tab.c ..\src\grammar.c
move y.tab.h ..\src\include\parse.h
