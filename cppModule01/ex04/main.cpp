#include <iostream>
#include <fstream>

void replace(std::string &fileContent, std::string s1, std::string s2)
{
    size_t pos = fileContent.find(s1);
    while (pos != std::string::npos)
    {
        fileContent.erase(pos, s1.size());
        fileContent.insert(pos, s2);
        pos = fileContent.find(s1, pos + s2.size());
    }
}

void replaceFile(std::string fileName, std::string fileContent)
{
    std::string outputFile = fileName + ".replace";
    std::ofstream ofs(outputFile);
    if (!ofs)
    {
        std::cerr << "Error: unable to open output file " << outputFile << '\n';
        exit(1);
    }
    ofs << fileContent;
    ofs.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0];
        std::cout << " <fileName> <string1> <string2>\n";
        return 0;
    }
    if (std::string(argv[2]).empty())
    {
        std::cout << "Don't try to replace your emptiness, embrace it.\n";
        return 0;
    }
    std::string fileName = argv[1];
    std::ifstream input_file(fileName);
    if (!input_file)
    {
        std::cerr << "Error: unable to open input file " << fileName << '\n';
        return 1;
    }
    std::string fileContent((std::istreambuf_iterator<char>(input_file)),
                            (std::istreambuf_iterator<char>()));
    replace(fileContent, argv[2], argv[3]);
    replaceFile(fileName, fileContent);
    return 0;
}
