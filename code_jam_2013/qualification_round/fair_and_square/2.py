import sys

fin = sys.stdin
fout = sys.stdout
FLORENTINE = 9

def bzzt(v, brzz):
    result = 0
    for i1 in range(0, len(v) - brzz, 1):
        result *= 10
        result += v[i1]
    for i1 in range(len(v) - 1, -1, -1):
        result *= 10
        result += v[i1]
    return result

def transform01(v):
    return bzzt(v, 1)

def transform02(v):
    return bzzt(v, 0)

def count01(v, A, B, first_empty_index, sum_so_far):
    result = 0
    if (sum_so_far <= FLORENTINE):
        n = len(v)
        if first_empty_index >= n:
            temp1 = transform01(v)
            temp1 *= temp1
            if (A <= temp1) and (temp1 <= B):
                result += 1
                fout.write("result += 1 for temp1 = " + str(temp1) +
                           ", first_empty_index = " +
                           str(first_empty_index) + "\n")
                pass
            pass
        else:
            for i1 in range(0, 10, 1):
                v[first_empty_index] = i1
                if (first_empty_index + 1) < n:
                    result += count01(v,
                                      A,
                                      B,
                                      first_empty_index + 1,
                                      sum_so_far + 2 * i1 * i1)
                    pass
                elif (first_empty_index >= n or
                      (sum_so_far + i1 * i1) <= FLORENTINE):
                    temp1 = transform01(v)
                    temp1 *= temp1
                    if (A <= temp1) and (temp1 <= B):
                        result += 1
                        fout.write("result += 1 for temp1 = " + str(temp1)
                                   + ", first_empty_index = " +
                                   str(first_empty_index) + "\n")
                        pass
                    pass
                pass
            pass
        pass
    return result

def dotestcase(i1):
    [A, B] = fin.readline().split()
    A = int(A)
    B = int(B)
    result = 0
    i2 = 1
    i3 = 10
    while (i3 <= 10 * B):
        if (i3 >= A):
            fout.write("i2 = " + str(i2) + "\n")
            v = list(range(0, i2, 1))
            for i4 in range(1, 10, 1):
                v[0] = i4
                if i2 == 1:
                    result += count01(v, A, B, 1, i4 * i4)
                    pass
                else:
                    result += count01(v, A, B, 1, 2 * i4 * i4)
                    pass
                pass
            pass
        i2 += 1
        i3 *= 100
        pass
    fout.write("Case #" + str(i1 + 1) + ": " + str(result) + "\n")
    pass

T = int(fin.readline())
for i1 in range(0, T, 1):
    dotestcase(i1)
    pass
