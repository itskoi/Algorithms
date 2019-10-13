# Author: @itskoi

# Functions

def initCell(array, dp):
    dp[1][1] = array[1][1]
    for j in range(2, m + 1, 1):
        dp[1][j] = dp[1][j - 1] + array[1][j]
    for i in range(2, n + 1, 1):
        dp[i][1] = dp[i - 1][1] + array[i][1]
    for i in range(2, n + 1, 1):
        for j in range(2, m + 1, 1):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + array[i][j]

def getSum(x, y, z, t, dp):
    return dp[z][t] - dp[x - 1][t] - dp[z][y - 1] + dp[x - 1][y - 1]

# Main
inp = input().split(' ')
n = int(inp[0])
m = int(inp[1])

array = [[0 for j in range(m + 1)] for i in range(n + 1)]
dp = [[0 for j in range(m + 1)] for i in range(n + 1)]

for i in range(n):
    inp = input().split(' ')
    for j in range(m):
        array[i + 1][j + 1] = int(inp[j])

initCell(array, dp)

Q = int(input())
for i in range(Q):
    inp = input().split(' ')
    x = int(inp[0])
    y = int(inp[1])
    print(getSum(1, 1, x, y, dp))
