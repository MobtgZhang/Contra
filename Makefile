SOURCE_PATH=source
TARGET_PATH=bin

EXECUTE_FILE=$(TARGET_PATH)/contra

all:
	mkdir -p $(TARGET_PATH)
	g++ -o $(EXECUTE_FILE) $(SOURCE_PATH)/*.cpp -w -lSDL2 -lSDL_mixer -lSDL_image
clean:
	rm -rf $(TARGET_PATH)
