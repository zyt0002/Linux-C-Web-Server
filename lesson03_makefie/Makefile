#define variable
src = $(wildcard ./*.c)
objs = $(patsubst %.c,%.o, $(src))

target = app
$(target):$(objs)
	$(CC) $(objs) -o $(target)

.PHONY:clean
clean:
	rm $(objs) -f
