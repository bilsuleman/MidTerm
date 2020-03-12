#include "FileFilter.h"

int main()
{
	ifstream infile;
	ofstream outfile;

	Encrypt e(10);
	Unchanged u;
	UpperCase up;

	e.doFilter(infile, outfile);
	u.doFilter(infile, outfile);
	up.doFilter(infile, outfile);
}