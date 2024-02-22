for outer in {1..3}; do 
    for inner in {1..5}; do
        if [[ $inner -eq 3 ]]; then
            break 2;  #closes the outer loop
        fi
        echo "value of inner = $inner"
    done
    # if [[ $outer -eq 2 ]]; then
    #     break
    #fi
    echo "value of outer = $outer"
done