#include <string>
#include <iostream>
#include <Windows.h>
#include <filesystem>
#include <stdlib.h>
#include <msclr\marshal_cppstd.h>
#include <cstdio>
#include <tchar.h>
#include <Urlmon.h>
#include "ISM.h"
#pragma comment(lib, "urlmon.lib")

using namespace System;
using namespace std;
using namespace std::filesystem;



string installationstring;

//prive personal

bool CheckIfDicrectoryExistsP(std::string value) {
	if (is_directory(value))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void IGIVEUP(std::string value) {
	String^ str2 = gcnew String(value.c_str());
	System::Windows::Forms::MessageBox::Show(str2);
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



void AYO::ShowBox(std::string value) {
	String^ str2 = gcnew String(value.c_str());
	System::Windows::Forms::MessageBox::Show(str2);
}

/*
* Return Values
* 0 = created directory
* 1 = direcotry aleady existed
*/
int AYO::CreateorVerifyInstallDic(std::string direcotry) {
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

/*
* return vlaues
* 0 = sussessfully installed
* 1 = directory did not exist
* 2 = URL does not exist
* 2 = failed to acces url
* 3 = could not install file
*/
int AYO::InstallHelpfuldebugger(std::string downloadpath) {
	if (!CheckIfDicrectoryExistsP(installationstring)) {
		IGIVEUP("The Directory you specified did not exist");
		return 1;
	}
	try
	{									
		system("ping google.com");
		try
		{
			URLDownloadToFileA(NULL, downloadpath.c_str(), installationstring.c_str(), BINDF_GETNEWESTVERSION, NULL);
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









	