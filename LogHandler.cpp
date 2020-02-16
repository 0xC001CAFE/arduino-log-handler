#include "LogHandler.h"

LogHandler::LogHandler(Print &logOutput, const char *origin): logOutput(logOutput){
	this->origin = origin;
}

void LogHandler::log(Level level, const char *messageFormat, ...) const{
	logOutput.print("[");
	logOutput.print(origin);
	logOutput.print("] -> ");
	
	switch(level){
		case INFO:
			logOutput.print("INFO: ");
			
			break;
		case WARNING:
			logOutput.print("WARNING: ");
			
			break;
		case ERROR:
			logOutput.print("ERROR: ");
			
			break;
	}
	
	va_list args;
	va_start(args, messageFormat);
	
	uint8_t length = strlen(messageFormat);
	
	for(uint8_t i = 0; i < length; i++){
		if(messageFormat[i] == '%'){
			i++;
			
			switch(messageFormat[i]){
				case 'i':
					logOutput.print(va_arg(args, int), DEC);
					
					break;
				case 'u':
					logOutput.print(va_arg(args, unsigned int), DEC);
					
					break;
				case 'f':
					logOutput.print(va_arg(args, double), 5);
					
					break;
				case 'c':
					logOutput.print((char)va_arg(args, int));
					
					break;
				case 's':
					logOutput.print(va_arg(args, const char*));
					
					break;
				case '%':
					logOutput.print(messageFormat[i]);
					
					break;
			}
		}else{
			logOutput.print(messageFormat[i]);
		}
	}
	
	va_end(args);
}
