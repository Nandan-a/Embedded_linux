mkdir test
ret=`echo $?`
if [[ ret -eq 0 ]]; then
    echo "dir created successfully"
else
    echo "failed"
fi
