#!/bin/bash
for (( index=1; index<=5; index++ ))
do
    echo "I am ruuning $index times"
    if [[ $index -eq 3 ]]; then
    break
    fi
done
