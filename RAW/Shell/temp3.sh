awk 'BEGIN{FS=",";OFS=","}{ print}' sample.csv

echo ""
echo ""

read pattern; awk -v patt="$pattern" -F ',' '$3 == patt' sample.csv




