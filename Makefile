displaytest: displaytest.c manboard.c mandisplay.c
	gcc -Wall displaytest.c manboard.c mandisplay.c -o displaytest

manfor2: manfor2.c manboard.c mandisplay.c
	gcc -Wall manfor2.c manboard.c mandisplay.c -o manfor2

manfor1: manfor1.c manboard.c mandisplay.c ManMax.c
	gcc -Wall manfor1.c manboard.c mandisplay.c ManMax.c -o manfor1

copytest: copytest.c manboard.c mandisplay.c ManMax.c
	gcc -Wall copytest.c manboard.c mandisplay.c ManMax.c -o test