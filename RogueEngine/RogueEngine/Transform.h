#pragma once
#include "Vector.h"

class Transform {
public:
	Vector& position();
	Vector& localPosition();
	Vector& scale();
	float& rotation();

	Transform& parent();
	void setParent(Transform& newParent);
	
	Vector up();
	Vector forward();
	Vector right();

private:
	Vector position;
	Vector scale;
	float rotation;
	
	Transform &parent;
};
