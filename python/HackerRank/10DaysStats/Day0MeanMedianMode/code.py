import sys
lines = sys.stdin.readlines()

n = int(lines[0])

numList = [int(x) for x in lines[1].split(' ')]
numList = sorted(numList)

assert n == len(numList)

mean = float(sum(numList))/n

if (n % 2 == 0):
  median = float(numList[n/2-1] + numList[n/2])/2
else:
  median = float(numList[n/2-1])

hist = {}
for num in numList:
  if num in hist.keys():
    hist[num] += 1
  else:
    hist[num] = 1

maxList = [k for k,v in hist.items() if v == max(hist.values()) ] # List of all the keys with max

mode = min(maxList)

print mean
print median
print mode 
