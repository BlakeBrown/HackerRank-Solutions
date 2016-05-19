# Don't mind me, just learning python :P
N = int(input()) # input() gets the whole line, int() converts from string to int
dictionary = {} # dictionaries appear to work the same as objects in javascript
for i in range(0, N): # don't forget the ':', necessary for all forloops in python!
    inputArray = input().split()
    marks = list(map(float, inputArray[1:])) # okay this line is cool, converts indices 1->end of inputArray to floats, puts them in a list
    dictionary[inputArray[0]] = sum(marks)/float(len(marks)) # sum(marks) adds up everything in marks.. woaaah
print("%.2f" % dictionary[input()]) # print(output) formatted to 2 decimal places