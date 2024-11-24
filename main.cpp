/*
	fixgz C++ rewrite
	attempts to fix gz binaries by removing extra CR that are followed by LF
	usage: fixgz bad.gz fixed.gz
	
	Original Copyright 1998 Jean-loup Gailly <jloup@gzip.org>
	
	This software is provided 'as-is', without any express or implied
	warranty. In no even will the author be held liable for any damages
	arising from the use of this software.
	
	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	int c1, c2;
	
	if (argc <= 2) {
		cerr << "usage: " << argv[0] << " bad.gz fixed.gz" << endl;
		return 1;
	}
	
	ifstream in (argv[1], ios_base::in | ios_base::binary);
	if (!in.good()) {
		cerr << "fixgz: cannot open " << argv[1] << endl;
		return 1;
	}
	
	ofstream out (argv[2], ios_base::out | ios_base::binary);
	if (!out.good()) {
		cerr << "fixgz: cannot create " << argv[2] << endl;
		return 1;
	}
	
	c1 = in.get();
	
	while ((c2 = in.get()) != EOF) {
		if (c1 != '\r' || c2 != '\n') {
			out << c1;
		}
		c1 = c2;
	}
	
	if (c1 != EOF) {
		out << c1;
	}
	
	return 0;
}