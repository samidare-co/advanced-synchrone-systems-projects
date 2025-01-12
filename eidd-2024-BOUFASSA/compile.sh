#!/bin/bash 


# Demander l'impression de toute commande avant exécution
set -x

# Compilation Heptagon -> C
heptc -target c app.ept
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    sed -i '' '/#include "pervasives.h"/d' app_c/app_types.h
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    sed -i '/#include "pervasives.h"/d' app_c/app_types.h
fi
# Compilation C -> Objet
gcc -c -I./ -I `heptc -where`/c  app_c/app.c
gcc  -I./ -I `heptc -where`/c -I ./app_c/  -c main.c

# Edition de liens
gcc main.o app.o -o main

# Nettyage
rm -Rf *~ *.o *.epci *.mls *.log app_c/
#rm -Rf *~ *.o *.epci *.mls *.log  
