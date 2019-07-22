s="hello"                 

for ((i=0;i<${#s};i++)); do
    result[$i]="${s:i:1}"
    if[ $result[$i] -eq 'e']
    then 
    result[$i] = 'L'
done                       

echo ${result[@]}

echo 