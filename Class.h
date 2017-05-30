class Object
{
private:
	int ID;
	int xN;
	int yN;
	int xV;
	int xMaxV;
	int yMaxV;
	int yV;
	int cxBitmap;
	int cyBitmap;
	int nSur;
	RECT Region;
	int fAlive;
public:
	Object();
	Object(int _ID);
	void Init(int _ID);
	void Restart();
	int nLeft();
	int nRight();
	int nTop();
	int nBottom();
	int GetSur();
	void Next();
	void Show();
	void Kill();
	bool CheckHit(int xGun, int yGun );
};
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
