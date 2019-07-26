import csv

"""
Initialization part
"""
# csv file name
filename = "data.csv"

# initializing the titles and rows list
fields = []
rows = []

# reading csv file
with open(filename, 'r') as csvfile:
    # creating a csv reader object
    csvreader = csv.reader(csvfile)

    # extracting field names through first row
    fields = next(csvreader)

    # extracting each data row one by one
    for row in csvreader:
        rows.append(row)


    # for matching with user input
    def matchingStatus(value, index_no):
        matchingData = []
        #total data size
        for i in range(12831):
            if value.lower() == rows[i][index_no].lower():
                matchingData.append(rows[i])
        return matchingData

"""
Main input starts here
"""

print("Searching On : Survey data set of New Zealand citizens")
print("Topic        : Changing nature of work")
print("Choose your option : ")
print("1.By Industry Name")
print("2.By Level")
print("3.By Line Code")
print("4.By Value")
print("5.By Size")
print("6.By Description")
print("7.Exit")
option = input("\n\nOption ? : ")

if option == "1":
    value = input("Enter the name of the Industry : ")
    result = matchingStatus(value, 1)

elif option == "2":
    value = input("Enter the value of the Level :")
    result = matchingStatus(value, 2)

elif option == "3":
    value = input("Enter the Line Code : ")
    result = matchingStatus(value, 4)

elif option == "4":
    value = input("Enter the Value : ")
    result = matchingStatus(value, 5)

elif option == "5":
    value = input("Enter the Size : ")
    result = matchingStatus(value, 3)

elif option == "6":
    value = input("Enter the Description : ")
    result = matchingStatus(value, 0)


elif option == "7":
    print("Exiting . . . .. ")
    exit(1)

"""
Main result printing
"""
totalResult = 0
if result:

    for i in result:
        print(i)
        totalResult = totalResult + 1

else:
    print("Total Result = " + totalResult + "\n\n")
    print("No matching found")

print("Total Result = ", totalResult)
