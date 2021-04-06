#include <iostream>

class Fish {
private:
	int m_scales;
public:
	Fish(int scales = 3) :
		m_scales(scales)
	{};
	int getScales() {
		return m_scales;
	}
	void setScales(int set) {
		m_scales = set;
	}
	virtual void declareScales() {
		std::cout << "I am a fish with " << getScales() << " scales!" << std::endl;
	}
};

class Piranha : public Fish {
public:
	virtual void declareScales() {
		std::cout << "I am a piranha with " << getScales() << " scales!" << std::endl;
	}
};

int main() {
	Piranha p;
	Fish* f = &p;

	p.declareScales();
	f->declareScales();


	return 0;
}