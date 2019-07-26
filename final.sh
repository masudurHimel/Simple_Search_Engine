searchBySize(){
echo "Enter the Size"
read pattern;
grep $pattern data.csv
}





echo "Searching On : Survey data set of New Zealand citizens"
echo "Topic        : Changing nature of work"

echo "Choose your option : "
echo "1.By Industry Name"
echo "2.By Level"
echo "3.By Line Code"
echo "4.By Value"
echo "5.By Size"
echo "6.By Description"
echo "7.Exit"

echo ""
echo "Option ? "

read option

if [ $option -eq 1 ]
then
echo "Enter the industry name"
read pattern; awk -v patt="$pattern" -F',' '$2 == patt' data.csv

elif [ $option -eq 2 ]
then
echo "Enter the Level"
read pattern; awk -v patt="$pattern" -F',' '$3 == patt' data.csv

elif [ $option -eq 3 ]
then
echo "Enter the Line code"
read pattern; awk -v patt="$pattern" -F',' '$5 == patt' data.csv

elif [ $option -eq 4 ]
then
echo "Enter the Value"
read pattern; awk -v patt="$pattern" -F',' '$6 == patt' data.csv

elif [ $option -eq 5 ]
then
searchBySize

elif [ $option -eq 6 ]
then
echo "Enter the Description"
read pattern; awk -v patt="$pattern" -F',' '$1 == patt' data.csv

else
echo "Exiting . . . "
fi


