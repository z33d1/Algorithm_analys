import timeit
import time


# Matrix format printing
def printMat(mat):
    for i in range(0, len(mat)):
        for x in mat[i]:
            print("{:^3}".format(x), sep = '', end = '')
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


# Levenstein alg with matrix, basic
def LevBasic(s1, s2):
    mat = makeMatForLev(len(s1) + 1, len(s2) + 1)

    for j in range(1, len(mat[0])):
        for i in range(1, len(mat)):

            D3 = mat[i - 1][j - 1] + 1
            if s1[i - 1] == s2[j - 1]:
                D3 -= 1
            mat[i][j] = min(mat[i - 1][j] + 1, mat[i][j - 1] + 1, D3)

#    printMat(mat)
    return mat[len(mat) - 1][len(mat[0]) - 1]


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


# Levenstein alg with matrix, recursive
def LevRecur(s1, s2):
    if (len(s1) <= 1) and (len(s2) <= 1):
        if (len(s1) == 0) and (len(s2) == 0):
            return 0
        elif len(s1) != len(s2):
            return 1

        if (s1[0] == s2[0]):
            return 0
        else:
            return 1

    if (len(s1) > 1) and (len(s2) > 1):
        D3 = LevRecur(s1[:len(s1) - 1], s2[:len(s2) - 1])
        if s1[len(s1) - 1] != s2[len(s2) - 1]:
            D3 += 1
    else:
        D3 = -1

    if len(s1) > 1:
        D1 = LevRecur(s1[:len(s1) - 1], s2) + 1
    else:
        D1 = -1

    if len(s2) > 1:
        D2 = LevRecur(s1, s2[:len(s2) - 1]) + 1
    else:
        D2 = -1

    if D1 < 0:
        D1 = max(D2, D3)
    if D2 < 0:
        D2 = max(D1, D3)
    if D3 < 0:
        D3 = max(D1, D2)

    return min(D1, D2, D3)


def main():
    s1 = input('Enter s1: ')
    s2 = input('Enter s2: ')
    print()

    for_output = (len(s2) + 1) * 3
    rep_num = int(50)

    basic = LevBasic(s1, s2)
    print('\nBasic:', basic)
    print('Basic time ({:d} reps):'.format(rep_num),
          timeit.timeit('LevBasic(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                        number = rep_num, globals=globals()))

    print('-' * for_output)
    print()

    modified = LevMod(s1, s2)
    print('\nModified:', modified)
    print('Modified time ({:d} reps)'.format(rep_num),
          timeit.timeit('LevMod(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                        number = rep_num, globals=globals()))

    print('-' * for_output)
    print()

    recur = LevRecur(s1, s2)
    print('\nRecur:', recur)

    print('Recur time ({:d} reps): {:f}'.format(int(rep_num),
          timeit.timeit('LevRecur(s1, s2)', setup='s1 = "{:s}"; s2 = "{:s}"'.format(s1, s2),
                        number = rep_num, globals=globals())))
    print()


main()
