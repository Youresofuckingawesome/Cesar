#include <cstdlib>
#include <fstream>
#include <string>
#include <cassert>

void Define(std::string& code, std::string substr, std::string newstr)
{
	size_t found = code.find(substr);
	if (found == std::string::npos) assert(false && "Not found any!");
	code.replace(found + substr.length(), 1, ' ' + newstr);
}

int main(int argc, char** argv)
{
	if (argc != 5) return 1;
	std::string type = argv[1];
    std::string amount = argv[2];
	std::string oper = argv[3];
	std::string container = argv[4];
	
	std::string code;
	std::fstream file("compile_time.txt");
	if (!file.is_open()) return 2;

	std::string line;
	while (std::getline(file, line))
		code += line + '\n';
	
	Define(code, "LENGTH", amount);
	Define(code, "TYPE", type);
	if (container == "array")
		Define(code, "ARRAY_CAPACITY", ", " + amount);
	Define(code, "CONTAINER_TYPE", "std::" + container + "<" + type + " ARRAY_CAPACITY" + ">");
	if (container == "array")
		Define(code, "FILL_OPERATOR", "container[i] = rand();");
	else
		Define(code, "FILL_OPERATOR", "container.push_back(rand() % 1000);");

	Define(code, "ACTION", "sum = sum " + oper + " container[i];");

	file.close();
	
	std::ofstream output("compile_time.cpp");
	output << code;
	output.close();

	system("g++ -o out compile_time.cpp");
	system("./out");
	
    return 0;
}
