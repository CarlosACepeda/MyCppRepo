#include <iostream>
#include <string>

using namespace std;


class Vector2
{
	float _x, _y;

public:
	Vector2(float x, float y) : _x(x), _y(y)
	{
	}
	float GetX() const { return _x; }
	float GetY() const { return _y; }

	//Operator Overloading (+)
	//I could use a reference "Vector2&" as the return type but the ideal scenario 
	//it'll be that we return a copy of the object.

	//Always overload related operators( for example, if I Override + i should override '+='
	Vector2 operator + (const Vector2& rightHandSide) const //Left hand Side operator is implied (When inside a class)
	{
		/*Vector2 local(_x + rightHandSide._x, _y + rightHandSide._y);
		return local;*/
		Vector2 local(*this); //<--default copy operator with each type. (Simpler way to do the same stuff)
		local += rightHandSide;
		return local;

	}
	Vector2& operator += (const Vector2& rightHandSide) //Left hand Side operator is implied.(When inside a class)
	{
		_x += rightHandSide._x;
		_y += rightHandSide._y;
		return *this; //<--return a reference. (of the implied left hand operator)
	}
	Vector2& operator ++() //Left hand Side operator is implied. (Prefix ++ operator) (When inside a class)
	{
		_x++;
		_y++;
		return *this; //<--return a reference. (of the implied left hand operator)
	}
	Vector2 operator ++(int) //Left hand Side operator is implied. (Postfix ++ operator), the int param doesnt' do anything LMAO
	{
		//Why is it correct? 
		Vector2 result(*this);
		operator++();
		return result;
	}


};
class Inventory
{

public:
	string operator () (int test) const
	{
		return "bash";
	}
	string operator [] (const string& hey) const
	{
		return hey + " there";
	}
	Inventory& operator , (const Inventory& invectory) //Some fun
	{
		cout << + "Really, C++??\n";
		return *this;
	}
};


//I also can define /override operator outside of a class (but then I should specify the left hand side operator)
Vector2 operator *(const Vector2& leftHandSide, const Vector2& rightHandSide)
{
	return Vector2(leftHandSide.GetX()* rightHandSide.GetX(), leftHandSide.GetY()* rightHandSide.GetY());
}
ostream& operator <<(ostream& out, const Vector2& rightHandSide)
{
	out << "(" << rightHandSide.GetX() << rightHandSide.GetY() << ")";
	return out;
}

int main()
{
	Vector2 myObject(1, 2);
	Vector2 myObject2(1, 2);
	Vector2 myObject3(3, 5);

	Vector2 result = myObject + myObject2;
	cout << result.GetX();
	cin.get();

	//Other operators I can overload:
	// %, %=
	// & | ~ ^ >> <<
	// == != > < <= => || &&
	// new new[] delete delete[]

	//[] -> Indexing
	//() -> n-ary operator (Called n-ary because the function can take n params!)

	Inventory inventory;
	cout << inventory["LMAO"];
	cout << inventory(3333); //-> Object using as a function (Functor) (maybe a delegate??)
	cout << endl;
	inventory, inventory, inventory, inventory, inventory; //XD //Some fun
	return 0;


	//Homework 10:

	//TODO: To write a BigInt class, this class can represent an integer of any numeric value.
	//it should support the following operators: +, -, =, ctor, dtor
	//+=, -=, *, *=, ==, !=, <, >, <=, >=, unary -, ostream >>, istream <<

}