#pragma once

#include "Vector.h"
#include "Component.h"
#include <iostream>

class Transform : public Component {
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
	Vector m_Position;
	Vector m_Scale;
	float m_Rotation;
	
	Transform &m_Parent;
};
