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

		
		
void AYO::SetInstallString(std::string value) {
	installationstring = value;
	
			
}

string AYO::ReturnInstallString() {
	string idk = installationstring;
	return idk;
}

		bool CheckIfDicrectoryExists(string value) {
			if (is_directory(value))
			{
				return true;
			}
			else
			{
				return false;
			}
			
		}

		void ShowBox(string value) {
			//System::Windows::Forms::MessageBox().Show("PEEPEE");
		}

		/*
		* Return Values
		* 0 = created directory
		* 1 = direcotry aleady existed
		*/
		int CreateorVerifyInstallDic(string direcotry) {
			if (!CheckIfDicrectoryExists(direcotry))
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
		int InstallHelpfuldebugger(std::string downloadpath) {
			if (!CheckIfDicrectoryExists(installationstring)) {
				ShowBox("The Directory you specified did not exist");
				return 1;
			}
			try
			{
				string t = "ping " + downloadpath;
				string s = "https://";
				t.erase(s.length());								
				system(("ping " + t).c_str());
			}
			catch (const std::exception&)
			{
				return 2;
			}
			try
			{								
				URLDownloadToFileA(NULL, downloadpath.c_str(), installationstring.c_str(), 0, NULL);
			}
			catch (const std::exception&)
			{
				return 3;
			}
		}








	