CC=gcc
SRC_DIR=src
BUILD_DIR=build

all: run

$(BUILD_DIR)/client: $(SRC_DIR)/client.c $(SRC_DIR)/connection.h
	$(CC) -o $@ $(SRC_DIR)/client.c -I$(SRC_DIR) -lrt -lpthread

$(BUILD_DIR)/server: $(SRC_DIR)/server.c $(SRC_DIR)/connection.h
	$(CC) -o $@ $(SRC_DIR)/server.c -I$(SRC_DIR) -lrt -lpthread

start: $(BUILD_DIR)/server
	@echo "Starting server..."
	@$(BUILD_DIR)/server & echo $$! > .server.pid
	@sleep 0.1

stop: $(BUILD_DIR)/client
	@echo "Stopping server..."
	@kill `cat .server.pid`
	@rm .server.pid /dev/shm/posix-shared-mem-example /dev/shm/sem.sem-buffer-count /dev/shm/sem.sem-mutex /dev/shm/sem.sem-spool-signal

client: $(BUILD_DIR)/client
	$(BUILD_DIR)/client

run: | start client stop
