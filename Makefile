EXEC   := sim
CC     := gcc

CFLAGS := -Wall
CFLAGS += -DCSFML_STATIC
CFLAGS += -Wno-deprecated-declarations

CFLAGS += $(EXTRA_CFLAGS)

SRC_DIR   := src
BUILD_DIR := build
OUT_DIR   := out

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJS    := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o, $(SOURCES))

LIB_DIR     := -Lextern/CSFML/lib
INCLUDE_DIR := -Iextern/CSFML/include

CFLAGS += $(INCLUDE_DIR)

LDFLAGS := $(LIB_DIR)
LDFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-main
LDFLAGS += -lopengl32 -lwinmm -lgdi32

.PHONY: all clean details build_dir out_dir re run

all: build_dir out_dir bin 

re: clean all run

bin: $(OBJS)
	@echo "LL		$^"
	@cp extern/CSFML/bin/* $(OUT_DIR)
	@$(CC) $^ $(LDFLAGS) -o $(OUT_DIR)/$(EXEC).exe  
	@echo "Finished compilation"

build_dir:
	@echo "Creating build directory"
	@mkdir -p $(BUILD_DIR)

out_dir:
	@echo "Creating out directory"
	@mkdir -p $(OUT_DIR)

run:
	@echo "Running..."
	@./$(OUT_DIR)/$(EXEC).exe

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "CC		$@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning"
	@rm -rf $(BUILD_DIR)
	@rm -rf $(OUT_DIR)/$(wildcard *.exe)
	@rm -rf $(OUT_DIR)/$(wildcard *.dll)

details:
	@echo "Sources: " $(SOURCES)
	@echo "Objects: " $(OBJS)
