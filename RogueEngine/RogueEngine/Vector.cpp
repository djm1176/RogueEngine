#include "Vector.h"

const Vector Vector::zero{ 0.0f };
const Vector Vector::one{ 1.0f };

const Vector Vector::up{ 0.0f, 1.0f, 0.0f };
const Vector Vector::right{ 1.0f, 0.0f, 0.0f };
const Vector Vector::forward{ 0.0f, 0.0f, 1.0f };

const float Vector::magnitude() {
	return 0.0f;
}

const float Vector::sqrMagnitude() {
	return 0.0f;
}

const Vector Vector::normalized() {
	return Vector();
}

const Vector Vector::cross(const Vector& a, const Vector& b) {
	return Vector();
}

const float Vector::distance(const Vector& a, const Vector& b) {
	return 0.0f;
}

const float Vector::dot(const Vector& a, const Vector& b) {
	return 0.0f;
}

const Vector Vector::lerp(const Vector& a, const Vector& b, const float& t) {
	return Vector();
}

Vector& Vector::operator=(const Vector& vec) {
	// TODO: insert return statement here
}

Vector& Vector::operator=(const Vector&& vec) {
	// TODO: insert return statement here
}

Vector& Vector::operator+=(const Vector& vec) {
	// TODO: insert return statement here
}

Vector& Vector::operator-=(const Vector& vec) {
	// TODO: insert return statement here
}

Vector& Vector::operator*=(const float& scalar) {
	// TODO: insert return statement here
}

Vector& Vector::operator/=(const float& scalar) {
	// TODO: insert return statement here
}

const Vector Vector::operator+(const Vector& vec) const {
	return Vector();
}

const Vector Vector::operator-(const Vector& vec) const {
	return Vector();
}

const Vector Vector::operator*(const float& scalar) const {
	return Vector();
}

const Vector Vector::operator/(const float& scalar) const {
	return Vector();
}

bool Vector::operator==(const Vector& other) const {
	return false;
}

bool Vector::operator!=(const Vector& other) const {
	return false;
}

const float& Vector::operator[](int index) const {
	// TODO: insert return statement here
}

std::ostream& Vector::operator<<(std::ostream& out) const {
	// TODO: insert return statement here
}
