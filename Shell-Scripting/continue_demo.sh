#!/bin/bash
for (( index=1; index<=5; index++ ))
do
    if [[ $index -eq 3 ]]; then
        continue
    fi
    echo "I am ruuning $index times"
done
