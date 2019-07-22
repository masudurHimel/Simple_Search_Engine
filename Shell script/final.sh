searchByIndustry()
{
echo "Enter the industry name"
read industry
grep $industry sample.csv
}

echo "OPtion ? "

read choice

if [ $choice -eq 1 ]
then
printf "please enter Industry name to search:\n%s"; read pattern; awk -v patt="$pattern" -F',' '$2 == patt' sample.csv

else
echo "Hoinai"
fi
