#!/bin/bash

# Demander l'impression de toute commande avant exécution
set -x

# Compilation Heptagon -> C
heptc -c extern.epi
heptc -target c gnc.ept
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    sed -i '' '/#include "pervasives.h"/d' gnc_c/gnc_types.h
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    sed -i '/#include "pervasives.h"/d' gnc_c/gnc_types.h
fi
# Compilation C -> Objet
gcc -c extern.c
gcc -c -I./ -I `heptc -where`/c main.c
gcc -c -I./gnc_c -I./ `heptc -where`/c gnc_c/gnc.c
# Edition de liens
gcc -o gnc extern.o main.o gnc.o

# Nettoyage
# rm -Rf *~ *.o *.epci *.mls *.log gnc_c 
#rm -Rf *~ *.o *.epci *.mls *.log  
