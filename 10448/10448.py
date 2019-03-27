n = int(input())
answer=['' for z in range(n)]
result=[0 for i in range(45)]
result[0]=1
find=0
for i in range(1,45):
    result[i]=int(((i+1)*(i+2))/2)
#print(result)
def finding(num):
    naljiBreak = True
    for i in range(n):
        for j in range(45):
            for k in range(45):
                for l in range(45):
                    #print(result[j], result[k], result[l])
                    if(result[j]+result[k]+result[l] >num):
                        break
                    elif(result[j]+result[k]+result[l] ==num):
                        naljiBreak = False
                        #print("find!!: ",result[j],result[k],result[l])
                        return "1"
                if(naljiBreak == False):
                    break
            if(naljiBreak == False):
                break
        return "0"
for t in range(n):
    num = int(input())
    print(finding(num))




