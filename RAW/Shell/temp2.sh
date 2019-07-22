searchByIndustry()
{
echo "Enter the industry name"
read industry
awk  -F',' '{print}' sample.csv
}

echo "OPtion ? "

read choice

if [ $choice -eq 1 ]
then
searchByIndustry


else
echo "Hoinai"
fi
