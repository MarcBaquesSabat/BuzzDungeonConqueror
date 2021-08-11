#include "SDL_Exception.h"

SDL_Exception::SDL_Exception(const char* message) : message(message)
{

}

const char* SDL_Exception::what() const throw()
{
	return message;
}
