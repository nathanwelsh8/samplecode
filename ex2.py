#ex2

#make empty array
nameArray = []

#while true loops
#forever untill broken
while True:
    
    name = input('Please enter a name \n:')

    #if not x then add name to list
    if name != str('x'):
        nameArray.append(name)

    # means x has been pressed so stop looping
    else:
        break

counter = 0

#count how many items in array
for i in nameArray:
    counter += 1

print(str(counter)+" names in list")
    
