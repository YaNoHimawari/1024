// LISTING 6.7 - A Demonstration of Default Parameter Values
#include <iostream>

int AreaCube(int length, int width = 25, int height = 1);

int main()
{
    int length = 100;
    int width = 50;
    int height = 2;
    int area;

    area = AreaCube(length, width, height);
    std::cout << "First area equals: " << area << "\n";

    area = AreaCube(length, width);
    std::cout << "Second time area equals: " << area << "\n";

    area = AreaCube(length);
    std::cout << "Third time area equals: " << area << "\n";

    return 0;
}

int AreaCube(int length, int width, int height)
{

    return (length * width * height);
}