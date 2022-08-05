if __name__ == '__main__':
    marksheet=[]
    for _ in range(int(input())):
        name = input()
        score = float(input())
        marksheet.append([name,score])
        
    sh = sorted(list(set([score for name, score in marksheet])))[1]
    print('\n'.join([a for a,b in sorted(marksheet) if b == sh]))
