OBJS = uimain.o tokenizer.o history.o
CFLAGS =-g -O3

all: tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h

clean: 
	rm -f *.o tokenizer

run:tokenizer
	./tokenizer

