#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Buffer {
private:
	char *data_;

public:
	int size_x;
	int size_y;

	Buffer(int sx, int sy):size_x(sx), size_y(sy) {
		data_ = new char[sx * sy];

		for (int y = 0; y < size_y; y++) {
			for (int x = 0; x < size_x; x++) {
				data_[y* size_x + x] = ' ';
			}
		}

	}

	~Buffer() {
		delete[]data_;
	}

	void draw()const {
		for (int y = 0; y < size_y; y++) {
			for (int x = 0; x < size_x; x++) {
				cout << data_[y* size_x + x];
			}
			cout << endl;
		}
	}

	void set(int x, int y, char c) {
		data_[y*size_x + x] = c;
	}

	char get(int x, int y) {
		return data_[y*size_x + x];
	}

};

class Shape {
private:
public:
	static const int size_x = 5;
	static const int size_y = 3;
	string type_;
	string type_art_;

	Shape(string t = "empty") : type_(type_) {
		if (type_ == "empty")
			type_art_ = "     \n"
			"     \n"
			"     \n";
		else if (type_ == "triangle")
			type_art_ = "  ^  \n"
			" / \ \n"
			"/___\\n";
		else if (type_ == "square")
			type_art_ = ".___.\n"
			"|   |\n"
			".___.\n";

	}

};

class Neighborhood {
private:
	Shape * data_;

public:
	int size_x;
	int size_y;
	Neighborhood(int size_x, int size_y) :size_x(size_x), size_y(size_y) {
		data_ = new Shape[size_x * size_y]();
	}


	~Neighborhood() {
		delete[] data_;
	}
	void animate(int frames) {
		Buffer b(size_x*Shape::size_x, size_y*Shape::size_y);

		for (int y = 0; y < size_y; y++) {
			for (int x = 0; x < size_x; x++) {
				b.set(x*Shape::size_x,
					y*Shape::size_y,
					data_[y * size_x + x].type_art_ );
			}
			cout << endl;
		}

		b.draw();
	}

};

int main() {
	Neighborhood n(80 / Shape::size_x, 25 / Shape::size_y);
	n.animate(1);


	system("pause");
	return 0;
}
