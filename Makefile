CC = g++
CFLAGS = -g

all:
	$(CC) $(CFLAGS) -o app.o main.cpp extractQuestion.cpp question.cpp quiz.cpp

clean:
	rm -rf *.o