a = input()
col = a.split(" ")[0]
row = a.split(" ")[1]
field = [[0 for j in range(int(row))] for j in range(int(col))]
check_field = [[0 for j in range(int(row)-2)] for j in range(int(col)-2)]
iceburg = [[0 for j in range(int(row)-2)] for j in range(int(col)-2)]
iceburg_ocean = [[0 for j in range(int(row)-2)] for j in range(int(col)-2)]
def DFS(findroute, startx,starty,lengthx,lengthy,checktable):
    noway=0
    if(int(checktable[startx][starty])==1 or int(findroute[startx][starty])==0):   #들린적있으면 패스
        if(int(findroute[startx][starty])==0):
            checktable[startx][starty]=0
        return checktable
    else:
        checktable[startx][starty]=1
        if(startx+1 >= 0 and startx+1<lengthx):
            if(checktable[startx+1][starty] ==2):  #아래
                checktable = DFS(findroute, startx + 1, starty, lengthx, lengthy, checktable)
        if(starty-1 >= 0):
            if (checktable[startx][starty-1] == 2):  #왼쪽
                checktable = DFS(findroute, startx, starty-1, lengthx, lengthy, checktable)
        if(starty+1 >= 0 and starty+1<lengthy):
            if (checktable[startx][starty+1] == 2):  #오른쪽
                checktable = DFS(findroute, startx, starty + 1, lengthx, lengthy, checktable)
        if(startx-1 >=0 ):  #이때 당시의 값으로 error값을 찾음 ㅅㅂ
            if (checktable[startx-1][starty] == 2 ):
                checktable = DFS(findroute,startx-1,starty,lengthx,lengthy,checktable)
        if((startx==0 or startx==lengthx-1) and (starty==0 or starty==lengthy-1)):
            if (startx + 1 < lengthx and checktable[startx + 1][starty] != 2):
                noway = noway + 1
            if (starty + 1 < lengthy and checktable[startx][starty + 1] != 2):
                noway = noway + 1
            if (starty - 1 >= 0 and checktable[startx][starty - 1] != 2):
                noway = noway + 1
            if (startx - 1 >= 0 and checktable[startx - 1][starty] != 2):
                noway = noway + 1
            if(noway==2):
                return checktable
        elif ((startx == 0 or startx == lengthx-1) or (starty == 0 or starty == lengthy-1)):
            if (startx + 1 < lengthx and checktable[startx + 1][starty] != 2):
                noway = noway + 1
            if (starty + 1 < lengthy and checktable[startx][starty + 1] != 2):
                noway = noway + 1
            if (starty - 1 >= 0 and checktable[startx][starty - 1] != 2):
                noway = noway + 1
            if (startx - 1 >= 0 and checktable[startx - 1][starty] != 2):
                noway = noway + 1
            if (noway == 3):
                return checktable
        else:
            if (startx + 1 < lengthx and checktable[startx + 1][starty] != 2):
                noway = noway + 1
            if (starty + 1 < lengthy and checktable[startx][starty + 1] != 2):
                noway = noway + 1
            if (starty - 1 >= 0 and checktable[startx][starty - 1] != 2):
                noway = noway + 1
            if (startx - 1 >= 0 and checktable[startx - 1][starty] != 2):
                noway = noway + 1
            if (noway == 4):
                return checktable

for i in range(int(col)):
    line = input()
    for j in range(int(row)):
        field[i][j]=line.split(" ")[j]          #인풋 저장
        if(i>0 and i<int(col)-1 and j>0 and j<int(row)-1):
            if(int(line.split(" ")[j]) != int(0)):
                iceburg[i-1][j-1] = line.split(" ")[j]
            else:
                iceburg[i - 1][j - 1] = 0      #빙산값만 저장

