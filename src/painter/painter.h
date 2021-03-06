#ifndef KITSUNE_PAINTER_H
#define KITSUNE_PAINTER_H

#include <string>
#include <exception>
#include <queue>
#include <vector>
#include <functional>

#include "SDL.h"
#include "GraphicsObject.h"
#include "Scene.h"

class PainterError : public std::exception {
public:
	PainterError() {};
	PainterError(const std::string& s) : msg(s) {};
	virtual ~PainterError() throw() {};
	virtual const char* what() const throw() { return msg.c_str(); };
private:
	std::string msg;
};

typedef std::priority_queue<unsigned int, std::vector<unsigned int>, std::greater<unsigned int>> AnimationQueue;

class Painter {
public:
	Painter(int width, int height, bool fs, std::string title);
	virtual ~Painter();

    void update();

    Scene* scene_;

    AnimationQueue queue_;
private:
    unsigned int next_event_time();
    SDL_GLContext gl_context_;
	SDL_Window *window_;
};

#endif
