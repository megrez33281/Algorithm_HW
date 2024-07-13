
n = input()
for i in range(0,int(n)):
     sum = input()
     sum = int(sum)
     j = 0
     while sum >= j+1:
          j += 1
          sum -= j

     j += 1
     print(j-sum," ",j, end='')
     if i != int(n)-1:
          print("")

