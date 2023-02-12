compile:
	gcc -Wall -lm hw1.c -o hw1

test_all: test1 test2 test3 test4 test5 test6 test7

test1:
	printf "#define NUM_STUDENTS 5 \n#define NUM_QUESTIONS 4 \n#define MIN_CHOICE 'A' \n#define MAX_CHOICE 'Z'" > hw1.h
	gcc -Wall -lm hw1.c -o hw1
	cd hw1tests ;\
	../hw1 <in_5_4_A_Z__C_0.0 >myout ;\
	diff out_5_4_A_Z__C_0.0 myout

test2:
	printf "#define NUM_STUDENTS 5 \n#define NUM_QUESTIONS 3 \n#define MIN_CHOICE 'A' \n#define MAX_CHOICE 'Z'" > hw1.h
	gcc -Wall -lm hw1.c -o hw1
	cd hw1tests ;\
	../hw1 <in_5_3_A_Z__C_-0.25 >myout ;\
	diff out_5_3_A_Z__C_-0.25 myout

test3:
	printf "#define NUM_STUDENTS 2 \n#define NUM_QUESTIONS 2 \n#define MIN_CHOICE 'E' \n#define MAX_CHOICE 'G'" > hw1.h
	gcc -Wall -lm hw1.c -o hw1
	cd hw1tests ;\
	../hw1 <in_2_2_E_G__G_0.0 >myout ;\
	diff out_2_2_E_G__G_0.0 myout

test4:
	printf "#define NUM_STUDENTS 10 \n#define NUM_QUESTIONS 5 \n#define MIN_CHOICE 'W' \n#define MAX_CHOICE 'Z'" > hw1.h
	gcc -Wall -lm hw1.c -o hw1
	cd hw1tests ;\
	../hw1 <in_10_5_W_Z__Y_-0.15 >myout ;\
	diff out_10_5_W_Z__Y_-0.15 myout

test5:
	printf "#define NUM_STUDENTS 10 \n#define NUM_QUESTIONS 4 \n#define MIN_CHOICE 'A' \n#define MAX_CHOICE 'E'" > hw1.h
	gcc -Wall -lm hw1.c -o hw1
	cd hw1tests ;\
	../hw1 <in_10_4_A_E__E_-0.25 >myout ;\
	diff out_10_4_A_E__E_-0.25 myout

test6:
	printf "#define NUM_STUDENTS 50 \n#define NUM_QUESTIONS 20 \n#define MIN_CHOICE 'A' \n#define MAX_CHOICE 'Z'" > hw1.h
	gcc -Wall -lm hw1.c -o hw1
	cd hw1tests ;\
	../hw1 <in_50_20_A_Z__Z_-0.038 >myout ;\
	diff out_50_20_A_Z__Z_-0.038 myout

test7:
	printf "#define NUM_STUDENTS 5000 \n#define NUM_QUESTIONS 40 \n#define MIN_CHOICE 'A' \n#define MAX_CHOICE 'Z'" > hw1.h
	gcc -Wall -lm hw1.c -o hw1
	cd hw1tests ;\
	../hw1 <in_5000_40_A_Z__E_-0.2 >myout ;\
	diff out_5000_40_A_Z__E_-0.2 myout