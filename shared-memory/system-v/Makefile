CC=gcc
SRC_DIR=src
BUILD_DIR=build

all: run

$(BUILD_DIR)/client: $(SRC_DIR)/client.c $(SRC_DIR)/connection.h
	$(CC) -o $@ $(SRC_DIR)/client.c -I$(SRC_DIR)

$(BUILD_DIR)/server: $(SRC_DIR)/server.c $(SRC_DIR)/connection.h
	$(CC) -o $@ $(SRC_DIR)/server.c -I$(SRC_DIR)

start: $(BUILD_DIR)/server
	@echo "Starting server..."
	@touch /tmp/shared_memory_key /tmp/sem-mutex-key /tmp/sem-buffer-count-key /tmp/sem-spool-signal-key
	@$(BUILD_DIR)/server & echo $$! > .server.pid
	@sleep 0.1

stop: $(BUILD_DIR)/client
	@echo "Stopping server..."
	@kill `cat .server.pid`
	@rm .server.pid /tmp/shared_memory_key /tmp/sem-mutex-key /tmp/sem-buffer-count-key /tmp/sem-spool-signal-key

client: $(BUILD_DIR)/client
	$(BUILD_DIR)/client

run: | start client stop
