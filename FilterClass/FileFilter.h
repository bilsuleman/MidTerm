#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

class FileFilter
{
public:
	void doFilter(ifstream& in, ofstream& out);
	virtual char transform(char ch) const = 0;
};

void FileFilter::doFilter(ifstream& in, ofstream& out)
{
	string fileName;

	cout << "Enter the name of the file you would like to create for output: ";
	cin >> fileName;
	in.open("input.txt");
	out.open(fileName);
	if (!in)
	{
		cout << "The file " << "input.txt"
			<< " cannot be opened.";
		exit(1);
	}
	if (!out)
	{
		cout << "The file " << fileName
			<< " cannot be opened.";
		exit(1);
	}

	char ch;
	char transCh;
	in.get(ch);
	while (!in.fail())
	{
		transCh = transform(ch);
		out.put(transCh);
		in.get(ch);
	}

	in.close();
	out.close();
}

class Encrypt : public FileFilter
{
protected:
	int key;
public:
	Encrypt(int a)
	{
		key = a;
	}
	char transform(char ch) const override
	{
		return ch + key;
	}
};
class Unchanged : public FileFilter
{
public:
	char transform(char ch) const override
	{
		return ch;
	}
};
class UpperCase : public FileFilter
{
public:
	char transform(char ch) const override
	{
		return toupper(ch);
	}
};