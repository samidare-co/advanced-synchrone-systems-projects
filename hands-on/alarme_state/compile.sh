#!/bin/bash 


# Demander l'impression de toute commande avant exécution
set -x

# Compilation Heptagon -> C
heptc -target c alarme.ept
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    sed -i '' '/#include "pervasives.h"/d' alarme_c/alarme_types.h
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    sed -i '/#include "pervasives.h"/d' alarme_c/alarme_types.h
fi
# Compilation C -> Objet
gcc -c -I./ -I `heptc -where`/c  alarme_c/alarme.c
gcc  -I./ -I `heptc -where`/c -I ./alarme_c/  -c main.c
# Edition de liens
gcc main.o alarme.o -o main

# Nettyage
rm -Rf *~ *.o *.epci *.mls *.logo scheduler_data_c scheduler_c 
rm -Rf *~ *.o *.epci *.mls *.log  
