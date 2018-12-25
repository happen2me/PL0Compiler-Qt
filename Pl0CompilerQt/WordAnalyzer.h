#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include "Word.h"

class WordAnalyzer
{
public:
	WordAnalyzer();
	WordAnalyzer(std::string filename);
	WordAnalyzer(std::string filename, std::ostream &out);
	~WordAnalyzer();
	
	void error(std::string, bool fatal = false);
	void analyze();
	std::vector<Word> getResult();
	std::string getBuffer();
	void printResult(std::ostream& out);
	int getErrorCount();

	static std::vector<std::string> reserved_words;
	static std::map<std::string, Word::WordType> reserved_word_map;
	static std::vector<std::string> types_name;

private:
	char ch;
	std::string token; //���ʴ�
	int num;
	Word::WordType symbol;
	std::string buffer;
	int readPtr;
	std::vector<Word> results;
	int line_counter;
	std::ostream& out;
	int errorCnt;

	char getchar();
	void clearToken();

	bool isLetter();
	bool isDigit();
	bool isSpace();
	bool isNewLine();
	bool isTab();
	bool isColon(); //ð��
	bool isComma();
	bool isSemi();	//�ֺ�
	bool isEqual();
	bool isPlus();
	bool isMinus();
	bool isDivide();
	bool isStar();
	bool isLpar();
	bool isRpar();
	bool isLess();
	bool isAbove();
	bool isDot();

	void catToken(); //���ӵ�ǰ�ַ�ch�뵥�ʴ�token
	void retract(); //���˶��ַ�
	Word::WordType reserver(); //��ʶ������0�������ַ��ر����������
	int transNum();	//�����ʴ�tokenת��Ϊ������ֵ

	void readFile(std::string filename);
	Word identifyWord();
	bool fileExits(std::string filename);

};

