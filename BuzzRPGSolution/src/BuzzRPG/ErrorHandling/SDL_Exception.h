#pragma once
#include <exception>

class SDL_Exception : public std::exception {
public:
	const char* message;
	SDL_Exception(const char* message);
	virtual const char* what() const throw();
};