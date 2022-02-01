C_FILES := $(wildcard ./*.c src/*.c src/*/*.c)

O_FILES := $(subst .c,.o,$(C_FILES))

COMPILED_FLAGS := -pedantic -W -Wall



INCLUDE_DIRECTORIES := -Iinclude



LIB_DIRECTORIES := -Llib



C_FLAGS := -I/usr/local/Cellar/mysql/8.0.28/include/mysql

LIB_FLAGS := -L/usr/local/Cellar/mysql/8.0.28/lib -L/usr/local/Cellar/openssl@1.1/1.1.1m/lib -L/usr/local/Cellar/zstd/1.5.2/lib -lmysqlclient -lz -lzstd -lssl -lcrypto -lresolv -lzstd



app: $(O_FILES)
	gcc -g $( C_FLAGS ) $(LIB_FLAGS) -o main main.c  &&  ./main




%.o: %.cpp
	g++ -c -s -w -Wall -std=c++11 $^ -o $@ $(INCLUDE_DIRECTORIES) $(COMPILED_FLAGS)



%.o: %.rc
	windres -c $^ -o $@ $(INCLUDE_DIRECTORIES)



clean:
	rm ./src/*.o ./src/*/*.o