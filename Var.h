#define		CLOUDV		1 
#define		NOBJECT		4
#define		NO			10

int MAXV=1;
HDC hdc;
HWND hWnd;
HPEN hpen;
HBRUSH hbrush;

int cxClient;
int cyClient;
int cxSurface=640;
int cySurface=480;
int xMouse=320;
int yMouse=240;

Object ob[NO];

LONGLONG iBeginTime = 0;
LONGLONG iRealTime = 0;
int iClick = 0;
int iHit = 0;