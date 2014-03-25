CC        = gcc
CFLAGS    = -O2 -lm -ansi

SRC_DIR   = ./src
BUILD_DIR = ./build
INC       = -I ./include

TARGET    = single_cycle
SRCS      = main.c fileIO.c \
			reg.c  mem.c    \
			core.c snap.c	\
			inst.c
OBJS      = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

RPT       = debug.out snapshot.rpt error_dump.rpt

all:$(TARGET)
	@echo "** Compile Finished **"
$(TARGET): $(OBJS)
	@echo "Compiling $<"
	@$(CC) -o $@ $(OBJS) $(INC) 
	
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $<" 
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@  
.PONNY = clean
clean:
	@-rm -f -r $(TARGET) $(BUILD_DIR) $(RPT) 
