import math

n = input()
n = int(n)
sum = 1
for i in range(2,math.floor(math.sqrt(n))+1):

	if n%i == 0:
		sum += i
		if n/i != i and n/i > i:#避免n/i是已經加過的數
			sum += n/i
print(sum)
