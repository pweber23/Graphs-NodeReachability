#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node* next;
};


class Queue {
private:
	Node* front;
	Node* rear;
public:
	Queue() {
		front = rear = nullptr;
	 }
	void inQueue(int val) {
		Node* temp = new Node();
		temp->data = val;
		temp->next = nullptr;

		if (front) {
			rear->next = temp;
			rear = temp;
		}
		else {
			front = temp;
			rear = temp;
		}
		
	}
	void deQueue() {
		Node* temp = front->next;
		delete front;
		front = temp;
	}
	bool contains(int x) {
		Node* temp = front;
		while (temp) {
			if (temp->data == x) {
				return true;
			}
			else {
				if (temp->next) {
					temp = temp->next;
				}
				else {
					return false;
				}
			}
		}
		return false;
	}

	void print() {
		Node* temp = front;
		while (temp) {
			cout << temp->data << " ";
			if (temp->next) {
				temp = temp->next;
			}
			else {
				break;
			}
		}
	}

	vector<int> convert() {
		vector<int> arr;
		Node* temp = front;
		while (temp) {
			if (temp->next) {
				arr.push_back(temp->data);
				deQueue();
				temp = front;
			}
			else {
				arr.push_back(temp->data);
				delete front;
				break;
			}
		}
		return arr;
	}
};
