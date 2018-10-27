/***************
 * phone.h
 ***************/

#ifndef PHONE_H
#define PHONE_H


// TODO: Put your phone class definition here...
class Phone
{
private:
	int areaCode;
	int prefix;
	int suffix;
public:
	void promptNumber();
	void display() const;
};

#endif
