CC = gcc
CFLAGS = -I./include -fPIC
SRCS = lib/add.c lib/subtract.c lib/multiply.c lib/divide.c
OBJS = $(SRCS:.c=.o)
LIBDIR = ./lib
INCDIR = ./include

all: static shared dynamic

# 정적 라이브러리 (.a) 생성
static: $(OBJS)
	ar rcs $(LIBDIR)/liboperations.a $(OBJS)
	$(CC) main.c -L$(LIBDIR) -loperations -o main_static $(CFLAGS)

# 공유 라이브러리 (.so) 생성
shared: $(OBJS)
	$(CC) -shared -o $(LIBDIR)/liboperations.so $(OBJS)
	$(CC) main.c -L$(LIBDIR) -loperations -o main_shared $(CFLAGS)

# 동적 라이브러리 실행 (공유 라이브러리 사용)
dynamic: shared
	$(CC) main.c -L$(LIBDIR) -loperations -o main_dynamic $(CFLAGS)

# 개별 소스 파일들에 대한 목적 파일 생성
%.o: %.c $(INCDIR)/operations.h
	$(CC) $(CFLAGS) -c $< -o $@

# 클린업
clean:
	rm -f $(LIBDIR)/*.o $(LIBDIR)/*.a $(LIBDIR)/*.so main_static main_shared main_dynamic
