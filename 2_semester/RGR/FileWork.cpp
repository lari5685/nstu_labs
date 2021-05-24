#include <string>
#include <fstream>

#include "FileWork.h"


void fileInput(std::string FileName, std::string& messege) {
	std::string text;
	std::ifstream fin(FileName);
	while (!fin.eof()) {
		fin >> text;
		messege += text + " ";
	}
	fin.close();
	if (messege.size() > 0)
		messege.erase(messege.end() - 1);
}

void fileOutput(std::string FileName, std::string& messege) {
	std::ofstream fout(FileName);
	fout << messege;
	fout.close();
}
