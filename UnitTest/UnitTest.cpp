#include "pch.h"
#include "CppUnitTest.h"

#include "Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<struct Vector>(const struct Vector& t) { return L"CppBoxesBuffer"; }
		}
	}
}

namespace UnitTest
{
	TEST_CLASS(UnitTestVectors)
	{
	public:

		Vector emptyVector{};
		
		TEST_METHOD(EmptyVectorInitializesZero) {
			Assert::AreEqual(0.0f, emptyVector.x);
			Assert::AreEqual(0.0f, emptyVector.y);
			Assert::AreEqual(0.0f, emptyVector.z);
		}

		TEST_METHOD(VectorComparisonOperator) {
			Assert::AreEqual(Vector::zero, emptyVector);
			Assert::AreNotEqual(Vector::zero, Vector::one);
		}

		TEST_METHOD(ImpreciseVectorNotEqual) {
			Vector _vec = Vector(1.000001f, 0.0f, 0.0f);
			Assert::AreNotEqual(_vec, Vector::right);
		}

		TEST_METHOD(DeepCopyConstructor) {
			Vector _vec(emptyVector);
			Assert::AreNotSame(_vec, emptyVector);
		}

		//The next 2 tests have values pulled from:
		//https://en.wikipedia.org/wiki/Pythagorean_quadruple#Primitive_Pythagorean_quadruples_with_small_norm
		
		TEST_METHOD(MagnitudeCorrectValue) {
			Vector _vec = Vector(2.0f, 10.0f, 11.0f);
			Assert::AreEqual(_vec.magnitude(), 15.0f);
		}

		TEST_METHOD(SqrMagnitudeCorrectValue) {
			Vector _vec = Vector(1.0f, 2.0f, 2.0f);
			Assert::AreEqual(_vec.magnitude(), 9.0f);
		}

		TEST_METHOD(NormalizedCorrectValue) {
			Vector _vec = Vector(1.0f, 2.0f, 2.0f);
			Vector _exp = Vector(1.0f / 3.0f, 2.0f / 3.0f, 2.0f / 3.0f);
			Assert::AreEqual(_vec.normalized(), _exp);
		}

		TEST_METHOD(CrossProductCorrectValue) {
			Vector _vec = Vector(2.0f, 1.0f, 0.0f);
			Vector _exp = Vector(-1.0f, 2.0f, -1.0f);
			Assert::AreEqual(Vector::cross(Vector::one, _vec), _exp);
		}

		TEST_METHOD(DistanceCorrectValue) {
			Vector _vec = Vector(4.0f, 5.0f, 1.0f);
			Assert::AreEqual(Vector::distance(_vec, Vector::one), 5.0f);
		}

		TEST_METHOD(DotProductCorrectValue) {
			Vector _a = Vector(1.0f, 0.0f, 0.0f);
			Vector _b = Vector(0.0f, 0.0f, 1.0f);
			Assert::AreEqual(Vector::dot(_a, _b), 0.0f);
		}

		TEST_METHOD(LerpCorrectValue) {
			Assert::AreEqual(Vector::lerp(Vector::zero, Vector::one, 0.0f), Vector(0.0f, 0.0f, 0.0f));
			Assert::AreEqual(Vector::lerp(Vector::zero, Vector::one, 0.0001f), Vector(0.0001f, 0.0001f, 0.0001f));
			Assert::AreEqual(Vector::lerp(Vector::zero, Vector::one, 0.5f), Vector(0.5f, 0.5f, 0.5f));
			Assert::AreEqual(Vector::lerp(Vector::zero, Vector::one, 0.9999f), Vector(0.9999f, 0.9999f, 0.9999f));
			Assert::AreEqual(Vector::lerp(Vector::zero, Vector::one, 1.0f), Vector(1.0f, 1.0f, 1.0f));
		}

		TEST_METHOD(OperatorPlusEquals) {
			Vector _vec{};
			_vec += Vector::one;
			Assert::AreEqual(_vec, Vector::one);
		}

		TEST_METHOD(OperatorTimesEquals) {
			Vector _vec{};
			_vec *= 5.0f;
			Assert::AreEqual(_vec, Vector(5.0f, 5.0f, 5.0f));
		}
	};
}
