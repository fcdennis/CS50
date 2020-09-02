while True:
    height = int(input('Height: '))
    if 0 < height <= 8:
        break

width = height  - 1

for row in range(0, height):
    for element in range(width , 0, -1):
        print(" ", end="")
    width -= 1
    for element in range( 0, row + 1) :
        print("#", end="")
    print()