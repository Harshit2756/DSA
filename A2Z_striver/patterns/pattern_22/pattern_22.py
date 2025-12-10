# Implementation of pattern 21 in Python

def pattern21(n):
    for i in range(n, 0, -1):
        for j in range(1, i + 1):
            print(j, end=" ")
        print()

if __name__ == "__main__":
    n = 5
    pattern21(n)