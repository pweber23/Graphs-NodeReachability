#include <array>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "ArgumentManager.h"
#include "Queue.h"

using namespace std;

int main(int argc, char* argv[])
{

	ArgumentManager am(argc, argv);

	string filename = "test.txt";
	string line;
	ifstream stream(filename.c_str());
	int root;
	int index = 0;
	int beginning;
	Queue queue;

	while (getline(stream, line)) {
		int temp = 0;
		string temp1 = "";
		string temp2 = "";
		string temp3 = "";
		for (int i = 0; i < line.length(); i++) {
			while (line[i] >= '0' && line[i] <= '9') {
				temp1 += line[i];
				i++;
			}
			while (line[i] == ' ') {
				i++;
			}
			while (line[i] >= '0' && line[i] <= '9') {
				temp2 += line[i];
				i++;
			}
			while (line[i] == ' ') {
				i++;
			}
			while (line[i] >= '0' && line[i] <= '9') {
				temp3 += line[i];
				i++;
			}

			cout << temp1 << " " << temp2 << " " << temp3 << endl;
		}
		
		if (index == 0 && stoi(temp3) > 0) {
			queue.inQueue(stoi(temp1));
			queue.inQueue(stoi(temp2));
		}
		else if (queue.contains(stoi(temp1)) && stoi(temp3) > 0) {
			if (!(queue.contains(stoi(temp2)))) {
				queue.inQueue(stoi(temp2));
			}
		}

		index++;
	}

	queue.deQueue();
	vector<int> temp = queue.convert();
	sort(temp.begin(), temp.end());

	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << " ";
	}

	system("pause");
	return 0;
}