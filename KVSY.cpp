#include "gaming.hpp"
bool isok=true;
int main()
{
	gameInitialize();
	thread thread1(mouse);//∂‡œﬂ≥Ã
	playerk k(200, 100, 10, 318, 240, 3);
	playery y(800, 250, 10, 200, 180, 0.2);
	//y.ai(k);	
	plot1();
	while(k.live&&y.live&&isok)
	{
		BeginBatchDraw();
		gameDraw();
		k.keyboard();k.bulletmove();k.bulletdraw();k.playerdraw(); k.showhp();
		y.keyboard();
		//y.ai(k);
		y.bulletmove();y.bulletdraw();y.playerdraw(); y.showhp();
		bulletclash(k, y);
		isok=gameover(k, y);
		EndBatchDraw();
	}
	gameDraw();
	plot2();
	mapInitialize();
	worrior kong; 
	while (1)
	{
		BeginBatchDraw();
		drawmap();
		kong.worDraw();
		kong.move();
		for (int i = 0; i < 20; i++)
		{
			 c[i].createBullet(); c[i].drawCannon(); c[i].moveandDraw();
		}
		EndBatchDraw();
	}
	system("pause");
	closegraph();
	return 0;
}

