
//Cross OS SDL2 includes

#ifndef SDL2COMMON_H_
#define SDL2COMMON_H_

//non SDL includes 
#include <cstdio>
#include <stdexcept>


#if defined(_WIN32) || defined(_WIN64)
//The SDL library
#include "SDL.h"
//Support for loading different types of images.
#include "SDL_image.h"
#else
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#endif
#endif

