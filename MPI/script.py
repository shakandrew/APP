import os
import sys
include_str = "#include<stdio.h>\n#include<mpi.h>\n#include <sys/time.h>\n"

test1 = [['8000000','8','8','8'],
        ['8','8000000','8000000','8'],
        ['800','800','800','800']]

test2 = list()
for i in range(100, 2001, 100):
    test2.append([str(i),str(i),str(i),str(i)])

def some(elems, file_in, file_out):
    a_rows = "#define NUM_ROWS_A " + elems[0] + "\n"
    a_cols = "#define NUM_COLUMNS_A " + elems[1] + "\n"
    b_rows = "#define NUM_ROWS_B " + elems[2] + "\n"
    b_cols = "#define NUM_COLUMNS_B " + elems[3] + "\n"
    lines = None
    with open(file_in) as f:
        lines = f.readlines()
    f = open(file_out,"w")

    f.write(include_str + a_rows + a_cols + b_rows + b_cols)

    for elem in lines:
        f.write(elem)
    f.close()

test = test2

if sys.argv[1] == "mpi":
    for mode in (3,5,9):
        print("Mode: " + str(mode-1))
        for elems in test:
            some(elems, "template_mpi.txt", "new.c")
            os.system('mpicc -o prog new.c -O3')
            os.system('mpirun -n ' + j +' ./prog')
else:
    print("Mode: 1")
    for elems in test:
        some(elems, "template_seq.txt", "circ.c")
        os.system("gcc -o prog circ.c -O3")
        os.system("./prog")
