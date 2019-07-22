#x="6-19 employees"

#echo $x | tr '-' '▒' 6▒19



read var
result=${var//-/▒}
echo $result

read a
if[ $a = 'a' ]
then
	echo "Hoise"




