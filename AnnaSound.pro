# параметры сборки, специфичные для окружения
win32:OPENAL_INCLUDES_PATH = E:\\openal\\include
win32:OPENAL_LIB_PATH = E:\\openal\\lib\\Win32

# общие настройки
TARGET = AnnaSound
TEMPLATE = lib
CONFIG += staticlib
#CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы проекта
HEADERS += \
	source/thewizardplusplus/utils/ByteOrderTesterHelper.h \
	source/thewizardplusplus/utils/os.h \
	source/thewizardplusplus/utils/ByteOrder.h \
	source/thewizardplusplus/utils/ByteOrderTester.h \
	source/thewizardplusplus/anna/maths/Maths.h \
	source/thewizardplusplus/anna/maths/Vector3D.h \
	source/thewizardplusplus/anna/sound/exceptions/SoundException.h \
	source/thewizardplusplus/anna/sound/exceptions/CreationException.h \
	source/thewizardplusplus/anna/sound/exceptions/UnableToOpenOpenALDeviceException.h \
	source/thewizardplusplus/anna/sound/exceptions/UnableToCreateOpenALContextException.h \
	source/thewizardplusplus/anna/sound/exceptions/UnableToCreateOpenALSourceException.h \
	source/thewizardplusplus/anna/sound/exceptions/UnableToCreateOpenALBufferException.h \
	source/thewizardplusplus/anna/sound/exceptions/SettingException.h \
	source/thewizardplusplus/anna/sound/exceptions/UnableToSetOpenALBufferException.h \
	source/thewizardplusplus/anna/sound/exceptions/UnableToSetDataToOpenALBufferException.h \
	source/thewizardplusplus/anna/sound/exceptions/ReadingException.h \
	source/thewizardplusplus/anna/sound/exceptions/FormatNotSupportedException.h \
	source/thewizardplusplus/anna/sound/exceptions/UnableToOpenSoundFileException.h \
	source/thewizardplusplus/anna/sound/exceptions/UnableToReadSoundFileException.h \
	source/thewizardplusplus/anna/sound/exceptions/RequestedTooMuchMemoryException.h \
	source/thewizardplusplus/anna/sound/AudioDeviceAttribute.h \
	source/thewizardplusplus/anna/sound/DistanceModel.h \
	source/thewizardplusplus/anna/sound/AudioDevice.h \
	source/thewizardplusplus/anna/sound/OpenALAudioDevice.h \
	source/thewizardplusplus/anna/sound/Listener.h \
	source/thewizardplusplus/anna/sound/OpenALListener.h \
	source/thewizardplusplus/anna/sound/SourceState.h \
	source/thewizardplusplus/anna/sound/SourceOffsetUnits.h \
	source/thewizardplusplus/anna/sound/Source.h \
	source/thewizardplusplus/anna/sound/OpenALSource.h \
	source/thewizardplusplus/anna/sound/PCMDataType.h \
	source/thewizardplusplus/anna/sound/PCMDataBits.h \
	source/thewizardplusplus/anna/sound/PCMData.h \
	source/thewizardplusplus/anna/sound/Buffer.h \
	source/thewizardplusplus/anna/sound/OpenALBuffer.h \
	source/thewizardplusplus/anna/sound/Loader.h \
	source/thewizardplusplus/anna/sound/WavLoader.h \
	source/thewizardplusplus/anna/sound/PCMDataManager.h \
	source/thewizardplusplus/anna/sound/Sound.h \
	source/thewizardplusplus/anna/sound/SoundManager.h
SOURCES += \
	#source/thewizardplusplus/main.cpp \
	source/thewizardplusplus/utils/ByteOrderTester.cpp \
	source/thewizardplusplus/anna/maths/Maths.cpp \
	source/thewizardplusplus/anna/sound/exceptions/SoundException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/CreationException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/UnableToOpenOpenALDeviceException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/UnableToCreateOpenALContextException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/UnableToCreateOpenALSourceException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/UnableToCreateOpenALBufferException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/ReadingException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/UnableToSetOpenALBufferException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/UnableToSetDataToOpenALBufferException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/SettingException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/FormatNotSupportedException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/UnableToOpenSoundFileException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/UnableToReadSoundFileException.cpp \
	source/thewizardplusplus/anna/sound/exceptions/RequestedTooMuchMemoryException.cpp \
	source/thewizardplusplus/anna/sound/AudioDevice.cpp \
	source/thewizardplusplus/anna/sound/OpenALAudioDevice.cpp \
	source/thewizardplusplus/anna/sound/Listener.cpp \
	source/thewizardplusplus/anna/sound/OpenALListener.cpp \
	source/thewizardplusplus/anna/sound/Source.cpp \
	source/thewizardplusplus/anna/sound/OpenALSource.cpp \
	source/thewizardplusplus/anna/sound/PCMData.cpp \
	source/thewizardplusplus/anna/sound/Buffer.cpp \
	source/thewizardplusplus/anna/sound/OpenALBuffer.cpp \
	source/thewizardplusplus/anna/sound/Loader.cpp \
	source/thewizardplusplus/anna/sound/WavLoader.cpp \
	source/thewizardplusplus/anna/sound/PCMDataManager.cpp \
	source/thewizardplusplus/anna/sound/Sound.cpp \
	source/thewizardplusplus/anna/sound/SoundManager.cpp

# файлы внешних библиотек
win32:INCLUDEPATH += $$OPENAL_INCLUDES_PATH
#win32:LIBS += -L$$OPENAL_LIB_PATH -lopenal32

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++03 -pedantic -Wall -W -O2
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
