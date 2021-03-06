/*
 * Copyright (c) 1997 - 2001 Hansj�rg Malthaner
 *
 * This file is part of the Simutrans project under the artistic licence.
 * (see licence.txt)
 */

#ifndef gui_kennfarbe_h
#define gui_kennfarbe_h

#include "gui_frame.h"
#include "components/action_listener.h"
#include "components/gui_button.h"
#include "components/gui_image.h"
#include "components/gui_textarea.h"
#include "components/gui_label.h"
#include "../utils/cbuffer_t.h"

/**
 * Hierueber kann der Spieler seine Kennfarbe einstellen
 *
 * @author Hj. Malthaner
 */
class farbengui_t : public gui_frame_t, action_listener_t
{
private:
	spieler_t *sp;
	cbuffer_t buf;
	gui_textarea_t txt;
	gui_label_t c1, c2;
	gui_image_t bild;

	button_t player_color_1[28];
	button_t player_color_2[28];

public:
	farbengui_t(spieler_t *sp);

	/**
	 * Manche Fenster haben einen Hilfetext assoziiert.
	 * @return den Dateinamen f�r die Hilfe, oder NULL
	 * @author Hj. Malthaner
	 */
	const char * get_hilfe_datei() const { return "color.txt"; }

//	bool infowin_event(const event_t *ev);

	/**
	 * This method is called if an action is triggered
	 * @author Hj. Malthaner
	 *
	 * Returns true, if action is done and no more
	 * components should be triggered.
	 * V.Meyer
	 */
	bool action_triggered(gui_action_creator_t*, value_t) OVERRIDE;
};

#endif
