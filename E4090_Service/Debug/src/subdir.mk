################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EncoderSettings.cpp \
../src/EncoderSettingsManager.cpp \
../src/ManagementPort.cpp \
../src/NetworkManager.cpp \
../src/PublicPort.cpp \
../src/TCPServer.cpp \
../src/Utility.cpp \
../src/main.cpp \
../src/pugixml.cpp 

OBJS += \
./src/EncoderSettings.o \
./src/EncoderSettingsManager.o \
./src/ManagementPort.o \
./src/NetworkManager.o \
./src/PublicPort.o \
./src/TCPServer.o \
./src/Utility.o \
./src/main.o \
./src/pugixml.o 

CPP_DEPS += \
./src/EncoderSettings.d \
./src/EncoderSettingsManager.d \
./src/ManagementPort.d \
./src/NetworkManager.d \
./src/PublicPort.d \
./src/TCPServer.d \
./src/Utility.d \
./src/main.d \
./src/pugixml.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


