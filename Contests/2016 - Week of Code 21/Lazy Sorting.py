import sys

# Pre-compute factorials to improve runtime
factorialCache = [1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0, 40320.0, 362880.0, 3628800.0, 39916800.0, 479001600.0, 6227020800.0, 87178291200.0, 1307674368000.0, 20922789888000.0, 355687428096000.0, 6402373705728000.0]

# Read input
inputs = []
lineNumber = 0
N = None
arr = []
for line in sys.stdin:
    if lineNumber == 0:
        N = float(line)
    else:
        arr = list(map(float, line.strip().split(' ')))
    lineNumber = 1

# Find the # of repeats
repeats = {}
for elem in arr:
    if elem in repeats:
        repeats[elem] += 1
    else:
        repeats[elem] = 1

# Edge case: List is already sorted
currentElem = arr[0]
alreadySorted = True
for elem in arr:
    if(elem >= currentElem):
        currentElem = elem

    else:
        alreadySorted = False
        break

if(alreadySorted):
    print('0.000000')
else:
    # Answer = N! / ((# of first repeat)! * (# of second repeat)! * ...)
    P = 1
    for key, value in repeats.items():
        if(value > 1):
            P *= factorialCache[int(value-1)]

    answer = factorialCache[int(N-1)]/P
    print(format(answer, '.6f'))
    