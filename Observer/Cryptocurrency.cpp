#include "Cryptocurrency.h"
#include"Bidder.h"

Cryptocurrency::Cryptocurrency(string name, int course) :name(name) {
	this->course.resize(5);
	for (size_t i = 0; i < this->course.size(); i++)
		this->course[i] = course;
}

void Cryptocurrency::Attach(Bidder* bidder) {
	bidders.push_back(bidder);
}

void Cryptocurrency::Detach(Bidder* bidder) {
	for (auto it = bidders.begin(); it != bidders.end(); it++) {
		if (*it == bidder) {
			bidders.erase(it);
			return;
		}
	}
}

void Cryptocurrency::Notify() {
	for (auto it = bidders.begin(); it != bidders.end(); it++) {
		(*it)->Update(this);
	}
	cout << "\n";
}

string Cryptocurrency::GetName() const
{
		return name;
	
}

const vector<int>& Cryptocurrency::GetCourse() const {
	return course;
}

int Cryptocurrency::GetLastCourse() const {
	return course[4];
}
void Cryptocurrency::SetCourse(int course) {
	if (course < 0)
		course = 0;

	this->course[0] = this->course[1];
	this->course[1] = this->course[2];
	this->course[2] = this->course[3];
	this->course[3] = this->course[4];
	this->course[4] = course;

	if (this->course[3] != course) {
		Notify();
	}
}

void Cryptocurrency::ShowCourse() const {
	cout << "\nCryptocurrency: " << name << "\nCourse: ";
	for (int elem : course)
		cout << elem << " ";
	cout << endl;
}