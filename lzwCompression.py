#  compress takes an uncompressed string, and compresses according
#  to the compression scheme. 
#  Returns the compressed result, as a sequence of integer codes.

def generateCodebook(datastream):
    
    temp = []
    #compress codebook
    if type(datastream) is not list:
        [temp.append(x) for x in datastream if x not in temp]
        temp = {x:ord(x) for x in temp}
    else: #decompress codebook
        [temp.append(x) for x in datastream if x < 128 if x not in temp]
        temp = {x:chr(x) for x in temp}
    return temp

def compress(datastream):
    codebook = generateCodebook(datastream)
    
    #more memory efficient to use lists over
    #repeated string concatination
    buffer = []
    output = []
    
    for char in datastream:
        
        if "".join(buffer)+char in codebook:
            buffer.append(char)
        else:
            codebook["".join(buffer)+char] = max(list(codebook.values())+[127])+1
            output.append(codebook["".join(buffer)])
            buffer = [char]
            
    output.append(codebook["".join(buffer)])
    return output
    
def decompress(datastream):
    
    codebook = generateCodebook(datastream)
    if len(datastream) >0:
        decodedString = codebook[datastream[0]]
    else:
        decodedString = ""
    #buffer = []
    output = []
    
    for code in range(1,len(datastream)):
        output.append(decodedString)
        buffer = [decodedString]
        
        if datastream[code] in codebook:
            decodedString = codebook[datastream[code]]
            
            # insert into next free code 
            codebook[max(list(codebook.keys())+[127])+1] = "".join(buffer)+decodedString[0]
        else:
            decodedString = "".join(buffer) +"".join(buffer)[0]
            codebook[max(list(codebook.keys())+[127])+1]  = decodedString
    output.append(decodedString)
    return "".join(output)
