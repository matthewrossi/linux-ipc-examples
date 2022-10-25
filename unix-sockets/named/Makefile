CC=gcc
SRC_DIR=src
BUILD_DIR=build

all: run

$(BUILD_DIR)/client: $(SRC_DIR)/client.c $(SRC_DIR)/connection.h
	$(CC) -o $@ $(SRC_DIR)/client.c -I$(SRC_DIR)

$(BUILD_DIR)/server: $(SRC_DIR)/server.c $(SRC_DIR)/connection.h
	$(CC) -o $@ $(SRC_DIR)/server.c -I$(SRC_DIR)

start: $(BUILD_DIR)/server
	@$(BUILD_DIR)/server & echo "Server starting..."
	@sleep 0.1

stop: $(BUILD_DIR)/client
	@$(BUILD_DIR)/client DOWN 2> /dev/null || echo "Server shutting down..."

ARGS=0 1 2 3 4 5 6 7 8 9
query: $(BUILD_DIR)/client
	$(BUILD_DIR)/client $(ARGS)

run: | start query stop
