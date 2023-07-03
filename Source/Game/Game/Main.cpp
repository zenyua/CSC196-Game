#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include <iostream>

using namespace std;


int main()
{
	kiko::g_memoryTracker.DisplayInfo();
	int* p = new int;
	kiko::g_memoryTracker.DisplayInfo();
	delete p;
	kiko::g_memoryTracker.DisplayInfo();

	kiko::Time timer;
	for (int i = 0; i < 1000000; i++) {}
	cout << timer.GetElapsedNanoseconds() << endl;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000000; i++)
	{
	}
	auto end = std::chrono::high_resolution_clock::now();
	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;

	/*cout << kiko::getFilePath() << endl;
	kiko::setFilePath("Assets");
	cout << kiko::getFilePath() << endl;
	size_t size;
	kiko::getFileSize("game.txt", size);
	cout << size << endl;

	std::string output;
	kiko::readFile("game.txt", output);
	cout << output << endl;

	kiko::seedRandom((unsigned int)time(nullptr));
	for (size_t i = 0; i < 10; i++)
	{
		cout << kiko::random(10,20) << endl;
	}*/
	
}
