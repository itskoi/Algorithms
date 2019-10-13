# Author: @itskoi
import math

# Variables
bit = []
phi = []
pillai = []
array = []
MOD = 1000000007
MAXRANGE = 500001

# Functions
def Modulo(val):
    return int((val % MOD + MOD) % MOD)

def TotientFunction():
    for i in range(0, MAXRANGE):
        phi.append(i)
    
    for i in range(2, MAXRANGE, 1):
        if (phi[i] == i): # Prime number
            for j in range(i, MAXRANGE, i):
                phi[j] -= phi[j] / i



def SumGCD():
    for i in range(0, MAXRANGE):
        pillai.append(0)
        
    for i in range(1, MAXRANGE, 1):
        for j in range(i, MAXRANGE, i):
             pillai[j] = (pillai[j] + (i * phi[j // i]) % MOD) % MOD

# Setup Fenwick Tree

def initBIT(N):
    for i in range(N + 1):
        bit.append(0)

def updateBIT(idx, val, N):
    while (idx <= N):
        bit[idx] = (bit[idx] + val) % MOD
        idx += idx & (-idx)
    return

def queryBIT(l, r, N):
    result1 = result2 = 0
    l -= 1

    while (l > 0):
        result1 = (result1 + bit[l]) % MOD
        l -= l & (-l)

    while (r > 0):
        result2 = (result2 + bit[r]) % MOD
        r -= r & (-r)

    return int(result2 - result1 + MOD) % MOD

# Main

# *Initialize
TotientFunction()
SumGCD()

# *Input
N = int(input())
str = input().split(' ') 
for x in str:
    val = int(x)
    array.append(val)

# *Setup BIT
initBIT(N)
for i in range(0, N):
    updateBIT(i + 1, pillai[array[i]], N)

# *Query
Q = int(input())
for i in range(Q):
    inp = input().split(" ")
    if (inp[0] == 'C') :
        print(queryBIT(int(inp[1]), int(inp[2]), N));
    else :
        updateBIT(int(inp[1]), -pillai[array[int(inp[1]) - 1]], N);
        array[int(inp[1]) - 1] = int(inp[2])
        updateBIT(int(inp[1]), pillai[array[int(inp[1]) - 1]], N);