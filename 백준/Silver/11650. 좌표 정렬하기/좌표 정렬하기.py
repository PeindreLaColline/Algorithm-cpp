N = int(input())
dot = []
for _ in range(N):
    dot.append(list(map(int, input().split())))
dot.sort()

for i in range(N):
    print(dot[i][0], dot[i][1])
