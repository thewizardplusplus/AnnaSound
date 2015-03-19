SOURCE_BASE = source/thewizardplusplus/
ANNA_SOURCE = $(SOURCE_BASE)anna/
ANNA_SOUND_SOURCE = $(ANNA_SOURCE)sound/
ANNA_SOUND_EXCEPTIONS_SOURCE = $(ANNA_SOUND_SOURCE)exceptions/
OBJECTS = \
	$(SOURCE_BASE)utils/ByteOrderTester.o \
	$(ANNA_SOURCE)maths/Maths.o \
	$(ANNA_SOUND_SOURCE)AudioDevice.o \
	$(ANNA_SOUND_SOURCE)OpenALAudioDevice.o \
	$(ANNA_SOUND_SOURCE)Listener.o \
	$(ANNA_SOUND_SOURCE)OpenALListener.o \
	$(ANNA_SOUND_SOURCE)Source.o \
	$(ANNA_SOUND_SOURCE)OpenALSource.o \
	$(ANNA_SOUND_SOURCE)PCMData.o \
	$(ANNA_SOUND_SOURCE)Buffer.o \
	$(ANNA_SOUND_SOURCE)OpenALBuffer.o \
	$(ANNA_SOUND_SOURCE)Loader.o \
	$(ANNA_SOUND_SOURCE)WavLoader.o \
	$(ANNA_SOUND_SOURCE)PCMDataManager.o \
	$(ANNA_SOUND_SOURCE)Sound.o \
	$(ANNA_SOUND_SOURCE)SoundManager.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)SoundException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)CreationException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)UnableToOpenOpenALDeviceException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)UnableToCreateOpenALContextException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)UnableToCreateOpenALSourceException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)UnableToCreateOpenALBufferException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)ReadingException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)UnableToSetOpenALBufferException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)UnableToSetDataToOpenALBufferException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)SettingException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)FormatNotSupportedException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)UnableToOpenSoundFileException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)UnableToReadSoundFileException.o \
	$(ANNA_SOUND_EXCEPTIONS_SOURCE)RequestedTooMuchMemoryException.o
BUILD = build/
BUILD_HEADERS = $(BUILD)headers/
BUILD_LIBRARIES = $(BUILD)libraries/anna/sound/
LIBRARY_NAME = $(BUILD_LIBRARIES)libAnnaSound.a
DOCS = docs/
CXXFLAGS += -std=c++03 -Wpedantic -Wall -Wextra -O2

.PHONY: install docs clean

main: $(OBJECTS)
	mkdir -p $(BUILD_LIBRARIES)
	$(AR) crs $(LIBRARY_NAME) $(OBJECTS)

	$(RM) -r $(BUILD_HEADERS)
	mkdir -p $(BUILD_HEADERS)
	rsync -r --include="*/" --include="*.h" --exclude="*" $(SOURCE_BASE) $(BUILD_HEADERS)

install:
	cp -r $(BUILD_HEADERS)* /usr/include/
	cp $(LIBRARY_NAME) /usr/lib/

docs:
	$(RM) -r $(DOCS)/html/
	doxygen $(DOCS)Doxyfile

clean:
	find . -name "*.o" -type f -delete
