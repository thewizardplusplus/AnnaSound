# параметры сборки, специфичные для окружения
win32:OPENAL_INCLUDES_PATH = E:\\openal\\include
win32:OPENAL_LIB_PATH = E:\\openal\\lib\\Win32
win32:OGG_INCLUDES_PATH = E:\\libogg\\include
win32:OGG_LIB_PATH =
win32:VORBIS_INCLUDES_PATH = E:\\libvorbis\\include
win32:VORBIS_LIB_PATH =

# общие настройки
TARGET = AnnaSound
#TEMPLATE = lib
#CONFIG += staticlib
CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы проекта
HEADERS += \
	source/anna/sound/AudioDevice.h \
	source/anna/sound/OpenALAudioDevice.h \
	source/anna/sound/AudioDeviceCreator.h \
	source/anna/sound/OpenALAudioDeviceCreator.h \
	source/anna/sound/Listener.h \
	source/anna/sound/OpenALListener.h \
	source/anna/sound/Source.h \
	source/anna/sound/OpenALSource.h \
	source/anna/sound/Buffer.h \
	source/anna/sound/OpenALBuffer.h \
	source/anna/sound/PCMData.h \
	source/anna/sound/Loader.h \
	source/anna/sound/LoaderCreator.h \
	source/anna/sound/PCMDataManager.h \
	source/anna/sound/Sound.h \
	source/anna/sound/SoundManager.h \
	source/anna/exceptions/SettingException.h \
	source/anna/exceptions/ReadingException.h \
	source/anna/exceptions/CreationException.h \
    source/anna/maths/Vector3D.h \
    source/anna/maths/Maths.h \
    source/anna/sound/WavLoaderCreator.h \
    source/anna/sound/WavLoader.h \
    source/anna/utils/ByteOrderTesterHelper.h \
    source/anna/utils/ByteOrderTester.h \
    source/anna/utils/ByteOrder.h \
    source/anna/utils/os.h
SOURCES += \
	source/main.cpp \
	source/anna/sound/OpenALAudioDevice.cpp \
	source/anna/sound/OpenALAudioDeviceCreator.cpp \
	source/anna/sound/OpenALListener.cpp \
	source/anna/sound/OpenALSource.cpp \
	source/anna/sound/OpenALBuffer.cpp \
	source/anna/sound/PCMDataManager.cpp \
	source/anna/sound/SoundManager.cpp \
    source/anna/maths/Maths.cpp \
    source/anna/sound/WavLoaderCreator.cpp \
    source/anna/sound/WavLoader.cpp \
    source/anna/utils/ByteOrderTester.cpp

# файлы внешних библиотек
win32:INCLUDEPATH += $$OPENAL_INCLUDES_PATH $$OGG_INCLUDES_PATH $$VORBIS_INCLUDES_PATH
win32:LIBS += -L$$OPENAL_LIB_PATH -lopenal32 -L$$OGG_LIB_PATH -L$$VORBIS_LIB_PATH
LIBS += -lvorbisfile

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++03 -pedantic -Wall -W -O2
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
