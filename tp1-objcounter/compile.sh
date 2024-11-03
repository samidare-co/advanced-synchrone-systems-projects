#!/bin/bash

# Demander l'impression de toute commande avant exécution
set -x

# Compilation Heptagon -> C
heptc -target c counter.ept
# Compilation C -> Objet
gcc -c -I./ -I `heptc -where`/c main.c
gcc -c -I./counter_c -I `heptc -where`/c counter_c/counter.c
# Edition de liens
gcc -o counter main.o counter.o

# Nettoyage
#rm -Rf *~ *.o *.epci *.mls *.log counter_c 
