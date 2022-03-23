#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
const int RegLength = 35;

const int ReadLen = 8;
const int buf = 4096;
typedef unsigned long long udlong;
udlong shift = 255;
std::vector<udlong> mcoefs = { RegLength,2 };
std::vector<wchar_t> onezero = { L'0',L'1' };
const udlong ReadPosBytes = shift<<RegLength;
const udlong one = 1;
const int nm = 100;
using namespace std;
using namespace System::Windows::Forms;
using namespace System;

void ParseRegString(string& str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!(str[i] == '0' || str[i] == '1'))
		{
			str.erase(i, 1);
			--i;
		}
	}
	if (str.length() != RegLength)  //?
		throw gcnew System::String("Initial register length is not right");
	
}

udlong StrToDecimal(string& str)
{
	udlong result = 0;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '1')
		{
			result += one << len - 1 - i;
		}
	}
	return result;
}
void DefinePosCoefs(vector<udlong>& koefs)
{
	
	for (unsigned int i = 0; i < koefs.size(); i++)
	{
		koefs[i] = one << (koefs[i]);
	}
}
udlong DefineZeroBit(udlong Reg,vector<udlong>&koefs)
{
	udlong result;
	 
		result = (Reg & koefs[0])>>mcoefs[0];
	for (unsigned int i = 1; i < koefs.size(); i++)
	{
		
			result = result ^ ((Reg & koefs[i]) >> mcoefs[i]);
		
	}
	return result;

}
unsigned char TransfromReg(udlong& Reg, vector<udlong>& koefs)
{	

	
	for (int i = 0; i < ReadLen; i++)
	{
		Reg <<= 1;
		Reg+= DefineZeroBit(Reg, koefs);
		
	}
	return (unsigned char)((Reg & ReadPosBytes)>>RegLength);
	
}

String ^ ToBinaryString(unsigned char val,String ^ str)
{
	
	for (int i = 0; i < ReadLen; i++)
	{
		str += onezero[(val & 0x80)>>(ReadLen-1)];
		val <<= 1;
	}
	return str;
}
void Encrypt(string& FilePath,string&regstr,RichTextBox^KeyTextBox, RichTextBox^ EncTextBox, RichTextBox^ DecTextBox)
{	
	vector<udlong> koefs = { RegLength,2 };
	udlong Reg;
	DefinePosCoefs(koefs);
	ParseRegString(regstr);
	Reg = StrToDecimal(regstr);


	ifstream in;
	in.open(FilePath, ios::binary);
	ofstream out;
	int p = FilePath.length() - 1;
	std::string NewName = FilePath;
	while ((NewName[p] != '.') && (p >= 0))
	{
		--p;
	}
	NewName.erase(p, NewName.length() - p);
	NewName.append(".b2n");
	 p = FilePath.length() - 1;
	while ((FilePath[p] != '\\') && (p >= 0))
	{
		--p;
	}
	unsigned char outmas[buf];
	int lengthfile = FilePath.length() - p - 1;
	outmas[0] = lengthfile;
	out.open(NewName, ios::binary);
	out.write(reinterpret_cast<char*>(outmas),1);
	FilePath.copy(reinterpret_cast<char*>(outmas), outmas[0], p+1);
	out.write(reinterpret_cast<char*>(outmas), lengthfile);
	
	unsigned char mas[buf];
	
	int count;
	unsigned char ByteOfReg;
	String^ strin = gcnew String("");
	String^ strout = gcnew String("");
	String^ strkey = gcnew String("");
	int scht = 1;
	while (in)
	{
		
		in.read(reinterpret_cast<char*>(mas), buf);
		count = in.gcount();

		for (int i = 0; i < count; i++)
		{	ByteOfReg= TransfromReg(Reg, koefs);

			outmas[i] = mas[i] ^ ByteOfReg;
			if (scht <= nm)
			{
				
				strkey = ToBinaryString(ByteOfReg, strkey);
				strin = ToBinaryString(mas[i], strin);
				strout = ToBinaryString(outmas[i], strout);		
				++scht;
			}
			
		}

		out.write(reinterpret_cast<char*>(outmas), count);

		

	}
	KeyTextBox->AppendText(strkey);
	EncTextBox->AppendText(strin);
	DecTextBox->AppendText(strout);

	in.close();
	out.close();

}
void Decrypt(string& FilePath, string& regstr, RichTextBox^ KeyTextBox, RichTextBox^ EncTextBox, RichTextBox^ DecTextBox)
{
	vector<udlong> koefs = { RegLength,2 };
	udlong Reg;
	DefinePosCoefs(koefs);
	ParseRegString(regstr);
	Reg = StrToDecimal(regstr);

	unsigned char mas[buf];
	ifstream in;
	in.open(FilePath, ios::binary);
	in.read(reinterpret_cast<char*>(mas), 1);
	int lengthfile = mas[0];
	in.read(reinterpret_cast<char*>(mas), lengthfile);
	std::string fname;
	fname.insert(0, reinterpret_cast<char*>(mas), lengthfile);
	ofstream out;
	int p = FilePath.length() - 1;
	std::string NewName = FilePath;
	while ((FilePath[p] != '\\') && (p >= 0))
	{
		--p;
	}
	NewName.erase(p+1, NewName.length() - p-1);
	NewName.append(fname);
	out.open(NewName, ios::binary);

	
	unsigned char outmas[buf];
	int count;
	unsigned char ByteOfReg;
	String^ strin = gcnew String("");
	String^ strout = gcnew String("");
	String^ strkey = gcnew String("");;
	int scht = 1;
	while (in)
	{
		
		in.read(reinterpret_cast<char*>(mas), buf);
		count = in.gcount();

		for (int i = 0; i < count; i++)
		{
			ByteOfReg = TransfromReg(Reg, koefs);
			outmas[i] = mas[i] ^ ByteOfReg;
			if (scht <= nm)
			{
				
				strkey = ToBinaryString(ByteOfReg, strkey);
				strin = ToBinaryString(mas[i], strin);
				strout = ToBinaryString(outmas[i], strout);
				++scht;
			}

		}

		out.write(reinterpret_cast<char*>(outmas), count);
		
	}
	KeyTextBox->AppendText(strkey);
	EncTextBox->AppendText(strin);
	DecTextBox->AppendText(strout);
	in.close();
	out.close();

}



