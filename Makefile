.SILENT:

################################################################################

include Makefile.inc

################################################################################

F_CPU = 16000000UL

CXX = avr-g++

TARGET = flash.hex

DEFINES = -DF_CPU=$(F_CPU) -DBOARD_ID=$(BOARD_ID)

LNKFLAGS = -mmcu=$(MCU)
CXXFLAGS = -g -O2 -Wall -mmcu=$(MCU) $(DEFINES)

INCLUDES = -I./

SOURCES = \
	main.cpp

################################################################################

include common/Makefile.inc
include EEPROM/Makefile.inc
include Encoder/Makefile.inc
include HD44780/Makefile.inc
include USART/Makefile.inc

################################################################################

DIRS = $(addprefix ./, $(LIBS))

################################################################################

all: $(TARGET)

$(TARGET): cppfiles
	@echo 'Linking...'
	@$(CXX) -o $(TARGET) $(LNKFLAGS) *.o $(addsuffix /*.o, $(DIRS))

################################################################################

cppfiles: $(SOURCES:.cpp=.o)

.SUFFIXES: .cpp .o

.cpp.o: $(SOURCES)
	@echo 'Compiling file: $*.cpp'
	@$(CXX) $(INCLUDES) -o $*.o -c $(CXXFLAGS) $*.cpp

################################################################################

install: all
	@for PORT in /dev/ttyACM0 /dev/ttyACM1 /dev/ttyUSB0 /dev/ttyUSB1; do \
		if ( test -e $$PORT ); then \
			if ( test $(BOARD_ID) -eq 3 ); then \
				stty -F $$PORT ispeed 1200 ospeed 1200 && avrdude -v -v -v -v -c $(PROGRAMMER) -p $(PART) -P $$PORT -D -U flash:w:$(TARGET); \
			else \
				avrdude -v -v -v -v -c $(PROGRAMMER) -p $(PART) -P $$PORT -b$(BAUD_RATE) -D -U flash:w:$(TARGET); \
			fi; \
			break; \
		fi \
	done;

erase:
	@avrdude -c $(PROGRAMMER) -p $(PART) -P $(PORT) -e

################################################################################

clean:
	@for DIR in $(DIRS); do \
		rm -f $$DIR/*.o; \
	done
	@rm -f *.o
	@rm -f *.hex
