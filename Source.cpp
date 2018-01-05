#include "List.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream in_file;
	ofstream out_file;

	List<string> q;

	string command;
	int index;
	string item;
	in_file.open(argv[1]);
	out_file.open(argv[2]);

	while (in_file >> command)
	{
		if (command == "clear")
		{
			out_file << command << endl;
			q.clear();
		}
		else if (command == "insert")
		{
			out_file << command;
			in_file >> index;
			out_file << " " << index;
			in_file >> item;
			out_file << " " << item << endl;
			q.insert(index, item);
		}
		else if (command == "print")
		{
			out_file << command << endl;
			q.print(out_file);
			
		}
		else if (command == "find")
		{
			in_file >> item;
			out_file << "find " << item << " "<< q.print_(item) << endl;
		}
		else if (command == "remove")
		{
			in_file >> index;
			out_file << "remove " << index << " " << q.get_print(index) << endl;
			q.remove(index);
		}
	}
	in_file.close();
	out_file.close();
	return 0;
}