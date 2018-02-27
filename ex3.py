#ex3

#------- reused from ex2 --------#

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

#------- --------------- --------#
    
# \n takes a new line in a string as used below
search = input("Enter a search term\n:")

#using a different type of looping here

for i in range(len( nameArray )):

    if str(nameArray[i]) == str(search):
        
        print( search + str(" found in nameArray") )

        #stop looping
        break
    else:
        #do nothing
        pass

    
