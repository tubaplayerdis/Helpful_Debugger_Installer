#include <string>
#include <iostream>
#include <Windows.h>
#include <filesystem>
#include <stdlib.h>
#include <msclr\marshal_cppstd.h>
#include <cstdio>
#include <tchar.h>
#include <Urlmon.h>
#include <fstream>
#include "ISM.h"
#pragma comment(lib, "urlmon.lib")

using namespace System;
using namespace std;
using namespace std::filesystem;



string installationstring;

//prive personal

void IGIVEUP(std::string value) {
	String^ str2 = gcnew String(value.c_str());
	System::Windows::Forms::MessageBox::Show(str2, "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
}

bool CheckIfDicrectoryExistsP(std::string value) {
	try
	{
		if (is_directory(value))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (const std::exception&)
	{
		IGIVEUP("Acces was denied to folder, restart with admin");		
	}
	

}

string ReturnInstallStringP() {
	string idk = installationstring;
	return idk;
}
		
		
void AYO::SetInstallString(std::string value) {
	installationstring = value;			
}

string AYO::ReturnInstallString() {
	string idk = installationstring;
	return idk;
}


/*
* int values for button
* 0 = OK
* 1 = OKCancel
* 2 AbortRetryIgnore
* 3 = YesNoCancel
* 4 = YesNo
* 5 = RetryCancel
* int values for picture
* 0 = None
* 1 = Hand
* 2 = Question
* 3 = Exclamation
* 4 = Asterisk
* 5 = Stop
* 6 = Error
* 7 = Warning
* 8 = Information
*/
void AYO::ShowBox(std::string mainmessage, std::string caption) {
	String^ str2 = gcnew String(mainmessage.c_str());
	String^ str3 = gcnew String(caption.c_str());	
	System::Windows::Forms::MessageBox::Show(str2, str3, System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
}

/*
* Return Values
* 0 = created directory
* 1 = direcotry aleady existed
*/
int AYO::CreateorVerifyInstallDic(std::string direcotry) {
	try
	{
		if (!CheckIfDicrectoryExistsP(direcotry))
		{
			filesystem::create_directory(direcotry);
			return 0;
		}
		else
		{
			return 1;
		}
	}
	catch (const std::exception&)
	{
		IGIVEUP("Acces was denied to folder, no folder was created even if it says after, run with admin");
	}
	
}

/*
* return vlaues
* 0 = sussessfully installed
* 1 = directory did not exist
* 2 = URL does not exist
* 2 = failed to acces url
* 3 = error with file
*/
int AYO::InstallHelpfuldebugger(std::string BashCurlURL, std::string Filename) {
	if (!CheckIfDicrectoryExistsP(installationstring)) {
		IGIVEUP("The Directory you specified did not exist");
		return 1;
	}
	try
	{		
		
		try
		{
			system("ping github.com");
			try
			{
				string s = "cd ";
				s += installationstring;
				s += " & "; // cd string && 
				string f = "powershell -ExecutionPolicy Bypass -Command \"Expand-Archive ";
				f += Filename;
				//IGIVEUP(installationstring);

				string t = "curl -LO ";
				t += BashCurlURL;
				f += "\"";
				s += t; // cd string && curl string
				s += " & ";
				s += f; // finished string								
				//IGIVEUP(s);
				IGIVEUP(s.c_str());
				system(s.c_str());
				Sleep(100);
				string h = "explorer -Path ";
				h += installationstring;
				h += "Helpful.Debugger.Release.v1.0";
				// change
				system(h.c_str());


				Sleep(500);
				return 0;
			}
			catch (const std::exception&)
			{
				return 3;
			}
		}
		catch (const std::exception&)
		{
			return 2;
		}
			
		
		
		
	}
	catch (const std::exception&)
	{
		return 2;
	}
	
}









	