#인풋 끝
ocean = 0  #각 빙산마다 주변 바다 몇갠지
ice_count = (int(row)-2) *(int(col)-2)
chang_ocean = 0#  각 년도마다 바다로 바뀐 빙산이 몇개인지 확인
year=0
island=0
single=0
while chang_ocean!=ice_count:
    cont = 0  # 조각갯수위해
    iceburg_sample = [[2 for j in range(int(row) - 2)] for j in range(int(col) - 2)]
    year=year+1
    chang_ocean=0
    for k in range(int(col)-2):        #빙산의 세로 줄씩
        for l in range(int(row)-2):    #빙산 가로의 가로 하나씩
            if(iceburg[k][l] ==0):
                iceburg_ocean[k][l] = ocean
            else:
                if(len(iceburg)==1):
                    single=1
                else:
                    if (k ==0 or k ==len(iceburg)-1) and (l ==0 or l ==int(row)-3):   #빙산 모서리들만
                        ocean = ocean+2  #위옆은 무조건 바다
                        if(k==0):
                            if(l==0):              #위왼쪽 모서리
                                if(iceburg[k][l+1]==0):
                                    ocean=ocean+1
                                if (iceburg[k+1][l] == 0):
                                    ocean = ocean + 1
                            else:                  #위오른쪽 모서리
                                if (iceburg[k][l - 1] == 0):
                                    ocean = ocean + 1
                                if (iceburg[k + 1][l] == 0):
                                    ocean = ocean + 1
                        else:             #아래 왼쪽 모서리
                            if (l == 0):
                                if (iceburg[k][l +1] == 0):
                                    ocean = ocean + 1
                                if (iceburg[k-1][l] == 0):
                                    ocean = ocean + 1
                            else:           #아래오른쪽모서리
                                if (iceburg[k][l - 1] == 0):
                                    ocean = ocean + 1
                                if (iceburg[k - 1][l] == 0):
                                    ocean = ocean + 1
                        iceburg_ocean[k][l]=ocean
                        ocean=0
                    elif((k==0 or k ==len(iceburg)-1) or (l==0 or l ==int(row)-3)):
                        ocean = ocean +1           #둘레부분은 +1
                        if(k==0):    #맨위 테두리
                            if (iceburg[k][l - 1] == 0):
                                ocean = ocean + 1
                            if (iceburg[k][l + 1] == 0):
                                ocean = ocean + 1
                            if (iceburg[k+1][l] == 0):
                                ocean = ocean + 1
                        elif(k==len(iceburg)-1):    #맨아래 테두리
                            if (iceburg[k][l - 1] == 0):
                                ocean = ocean + 1
                            if (iceburg[k][l + 1] == 0):
                                ocean = ocean + 1
                            if (iceburg[k-1][l] == 0):
                                ocean = ocean + 1
                        elif(l==0):   #맨왼쪽 테두리
                            if (iceburg[k][l + 1] == 0):
                                ocean = ocean + 1
                            if (iceburg[k-1][l] == 0):
                                ocean = ocean + 1
                            if (iceburg[k+1][l] == 0):
                                ocean = ocean + 1
                        else:      #맨오른쪽 테두리
                            if (iceburg[k][l-1] == 0):
                                ocean = ocean + 1
                            if (iceburg[k-1][l] == 0):
                                ocean = ocean + 1
                            if (iceburg[k+1][l] == 0):
                                ocean = ocean + 1
                        iceburg_ocean[k][l] = ocean
                        ocean=0
                    else:  #내부애들
                        if (iceburg[k][l - 1] == 0):
                            ocean = ocean + 1
                        if (iceburg[k][l + 1] == 0):
                            ocean = ocean + 1
                        if (iceburg[k - 1][l] == 0):
                            ocean = ocean + 1
                        if (iceburg[k + 1][l] == 0):
                            ocean = ocean + 1
                        iceburg_ocean[k][l] = ocean
                        ocean = 0
    if(single ==1):
        print(0)
        break
    for k in range(int(col)-2):
        for l in range(int(row)-2):
            iceburg[k][l]=int(iceburg[k][l])-int(iceburg_ocean[k][l])
            if(iceburg[k][l]<=0):
                iceburg[k][l]=0
                chang_ocean=chang_ocean+1
    # 주변 바다갯수 빼기 완료
    if(chang_ocean<int(col)-2):
        island = island + 1
        continue
    else:
        for k in range(int(col)-2):
            for l in range(int(row)-2):
                if(iceburg[k][l] != 0 and iceburg_sample[k][l]==2):
                    iceburg_sample= DFS(iceburg,k,l,int(col)-2,int(row)-2,iceburg_sample)  # 숫자이고 들린적이없어서 0이면
                    cont=cont+1
    if (cont > 1):
        print(year)
        break
    else:
        island=island+1
if(year == island):
    print(0)