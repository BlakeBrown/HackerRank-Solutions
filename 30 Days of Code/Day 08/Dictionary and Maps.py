import sys
inputList=[]

for l in sys.stdin:
    inputList.append(l)

a = int(inputList[0])
entries = inputList[1:a+1]
queries = inputList[a+1:]

phoneBook = {}

for entry in entries:
    name, id = entry.split()
    phoneBook[name] = id

for query in queries:
    stripQuery = query.rstrip() 
    if stripQuery in phoneBook:
        print(stripQuery + "=" + str(phoneBook[stripQuery]))
    else:
        print("Not found")
