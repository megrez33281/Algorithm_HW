def factorial(n):
    fact = 1
    for i in range(1, n+1):
        fact *= i
    return fact


def combination(n, k):

    numerator = 1
    for i in range(n-k+1, n+1):
        numerator *= i
    denominator = factorial(k)
    return numerator // denominator


time = int(input())
for i in range(time):
    row, col = map(int, input().split())
    paths = combination(row+col-2, col-1)
    print(paths)
