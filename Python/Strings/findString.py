def count_substring(string, sub_string):
    c=0
    for x in range(len(string)):
        if string[x:].startswith(sub_string):
            c+=1
    return c
