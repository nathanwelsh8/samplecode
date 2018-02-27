#ex4

nameArray = []
message = "\nPlease Enter a name\n:"

while True:

    #input can display a premade string
    name = input(message)
    
    #new code is the and. you can
    #compare may cases in one if statement
    
    if name != str('x') and len(name)>=3:
        nameArray.append(name)

        message = "\nPlease Enter a  name\n:"
    
    elif name == str('x'):
        break
    else:
        message = "\nPlease Enter a valid name\n:"


search = input("Enter a search term\n:")

for i in range(len( nameArray )):

    if str(nameArray[i]) == str(search):
        
        print( search + str(" found in nameArray") )
        break
    
    else:
        # it is messy to show if name not found in array
        # will show you a better way of doing
        # this when we do functions
        pass 

    
