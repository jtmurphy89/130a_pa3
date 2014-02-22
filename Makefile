#Kevin Malta, perm: 4652251
#Jason Murphy, perm: 5198460

OBJS	:=	$(addsuffix	.o,	minTree)

all:	$(OBJS)	sbSocialSpan.cpp
	clang++	$(OBJS)	sbSocialSpan.cpp	-g	-o	prog3

%.o:	%.cpp
	clang++	-c	$<

clean:
	rm	-f 	*.o	prog3
