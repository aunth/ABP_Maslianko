#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string find_screen_height(int width, const string &ratio)
{
	size_t colonPos = ratio.find(':');
    int ratio_width = stoi(ratio.substr(0, colonPos));
    int ratio_height = stoi(ratio.substr(colonPos + 1));
	int height = round(width * ratio_height / ratio_width);
	string width_str = to_string(width);
	string height_str = to_string(height);
	return width_str + "x" + height_str;
}