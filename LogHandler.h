#ifndef LogHandler_h
#define LogHandler_h

#include <Print.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

class LogHandler{
	public:
		enum Level{
			INFO,
			WARNING,
			ERROR
		};
		
		LogHandler(Print &logOutput, const char *origin);
		
		void log(Level level, const char *messageFormat, ...) const;
	private:
		Print &logOutput;
		
		const char *origin;
};

#endif
