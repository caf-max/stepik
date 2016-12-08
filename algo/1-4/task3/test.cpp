#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void)
{
	std::ifstream infile("data.txt");
	std::vector<std::string> tasks;
	std::vector<std::string> ans;

	bool isTask = true;
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		if (isTask) {
			tasks.push_back(line);
		}
		else {
			ans.push_back(line);
		}
		isTask = !isTask;
	}
	
	std::system("g++ -std=c++11 -static-libgcc -static-libstdc++ main.cpp -o main.exe");
	std::system("echo ANSWERS > answer.txt");
	for (auto& line : tasks) {
		std::string cmd = "echo " + line + " | main.exe >> answer.txt";
		// std::cout << cmd << std::endl;
		std::system(cmd.c_str());
	}

	infile.close();
	infile.open("answer.txt");
	std::vector<std::string> res;

	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		res.push_back(line);
	}
	std::cout << res.size() << std::endl;
	for (int i = 0; i < res.size(); i++) {
		std::cout << tasks[i] << " = " << res[i];
		if (res[i] == ans[i]) {
			std::cout << " --OK" << std::endl;
		}
		else {
			std::cout << " --ERROR (" << ans[i] << ")" << std::endl;
		}
	}

	return 0;
}
