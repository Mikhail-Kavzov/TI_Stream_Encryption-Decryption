#pragma once
#include <string>
using namespace std;
using System::Windows::Forms;
void Encrypt(string& FilePath, string& regstr, RichTextBox^ KeyTextBox, RichTextBox^ EncTextBox, RichTextBox^ DecTextBox);
void Decrypt(string& FilePath, string& regstr, RichTextBox^ KeyTextBox, RichTextBox^ EncTextBox, RichTextBox^ DecTextBox);