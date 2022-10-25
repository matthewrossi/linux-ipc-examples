CC=gcc
CFLAGS=-I$(SRC_DIR)
SRC_DIR=src
BUILD_DIR=build
TARGET=main

all: run

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)

$(BUILD_DIR)/$(TARGET): $(BUILD_DIR)/main.o
	$(CC) -o $@ $^ $(CFLAGS)

run: $(BUILD_DIR)/$(TARGET)
	@$(BUILD_DIR)/$(TARGET) "This is a string"
