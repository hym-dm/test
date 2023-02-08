
CFLAGS=-g
BIN1=exe1
BIN2=exe2

all:$(BIN1) $(BIN2) 
$(BIN2):test.c
		gcc $^ -o $@ $(CFLAGS)
$(BIN1):main.c a.c b.c c.c d.c
		gcc $^ -o $@
clean: 
	rm main test
