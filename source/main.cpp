/*---------------------------------------------------------------------------------

	$Id: main.cpp,v 1.13 2008-12-02 20:21:20 dovoto Exp $
	Atari Breakout clone for nintendo DS -- damien


---------------------------------------------------------------------------------*/
#include "includes.h"
#include "grid.h"
//---------------------------------------------------------------------------------

int g_vol = 0;
int main(void) {
//---------------------------------------------------------------------------------
	videoSetMode(MODE_5_3D);
	consoleDemoInit();
	glScreen2D();
	soundEnable();

	Grid _grid;

	int sound_id = soundPlayNoise(8000, g_vol, 64);
	bool _pause = false;
	int ticker =0;

	int ticker2 =0 ;
	while(1) {
		glBegin2D();		
		scanKeys();

		touchPosition data;
		touchRead(&data);
		int key_down = keysDown();
		if (key_down & KEY_A)
			_grid.NewPellets();
		if (key_down & KEY_UP){
			_grid.SnakeUp();
		}
		if (key_down & KEY_DOWN){
			_grid.SnakeDown();
		}
		if (key_down & KEY_LEFT){
			_grid.SnakeLeft();
		}
		if (key_down & KEY_RIGHT){
			_grid.SnakeRight();
		}



		_grid.Draw();
		ticker++;

		if ((ticker % 5) == 0)
		{
			ticker2++;		
			if (_grid.Update()){
				_grid.Init();
		}}

		printf("\x1b[2;0Hsnack - damien");
		printf("\x1b[3;0Hlength: %d      ", _grid.GetLength());
		printf("\x1b[4;0Hscore: %d      ", _grid.GetLength()-3);
		
		printf("\x1b[5;0Hticker: %d      ", ticker);
		printf("\x1b[6;0Hticker2: %d      ", ticker2);
		//printf("\x1b[6;0Hlength: %d", _grid.GetLength());
		printf("\x1b[9;0Htouch x: %d y: %d          ", data.px, data.py);
		printf("\x1b[10;0Hvolume: %d          ", g_vol);

		soundSetVolume(sound_id, g_vol);
		g_vol -= 4;
		if (g_vol < 0) g_vol = 0;
		glEnd2D();
		glFlush(0);
		swiWaitForVBlank();
	}

	return 0;
}
