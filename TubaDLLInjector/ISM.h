#pragma once

#include <string.h>
#include <string>





public class AYO {
public:
	void SetInstallString(std::string vlaue);

	std::string ReturnInstallString();

	void ShowBox(std::string value);

	/*
	* Return Values
	* 0 = created directory
	* 1 = direcotry aleady existed
	*/
	int CreateorVerifyInstallDic(std::string direcotry);

	/*
	* return vlaues
	* 0 = sussessfully installed
	* 1 = directory did not exist
	* 2 = URL does not exist
	* 2 = failed to acces url
	* 3 = could not install file
	*/
	int InstallHelpfuldebugger(std::string downloadpath);
};








