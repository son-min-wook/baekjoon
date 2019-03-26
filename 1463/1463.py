n = int(input())
result=[1000000 for i in range(1000001)]
result[1]=0
for i in range(1,n):
    result[i+1]=min(result[i+1],result[i]+1)
    if(i*2 <=1000000):
        result[i*2]=min(result[i*2],result[i]+1)
    if(i * 3 <= 1000000): result[i * 3]=min(result[i * 3], result[i]+1)
print(result[n])
