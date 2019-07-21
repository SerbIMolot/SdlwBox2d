#pragma once

#include "stdafx.h"

static bool KEYS[322];

enum MouseB
{
	mLeft,
	mRight,
	mWheel
};

class EventHandle
{
	SDL_Event e;
public:
	EventHandle();
	~EventHandle();


	void Update();
	void handleInput();
};

