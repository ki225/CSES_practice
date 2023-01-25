total_move_path=0
#possible_path=1
canpass=[] #如果可以走就是1，途中發現不能走就是0

#從文件中讀取迷宮矩陣
def get_maze():
    f = open('input.txt', 'r')
    maze = []
    for lines in f.readlines():
        maze.append(lines.split())
    f.close()
    return maze

#move_path=[]

def move(maze,start): #判斷能否移動
    i=start[0]
    j=start[1]
    if maze[i][j]=='1':
        return True
    else:
        canpass.append(0)
        return False


def find_path(maze,start,end):
    move_direct=[(1,0),(0,1)] #往下或往右
    if start == end:
        #path.append(start)
        #total_move_path.append(path)
        #print(1)
        canpass.append(1)
        return True
    
    #往右
    next_start1=(start[0]+move_direct[0][0],start[1]+move_direct[0][1])
    #往下
    next_start2=(start[0]+move_direct[1][0],start[1]+move_direct[1][1])
    if move(maze,next_start1) and move(maze,next_start2):
        find_path(maze,next_start1,end)
        find_path(maze,next_start2,end)
        return True
    elif move(maze,next_start1):
        if find_path(maze,next_start1,end):
            return True
        return True
    elif move(maze,next_start2):
        if find_path(maze,next_start2,end):
            return True
    else:
        return False

map=get_maze()
#possible_path=1
if find_path(map,start=(1,1),end=(5,5)):
        #print(move_path[::-1]) 。#遞迴法下的輸出是用「stack」，因為要先執行下一個 Function 直到終止條件之後再一個一個 return 回上層
    for i in canpass:
        if i == 1:
            total_move_path+=1
    print(total_move_path)

else:
    find_path(map,start=(1,1),end=(5,5)) == False #Positional argument cannot appear after keyword argumentsPylance
    print(0)
