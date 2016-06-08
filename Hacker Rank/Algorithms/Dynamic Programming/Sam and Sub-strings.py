def sumSubstring(n):
    result = 0
    multiplier = 0
    numDigits = len(str(n))
    for i in range(0, numDigits):
        # perform the modulo on each iteration, drastically reduces the computation time for large numbers
        multiplier = (multiplier + (10**i))%(10**9 + 7)
        digit = n % 10
        result = (result + digit*(numDigits-i)*multiplier)%(10**9 + 7)
        n //= 10 
    return str(result)

N = int(input())
print(sumSubstring(N))
