case=int(input())
stack=[]
len=-1
for i in range(case):
    command=input()
    if(" " in command):
        order = command.split(" ")[0]
        number = int(command.split(" ")[1])
    else:
        order = command
    if(order=="push"):
        stack.append(number)
        len+=1
    elif(order=="top"):
        if(len==-1):
            print(-1)
        else:
            print(stack[len])
    elif(order=="size"):
        print(len+1)
    elif(order=="empty"):
        if(len==-1):
            print(1)
        else:
            print(0)
    elif(order=="pop"):
        if(len!=-1):
            print(stack[len])
            len = len - 1
            stack.pop()
        else:
            print(-1)


