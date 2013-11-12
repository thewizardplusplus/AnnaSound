# параметры сборки, специфичные для окружения
win32:OPENAL_INCLUDES_PATH = E:\\openal\\include
win32:OPENAL_LIB_PATH = E:\\openal\\lib\\Win32

# общие настройки
CONFIG += console
CONFIG += warn_on
CONFIG -= qt

# файлы внешних библиотек
INCLUDEPATH += ./../release/includes/ $$OPENAL_INCLUDES_PATH
LIBS += -L./../release/libs/ -lAnnaSound
win32:LIBS += -L$$OPENAL_LIB_PATH -lopenal32

# файлы проекта
SOURCES += \
	main.cpp

# флаги компилятора
unix | win32-g++ {
	QMAKE_CXXFLAGS += -std=c++03 -pedantic -Wall -W -O2
}
win32-g++ {
	QMAKE_CXXFLAGS += -U__STRICT_ANSI__
}
