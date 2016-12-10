import sys

lines = sys.stdin.readlines()

N = [int(x) for x in lines[1].split()]
W = [int(x) for x in lines[2].split()]

weightedSum = (float(sum([N[i]*W[i] for i in range(len(N))])))/sum(W)

print round(weightedSum ,1)
