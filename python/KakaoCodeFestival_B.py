import math

N, K = map(int,input().split())
fav = list(map(int,input().split()))
nums = []
def mean(values):
  return sum(values, 0.0) / len(values)

def std(values):
  sum = 0.0
  meanValue = mean(values)
  for i in range(len(values)):
    sum = (values[i] - meanValue)**2
  sd = math.sqrt(sum / (len(values)))
  return sd

for i in range(N-K+1):
  nums.append(std(fav[i:i+K]))
print(min(nums))
