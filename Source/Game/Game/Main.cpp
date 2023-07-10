#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include <iostream>
#include <vector>

using namespace std;
using vec2 = kiko::Vector2;

class Star {
public: 
	Star(const vec2& pos, const vec2& vel) :
		m_pos{ pos }, m_vel{ vel }
	{}

	void Update(int width, int height) {
		m_pos += m_vel;
		if (m_pos.x >= width) m_pos.x = 0;
		if (m_pos.y >= height) m_pos.y = 0;
	}

	void Draw(kiko::Renderer& renderer) {
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}


public:
	kiko::Vector2 m_pos;
	kiko::Vector2 m_vel;
};



int main(int argc, char* argv[])
{
	kiko::seedRandom((unsigned int) time(nullptr));

	kiko::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	vector<Star> stars;
	for (int i = 0; i < 1000; i++) {
		kiko::Vector2 pos(kiko::Vector2(kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight())));
		kiko::Vector2 vel(kiko::randomf(1, 4), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	while (true) {
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		kiko::Vector2 vel(1.0f, 0.3f);

		for (auto& star: stars)
		{
			star.Update(renderer.GetWidth(), renderer.GetHeight());

			if (star.m_pos.x >= renderer.GetWidth()) star.m_pos.x = 0;
			if (star.m_pos.y >= renderer.GetHeight()) star.m_pos.y = 0;

			renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), kiko::random(256));
			star.Draw(renderer);
			renderer.DrawPoint(star.m_pos.x, star.m_pos.y);
		}

		//renderer.SetColor(255, 0, 0, 100);
		////random num between 0-255 for first num
		//for (int i = 0; i < 1000; i++) {
		//	kiko::Vector2 pos(kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight()));
		//	//int x = kiko::random(renderer.GetWidth());
		//	//int y = kiko::random(renderer.GetHeight());

		//	renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), kiko::random(256));
		//	renderer.DrawPoint(pos.x,pos.y);
		//	//renderer.DrawLine(kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight()),
		//		kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight()));
		//}
		//// draw
		renderer.EndFrame();
	}

	//cin.get();

	return 0;

	/*kiko::g_memoryTracker.DisplayInfo();
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
	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;*/

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
