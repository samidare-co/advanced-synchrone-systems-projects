#!/bin/bash 


# Demander l'impression de toute commande avant exécution
set -x

# Compilation Heptagon -> C
heptc -target c scheduler_data.ept
heptc -c externc.epi
heptc -target c scheduler.ept
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    sed -i '' '/#include "pervasives.h"/d' gnc_c/gnc_types.h
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    sed -i '/#include "pervasives.h"/d' gnc_c/gnc_types.h
fi
# Compilation C -> Objet
gcc -c -I./ -I `heptc -where`/c  scheduler_data_c/scheduler_data.c
gcc -c -I./ -I `heptc -where`/c -I ./scheduler_data_c/  externc.c
gcc -c -I./ -I `heptc -where`/c -I ./scheduler_data_c/ scheduler_c/scheduler.c
gcc  -I./ -I `heptc -where`/c -I ./scheduler_data_c/  -c main.c
# Edition de liens
gcc main.o externc.o scheduler.o scheduler_data.o -o main

# Nettoyage
 rm -Rf *~ *.o *.epci *.mls *.log scheduler_data_c scheduler_c 
rm -Rf *~ *.o *.epci *.mls *.log  
