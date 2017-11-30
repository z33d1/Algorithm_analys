import timeit

# Matrix format printing
def printMat(mat):
    for i in range(0, len(mat)):
        for x in mat[i]:
            print("{:^3}".format(x), sep='', end='')
        print()


# Matrix creation size len1xlen2 for Levenstein alg
def makeMatForLev(len1, len2):
    mat = [[]] * len1
    for i in range(0, len1):
        mat[i] = [0] * len2

    for i in range(0, len(mat)):
        mat[i][0] = i
    for i in range(0, len(mat[0])):
        mat[0][i] = i

    return mat


# Levenstein alg with matrix, modifyed
def LevMod(s1, s2):
    mat = makeMatForLev(len(s1) + 1, len(s2) + 1)

    for j in range(1, len(mat[0])):
        for i in range(1, len(mat)):

            D3 = mat[i - 1][j - 1] + 1
            if s1[i - 1] == s2[j - 1]:
                D3 -= 1

            if (i > 1) and (j > 1):
                D4 = max(mat[i - 1][j] + 1, mat[i][j - 1] + 1, D3)
                if (s1[i - 1] == s2[j - 2]) and (s1[i - 2] == s2[j - 1]):
                    D4 = mat[i - 2][j - 2] + 1

                mat[i][j] = min(mat[i - 1][j] + 1, mat[i][j - 1] + 1, D3, D4)

            else:
                mat[i][j] = min(mat[i - 1][j] + 1, mat[i][j - 1] + 1, D3)

                #    printMat(mat)
    return mat[len(mat) - 1][len(mat[0]) - 1]




################## ТЕЛО ##################

rep_num = 1

# Один размер
s1 = 'Базовый'
s2 = 'Базовый'

print('L = 0', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Базавый'
print('L = 1', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Патовый'
print('L = 2', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Паровой'
print('L = 3', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Топовые'
print('L = 4', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Муратый'
print('L = 6', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

print()
# Разный размер
s1 = 'Базовый'
s2 = 'Базовый'

print('L = 0', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Базовы'
print('L = 1', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Базов'
print('L = 2', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Базо'
print('L = 3', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Баз'
print('L = 4', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number= rep_num, globals=globals()))

s2 = 'Ба'
print('L = 6', 1000*timeit.repeat('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                                  repeat = rep_num, number=rep_num, globals=globals()))

