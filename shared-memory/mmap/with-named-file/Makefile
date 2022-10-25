CC=gcc
SRC_DIR=src
BUILD_DIR=build

all: run

$(BUILD_DIR)/receiver: $(SRC_DIR)/receiver.c $(SRC_DIR)/connection.h
	$(CC) -o $@ $(SRC_DIR)/receiver.c -I$(SRC_DIR)

$(BUILD_DIR)/sender: $(SRC_DIR)/sender.c $(SRC_DIR)/connection.h
	$(CC) -o $@ $(SRC_DIR)/sender.c -I$(SRC_DIR)

send: $(BUILD_DIR)/sender
	@ echo "Sending..."
	@$(BUILD_DIR)/sender

receive: $(BUILD_DIR)/receiver
	@ echo "Receiving..."
	@$(BUILD_DIR)/receiver

run: | send receive
