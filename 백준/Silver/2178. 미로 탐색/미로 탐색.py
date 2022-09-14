def bfs():
    arr = []
    arr.append([0, 0])
    visit[0][0] = 1
    while arr:
        cur = arr.pop(0)
        x = cur[0]
        y = cur[1]
        if cur == [row-1, col-1]:
            print(visit[x][y])
            break
        now = visit[x][y]
        for i in range(4):
            wx = x + dir[i][0]
            wy = y + dir[i][1]
            if wx >= row or wy >= col or wx < 0 or wy < 0:
                continue
            if visit[wx][wy] == 0 and map[wx][wy] == '1':
                visit[wx][wy] = now + 1
                arr.append([wx, wy])

row, col = map(int, input().split())
map = [""] * row
visit = [[0] * col for _ in range(row)]
dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]

for i in range(row):
    map[i] = input()
    
bfs()
