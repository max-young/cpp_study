def insertSpaceToString(myStr, spaceList):
    result = []
    index = 0
    for i in myStr:
        if index in spaceList:
            result.append(' ')
        result.append(i)
        index += 1
    return "".join(result)

myStr = "icodeinpython"
spaceList = [1, 5, 7, 9]
print(insertSpaceToString(myStr, spaceList))