/*
   Copyright 2005-2009 Last.fm Ltd. 
      - Primarily authored by Jono Cole and Doug Mansell

   This file is part of the Last.fm Desktop Application Suite.

   lastfm-desktop is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   lastfm-desktop is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with lastfm-desktop.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SCROBBLE_CONTROLS_H
#define SCROBBLE_CONTROLS_H

#include "lib/unicorn/StylableWidget.h"

#include <lastfm/Track>
#include <lastfm/XmlQuery>

namespace unicorn{ class Session; };
namespace lastfm{ class UserDetails; };

class QPushButton;
class ScrobbleControls : public StylableWidget
{
    Q_OBJECT
public:
    ScrobbleControls( const Track& track );

protected:
    struct {
        QPushButton* love;
        QPushButton* tag;
        QPushButton* share;
        QPushButton* buy;
    } ui;

public slots:
    void setLoveChecked( bool checked );

private slots:
    void onLoveChanged( bool checked );
    void onShare();
    void onTag();

private:
    Track m_track;
};

#endif //SCROBBLE_CONTROLS_H