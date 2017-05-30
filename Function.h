int Rand(int n)
{
	return rand()%n;
}
int Rand(int nBottom,int nTop)
{
	int nOff = nTop-nBottom;
	return nBottom+Rand(nOff+1);
}
////////////////////////////////////////////////////////////////////////////////////////////////
int Object::nLeft()
{
	return xN-cxBitmap/2;
}
int Object::nRight()
{
	return xN+cxBitmap/2;
}
int Object::nTop()
{
	return yN-cyBitmap/2;
}
int Object::nBottom()
{
	return yN+cyBitmap/2;
}
bool Object::CheckHit(int xGun, int yGun )
{
	if( xGun>nLeft() && xGun<nRight() && yGun>nTop() && yGun<nBottom() )
		return true;
	else return false;
}
int Object::GetSur()
{
	return nSur;
}
void Object::Next()
{
	if( fAlive == 1 )
	{
		if( nLeft()+xV <= Region.left )
		{
			xN = Region.left+cxBitmap/2;
			yN += yV;
			xV = -xV;
		}
		if( nRight()+xV >= Region.right )
		{
			xN = Region.right-cxBitmap/2;
			yN += yV;
			xV = -xV;
		}
		if( nTop()+yV <= Region.top )
		{
			yN = Region.top+cyBitmap/2;
			xN += xV;
			yV = -yV;
		}
		if( nBottom()+yV >= Region.bottom )
		{
			yN = Region.bottom-cyBitmap/2;
			xN += xV;
			yV = -yV;
		}
		xN += xV;
		yN += yV;
		if( nSur==1 )
		{
			xV = Rand(-xMaxV,xMaxV);
			yV = Rand(-yMaxV,yMaxV);
		}
		else if( nSur==2 )
			yV = Rand(-yMaxV,yMaxV);
		else if( nSur==3 )
			xV = Rand(-xMaxV,xMaxV);
	}
	else if( fAlive == 0 )
	{
		xV = 0;
		yV = 30;
		yN += yV;
		if( yN>cySurface )
		{
			fAlive = -1;
			iHit++;
		}
	}
}
void Object::Kill()
{
	fAlive = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
Object::Object(int _ID)
{
	ID=_ID;
	Restart();
}
void Object::Restart()
{
	if( ID==0 )
	{
		Region.left = 0;
		Region.right = cxSurface;
		Region.top = 0;
		Region.bottom = cySurface;
		fAlive = 1;
		nSur = 0;
		cxBitmap = 32;
		cyBitmap = 32;
		xN = Rand(Region.left+cxBitmap/2,Region.right-cxBitmap/2);
		yN = Rand(Region.top+cyBitmap/2,Region.bottom-cyBitmap/2);
		xMaxV = MAXV;
		xV = Rand(-MAXV,MAXV);
		yMaxV = MAXV/5;
		yV = Rand(-MAXV/5,MAXV/5);
	}
	else if( ID==1 )
	{
		Region.left = 0;
		Region.right = cxSurface;
		Region.top = 0;
		Region.bottom = cySurface/2;
		fAlive = 1;
		nSur = 1;
		cxBitmap = 8;
		cyBitmap = 8;
		xN = Rand(Region.left+cxBitmap/2,Region.right-cxBitmap/2);
		yN = Rand(Region.top+cyBitmap/2,Region.bottom-cyBitmap/2);
		xMaxV = MAXV;
		xV = Rand(-MAXV,MAXV);
		yMaxV = MAXV/5;
		yV = Rand(-MAXV/5,MAXV/5);
	}
	else if( ID==2 )
	{
		cxBitmap = 54;
		cyBitmap = 24;
		Region.left = 0;
		Region.right = cxSurface;
		Region.top = cySurface-6*cyBitmap;
		Region.bottom = cySurface-2*cyBitmap;
		fAlive = 1;
		nSur = 2;
		xN = Rand(Region.left+cxBitmap/2,Region.right-cxBitmap/2);
		yN = Rand(Region.top+cyBitmap/2,Region.bottom-cyBitmap/2);
		
		xMaxV = MAXV;
		xV = Rand(MAXV*3/4,MAXV);
		yMaxV = 1;
		yV = 1;

	}
	else if( ID==3 )
	{
		cxBitmap = 16;
		cyBitmap = 48;
		Region.left = 0;
		Region.right = cxSurface;
		Region.top = cyBitmap/2;
		Region.bottom = cySurface-2*cyBitmap;
		fAlive = 1;
		nSur = 3;
		xN = Rand(Region.left+cxBitmap/2,Region.right-cxBitmap/2);
		yN = Rand(Region.top+cyBitmap/2,Region.bottom-cyBitmap/2);
		
		xMaxV = 2;
		xV = Rand(-2,2);;
		yMaxV = MAXV;
		yV = Rand(MAXV*3/4,MAXV);
	}
}
void Object::Init(int _ID)
{
	ID=_ID;
	Restart();
}
Object::Object()
{
	int i;
	i=Rand(4);
	/*if( i<10 )
		i=2;
	else if( 10<=i && i<40 )
		i=3;
	else if( 40<=i && i<50 )
		i=0;
	else 
		i=1;
		*/
	Init(i);
}
void Object::Show()
{
	if( fAlive != -1 )
		lpDDBack->BltFast( nLeft(), nTop(), lpDDObject[ID], NULL, DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY );
}