#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;


struct Ball
{
	float radius;
	sf::Vector2f position;
	sf::Vector2f velocity;
	int charge;
	float mass;
};


int main()
{
	srand(time(0));

	const int width = 1000;
	const int height = 800;
	const int n_balls = 10;

	const float delta_t = 0.1;


	sf::RenderWindow window(sf::VideoMode(width, height), "My window");

	window.setFramerateLimit(60);

	sf::CircleShape circle(50.0f);
	circle.setFillColor({ 255, 0, 0 });

	std::vector<Ball> balls;
	balls.resize(n_balls);
	int color = 0;
	float mid_charge = 0;
	float mid_mass = 0;

	for (int i = 0; i < n_balls; i++)
	{
		balls[i].radius = 4 + rand() % 10;
		balls[i].mass = balls[i].radius * balls[i].radius * 3.14 * (100);
		balls[i].position = { (float)(rand() % width), (float)(rand() % height) };
		balls[i].velocity = { (float)(rand() % 100 - 50), (float)(rand() % 100 - 50) };
		balls[i].charge = (int)(rand() % 21 - 10);
		mid_charge += balls[i].charge;
		mid_mass += balls[i].mass;
		color = balls[i].charge * 25;
			if (balls[i].charge > 0)
			{
				circle.setFillColor({ color, 0, 0 });
			}
			if (balls[i].charge < 0)
			{
				circle.setFillColor({ 0, 0, color});
			}
			if (balls[i].charge == 0)
			{
				circle.setFillColor({ 255, 255, 255 });
			}
	}
	mid_mass /= n_balls;
	mid_charge /= n_balls;

	while (window.isOpen())
	{
		//sf::CircleShape b(50.0f); - рисование круга по клику мыши 
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					Ball a;
					b.setPosition(event.mouseMove.x, event.mouseMove.y);
					a.mass = 1000000;
					a.charge = 100;
					a.radius = 4 + rand() % 10;
					if (event.mouseButton.button == sf::Keyboard::LShift)//нажатие левого shift
					{
						a.charge *= (-1);
					}
					if (event.mouseButton.button == sf::Keyboard::RShift)//нажатие правого shift
					{
						a.charge *= (-1);
					}
					b.setRadius(a.radius);
					b.setOrigin(a.radius, a.radius);
				}
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					Ball a;
					b.setPosition(event.mouseMove.x, event.mouseMove.y);
					a.mass = mid_mass;
					a.charge = mid_charge;
					a.radius = 4 + rand() % 10;
					if (event.mouseButton.button == sf::Keyboard::LShift)//нажатие левого shift
					{
						a.charge *= (-1);
					}
					if (event.mouseButton.button == sf::Keyboard::RShift)//нажатие правого shift
					{
						a.charge *= (-1);
					}
					b.setRadius(a.radius);
					b.setOrigin(a.radius, a.radius);
				}
			}
		}
		window.clear(sf::Color::Black);

		for (int i = 0; i < n_balls; i++)
		{
			balls[i].position += balls[i].velocity * delta_t;

			Граничное условие - тор  
			if (balls[i].position.x < 0)
				balls[i].position.x += width;
			if (balls[i].position.x > width)
				balls[i].position.x -= width;

			if (balls[i].position.y < 0)
				balls[i].position.y += height;
			if (balls[i].position.y > height)
				balls[i].position.y -= height;
			

			Граничное условие - стенки 
			if (balls[i].position.x <= 0)
				balls[i].velocity.x = (-1)*balls[i].velocity.x;
			if (balls[i].position.x >= width)
				balls[i].velocity.x = (-1)*balls[i].velocity.x;

			if (balls[i].position.y <= 0)
				balls[i].velocity.y = (-1)*balls[i].velocity.y;
			if (balls[i].position.y >= height)
				balls[i].velocity.y = (-1)*balls[i].velocity.y;
				
			
			Задача N тел
				float const G = 6.67 * pow(10, -11);
				for (int k = 0; k < n_balls; k++)
				{
					if (k != i)
					{
						float distance = pow(((balls[i].position.x - balls[k].position.x) * (balls[i].position.x - balls[k].position.x) + (balls[i].position.y - balls[k].position.y) * (balls[i].position.y - balls[k].position.y)), 0.5);
						double fcos = (balls[k].position.x - balls[i].position.x) / distance;
						double fsin = (balls[k].position.y - balls[i].position.y) / distance;
						double force = G / (distance * distance);
						balls[i].velocity.x += (force * fcos * delta_t);// рассматриваем действие остальных шаров на данный 
						balls[i].velocity.y += (force * fsin * delta_t);
					}
				}


				//адача N тел с массой
					float const G = 6.67;// для наблюдения взаимодействия необходимо убрать степень 10
					for (int k = 0; k < n_balls; k++)
					{
						if (k != i)
						{
							float distance = pow(((balls[i].position.x - balls[k].position.x) * (balls[i].position.x - balls[k].position.x) + (balls[i].position.y - balls[k].position.y) * (balls[i].position.y - balls[k].position.y)),0.5);
							if (distance > 40)
							{
								double fcos = (balls[k].position.x - balls[i].position.x) / distance;
								double fsin = (balls[k].position.y - balls[i].position.y) / distance;
								double force = G * balls[k].mass / (distance * distance);
								balls[i].velocity.x += (force * fcos * delta_t);// рассматриваем действие остальных шаров на данный
								balls[i].velocity.y += (force * fsin * delta_t);
							}
						}
					}
					

					//Электрические заряды
							float const Kul = 9;// для наблюдения взаимодействия необходимо убрать степень 10
							for (int k = 0; k < n_balls; k++)
							{ 
								if (k != i)
								{
									float distance = pow(((balls[i].position.x - balls[k].position.x) * (balls[i].position.x - balls[k].position.x) + (balls[i].position.y - balls[k].position.y) * (balls[i].position.y - balls[k].position.y)),0.5);
									if (distance > 40)
									{
										double fcos = (balls[k].position.x - balls[i].position.x) / distance;
										double fsin = (balls[k].position.y - balls[i].position.y) / distance;
										double force = Kul * balls[k].charge * balls[i].charge / (distance * distance * balls[i].mass);
										balls[i].velocity.x -= (force * fcos * delta_t);// величина уменьшается ввиду обратности 
										balls[i].velocity.y -= (force * fsin * delta_t);
									}
								}
							}
							
	
			circle.setRadius(balls[i].radius);
			circle.setOrigin(balls[i].radius, balls[i].radius);
			circle.setPosition(balls[i].position);

			window.draw(circle);
			window.draw(b); -рисование круга по клику 
		}

		window.display();
	}
	return 0;
}