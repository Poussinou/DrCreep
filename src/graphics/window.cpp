/*
 *  The Castles of Dr. Creep 
 *  ------------------------
 *
 *  Copyright (C) 2009-2010 Robert Crossfield
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *  ------------------------------------------
 *  SDL Video Window Wrapper
 *  ------------------------------------------
 */

#include "../stdafx.h"
#include "window.h"

cVideoWindow::cVideoWindow( size_t pWidth, size_t pHeight, size_t pBytesPixel, bool pFullScreen ) {
	size_t flags = SDL_ANYFORMAT;

	if( pFullScreen )
		flags |= SDL_FULLSCREEN;

	_width = pWidth;
	_height = pHeight;
	_pixelBytes = pBytesPixel;

	SDL_Init ( SDL_INIT_VIDEO ); 
	atexit ( SDL_Quit ) ;

#ifdef _WII
	if( pWidth > 640 )
		pWidth = 640;
	if( pHeight > 480 )
		pHeight = 480;
#endif

	_surface = SDL_SetVideoMode ( pWidth , pHeight , pBytesPixel * 8 , flags ) ;

	if(!_surface) {
		cout << "Surface creation at SDL_SetVideoMode failed" << endl;
		exit(1);
	}
}

cVideoWindow::~cVideoWindow() {

	SDL_FreeSurface( _surface );

}

