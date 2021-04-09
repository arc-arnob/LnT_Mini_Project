PROJ_NAME = vaccine_proj
TEST_PROJ_NAME = Test_$(PROJ_NAME)

SRC =src/create_ll.c \
src/display_ll.c \
src/insert_end.c \
src/find_by_id.c \
src/update_record.c \
src/indexFile.c \
src/validate_id.c

TEST_SRC = test/test.c \
unity/unity.c 
INC_H = inc
INC_T = unity

ifdef OS
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
	  EXEC = out
   endif
endif

all:
	gcc -I $(INC_H) $(SRC) main.c -o $(PROJ_NAME).$(EXEC)

run:
	$(PROJ_NAME).exe
test:
	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(TEST_PROJ_NAME).exe

cppcheck:
	cppcheck --enable=all $(SRC)

valgrind:
	valgrind ./$(PROJ_NAME).out
debug:
	gcc -I $(INC_H) $(SRC) main.c -g -o $(PROJ_NAME).exe
	gdb $(PROJ_NAME).exe
