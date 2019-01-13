def flatten(x,temp_list=[]):
    #flattens a x Dimensional list
    for index in x:
        if type(index) is list:
            flatten(index,temp_list)
        else:
            temp_list.append(index)
    
    return temp_list
    
flatten([1,[2,4,5,[6,[7],7],[8]],2,3,[1,2],[1,[1,2,3,[1,2]]]])



def chunks(_list,size):
    #splits list into given chunks
    #e.g
    #Input: [1,2,3,5,1,3,4,12,3,5,3,2,3,4,5], 
    #6 Output: [[1, 2, 3, 5, 1, 3], [4, 12, 3, 5, 3, 2], [3, 4, 5]]
    if size > len(_list):
        return _list
    new_list = [[x for x in _list[y:y+size]]
                    for y in range(0,len(_list),size)]
    
    return new_list  
    
def applyfunondict(_dict,func):
    
    #applies a function to every value in dict
    #works on nested dicts
    
    for key,elem in _dict.items():

    #recurse
    if type(elem) is dict:
        applyfunondict(elem,func)

    else: #map function
        _dict[key] = func(elem)         
    return _dict
                                                                       # square every value
applyfunondict({"a":1,"b":{'e':4,'f':5,'g':{'h':6,'i':7}},"c":2,"d":3},lambda x:x**2) 

def comparedicts(*args):
    #compares dictionaries and returns True if
    #dicts match, False otherwise
    list_dicts = []
    
    for _dict in args:
        list_dicts.append([list(_dict.keys()),list(_dict.values())])
    
    for dicts in range(1,len(list_dicts)):
        for i in range(len(list_dicts[dicts][0])):
            #if keys & dicts match
            try: #index error if dicts not all same length
                if (list_dicts[0][0][i] not in list_dicts[dicts][0]) or (list_dicts[0][1][i] not in list_dicts[dicts][1]):
                    return False
            except IndexError:
                return False

    return True

comparedicts({'a':1,'b':2,'c':3},{'b':2,'c':3,'a':1,'a':1},{'a':1,'b':2,'c':3})

def differences(*args):
    # returns a set of tuples contains all 
    # key,values not common to all sets
    difference= []
    comparitor_dict = args[0]
    
    # takes set and compaires if key,vals in other set(s)
    # missing key vals are added to difference list 
    process = lambda x,y=comparitor_dict:[difference.append([key,value,x]) for key,value in args[x].items()
                  if key not in y.keys() or value not in y.values() 
                      if [key,value,x] not in difference ]
    
    #add to difference list if not in reference set
    for _dict in range(1,len(args)):        
        process(_dict)
        
    #check flagged points and add to difference list if necessary
    [process(0,args[x[2]]) for x in difference]
    
    # z is set it came from not required for output
    return set((x,y) for x,y,z in difference)

differences({'a':1,'b':2,'c':3,'g':5},{'a':1,'b':2,'d':3,'e':4},{'a':1,'b':2,'d':3,'e':4})



    
